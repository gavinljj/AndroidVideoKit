/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <stdlib.h>
#include "logjam.h"
/* Header for class com_avos_minute_util_VideoEngine */
#include "com_avos_minute_util_VideoEngine.h"

static JavaVM *sVm;
extern int process(int argc, char** argv);

JNIEXPORT jint JNICALL JNI_Onload(JavaVM *jvm, void* reserved)
{
    LOGI("Loading native library compiled at " __TIME__ " " __DATE__);
    sVm = jvm;
    return JNI_VERSION_1_2;
}

/*
 * Class:     com_avos_minute_util_VideoEngine
 * Method:    crop
 * Signature: (Ljava/lang/String;Ljava/lang/String;II)I
 */
JNIEXPORT jint JNICALL Java_com_avos_minute_util_VideoEngine_crop
  (JNIEnv *env, jobject obj, jstring inputFile, jstring outputFile, jint width, jint height)
{
    jbyte *input = (*env)->GetStringUTFChars(env, inputFile, NULL);
    jbyte *output = (*env)->GetStringUTFChars(env, outputFile, NULL);
    LOGD("crop() called. in=%s, out=%s, w=%d h=%d", input, output, width, height);
    int i = 0;
    int result = -1;
    int argc = 8;
    char** argv = (char**)malloc(sizeof(char*) * argc);
    if (NULL == argv) {
        (*env)->ReleaseStringUTFChars(env, inputFile, input);
        (*env)->ReleaseStringUTFChars(env, outputFile, output);
        return (jint)result;
    }
    // ffmpeg -i inputfile -vf "crop=w:h" -acodec copy outputfile
    for (i = 0; i < argc; i++) {
        argv[i] = (char*)malloc(256);
        if (NULL == argv[i]) {
            break;
        }
        switch (i) {
            case 0:
                snprintf(argv[i], 256, "%s", "ffmpegutil");
                break;
            case 1:
                snprintf(argv[i], 256, "%s", "-i");
                break;
            case 2:
                snprintf(argv[i], 256, "%s", input);
                break;
            case 3:
                snprintf(argv[i], 256, "%s", "-vf");
                break;
            case 4:
                snprintf(argv[i], 256, "crop=%d:%d,transpose=1", width, height);
                break;
           case 5:
                snprintf(argv[i], 256, "%s", "-acodec");
                break;
           case 6:
                snprintf(argv[i], 256, "%s", "copy");
                break;
           case 7:
                snprintf(argv[i], 256, "%s", output);
                break;
           default:
                break;
        };
    }
    (*env)->ReleaseStringUTFChars(env, inputFile, input);
    (*env)->ReleaseStringUTFChars(env, outputFile, output);
 
    if (i == argc) {
        result = process(argc, argv);
    }
    for (i = 0; i < argc; i++) {
        if (NULL != argv[i]) {
            free(argv[i]);
            argv[i] = NULL;
        }
    };
    free(argv);
    argv = NULL;
    return (jint)result;
}

