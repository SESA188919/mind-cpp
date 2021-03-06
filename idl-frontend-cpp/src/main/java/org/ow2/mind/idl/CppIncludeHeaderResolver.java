/**
 * Copyright (C) 2014 Schneider-Electric
 *
 * This file is part of "Mind Compiler" is free software: you can redistribute 
 * it and/or modify it under the terms of the GNU Lesser General Public License 
 * as published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact: mind@ow2.org
 *
 * Authors: Stephane Seyvoz
 * Contributors: 
 */

package org.ow2.mind.idl;

import static org.ow2.mind.PathHelper.getExtension;
import static org.ow2.mind.PathHelper.toAbsolute;
import static org.ow2.mind.idl.ast.IDLASTHelper.getIncludedPath;
import static org.ow2.mind.idl.ast.CppInclude.CPP_HEADER_EXTENSION_0;
import static org.ow2.mind.idl.ast.CppInclude.CPP_HEADER_EXTENSION_1;
import static org.ow2.mind.idl.ast.CppInclude.CPP_HEADER_EXTENSION_2;
import static org.ow2.mind.idl.ast.CppInclude.CPP_HEADER_EXTENSION_3;
import static org.ow2.mind.idl.ast.Include.HEADER_EXTENSION;

import java.net.URL;
import java.util.Map;

import org.objectweb.fractal.adl.ADLException;
import org.objectweb.fractal.adl.NodeFactory;
import org.ow2.mind.CommonASTHelper;
import org.ow2.mind.PathHelper;
import org.ow2.mind.PathHelper.InvalidRelativPathException;
import org.ow2.mind.error.ErrorManager;
import org.ow2.mind.idl.IncludeResolver.AbstractDelegatingIncludeResolver;
import org.ow2.mind.idl.ast.Header;
import org.ow2.mind.idl.ast.IDL;
import org.ow2.mind.idl.ast.IDLASTHelper;
import org.ow2.mind.idl.ast.Include;

import com.google.inject.Inject;

/**
 * Refine the standard @see IncludeHeaderResolver to allow C++ extensions.
 * See Module class and mind-plugin.xml for override details.
 *
 */
public class CppIncludeHeaderResolver extends AbstractDelegatingIncludeResolver {

  @Inject
  protected ErrorManager errorManagerItf;

  @Inject
  protected NodeFactory  nodeFactoryItf;

  @Inject
  protected IDLLocator   idlLocatorItf;

  // ---------------------------------------------------------------------------
  // Implementation of the UsedIDLResolver interface
  // ---------------------------------------------------------------------------

  public IDL resolve(final Include include, final IDL encapsulatingIDL,
      final String encapsulatingName, final Map<Object, Object> context)
      throws ADLException {
    String path = getIncludedPath(include);
    if (getExtension(path).equals(HEADER_EXTENSION)
        || getExtension(path).equals(CPP_HEADER_EXTENSION_0)
        || getExtension(path).equals(CPP_HEADER_EXTENSION_1)
        || getExtension(path).equals(CPP_HEADER_EXTENSION_2)
        || getExtension(path).equals(CPP_HEADER_EXTENSION_3)) {
      // include node references a header C/C++ file.

      if (IDLASTHelper.getIncludeDelimiter(include) == IDLASTHelper.IncludeDelimiter.QUOTE) {
        // try to find header file and update the path if needed

        final String encapsulatingIDLName = (encapsulatingIDL != null)
            ? encapsulatingIDL.getName()
            : encapsulatingName;
        final String encapsulatingDir;
        if (encapsulatingIDLName.startsWith("/")) {
          encapsulatingDir = PathHelper.getParent(encapsulatingIDLName);
        } else {
          encapsulatingDir = PathHelper
              .fullyQualifiedNameToDirName(encapsulatingIDLName);
        }

        if (!path.startsWith("/")) {
          // look-for header relatively to encapsulatingDir
          String relPath;
          try {
            relPath = toAbsolute(encapsulatingDir, path);
          } catch (final InvalidRelativPathException e) {
            errorManagerItf.logError(IDLErrors.INVALID_INCLUDE, include, path);
            return IDLASTHelper.newUnresolvedIDLNode(nodeFactoryItf, path);
          }
          URL url = idlLocatorItf.findSourceHeader(relPath, context);
          if (url != null) {
            // IDL found with relPath
            path = relPath;
            IDLASTHelper.setIncludePathPreserveDelimiter(include, path);
          } else if (path.startsWith("./") || path.startsWith("../")) {
            // the path starts with "./" or "../" which force a resolution
            // relatively to encapsulatingDir. the file has not been found.
            errorManagerItf.logError(IDLErrors.IDL_NOT_FOUND, include, path);
            return IDLASTHelper.newUnresolvedIDLNode(nodeFactoryItf, path);
          } else {
            // look-for header relatively to source-path
            path = "/" + path;
            url = idlLocatorItf.findSourceHeader(path, context);
            if (url != null) {
              IDLASTHelper.setIncludePathPreserveDelimiter(include, path);
            }
          }
        }
      }

      // create a new Header AST node
      final Header header = CommonASTHelper.newNode(nodeFactoryItf, "header",
          Header.class);
      header.setName(path);
      return header;
    } else {
      return clientResolverItf.resolve(include, encapsulatingIDL,
          encapsulatingName, context);
    }
  }
}
