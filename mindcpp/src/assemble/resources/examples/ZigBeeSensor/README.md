ExampleCpp01
====================

An example of mincpp usage


################################################################################

To generate the User and Developer Guides, perform the following command in the
mind-compiler directory :

$ mvn -N clean pre-site

The PDF and HTML documents can then be found in the <module-dir>/target/site
directory.

When editing docbooks, it is recommended to "touch" top-level docbook files 
before executing the maven-docbkx-plugin. Indeed, docbook sources are split in
various XML files which is not correctly handle by the plugin (if the top-level
file has not been updated, the plugin will not re-compile the doc). So when 
editing the documentation the command should be :

$ touch src/docbkx/*.xml; mvn -N clean pre-site