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

JSValueRef FoobarGetter(JSContextRef ctx, JSObjectRef, JSStringRef, JSValueRef*) {
    return JSValueMakeNumber(ctx, 42);
}

bool FoobarSetter(JSContextRef, JSObjectRef, JSStringRef, JSValueRef, JSValueRef*) {
    return false;
}

static JSStaticValue foobar = {"foobar", FoobarGetter, FoobarSetter, 0};

static JSStaticValue staticValues[] = {
    foobar,
    { 0, 0, 0, 0 }
};

static JSStaticFunction staticFunctions[] = {
    { 0, 0, 0 }
};

JSClassDefinition globalsDefinition = {
    0, kJSClassAttributeNone, "globals", 0, staticValues, staticFunctions,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


void callMyName() {
    JSClassRef globals = JSClassCreate(&globalsDefinition);
    JSContextRef ctx = JSGlobalContextCreate(globals);
    JSStringRef script = JSStringCreateWithUTF8CString("foobar");
    JSValueRef exception = NULL;
    JSValueRef result = JSEvaluateScript(ctx, script, NULL, NULL, 1, &exception);
    
    std::cout << "Returned : " << JSValueToNumber(ctx, result, NULL) << std::endl;
    JSStringRelease(script);
}
