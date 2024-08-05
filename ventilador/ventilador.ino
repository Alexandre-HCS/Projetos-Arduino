int motor=5;
int valor;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  valor=analogRead (A0)/4;
  analogWrite(motor,valor);
  
  Serial.print("Motor en movimiento");
  Serial.println(valor);
}
