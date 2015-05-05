#include <jni.h>
#include <android/log.h>




extern "C" JNIEXPORT void JNICALL Java_com_github_bastian_BastianMainActivity_callMyName(JNIEnv* env, jobject thiz) {
    __android_log_write(ANDROID_LOG_INFO, "Bastian", "Moon Child !");
}
