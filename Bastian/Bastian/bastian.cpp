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

static JSValueRef add(JSContextRef ctx, JSObjectRef /*function*/, JSObjectRef thisObject, size_t argumentCount, const JSValueRef* arguments, JSValueRef* exception) {
    
    double val1 = JSValueToNumber (ctx, arguments[0], exception);
    double val2 = JSValueToNumber (ctx, arguments[1], exception);
    
    return JSValueMakeNumber (ctx, val1 + val2);
}


static JSStaticValue staticValues[] = {
    { 0, 0, 0, 0 }
};

static JSStaticFunction staticFunctions[] = {
    { "add", add, kJSPropertyAttributeNone },
    { 0, 0, 0 }
};

JSClassDefinition globalsDefinition = {
    0, kJSClassAttributeNone, "globals", 0, staticValues, staticFunctions,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


void callMyName() {
    JSClassRef globals = JSClassCreate(&globalsDefinition);
    JSContextRef ctx = JSGlobalContextCreate(globals);
    JSStringRef script = JSStringCreateWithUTF8CString("add(1, 1)");
    JSValueRef exception = NULL;
    JSValueRef result = JSEvaluateScript(ctx, script, NULL, NULL, 1, &exception);
    
    std::cout << "Returned : " << JSValueToNumber(ctx, result, NULL) << std::endl;
    JSStringRelease(script);
}
