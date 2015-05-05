package com.github.phantasien.bastian;

import android.app.Activity;
import android.os.Bundle;

public class BastianMainActivity extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
	callMyName();
    }
    
    public native void callMyName();

    static {
       System.loadLibrary("bastian");
    }
}
