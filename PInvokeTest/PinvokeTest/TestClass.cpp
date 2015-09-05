//
//  TestClass.cpp
//  PinvokeTest
//
//  Created by Bryon on 5/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#include "TestClass.h"

TestClass::TestClass()
{
    number = 123;
    return;
}

TestClass::~TestClass()
{
    return;
}

int TestClass::GetNumber()
{
    return number;
}
