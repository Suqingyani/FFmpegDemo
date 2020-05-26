package com.qy.demo.base;

/**
 * @Description: java类作用描述
 * @Author: 苏青岩
 * @CreateDate: 2020/5/26 15:53
 * @UpdateUser: 更新者：
 * @UpdateDate: 2020/5/26 15:53
 * @UpdateRemark: 更新说明：
 * @Version: 1.0
 */
public abstract class LibraryManager {
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avutil-55");
        System.loadLibrary("postproc-54");
        System.loadLibrary("swresample-2");
        System.loadLibrary("swscale-4");
    }

}
