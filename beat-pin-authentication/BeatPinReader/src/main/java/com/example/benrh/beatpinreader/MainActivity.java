package com.example.benrh.beatpinreader;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Environment;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    //Widgets
    Button buttonBeat, buttonNewPin, buttonRetry, buttonNext;
    Spinner spinnerDevice, spinnerStatus;
    TextView textViewStatus;

    //BeatPin Statistics
    String stringDevice, stringStatus;
    Integer beatPinNumber, beatPinAttempt;
    ArrayList<String> listEvents;
    ArrayList<Double> listEventTimes;
    Double startTime;

    //File Objects
    File fileDownloadDirectory, fileBeatPinsCSV, fileBeatPinNumber;
    BufferedWriter bufferedWriterCSV, bufferedWriterBeatPinNumber;
    BufferedReader bufferedReaderBeatPinNumber;
    Boolean writeOK;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Get Widget References & Define Callbacks
        defineWidgets();

        writeOK = false; // We have not yet validated that write permissions are allowed!
        beatPinAttempt = 1;

        //Initialize the Lists
        listEvents = new ArrayList<String>();
        listEventTimes = new ArrayList<Double>();

        //Request file permissions if not available
        if (  (ActivityCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) ||
                (ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED)    ){
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                requestPermissions(new String[] {
                        Manifest.permission.WRITE_EXTERNAL_STORAGE,
                        Manifest.permission.READ_EXTERNAL_STORAGE
                }, 10);
            }
        }
        else{
            openOutput();
        }

        //Mark the start time.
        startTime = System.nanoTime()/1e9;
    }

    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch(requestCode){
            case 10:
                if(grantResults.length>0 && grantResults[0] == PackageManager.PERMISSION_GRANTED){
                    //We can write files!
                    openOutput();
                }
        }
    }

    public void openOutput(){
        String stringBeatPinNumber;

        Log.e("BeatPin", "openOutput()");

        writeOK = true;

        //Get path references.
        fileDownloadDirectory = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS);
        fileBeatPinsCSV = new File(fileDownloadDirectory, "_beatPins.csv");
        fileBeatPinNumber = new File(fileDownloadDirectory, "_beatPinNumber.txt");

        //Create file
        if(!fileBeatPinsCSV.exists()){
            try{
                fileBeatPinsCSV.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        //Open for writing.
        try {
            bufferedWriterCSV = new BufferedWriter(new FileWriter(fileBeatPinsCSV, true));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Log.e("BeatPin", "openOutput() Created CSV");

        //Create file if it doesn't exist. Read current beatpin index if it does.
        if(!fileBeatPinNumber.exists()){
            try{
                beatPinNumber = 1;
                fileBeatPinNumber.createNewFile();
                Log.e("BeatPin", "openOutput() Created fileBeatPinNumber");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        else {
            try{
                bufferedReaderBeatPinNumber = new BufferedReader(new FileReader((fileBeatPinNumber)));
                stringBeatPinNumber = bufferedReaderBeatPinNumber.readLine();

                try{ beatPinNumber = Integer.parseInt(stringBeatPinNumber) + 1;}
                catch (Exception e){ beatPinNumber = 1; }

                bufferedReaderBeatPinNumber.close();
                Log.e("BeatPin", "openOutput() Reading fileBeatPinNumber");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        updateTextViewStatus();
    }

    public void closeOutput(){
        try {
            bufferedWriterCSV.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            bufferedWriterBeatPinNumber.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeBeatPin(){
        if(writeOK){
            try {
                bufferedWriterCSV.flush();
                bufferedWriterCSV.write(beatPinToString());
                bufferedWriterCSV.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                bufferedWriterBeatPinNumber = new BufferedWriter(new FileWriter(fileBeatPinNumber, false));
                bufferedWriterBeatPinNumber.write(beatPinNumber.toString());
                bufferedWriterBeatPinNumber.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void clearBeatPin(){
        //Clear data.
        listEvents.clear();
        listEventTimes.clear();

        //Reset start time.
        startTime = System.nanoTime()/1e9;

        listEvents.add("Start");
        listEventTimes.add( System.nanoTime()/1e9 - startTime );
    }

    String beatPinToString(){
        String stringBeatPin;
        Integer i;

        stringBeatPin = "";
        stringBeatPin = beatPinNumber.toString();
        stringBeatPin = stringBeatPin + "," + stringStatus;
        stringBeatPin = stringBeatPin + "," + stringDevice;

        for(i = 0; i < listEvents.size(); i++){
            stringBeatPin = stringBeatPin + "," + listEvents.get(i);
            stringBeatPin = stringBeatPin + "," + listEventTimes.get(i);
        }

        return stringBeatPin;
    }

    private void defineWidgets(){
        buttonBeat = (Button) findViewById(R.id.buttonBeat);
        buttonNewPin = (Button) findViewById(R.id.buttonNewPin);
        buttonRetry = (Button) findViewById(R.id.buttonRetry);
        buttonNext = (Button) findViewById(R.id.buttonNext);
        spinnerDevice = (Spinner) findViewById(R.id.spinnerDevice);
        spinnerStatus = (Spinner) findViewById(R.id.spinnerStatus);
        textViewStatus = (TextView) findViewById(R.id.textViewStatus);

        defineButtonBeat();
        defineButtonNewPin();
        defineButtonRetry();
        defineButtonNext();
        defineSpinnerDevice();
        defineSpinnerStatus();
    }

    private void defineButtonBeat(){

        buttonBeat.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN){
                    listEvents.add("ActionDown");
                    Log.e("ActionDown", String.valueOf(event.getEventTime()));
                    listEventTimes.add( System.nanoTime()/1e9 - startTime );
                }
                if(event.getAction() == MotionEvent.ACTION_UP){
                    listEvents.add("ActionUp");
                    Log.e("ActionUp", String.valueOf(event.getEventTime()));
                    listEventTimes.add( System.nanoTime()/1e9 - startTime );
                }
                return false;
            }
        });
    }

    private void defineButtonNewPin(){
        buttonNewPin.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN){
                    //Action Down
                    listEvents.add("Stop");
                    listEventTimes.add( System.nanoTime()/1e9 - startTime );

                    writeBeatPin();
                    clearBeatPin();
                    beatPinNumber++;
                    beatPinAttempt++;

                    updateTextViewStatus();
                }
                return false;
            }
        });
    }

    private void defineButtonNext(){
        buttonNext.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN){
                    //Action Down
                    listEvents.add("Stop");
                    listEventTimes.add( System.nanoTime()/1e9 - startTime );

                    writeBeatPin();
                    clearBeatPin();
                    beatPinAttempt++;

                    updateTextViewStatus();
                }
                return false;
            }
        });
    }

    private void defineButtonRetry(){
        buttonRetry.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_DOWN){
                    //Action Down
                    clearBeatPin();
                    beatPinAttempt++;
                    updateTextViewStatus();
                }
                return false;
            }
        });
    }

    private void defineSpinnerStatus() {
        ArrayAdapter<CharSequence> arrayAdapterStatus = ArrayAdapter.createFromResource(this,
                R.array.stringArrayStatus, android.R.layout.simple_spinner_item);
        arrayAdapterStatus.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerStatus.setAdapter(arrayAdapterStatus);

        //Initialize string
        stringStatus = spinnerStatus.getSelectedItem().toString();

        spinnerStatus.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parentView, View selectedItemView, int position, long id) {
                stringStatus = spinnerStatus.getSelectedItem().toString();
                Toast.makeText(parentView.getContext(), stringStatus + " Mode Selected", Toast.LENGTH_SHORT).show();
                updateTextViewStatus();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parentView) {
            }
        });
    }

    private void defineSpinnerDevice() {
        ArrayAdapter<CharSequence> arrayAdapterDevices = ArrayAdapter.createFromResource(this,
                R.array.stringArrayDevice, android.R.layout.simple_spinner_item);
        arrayAdapterDevices.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerDevice.setAdapter(arrayAdapterDevices);

        //Initialize string
        stringDevice = spinnerDevice.getSelectedItem().toString();

        spinnerDevice.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parentView, View selectedItemView, int position, long id) {
                stringDevice = spinnerDevice.getSelectedItem().toString();
                Toast.makeText(parentView.getContext(), stringDevice + " Selected", Toast.LENGTH_SHORT).show();
                updateTextViewStatus();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parentView) {
            }
        });
    }

    public void updateTextViewStatus(){
        String stringTextViewStatus;
        stringTextViewStatus = "Device: " + stringDevice + "   -   Status: " + stringStatus
                + "\nBeatPinNumber: " + beatPinNumber.toString() + "   -   Attempt: " + beatPinAttempt.toString();
        textViewStatus.setText(stringTextViewStatus.toString());
    }


    //Full android life-cycle below. Couple routines used for file handling.
    @Override
    protected void onStart() {
        super.onStart();
        // The activity is about to become visible.
        clearBeatPin();
    }
    @Override
    protected void onResume() {
        super.onResume();
        // The activity has become visible (it is now "resumed").
        clearBeatPin();
    }
    @Override
    protected void onPause() {
        super.onPause();
        // Another activity is taking focus (this activity is about to be "paused").
        clearBeatPin();
    }
    @Override
    protected void onStop() {
        super.onStop();
        // The activity is no longer visible (it is now "stopped")
        clearBeatPin();
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
        // The activity is about to be destroyed.
        closeOutput();
    }
}