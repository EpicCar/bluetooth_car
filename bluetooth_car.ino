//www.elegoo.com
//2016.09.12

int LED=13;
volatile int state = LOW;
char getstr;
int in1=9;
int in2=8;
int in3=7;
int in4=6;
int ENA=11;
int ENB=5;
int ABR=50;
int ABS=100;
int ABT=150;
int ABU=200;
int wheelAlignment=25;

void _mRocket()
{
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}
void _mForward()
{
  analogWrite(ENA,ABS + wheelAlignment);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}
void _mBack()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}
void _mleft()
{
  analogWrite(ENA,ABT);
  analogWrite(ENB,ABT);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go left!");
}
void _mright()
{
  analogWrite(ENA,ABT);
  analogWrite(ENB,ABT);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go right!");
}

void _mFRight()
{
  analogWrite(ENA,ABR + wheelAlignment);
  analogWrite(ENB,ABU);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward, right!");
}

void _mFLeft()
{
  analogWrite(ENA,ABU + wheelAlignment);
  analogWrite(ENB,ABR);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward, right!");
}


void _mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop!");
}
void stateChange()
{
  state = !state;
  digitalWrite(LED, state);
}


void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
}
void loop()
  {
  getstr=Serial.read();
 if(getstr=='f')
  {
      _mForward();
  }
  else if(getstr=='b')
  {
    _mBack();
    delay(200);
  }
  else if(getstr=='l')
  {
    _mleft();
    delay(200);
  }
  else if(getstr=='r')
  {
    _mright();
    delay(200);
  }

   else if(getstr=='g')
  {
    _mFRight();
    delay(200);
  }
   else if(getstr=='h')
  {
    _mFLeft();
    delay(200);
  }
     else if(getstr=='i')
  {
    _mRocket();
    delay(200);
  }
  else if(getstr=='s')
  {
     _mStop();
  }
  else if(getstr=='A')
  {
  stateChange();
  }
}

