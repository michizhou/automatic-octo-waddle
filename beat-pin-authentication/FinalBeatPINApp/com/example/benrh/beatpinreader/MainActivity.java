package com.example.benrh.beatpinreader;

import android.graphics.Color;
import android.os.Build.VERSION;
import android.os.Bundle;
import android.os.Environment;
import android.support.annotation.NonNull;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    Integer beatPinAttempt;
    BufferedWriter bufferedWriterCSV;
    Button buttonBeat;
    Button buttonRetry;
    Button buttonSave;
    Integer currentPasswordLength;
    EditText editTextUserName;
    File fileBeatPinsCSV;
    File fileDownloadDirectory;
    Integer firstPasswordLength;
    ArrayList<Double> listEventTimes;
    ArrayList<String> listEvents;
    Spinner spinnerDevice;
    Spinner spinnerStatus;
    Double startTime;
    String stringDevice;
    String stringStatus;
    TextView textViewStatus;
    Toast toastWrongPasswordLength;
    Boolean writeOK;

    class C01891 implements OnTouchListener {
        C01891() {
        }

        public boolean onTouch(View v, MotionEvent event) {
            if (event.getAction() == 0) {
                MainActivity.this.listEvents.add("ActionDown");
                Log.e("ActionDown", String.valueOf(event.getEventTime()));
                MainActivity.this.listEventTimes.add(Double.valueOf((((double) System.nanoTime()) / 1.0E9d) - MainActivity.this.startTime.doubleValue()));
                MainActivity.this.updateTextViewStatus();
                Integer num = MainActivity.this.currentPasswordLength;
                MainActivity.this.currentPasswordLength = Integer.valueOf(MainActivity.this.currentPasswordLength.intValue() + 1);
            } else if (event.getAction() == 1) {
                MainActivity.this.listEvents.add("ActionUp");
                Log.e("ActionUp", String.valueOf(event.getEventTime()));
                MainActivity.this.listEventTimes.add(Double.valueOf((((double) System.nanoTime()) / 1.0E9d) - MainActivity.this.startTime.doubleValue()));
                MainActivity.this.updateTextViewStatus();
            }
            return true;
        }
    }

    class C01902 implements OnTouchListener {
        C01902() {
        }

        public boolean onTouch(View v, MotionEvent event) {
            if (event.getAction() == 0) {
                if (MainActivity.this.firstPasswordLength.intValue() < 0) {
                    MainActivity.this.firstPasswordLength = MainActivity.this.currentPasswordLength;
                }
                if (MainActivity.this.currentPasswordLength == MainActivity.this.firstPasswordLength) {
                    MainActivity.this.listEvents.add("Stop");
                    MainActivity.this.listEventTimes.add(Double.valueOf((((double) System.nanoTime()) / 1.0E9d) - MainActivity.this.startTime.doubleValue()));
                    MainActivity.this.writeBeatPin();
                    MainActivity.this.clearBeatPin();
                    MainActivity.this.currentPasswordLength = Integer.valueOf(0);
                    Integer num = MainActivity.this.beatPinAttempt;
                    MainActivity.this.beatPinAttempt = Integer.valueOf(MainActivity.this.beatPinAttempt.intValue() + 1);
                } else {
                    MainActivity.this.currentPasswordLength = Integer.valueOf(0);
                    MainActivity.this.clearBeatPin();
                    Toast toast = MainActivity.this.toastWrongPasswordLength;
                    Toast.makeText(MainActivity.this, "Wrong Password Length. Try again!", 0).show();
                }
                MainActivity.this.updateTextViewStatus();
            }
            return false;
        }
    }

    class C01913 implements OnTouchListener {
        C01913() {
        }

        public boolean onTouch(View v, MotionEvent event) {
            if (event.getAction() == 0) {
                MainActivity.this.currentPasswordLength = Integer.valueOf(0);
                MainActivity.this.clearBeatPin();
                MainActivity.this.updateTextViewStatus();
            }
            return false;
        }
    }

    class C01924 implements OnItemSelectedListener {
        C01924() {
        }

        public void onItemSelected(AdapterView<?> adapterView, View selectedItemView, int position, long id) {
            MainActivity.this.stringStatus = MainActivity.this.spinnerStatus.getSelectedItem().toString();
            MainActivity.this.updateTextViewStatus();
        }

        public void onNothingSelected(AdapterView<?> adapterView) {
        }
    }

    class C01935 implements OnItemSelectedListener {
        C01935() {
        }

        public void onItemSelected(AdapterView<?> adapterView, View selectedItemView, int position, long id) {
            MainActivity.this.stringDevice = MainActivity.this.spinnerDevice.getSelectedItem().toString();
            MainActivity.this.updateTextViewStatus();
        }

        public void onNothingSelected(AdapterView<?> adapterView) {
        }
    }

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView((int) C0194R.layout.activity_main);
        this.writeOK = Boolean.valueOf(false);
        this.firstPasswordLength = Integer.valueOf(-1);
        this.beatPinAttempt = Integer.valueOf(0);
        this.currentPasswordLength = Integer.valueOf(0);
        defineWidgets();
        this.listEvents = new ArrayList();
        this.listEventTimes = new ArrayList();
        if (ContextCompat.checkSelfPermission(this, "android.permission.WRITE_EXTERNAL_STORAGE") == 0 && ContextCompat.checkSelfPermission(this, "android.permission.READ_EXTERNAL_STORAGE") == 0) {
            defineCallBacks();
            openOutput();
        } else if (VERSION.SDK_INT >= 23) {
            requestPermissions(new String[]{"android.permission.WRITE_EXTERNAL_STORAGE", "android.permission.READ_EXTERNAL_STORAGE"}, 10);
        }
        this.startTime = Double.valueOf(((double) System.nanoTime()) / 1.0E9d);
    }

    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode) {
            case 10:
                if (grantResults.length > 0 && grantResults[0] == 0) {
                    defineCallBacks();
                    openOutput();
                    return;
                }
                return;
            default:
                return;
        }
    }

    public void openOutput() {
        Log.e("BeatPin", "openOutput()");
        this.writeOK = Boolean.valueOf(true);
        this.fileDownloadDirectory = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS);
        this.fileBeatPinsCSV = new File(this.fileDownloadDirectory, "_beatPins.csv");
        if (!this.fileBeatPinsCSV.exists()) {
            try {
                this.fileBeatPinsCSV.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            this.bufferedWriterCSV = new BufferedWriter(new FileWriter(this.fileBeatPinsCSV, true));
        } catch (IOException e2) {
            e2.printStackTrace();
        }
        Log.e("BeatPin", "openOutput() Created CSV");
        updateTextViewStatus();
    }

    public void closeOutput() {
        try {
            this.bufferedWriterCSV.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void writeBeatPin() {
        if (this.writeOK.booleanValue()) {
            try {
                this.bufferedWriterCSV.flush();
                this.bufferedWriterCSV.write(beatPinToString());
                this.bufferedWriterCSV.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void clearBeatPin() {
        this.listEvents.clear();
        this.listEventTimes.clear();
        this.startTime = Double.valueOf(((double) System.nanoTime()) / 1.0E9d);
        this.listEvents.add("Start");
        this.listEventTimes.add(Double.valueOf((((double) System.nanoTime()) / 1.0E9d) - this.startTime.doubleValue()));
    }

    String beatPinToString() {
        String stringBeatPin = "";
        stringBeatPin = (this.editTextUserName.getText().toString() + "," + this.stringStatus) + "," + this.stringDevice;
        for (Integer i = Integer.valueOf(0); i.intValue() < this.listEvents.size(); i = Integer.valueOf(i.intValue() + 1)) {
            stringBeatPin = (stringBeatPin + "," + ((String) this.listEvents.get(i.intValue()))) + "," + this.listEventTimes.get(i.intValue());
        }
        return stringBeatPin;
    }

    private void defineCallBacks() {
        defineButtonBeat();
        defineButtonRetry();
        defineButtonSave();
        defineSpinnerDevice();
        defineSpinnerStatus();
    }

    private void defineWidgets() {
        this.buttonBeat = (Button) findViewById(C0194R.id.buttonBeat);
        this.buttonRetry = (Button) findViewById(C0194R.id.buttonRetry);
        this.buttonSave = (Button) findViewById(C0194R.id.buttonSave);
        this.spinnerDevice = (Spinner) findViewById(C0194R.id.spinnerDevice);
        this.spinnerStatus = (Spinner) findViewById(C0194R.id.spinnerStatus);
        this.textViewStatus = (TextView) findViewById(C0194R.id.textViewStatus);
        this.editTextUserName = (EditText) findViewById(C0194R.id.editTextUserName);
        this.spinnerDevice.setBackgroundColor(Color.parseColor("#EDEE91"));
        this.spinnerStatus.setBackgroundColor(Color.parseColor("#EDEE91"));
        this.editTextUserName.setBackgroundColor(Color.parseColor("#EDEE91"));
    }

    private void defineButtonBeat() {
        this.buttonBeat.setOnTouchListener(new C01891());
    }

    private void defineButtonSave() {
        this.buttonSave.setOnTouchListener(new C01902());
    }

    private void defineButtonRetry() {
        this.buttonRetry.setOnTouchListener(new C01913());
    }

    private void defineSpinnerStatus() {
        ArrayAdapter<CharSequence> arrayAdapterStatus = ArrayAdapter.createFromResource(this, C0194R.array.stringArrayStatus, 17367048);
        arrayAdapterStatus.setDropDownViewResource(17367049);
        this.spinnerStatus.setAdapter(arrayAdapterStatus);
        this.stringStatus = this.spinnerStatus.getSelectedItem().toString();
        this.spinnerStatus.setOnItemSelectedListener(new C01924());
    }

    private void defineSpinnerDevice() {
        ArrayAdapter<CharSequence> arrayAdapterDevices = ArrayAdapter.createFromResource(this, C0194R.array.stringArrayDevice, 17367048);
        arrayAdapterDevices.setDropDownViewResource(17367049);
        this.spinnerDevice.setAdapter(arrayAdapterDevices);
        this.stringDevice = this.spinnerDevice.getSelectedItem().toString();
        this.spinnerDevice.setOnItemSelectedListener(new C01935());
    }

    public String getCurrentEvent() {
        String currentEvent;
        String currentEventTime;
        Integer listEventsSize = Integer.valueOf(this.listEvents.size());
        Integer listEventTimeSize = Integer.valueOf(this.listEventTimes.size());
        if (listEventsSize.intValue() > 0) {
            currentEvent = (String) this.listEvents.get(listEventsSize.intValue() - 1);
        } else {
            currentEvent = " ";
        }
        if (listEventTimeSize.intValue() > 0) {
            currentEventTime = String.format("%.3f", new Object[]{this.listEventTimes.get(listEventTimeSize.intValue() - 1)});
        } else {
            currentEventTime = " ";
        }
        return currentEvent + " : " + currentEventTime;
    }

    public void updateTextViewStatus() {
        this.textViewStatus.setText(("Device: " + this.stringDevice + "   -   Status: " + this.stringStatus + "\nUserName: " + this.editTextUserName.getText().toString() + "   -   Finished Attempts: " + this.beatPinAttempt.toString() + "\n" + getCurrentEvent() + "\nPassword Length: " + this.currentPasswordLength).toString());
    }

    protected void onStart() {
        super.onStart();
        this.beatPinAttempt = Integer.valueOf(0);
        this.firstPasswordLength = Integer.valueOf(-1);
        clearBeatPin();
    }

    protected void onResume() {
        super.onResume();
        clearBeatPin();
        updateTextViewStatus();
    }

    protected void onPause() {
        super.onPause();
    }

    protected void onStop() {
        super.onStop();
        clearBeatPin();
    }

    protected void onDestroy() {
        super.onDestroy();
        closeOutput();
    }
}
