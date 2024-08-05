//Progama mucho loko que envia um sinal alto à saída 7, aguarda 5 segundos e manda um sinal baixo para a saída 7 daí repete :P
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7,HIGH);
  delay(5000);
  digitalWrite(7,LOW);
  delay(5000);
  
}
