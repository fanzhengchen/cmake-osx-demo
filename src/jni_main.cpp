//
// Created by fanzhengchen on 6/29/17.
//

#include "jni_main.h"
#include <cstring>
#include <cstdlib>

static char *new_str = NULL;
static jclass gClass;
static jobject gObject;

extern "C"
JNIEXPORT void JNICALL Java_Main_doubleString
        (JNIEnv *env, jobject obj, jstring _jstr) {
    const char *str = env->GetStringUTFChars(_jstr, NULL);
    printf("cpp: ========%s\n", str);

    size_t len = strlen(str);
    new_str = (char *) malloc(len << 1 | 1);
    new_str[len << 1] = 0;
    for (size_t i = 0; i < len; ++i) {
        new_str[i] = new_str[i + len] = str[i];
    }

    gClass = env->GetObjectClass(obj);
//    gClass = env->FindClass();
    jmethodID _jmethod = env->GetMethodID(gClass, "callFromNative", "(Ljava/lang/String;)V");

    jstring ret = env->NewStringUTF(new_str);

    printf("cpp:========before call method\n");
    env->CallVoidMethod(obj, _jmethod, ret);
    env->ReleaseStringUTFChars(ret, new_str);
//    free(new_str);
}

extern "C"
JNIEXPORT void JNICALL Java_Main_release
        (JNIEnv *, jobject) {
    free(new_str);
}


