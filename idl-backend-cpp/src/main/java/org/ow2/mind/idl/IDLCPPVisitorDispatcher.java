
package org.ow2.mind.idl;

import java.util.Map;
import java.util.Set;

import org.ow2.mind.AbstractVoidVisitorDispatcher;
import org.ow2.mind.VoidVisitor;
import org.ow2.mind.adl.CppAnnotation;
import org.ow2.mind.idl.ast.IDL;

import com.google.inject.Inject;

public class IDLCPPVisitorDispatcher extends AbstractVoidVisitorDispatcher<IDL>
    implements
      IDLVisitor {

  @Inject
  @CppAnnotation
  protected Set<IDLVisitor> visitors;

  @Override
  protected Iterable<? extends VoidVisitor<IDL>> getVisitorsItf(
      final Map<Object, Object> context) {
    return visitors;
  }
}
