# Xamarin-PInvoke-Example
This repository demonstrates using PInvoke in Xamarin C# to call methods in an XCode C++ class.

To use this project you need to build the C and C++ from the command line using "make". To clean the build use "make clean"

After the make has completed you will have a libPInvokeTestSDK.a file which is the static library that is needed in the Xamarin project.

libPInvokeTestSDK.a is built to contain all the required architectures. Run lipo to examine the contents:
lipo -info libPinvokeTestSDK.a
Architectures in the fat file: libPinvokeTestSDK.a are: i386 armv7 x86_64 arm64

Every time you make a change to your XCode project you will need to copy a new fat library from the XCode project intot he Xamarin project.

Linker options are set to generate a map file (output.map) so you can see the symbols.

# Behind the scenes:
The Build Options in the Xamarin project (Build > iOS Build > Additional Options) need to be configured:
     -cxx -gcc_flags "-L${ProjectDir} -lPinvokeTestSDK -force_load ${ProjectDir}/libPinvokeTestSDK.a" -gcc_flags "-Wl,-map,${ProjectDir}/output.map" 

The XCode Project's Code Signing is set to Developer.
