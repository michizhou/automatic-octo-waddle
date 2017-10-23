package com.example.michaelzhou.beatpindatamine;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.support.design.widget.Snackbar;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    long startTime;
    long stopTime;
    String statusmode, devicemode;
    int counter = 1;
    static int bpNum = 1;
    int lineCounter = 0;
    float startTimeArray[] = new float[11];
    float stopTimeArray[] = new float[11];
    String startList[] = new String[11];
    String stopList[] = new String[11];
    String eventList[] = new String[22];

    MotionEvent touchEvent;

    //Define all widgets
    Button buttonBeats;
    Button buttonNewPin;
    Button buttonNext;
    Spinner spinnerStatus;
    Spinner spinnerDevice;
    TextView textViewCurrentPin;

    String filename = "TimestampData.CSV";
    File fileOutput = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS), filename);
    CSVWriter writer;
    CSVReader csvReader;
    FileWriter mFileWriter;
    Vector<String> data = new Vector<>(22, 1);

    public boolean onTouch(View view, MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            return true;
        } else if (event.getAction() == MotionEvent.ACTION_UP) {
            return false;
        }
        return false;
    }

    public void beatMessage(View view) {
        startTimeArray[counter] = (float) ((System.nanoTime() - startTime) / 1000000000.000);
        eventList[counter] = "ActionDown ";
        float releaseTime = startTimeArray[counter];
        while (onTouch(view, touchEvent)) {
            releaseTime = (float) ((System.nanoTime() - startTime) / 1000000000.000);
        }
        stopTimeArray[counter - 1] = releaseTime;
        eventList[counter + 1] = "ActionUp ";
        counter = counter + 2;
    }

    public void stopMessage(View view) {
        stopTime = (System.nanoTime() - startTime) / 1000000000;
        stopTimeArray[10] = (float) stopTime;
        for (int i = 0; i < 11; i++) {
            startList[i] = Float.toString(startTimeArray[i]) + " s ";
            stopList[i] = Float.toString(stopTimeArray[i]) + " s ";
        }
        data.add(0, startList[0]);
        data.add(eventList[0]);
        int begCount = 1;
        for (int i = 1; i < 11; i++) {
            data.add(startList[begCount]);
            data.add(eventList[2*i-1]);
            data.add(stopList[begCount-1]);
            data.add(eventList[2*i]);
            begCount++;
        }
        data.add(stopList[begCount-1]);
        data.add(eventList[21]);
        try {
            csvReader = new CSVReader(new FileReader(fileOutput), ',', '\'', lineCounter);
            try {
                mFileWriter = new FileWriter(fileOutput, true);
                writer = new CSVWriter(mFileWriter);
            /*String[] trial = {String.valueOf(bpNum), statusmode, devicemode, startList[0], eventList[0],
                startList[1], eventList[1], stopList[0], eventList[2], startList[2], eventList[3],
                stopList[1], eventList[4], startList[3], eventList[5], stopList[2], eventList[6],
                startList[4], eventList[7], stopList[3], eventList[8], startList[5], eventList[9],
                stopList[4], eventList[10], startList[6], eventList[11], stopList[5], eventList[12],
                startList[7], eventList[13], stopList[6], eventList[14], startList[8], eventList[15],
                stopList[7], eventList[16], startList[9], eventList[17], stopList[8], eventList[18],
                startList[10], eventList[19], stopList[9], eventList[20], stopList[10], eventList[21]};*/
                String[] trial = {String.valueOf(bpNum), statusmode, devicemode, data.toString()};

                writer.writeNext(trial);
                try {
                    writer.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Get widget references.
        buttonNewPin = (Button) findViewById(R.id.buttonNewPin);
        buttonBeats = (Button) findViewById(R.id.buttonBeats);
        buttonNext = (Button) findViewById(R.id.buttonNext);
        spinnerDevice = (Spinner) findViewById(R.id.spinnerDevice);
        spinnerStatus = (Spinner) findViewById(R.id.spinnerStatus);
        textViewCurrentPin = (TextView) findViewById(R.id.textViewCurrentPin);

        //Defines all callbacks
        defineWidgets();

        startTime = System.nanoTime();

        //Check to see if there are permissions. If there are none, request them
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED
                && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                requestPermissions(new String[]{Manifest.permission.ACCESS_FINE_LOCATION,
                        Manifest.permission.ACCESS_COARSE_LOCATION}, 10);
            }
        }

        //Initialize textfile & beatPinNumber
        //If file doesn't exist, create it and start at 1.
        //If file exists, read last beatpin number and increment.
        if (fileOutput.exists() && !fileOutput.isDirectory()) {
            if (isExternalStorageReadable()) {
                try {
                    csvReader = new CSVReader(new FileReader(fileOutput), ',', '"', 1);
                    String[] row;
                    try {
                        while ((row = csvReader.readNext()) != null) {
                            bpNum = Integer.parseInt(row[0]);
                            lineCounter++;
                        }
                        bpNum++;
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }
        else if (!fileOutput.exists() && isExternalStorageWritable()) {
            try {
                writer = new CSVWriter(new FileWriter(fileOutput));
                String[] headers = {"Pin ID ", "Status ", "Device ", "Data "};
                writer.writeNext(headers);
                bpNum = 1;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        startTimeArray[0] = (float) 0.0;
        eventList[0] = "Start";
        textViewCurrentPin.setText("Beat PIN #: " + bpNum);
    }

    private void defineWidgets(){
        defineButtonBeats();
        defineButtonNewPin();
        defineButtonNext();
        defineSpinnerStatus();
        defineSpinnerDevice();
    }

    private void defineButtonBeats(){
        buttonBeats.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Timestamp: " + (float) ((System.nanoTime() - startTime) / 1000000000.000)
                        + " s", Snackbar.LENGTH_INDEFINITE).setAction("Action", null).show();
            }
        });
    }

    private void defineButtonNewPin(){
        buttonNewPin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bpNum++;
                textViewCurrentPin.setText("Beat PIN #: " + bpNum);

                Snackbar.make(view, "Start: " + (float) startTime + " s", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });
    }

    private void defineButtonNext(){
        buttonNext.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "End beats", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });
    }

    private void defineSpinnerStatus() {
        // Create an ArrayAdapter using the string array and a default spinner layout
        ArrayAdapter<CharSequence> arrayAdapterStatus = ArrayAdapter.createFromResource(this,
                R.array.status_array, android.R.layout.simple_spinner_item);
        // Specify the layout to use when the list of choices appears
        arrayAdapterStatus.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        // Apply the adapter to the spinner
        spinnerStatus.setAdapter(arrayAdapterStatus);
        spinnerStatus.setOnItemSelectedListener(this);
    }

    private void defineSpinnerDevice() {
        // Create an ArrayAdapter using the string array and a default spinner layout
        ArrayAdapter<CharSequence> arrayAdapterDevices = ArrayAdapter.createFromResource(this,
                R.array.devices_array, android.R.layout.simple_spinner_item);
        // Specify the layout to use when the list of choices appears
        arrayAdapterDevices.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        // Apply the adapter to the spinner
        spinnerDevice.setAdapter(arrayAdapterDevices);
        spinnerDevice.setOnItemSelectedListener(this);
    }


    public void onItemSelected (AdapterView parent, View view,int pos, long id){
        Spinner testcase = (Spinner) parent;
        if (testcase.getId() == R.id.spinnerStatus) {
            switch (pos) {
                case 0:
                    Toast.makeText(parent.getContext(), "Setup Mode Selected", Toast.LENGTH_SHORT).show();
                    statusmode = " Setup";
                    break;
                case 1:
                    Toast.makeText(parent.getContext(), "SlowWalk Mode Selected", Toast.LENGTH_SHORT).show();
                    statusmode = " SlowWalk";
                    break;
                case 2:
                    Toast.makeText(parent.getContext(), "Sitting Mode Selected", Toast.LENGTH_SHORT).show();
                    statusmode = " Sitting";
                    break;
                case 3:
                    Toast.makeText(parent.getContext(), "FastWalk Mode Selected", Toast.LENGTH_SHORT).show();
                    statusmode = " FastWalk";
                    break;
            }
        }
        else if (testcase.getId() == R.id.spinnerDevice) {
            switch (pos) {
                case 0:
                    Toast.makeText(parent.getContext(), "Huawei Honor Selected", Toast.LENGTH_SHORT).show();
                    devicemode = " Huawei Honor";
                    break;
                case 1:
                    Toast.makeText(parent.getContext(), "Galaxy Tab S Selected", Toast.LENGTH_SHORT).show();
                    devicemode = " Galaxy Tab S";
                    break;
                case 2:
                    Toast.makeText(parent.getContext(), "LG L15G Selected", Toast.LENGTH_SHORT).show();
                    devicemode = " LG L15G";
                    break;
                case 3:
                    Toast.makeText(parent.getContext(), "Samsung Galaxy S2 Selected", Toast.LENGTH_SHORT).show();
                    devicemode = " Samsung Galaxy S2";
                    break;
                case 4:
                    Toast.makeText(parent.getContext(), "Nexus 4 Selected", Toast.LENGTH_SHORT).show();
                    devicemode = " Nexus 4";
                    break;
                case 5:
                    Toast.makeText(parent.getContext(), "Moto G Selected", Toast.LENGTH_SHORT).show();
                    devicemode = " Moto G";
                    break;
            }
        }
    }

    public void onNothingSelected (AdapterView parent){
        Toast.makeText(parent.getContext(), "Nothing was selected", Toast.LENGTH_SHORT).show();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    /* Checks if external storage is available for read and write */
    public boolean isExternalStorageWritable() {
        String state = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED.equals(state)) {
            return true;
        }
        return false;
    }

    /* Checks if external storage is available to at least read */
    public boolean isExternalStorageReadable() {
        String state = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED.equals(state) ||
                Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
            return true;
        }
        return false;
    }
}
