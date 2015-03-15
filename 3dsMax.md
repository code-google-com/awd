# AWD in 3ds Max #


## Introduction ##
For users of Autodesk 3ds Max there is a plug-in that allows you to export AWD2 files supporting most of the features that the AWD format supports. Features supported are:

  * Geometry and meshes (including instancing)
  * Scene graph with containers and parenting
  * Basic color and texture materials
  * Skeletons
  * Skeletal animation

## 3ds Max versions supported ##
Currently the only supported version is 2012 (both 32 bit and 64 bit) although versions of the plug-in for 3ds Max 2013 will be released shortly.

## Instructions for installing ##
  1. Download the correct package for your 3ds Max version and platform (32 bit or 64 bit) from the downloads page.
  1. Unzip the package
  1. Move all of the files in the package to the plugins folder in your 3ds Max installation. Usually this will be something like `C:\Program Files\Autodesk\3ds Max 2012\plugins`.

If you are on a 64 bit system but using a 32 bit version of Max the default install location is `C:\Program Files (x86)\Autodesk\3ds Max 2012\plugins` instead. Note that it needs to be the `plugins` folder, not `plug-ins`.

## Instructions for use ##
Once you have installed the AWD exporter for 3ds Max you will see the AWD file format added to the export dialog, where you select location and file name. Picking AWD here and clicking export will open up the AWD export dialog with options.

See the separate [sequences.txt wiki page](UsingSequencesTxtFiles.md) for instructions on how to specify frame ranges for named animation sequences. Failure to do so will prevent animation sequences from being exported.

## Version history ##
### 1.0.2 (June 12, 2012) ###
  * Fixes crash issue in 32 bit version.
  * Contains significant performance improvements when exporting large geometry.
  * Fixes issues when exporting a scene that contains splines (which will now be skipped).
  * Fixes incorrect coordinate system conversion (flipped models)
  * Fixes incorrect UV mappings (vertically flipped textures)
  * Includes fix for severe implementation error in libawd (causing incorrect AWD2 files to be created.)
  * Some known issues exist and will be fixed in 1.0.3. See issue tracker.

### 1.0.1 (May 14, 2012) ###
  * Fixes issue that would cause crashes when invoking the exporter after having restarted Max.
  * Minor stability improvements and bug fixes.
  * Latest viewer automatically scales textures (no invalid dimension errors) and fixes issue where it would sometime not properly fill the browser window.

### 1.0.0 (May 10, 2012) ###
  * First release.
  * Supports AWD2.0 basic functionality.