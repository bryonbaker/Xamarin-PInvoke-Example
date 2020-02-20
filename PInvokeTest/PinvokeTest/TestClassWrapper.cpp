//
//  TestModule.c
//  PinvokeTest
//
//  Created by Bryon on 5/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#include "TestClassWrapper.h"

extern "C" TestClass* CreateTestClass()
{
    return new TestClass();
}

extern "C" void DisposeTestClass( TestClass* pObject)
{
    if(pObject != NULL)
    {
        delete pObject;
        pObject = NULL;
    }
}

extern "C" int GetNumber( TestClass *pObject )
{
    // This is unsafe. You should check the pointer is not NULL/
    // I haven't tested what happens if an exception is thrown from C++ to C#.
    return pObject->GetNumber();
}
