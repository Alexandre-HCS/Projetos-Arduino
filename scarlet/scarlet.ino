//Progama mucho loko que envia um sinal alto à saída 7, aguarda 5 segundos e manda um sinal baixo para a saída 7 daí repete :P
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  aqui o 7 tá alto
  digitalWrite(7,HIGH);
  delay(5000);
  //  aqui o 7 tá baixo
  digitalWrite(7,LOW);
  delay(5000);
  
}
