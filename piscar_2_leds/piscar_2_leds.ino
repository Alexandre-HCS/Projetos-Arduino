//Progama mucho loko que envia um sinal alto à saída 7, aguarda 5 segundos e manda um sinal baixo para a saída 7 daí repete :P
//Progama mucho loko que envia um sinal baixo à saída 8, aguarda 5 segundos e manda um sinal alto para a saída 8 daí repete :P
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  aqui o 7 tá alto e o 8 tá baixo
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  delay(5000);
  //  aqui o 8 tá alto e o 7 tá baixo
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(5000);
  
}
