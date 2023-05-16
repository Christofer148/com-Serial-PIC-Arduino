/*
Serial:
rx = 0
tx = 1

Serial1:
rx1 = 19
tx1 = 18

https://www.arduino.cc/reference/en/language/functions/communication/serial/
*/

int dato = 0;

void setup()
{
  Serial1.begin(9600);                // inicializamos Serial1 con los mismos baudios que el PIC
  Serial.begin(9600);                 // inicializamos Serial que es la comunicacion con la computadora
  pinMode(LED_BUILTIN, OUTPUT);
  while (!Serial1) {                  // esperamos a que inicie el serial1
    
  }
  while(!Serial){                     // esperamos a que inicie el serial0
    
  }
}

void loop() 
{
  if(Serial1.available() > 0){        // esperamos a que haya un dato disponible
    digitalWrite(LED_BUILTIN, HIGH);  // encendemos el led
    dato = Serial1.read();            // leemos el dato
    Serial.println(dato);             // lo imprimimos en el monitor serie
  }

  digitalWrite(LED_BUILTIN, LOW);     // apagamos el led
}
