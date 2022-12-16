
int sensora = 2; 
int sensorb = 3;
int saida_pwm = 5;

int a = 0;
int b = 0;

volatile int pos = 0;
bool cc = false;

void setup(){
    Serial.begin(115200);
    pinMode(sensora, INPUT);
    pinMode(sensorb, INPUT);

    pinMode(saida_pwm, OUTPUT);
}

void loop (){
  
  while(digitalRead(sensora)){
    b = digitalRead(sensorb);
  }
  
  while(!digitalRead(sensora)){
    
    if((digitalRead(sensorb) == 0) && b == 1){
      cc = true;
    }else if ((digitalRead(sensorb) == 1) && b == 0){
      cc = false;
    }
  }

  if (cc == true){
    if (pos == 357){
      pos = 0;
    }else{
      pos += 3;
    }
  } else {
    if (pos == 0 ){
      pos = 357;
    }else{
      pos -= 3;
    }
  }

  Serial.println();
  Serial.print(pos);
  if ( cc == false){
    Serial.print(" CW");    
  } else{
    Serial.print(" CCW ");
  } 
}
