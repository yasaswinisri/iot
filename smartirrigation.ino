const int moisensor=6;
int r=7;
int s=8;

void setup() {
  pinMode(moisensor,INPUT);
  pinMode(r,OUTPUT);
  pinMode(s,INPUT);
  Serial.begin(9600);
}

void loop() 
{
    mois();  
}

void mois()
{
  int m=digitalRead(moisensor);
  int n=digitalRead(s);
  if(m==HIGH||n==1)
  {
    Serial.println("1");
    digitalWrite(r,HIGH);
    delay(1000);
  }
  else
  {
    Serial.println("2");
    digitalWrite(r,LOW );
    delay(1000);
  }
    delay(500);
}
