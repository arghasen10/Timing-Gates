#define IR A5
#define button 9
int previousVal = 0;

int currentVal;
int flag1=0;
int flag2=0;
int starttime;
int reactiontime;
void setup() {
Serial.begin(9600);
pinMode(IR,INPUT);
 pinMode(button,INPUT);
}

void loop() {
  if(digitalRead(button)==HIGH && flag1==0){
    starttime=millis();
    //Send data to server
    flag1=1;
    Serial.print(starttime+1137);
  }
 
  currentVal=analogRead(IR);
  if(currentVal>950 && previousVal<currentVal ){
    
    previousVal=currentVal;
    if(previousVal>960 && flag2==0){
      reactiontime = millis();
      //Send data to the server
      previousVal=0;
   
  } }

}

