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

# Known Issues
1. BUIlding the sample app fails in Visual Studio because the libPInvokeTestSDK.a is not copied to the build server. 
To fix this, you need to set the "Copy to output directory" value in the libPInvokeTestSDK.a properties to "Copy Always". 
It is currently set to "Do not copy" which results in the library not being copied to the Mac build host and thus the file not being found. 
To fix this all you have to do is:
a. Open the properties for the libPInvokeTestSDK.a and change the value for the "Copy to output directory" field to "Copy Always."
b. Right click on the libPInvokeTestSDK.a file and select "Properties"
c. In the properties pane that opens, change the value for "Copy to output directory" from "Do not copy" to "Always Copy".