package com.example.drone;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.drone.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'drone' library on application startup.
    static {
        System.loadLibrary("drone");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        Button ButtonAvancer =binding.buttonAvancer;
        ButtonAvancer.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Avancer();

            }
        });
        Button buttonCommande= binding.buttonCommande;
        buttonCommande.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ModeCommande();
            }
        });

        Button buttonDroite= binding.buttonDroite;
        buttonDroite.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Droite();
            }
        });

        Button buttonReculer=binding.buttonReculer;
        buttonReculer.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Reculer();
            }
        });

        Button buttonDecoller=binding.buttonDecoller;
        buttonDecoller.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Decoller();
            }
        });

    }

    /**
     * A native method that is implemented by the 'drone' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String Avancer();
    public native String ModeCommande();
    public native String Droite();
    public native String Reculer();
    public native String Decoller();
}