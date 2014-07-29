#include <Servo.h> 
#define pinServoEntrada 10
#define pinBotonEntrada 11
#define pinBotonSalida 12
#define CAPACIDAD_MAXIMA 9
const byte digito[10]= { 
  B01111110,B00001100,B10110110,B10011110,B11001100,B11011010,B11111010,B10001110,B11111110,B11001110};  // A=1 B=2 C=3 D=4 E=5 F=6 G=7
int stock = CAPACIDAD_MAXIMA;
int estadoBotonEntrada;
int estadoBotonSalida;
Servo servoEntrada;

void setup() 
{ 
  DDRD=B11111110;
  mostrar(CAPACIDAD_MAXIMA);
  pinMode(pinBotonEntrada,OUTPUT);
  pinMode(pinBotonSalida,OUTPUT);
  servoEntrada.attach(pinServoEntrada);
  Serial.begin(9600);
  Serial.println(stock);
} 


void loop() 
{ 
  estadoBotonEntrada = digitalRead(pinBotonEntrada);
  estadoBotonSalida = digitalRead(pinBotonSalida);
  if(estadoBotonEntrada == HIGH && stock > 0){
    stock= (stock > 0)? stock-- : 0; 
    Serial.println(stock);
    mostrar(stock); 
    abrirEntrada();
  }
  else if(estadoBotonSalida == HIGH){
    stock= (stock < CAPACIDAD_MAXIMA)? stock++ : CAPACIDAD_MAXIMA; 
    Serial.println(stock);
    mostrar(stock);
    abrirEntrada();
  }

}

void mostrar(int numero){
  PORTD = digito[numero];
}

void abrirEntrada(){
  for(int pos = 100 ; pos>=10; pos--)  
  {                                
    servoEntrada.write(pos);           
    delay(15);                 
  } 
  delay(500);

  for(int pos = 10; pos < 100; pos ++) 
  {    
    servoEntrada.write(pos);
    delay(15);          
  } 
}






