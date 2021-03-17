#define Sensor_1 2  // Attaches Sensor 1 to Digital Pin 2 (These values can be changed if using different pins on different boards)
#define Sensor_2 3  // Attaches Sensor 2 to Digital Pin 3
long StartS1;   // time in microseconds Sensor 1 first sees light/laser
long StartS2;   // time in microseconds Sensor 2 first sees light/laser
long StopS1;    // time in microseconds that Sensor 1 stops seeing light/laser
long StopS2;    // time in microseconds that Sensor 2 stops seeing light/laser


void setup() {                                                  

  Serial.begin(9600);     //opens a serial connection.
  attachInterrupt(digitalPinToInterrupt(Sensor_1), Sensor1, CHANGE);  // Calls Sensor1 Function anytime Sensor 1 Pin detects change
  attachInterrupt(digitalPinToInterrupt(Sensor_2), Sensor2, CHANGE);  // Calls Sensor2 Function anytime Sensor 2 Pin detects change
}

void loop(){                                       
    // I kept this empty to leave processes free to grab sensor time changes as fast as possible
}
 
void Print(){    
  int s1i = 0;
  int s2i = 0;
  Serial.print("//========================\\");
  Serial.println();
  if(StartS1 != 0 && StopS1 !=0){
    Serial.print("S1 Start: ");
    Serial.println(StartS1);
    Serial.print("S1 Stop: ");
    Serial.println(StopS1);
    long SpeedS1 = (StopS1 - StartS1);      // make a variable called speed, which is the total number of microseconds that the shutter is open for
    Serial.print("Microseconds: ");
    Serial.println(SpeedS1);                // total legth in microseconds that shutter was open on that sensor
    float SSS1 = (float)SpeedS1/1000000;    // makes variable to convert microseconds to seconds
    float SS2S1 = 1/SSS1;                   // this divides the seconds by 1 to create a shutter speed that is more recognizable
    Serial.print("Sensor 1 Shutter Speed: 1/");
    Serial.println(SS2S1);                
    Serial.println();
  }
  else {
    s1i = 1;
    Serial.print("Sensor 1 Incomplete Data");
    Serial.println(StartS1);
    Serial.println(StopS1);
    Serial.println();
  }
  if(StartS2 != 0 && StopS2 != 0){
    Serial.print("S2 Start: ");
    Serial.println(StartS2);
    Serial.print("S2 Stop: ");
    Serial.println(StopS2);
    long SpeedS2 = (StopS2 - StartS2);      
    Serial.print("Microseconds: ");
    Serial.println(SpeedS2);               
    float SSS2 = (float)SpeedS2/1000000;    
    float SS2S2 = 1/SSS2;                   
    Serial.print("Sensor 2 Shutter Speed: 1/");
    Serial.println(SS2S2);                
    Serial.println();
  }
  else {
    s2i = 1;
    Serial.print("Sensor 2 Incomplete Data");
    Serial.println(StartS2);
    Serial.println(StopS2);
    Serial.println();
  }
  if(s1i == 1 || s2i == 1){
    Serial.print("Curtain Speeds were not calculated");
    Serial.println();
  }
  else {          // As long as both sensors received open and close data this will calculate Curtain speeds from Sensor 1 Open to Sensor 2 Open and Sensor 1 Close to Sensor 2 Close
    long Curtain1 = (StartS2 - StartS1);
    long Curtain2 = (StopS2 - StopS1);
    float C1 = (float)Curtain1/1000;
    float C2 = (float)Curtain2/1000;
    Serial.print("Opening Curtain Travel Time: ");
    Serial.print(C1);
    Serial.print(" ms");
    Serial.println();
    Serial.print("Closing Curtain Travel Time: ");
    Serial.print(C2);
    Serial.println(" ms");
    Serial.println();
  }
  Serial.print("//========================\\");
  DataReset();
} 

void Sensor1(){            // Interrupt functions for the Sensors to gather time info
  if(digitalRead(Sensor_1) == LOW){
    StartS1 = micros();
                    
  }
  if(digitalRead(Sensor_1) == HIGH){
    StopS1 = micros();        
    
  }
}

void Sensor2(){
  if(digitalRead(Sensor_2) == LOW) {
    StartS2 = micros();
    
  }
  if(digitalRead(Sensor_2) == HIGH) {  
    StopS2 = micros();
    Print();  // This Sends the program to calculate and print out the results
  }
}

void DataReset(){  // Resets our sensor data, mainly for error checking reasons
  StartS1 = 0;
  StartS2 = 0;
  StopS1 = 0;
  StopS2 = 0;
}
