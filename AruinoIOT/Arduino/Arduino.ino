
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "fir-36be1-default-rtdb.firebaseio.com"                       
#define FIREBASE_AUTH "C2bT2IDmaqhQusT6qcGEP2xAt30EMoFTpkLDs9tY"                    
#define WIFI_SSID ""                                         
#define WIFI_PASSWORD ""    


  
                                                           
 
String fireStatus = "";    

String fireStatus1 = "";  

String fireStatus2 = "";

String fireStatus3 = "";    
int led = D1; 
int led1 = D2; 
int led2 = D3; 
int led3 = D5; 
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(200000);
  pinMode(LED_BUILTIN, OUTPUT);      
  pinMode(led, OUTPUT);  
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);     
  pinMode(led3, OUTPUT);           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                                    
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                                     
  Firebase.setString("Led1Status", "OFF"); 
  Firebase.setString("Led2Status", "OFF");
  Firebase.setString("Led3Status", "OFF"); 
  Firebase.setString("Led4Status", "OFF"); 
  
}
void loop() {
  fireStatus = Firebase.getString("Led1Status/status");                                  
  if (fireStatus == "ON") {                                                          
    Serial.println("Led 1 Turned ON");                         
    digitalWrite(LED_BUILTIN, LOW);                                                  
    digitalWrite(led, HIGH);  
    delay(10);
  } 
  else {                                               
    Serial.println("Led 1 Turned OFF");
    digitalWrite(LED_BUILTIN, HIGH);                                               
    digitalWrite(led, LOW);                                                        
  }



    fireStatus1 = Firebase.getString("Led2Status/status");                                   
  if (fireStatus1 == "ON") {                                                         
    Serial.println("Led 2 Turned ON");                         
    digitalWrite(LED_BUILTIN, LOW);                                                 
    digitalWrite(led1, HIGH);  
    delay(10);
  } 
  else {                                                  
    Serial.println("Led 2 Turned OFF");
    digitalWrite(LED_BUILTIN, HIGH);                                               
    digitalWrite(led1, LOW);                                                        
  }



   fireStatus2 = Firebase.getString("Led3Status/status");                                     
  if (fireStatus2 == "ON") {                                                      
    Serial.println("Led 3 Turned ON");                         
    digitalWrite(LED_BUILTIN, LOW);                                               
    digitalWrite(led2, HIGH);  
    delay(10);
  } 
  else {                                                 
    Serial.println("Led 3 Turned OFF");
    digitalWrite(LED_BUILTIN, HIGH);                                              
    digitalWrite(led2, LOW);                                                        
  }


     fireStatus3 = Firebase.getString("Led4Status/status");                                   
  if (fireStatus3 == "ON") {                                                         
    Serial.println("Led 4 Turned ON");                         
    digitalWrite(LED_BUILTIN, LOW);                                                  
    digitalWrite(led3, HIGH);  
    delay(10);
  } 
  else {                                                
    Serial.println("Led 4 Turned OFF");
    digitalWrite(LED_BUILTIN, HIGH);                                               
    digitalWrite(led3, LOW);                                                       
  }
int  randNumber = random(300);
  Firebase.setInt("RandStatus",randNumber); 
  Serial.println(randNumber);

  
  

  delay(50);

}
