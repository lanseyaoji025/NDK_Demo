package com.example.admini.myapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    //定义好的数组
    int[]  array ={1,9,2,3,4,6,4,3,7};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());
        //调用native函数
        giveArray(array);
        //调用native函数后，在native层利用C语言对上面定义好的数组重新排序，之后打印出来
        for(int i : array){
            System.out.println(i);
        }

    }

    /**
     * A native method that is implemented by the 'native-lib' native library
     * which is packaged with this application.,
     */
    public native String stringFromJNI();

    //参数类型为int数组的Java层native函数
    public native void giveArray(int[] array);

}
