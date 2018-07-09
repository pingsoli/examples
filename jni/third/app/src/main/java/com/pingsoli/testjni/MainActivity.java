package com.pingsoli.testjni;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends Activity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setTitle("jni testing");

        Runtime rt = Runtime.getRuntime();
        long maxMemory = rt.maxMemory();
        Log.i("onCreate", "maxMemory: " + Long.toString(maxMemory));

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        Button btn = (Button) this.findViewById(R.id.sample_button);
        btn.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                TestJNI.memoryLeakByUnreleaseLocalRef();
            }
        });

        // You can see the log info from logcat terminal. make sure the log level is right.
//        TestJNI.nativePrintInnerClassInstance(jni);
//        TestJNI.nativePrintInnerClassInstanceByCallingJavaMethod(jni);
//        TestJNI.nativeCallInnerClassStaticPrintMethodNativeThread();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}