//
//  bastian.cpp
//  Bastian
//
//  Created by David Corticchiato on 05/05/2015.
//  Copyright (c) 2015 David Corticchiato. All rights reserved.
//

#include <iostream>
#include "bastian.h"
#include <JavascriptCore/JavascriptCore.h>

void sayMyName() {
    JSContextRef ctx = JSGlobalContextCreate(NULL);
    JSStringRef script = JSStringCreateWithUTF8CString("1 + 1");
    JSValueRef exception = NULL;
    JSValueRef result = JSEvaluateScript(ctx, script, NULL, NULL, 1, &exception);
    
    std::cout << "Returned : " << JSValueToNumber(ctx, result, NULL) << std::endl;
    JSStringRelease(script);
}
