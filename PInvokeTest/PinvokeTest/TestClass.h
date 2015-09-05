//
//  TestClass.h
//  PinvokeTest
//
//  Created by Bryon on 5/09/2015.
//  Copyright (c) 2015 Bryon Baker. All rights reserved.
//

#ifndef __PinvokeTest__TestClass__
#define __PinvokeTest__TestClass__

#include <stdio.h>

class TestClass {
public:
    TestClass();
    ~TestClass();
    
    int GetNumber();
    
private:
    int number;
};

#endif /* defined(__PinvokeTest__TestClass__) */
