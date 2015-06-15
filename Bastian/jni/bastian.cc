#include <jni.h>
#include <android/log.h>
#include <v8.h>

#include <sstream>

using namespace v8;

extern "C" JNIEXPORT void JNICALL Java_com_github_phantasien_bastian_BastianMainActivity_callMyName(JNIEnv* env, jobject thiz) {

  const char * rawSource = "foobar";
  
  // Create a new Isolate and make it the current one.
  Isolate* isolate = Isolate::New();
  Isolate::Scope isolate_scope(isolate);

  HandleScope handle_scope(isolate);

  Handle<ObjectTemplate> global = ObjectTemplate::New(isolate);

  global->Set(String::NewFromUtf8(isolate, "foobar"), Number::New(isolate, 42));

  // Create a new context.
  Local<Context> context = Context::New(isolate, NULL, global);

  // Enter the context for compiling and running the hello world script.
  Context::Scope context_scope(context);

  Local<String> source = String::NewFromUtf8(isolate, rawSource);
  Local<Script> script = Script::Compile(source);

  Local<Value> result = script->Run();

  std::stringstream stream;
  std::string logValue;

  stream << result->NumberValue();

  __android_log_write(ANDROID_LOG_INFO, "Bastian", stream.str().c_str());
}
