#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_admini_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obj/* this */) {
    std::string hello = "Hello from C++";
    //1.obj就代表MainActivity的实体对象，但我们这里需要的是MainActiviyt.class字节码文件，
    // 通过以下方法可得到MainActiviy对应的字节码文件。
//    jclass cls =(*env)->GetObjectClass(env,obj);
    return env->NewStringUTF(hello.c_str());
}
