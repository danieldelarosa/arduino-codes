#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Se crea el objeto para el RC522

void setup() {
  Serial.begin(9600); //Se inicia la comunicación  serial
  SPI.begin();        //Se iniciael Bus SPI
  mfrc522.PCD_Init(); // Se inicia  el MFRC522
  Serial.println("Escritura del UID");
}

void loop() {
  // Se revisa si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Se selecciona una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Se envia serialemente su UID
                  Serial.print("Card UID:");
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                  } 
                  Serial.println();
                  // Se finaliza la lectura de la tarjeta  actual
                  mfrc522.PICC_HaltA();         
            }      
  } 
}
