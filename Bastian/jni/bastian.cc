#include <jni.h>
#include <android/log.h>
#include <v8.h>

using namespace v8;


extern "C" JNIEXPORT void JNICALL Java_com_github_phantasien_bastian_BastianMainActivity_callMyName(JNIEnv* env, jobject thiz) {

  // Create a new Isolate and make it the current one.
  Isolate* isolate = Isolate::New();
  Isolate::Scope isolate_scope(isolate);

  __android_log_write(ANDROID_LOG_INFO, "Bastian", "Moon Child !");
}
