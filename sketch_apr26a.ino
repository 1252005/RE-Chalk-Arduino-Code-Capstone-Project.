
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

int whiteMin = -10;
int whiteMax = 150;

int colordeg = 0;

int whiteValue;

void setup() {
 
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}

void loop() {
  colordeg = getcolordeg();
  whiteValue = map(colordeg, whiteMin, whiteMax, 255, 0);
   
  Serial.print(" - White = ");
  Serial.println(whiteValue);
if (whiteValue >= 146) { pinMode(13,LOW);
  Serial.println("Add less gypsum");}
  else if (whiteValue >= 140 ){  pinMode(13,LOW);
  Serial.println("Add more coal");}
else if (whiteValue <= 99){ pinMode(13,LOW);
   Serial.println("Add more gypsum");}
   else if (whiteValue >= 152){ pinMode(13,LOW);
   Serial.println("Increase gypsum and coal concentration");}
  delay(5000);
}

int getcolordeg() {
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);

  int deg;
  deg = pulseIn(sensorOut,LOW);
  return deg;
}
