#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522

void setup() {
  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Control de acceso:");
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte herramienta1[4]= {0xE0, 0x62, 0x92, 0xDE} ; //código de la herramienta A1
byte herramienta2[4]= {0xE0, 0xAA, 0x94, 0xDE} ; //código de la herramienta A2
byte herramienta3[4]= {0xD0, 0x64, 0xA3, 0xDE} ; //código de la herramienta A3
byte herramienta4[4]= {0x50, 0x4C, 0x9C, 0xDE} ; //código de la herramienta A4
byte herramienta5[4]= {0x4A, 0xC0, 0x6E, 0xCB} ; //código de la herramienta A5
byte herramienta6[4]= {0xF0, 0xA9, 0x99, 0xDE} ; //código de la herramienta A6
byte herramienta7[4]= {0x30, 0xB9, 0x97, 0xDE} ; //código de la herramienta A7
byte herramienta8[4]= {0xDA, 0xF5, 0x67, 0xCB} ; //código de la herramienta A8
byte herramienta9[4]= {0xC1, 0x2F, 0xD6, 0x0E} ; //código de la herramienta A9
byte herramienta10[4]= {0xC1, 0x2F, 0xD6, 0x0E} ; //código de la herramienta A10
byte tarjeta[4]= {0x73, 0xC8, 0x62, 0x02} ; //código de la tarjeta
byte tag[4]= {0xC2, 0x7C, 0x92, 0x6F} ; //código del tag

void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print(F("Card UID:"));
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  } 
                  Serial.print("     ");                 
                  //comparamos los UID para determinar si es uno de nuestras herramientas  
                  if(compareArray(ActualUID,herramienta1))
                    datos_herramienta1();
                  else if(compareArray(ActualUID,herramienta2))
                    datos_herramienta2();
                  else if(compareArray(ActualUID,herramienta3))
                    datos_herramienta3(); 
                  else if(compareArray(ActualUID,herramienta4))
                    datos_herramienta4(); 
                  else if(compareArray(ActualUID,herramienta5))
                    datos_herramienta5();
                  else if(compareArray(ActualUID,herramienta6))
                    datos_herramienta6();
                  else if(compareArray(ActualUID,herramienta7))
                    datos_herramienta7();
                  else if(compareArray(ActualUID,herramienta8))
                    datos_herramienta8();
                  else if(compareArray(ActualUID,herramienta9))
                    datos_herramienta9();
                  else if(compareArray(ActualUID,herramienta10))
                    datos_herramienta10();
                  else if(compareArray(ActualUID,tarjeta))
                    datos_tarjeta();
                  else if(compareArray(ActualUID,tag))
                    datos_tag();             
                  else
                    Serial.println("ERROR");
                  
                  // Terminamos la lectura de la tarjeta tarjeta  actual
                  mfrc522.PICC_HaltA();
          
            }
      
  }
}
  
//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}

void datos_herramienta1(){
  Serial.println("Herramienta A1 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta2(){
  Serial.println("Herramienta A2 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta3(){
  Serial.println("Herramienta A3 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta4(){
  Serial.println("Herramienta A4 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta5(){
  Serial.println("Herramienta A5 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta6(){
  Serial.println("Herramienta A6 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta7(){
  Serial.println("Herramienta A7 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta8(){
  Serial.println("Herramienta A8 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta9(){
  Serial.println("Herramienta A9 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_herramienta10(){
  Serial.println("Herramienta A10 validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_tarjeta(){
  Serial.println("Tarjeta validada");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}

void datos_tag(){
  Serial.println("Tag validado");
  delay(1);        // retardo entre lecturas para estabilidad
  Serial.println("Dimensiones: 3x4x5");
  delay(1);        // retardo entre lecturas para estabilidad
}
