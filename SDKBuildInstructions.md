# Introduction #
Until there are binary packages available for the different modules of the AWD SDK, anyone who wishes to use the SDK in any way (including using an AWD exporter plug-in) must build the SDK from source.

# Building/installing on Windows #
The official way to build the AWD SDK on Windows is to use Microsoft Visual C++ 2008 Express or 2010 Express, which are both free (as in beer, not freedom.) Tests are being continuously performed on VC++ 2008 on Windows 7, but other versions have been reported to work and the official 64 bit version is built on 2010 Express.

## Compiling Python ##
Before PyAWD can be compiled, the Python source distribution needs to be downloaded into the right location and the libraries compiled. Perform these steps if you intend to build PyAWD, or skip them if you only want to build libawd.

  1. Download the Python source from http://python.org/download/. Make sure that the downloaded version matches the environment in which you want to use PyAWD (e.g. 2.6 in Maya, 3.x in Blender et c.)
  1. Unzip the sources, which will create a Python-x.x.x folder.
  1. Move the unzipped folder into the python-pyawd directory in the AWD distribution, renaming it "Python".
  1. Inside the Python folder is a PCBuild folder. Open the pcbuild.sln solution in VC++ from that folder.
  1. Make sure the "Release" configuration is selected, and the right target architecture, and build the solution. Some projects are likely to fail, especially `_bsddb`, `bz2`, `_tkinter`, `_ssl`, and `_sqlite3`. Remove those if they fail and rebuild.

The build was successful (enough) when a `python26.lib` file has been generated in the PCBuild directory.

## Compiling the AWD SDK ##
The SDK source distribution (`sdks` folder in the repository) includes a VC++ solution called `sdk.sln`, which in turn includes projects for both libawd and PyAWD. Open the solution in VC++ and build it, or just the libawd project if you intend not to build PyAWD.

If the build succeeds, a libawd.lib file will have been created in the `sdks/cpp-libawd/build` folder, and a directory called `pyawd` which is the PyAWD Python package will be in the `sdks/python-pyawd/build` folder.

If you intend to install PyAWD as a part of an exporter, see the install instructions for that exporter on where to put the freshly built pyawd directory.

# Building/installing on Mac OSX and Linux/UNIX #
On Mac OSX and other UNIX flavors the supported building method for libawd is GNU make, whereas PyAWD uses the standard Python distutils for building and installing.

## Building and installing libawd ##
Install libawd if you will be using (or creating) tools that are built using C/C++, or if you intend to use the libawd back-end for PyAWD (which is vastly more performant than the strictly Python version.)

Building libawd using GNU make is very simple. Starting at the root of the source tree of AWD, execute the following commands in order in your terminal.
```
$ cd sdks/cpp-libawd
$ sudo make install
```

This will build libawd and install it into /usr/local/lib and /usr/local/include on your machine. This is where any dynamically linked binaries will find it at runtime, and also where the linker will find it when building statically linked binaries.

## Building and installing PyAWD ##
By default, PyAWD will be built to rely on libawd, so first make sure that libawd was correctly installed in the previous steps. Then, from the root of the source tree of AWD, execute the following commands in order.
```
$ cd sdks/python-pyawd
$ python setup.py install
```

This will install PyAWD for the python installation to which the "python" binary belongs. If you need to install it into Maya, for instance, then use the python binary belonging to Maya, e.g:
```
$ /Applications/Autodesk/maya2011/Maya.app/Contents/bin/mayapy setup.py install
```

Note that this will only install the PyAWD package of supporting modules. It will not install the Maya exporter, which is distributed separately is a set of Python and MEL files to be installed into the Maya plug-ins and scripts folders.