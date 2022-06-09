#define VEL_MOT_DER 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define VEL_MOT_IZQ 11
#define IRD 4
#define IRI 5
#define DER true
#define IZQ false
#define DETECTO true
#define NO_DETECTO false
#define VEL 100

void setup() {
  Serial.begin(9600);
  pinMode(VEL_MOT_IZQ,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(VEL_MOT_DER,OUTPUT);
  pinMode(IRD, INPUT);
  pinMode(IRI, INPUT);
}

void avanzar(){
  analogWrite(VEL_MOT_IZQ,VEL);
  analogWrite(VEL_MOT_DER,VEL);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void retroceder(){
  analogWrite(VEL_MOT_IZQ,VEL);
  analogWrite(VEL_MOT_DER,VEL);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void girar_robot (bool sentido){
  if(sentido==IZQ){
    analogWrite(VEL_MOT_IZQ,0);
    analogWrite(VEL_MOT_DER,VEL);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
  }  
  else{  
    analogWrite(VEL_MOT_IZQ,VEL);
    analogWrite(VEL_MOT_DER,0);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);  
  }
}

void frenar(){
  analogWrite(VEL_MOT_DER,0);
  analogWrite(VEL_MOT_IZQ,0);
}

void loop(){
  bool lect_I = digitalRead(IRI);
  bool lect_D = digitalRead(IRD);
  if (!lect_D & !lect_I){
    avanzar();
  }
  else if (lect_D){
    girar_robot(IZQ);
  }
  else if (lect_I){
    girar_robot(DER);
  }
}
