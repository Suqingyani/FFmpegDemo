#include <jni.h>
#include <string>

extern "C" {
#include "./../jniLibs/include/libavutil/avutil.h"
#include "./../jniLibs/include/libavfilter/avfilter.h"
#include "./../jniLibs/include/libavformat/avformat.h"
#include "./../jniLibs/include/libavcodec/avcodec.h"
JNIEXPORT jstring JNICALL
Java_com_qy_demo_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_qy_demo_MainActivity_urlprotocolinfo(JNIEnv *env, jobject thiz) {
    // TODO: implement urlprotocolinfo()
    char info[40000] = {0};
    av_register_all();

    struct URLProtocol *pup = NULL;

    struct URLProtocol **p_temp = &pup;
    avio_enum_protocols((void **) p_temp, 0);

    while ((*p_temp) != NULL) {
        sprintf(info, "%sInput: %s\n", info, avio_enum_protocols((void **) p_temp, 0));
    }
    pup = NULL;
    avio_enum_protocols((void **) p_temp, 1);
    while ((*p_temp) != NULL) {
        sprintf(info, "%sInput: %s\n", info, avio_enum_protocols((void **) p_temp, 1));
    }
    return env->NewStringUTF(info);
}
JNIEXPORT jstring JNICALL
Java_com_qy_demo_MainActivity_avformatinfo(JNIEnv *env, jobject thiz) {
    // TODO: implement avformatinfo()
    char info[40000] = {0};

    av_register_all();

    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    while (if_temp != NULL) {
        sprintf(info, "%sInput: %s\n", info, if_temp->name);
        if_temp = if_temp->next;
    }
    while (of_temp != NULL) {
        sprintf(info, "%sOutput: %s\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    return env->NewStringUTF(info);
}
JNIEXPORT jstring JNICALL
Java_com_qy_demo_MainActivity_avfilterinfo(JNIEnv *env, jobject thiz) {
    // TODO: implement avfilterinfo()
    char info[40000] = {0};

    av_register_all();

    AVCodec *c_temp = av_codec_next(NULL);

    while (c_temp != NULL) {
        if (c_temp->decode != NULL) {
            sprintf(info, "%sdecode:", info);
        } else {
            sprintf(info, "%sencode:", info);
        }
        switch (c_temp->type) {
            case AVMEDIA_TYPE_VIDEO:
                sprintf(info, "%s(video):", info);
                break;
            case AVMEDIA_TYPE_AUDIO:
                sprintf(info, "%s(audio):", info);
                break;
            default:
                sprintf(info, "%s(other):", info);
                break;
        }
        sprintf(info, "%s[%10s]\n", info, c_temp->name);
        c_temp = c_temp->next;
    }

    return env->NewStringUTF(info);
}
}