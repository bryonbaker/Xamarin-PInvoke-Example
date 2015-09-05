//
//  TestModule.h
//  PinvokeTest
//
//  Created by Bryon on 5/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#ifndef __PinvokeTest__TestClassWrapper__
#define __PinvokeTest__TestClassWrapper__

#include <stdio.h>
#include "TestClass.h"

extern "C" TestClass* CreateTestClass();
extern "C" void DisposeTestClass( TestClass* pObject);
extern "C" int GetNumber( TestClass *pObject );


#endif /* defined(__PinvokeTest__TestClassWrapper__) */
