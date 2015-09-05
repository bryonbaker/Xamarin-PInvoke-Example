PROJECTNAME=PinvokeTest

TARGET=$(PROJECTNAME)
XBUILD=xcodebuild
XBUILD_FLAGS=-Wl,-map,output.map
PROJECT_ROOT=.
SOURCE=$(PROJECT_ROOT)/$(PROJECTNAME)
PROJECT=$(PROJECT_ROOT)/$(PROJECTNAME).xcodeproj
SDK=iphoneos8.4
NAMESPACE=$(PROJECTNAME)

all: lib$(TARGET)SDK.a 

lib$(TARGET)-i386.a:
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphonesimulator -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphonesimulator/lib$(TARGET).a $@

lib$(TARGET)-armv7.a:
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphoneos -arch armv7 -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphoneos/lib$(TARGET).a $@

lib$(TARGET)-arm64.a:
	$(XBUILD) -project $(PROJECT) -target $(TARGET) -sdk iphoneos -arch arm64 -configuration Release clean build
	-mv $(PROJECT_ROOT)/build/Release-iphoneos/lib$(TARGET).a $@

lib$(TARGET)SDK.a: lib$(TARGET)-i386.a lib$(TARGET)-armv7.a lib$(TARGET)-arm64.a
	xcrun -sdk iphoneos lipo -create -output $@ $^

clean:
	-rm -rf *.a *.dll build

