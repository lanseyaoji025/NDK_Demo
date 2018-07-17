//
// Created by admini on 2018/7/17.
//
#include <jni.h>
#include <stdlib.h>

//extern "C"
//这个我们自定义的函数，在利用C语言的qsort函数进行排序时会用到
int compare(int *a,int *b) {
    return (*a) - (*b);
}

JNIEXPORT void
JNICALL
Java_com_example_admini_myapplication_MainActivity_giveArray(
        JNIEnv *env,jobject obj,jintArray arr){

    jint *elems = (*env)->GetIntArrayElements(env, arr, NULL);
    //输出的两个数组地址不一样，这说明通过上面的GetIntArrayElements()函数，把原来的数组拷贝了一份
    printf("%#x,%#x\n", &elems, &arr);

    //数组的长度
    int len = (*env)->GetArrayLength(env, arr);
    //C语言中的排序函数，记得要引入stdlib.h头文件才可以使用
    qsort(elems, len, sizeof(jint), compare);
    //同步
    //最后一个参数有如下几种，代表的意义如下
    //0, Java数组进行更新，并且释放C/C++数组
    //JNI_ABORT, Java数组不进行更新，但是释放C/C++数组
    //JNI_COMMIT，Java数组进行更新，不释放C/C++数组（函数执行完，数组还是会释放）
    (*env)->ReleaseIntArrayElements(env, arr, elems, JNI_COMMIT);
}
