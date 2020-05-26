package com.qy.demo;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView textView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = findViewById(R.id.sample_text);
        textView.setText(stringFromJNI() +
                urlprotocolinfo() +
                avformatinfo() +
                avfilterinfo());
    }

    public native String stringFromJNI();

    public native String urlprotocolinfo();

    public native String avformatinfo();

    public native String avfilterinfo();
/**视频
 * HelloActivity
 * 使用Android Camera2 API获取YUV数据
 * YUV与RGB互转
 * 在YUV基础上美颜
 * 基于FFmpeg的H265/h264编码器
 *=======
 *
 * */

/**音频
 *使用 AudioRecord 采集音频PCM并保存到文件
 *Android pcm降噪变声 Speex
 *Android端PCM编码AAC的软编和硬编
 *
 * */

/**音视频
 *基于FFmpeg音视频流同步  https://blog.csdn.net/u010872301/article/details/81105757
 *
 * */

}
