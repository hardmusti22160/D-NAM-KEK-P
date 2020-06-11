#include <SoftwareSerial.h>
SoftwareSerial KGSerial(11,10);
SoftwareSerial BTSerial(8,9);


void setup() {
  BTSerial.begin(9600);
  KGSerial.begin(9600);
  Serial.begin(9600);
  
}

void loop() {

  BTSerial.print(receive_message());
  Serial.print(receive_message());
  

   

 
 

}

String receive_message(){
  char incoming_char;
  int max_size = 64;                                                        //size of serial buffer on UNO
  String message_string = "";
  
 
 
  if( KGSerial.available() )
  {
    incoming_char = KGSerial.read();
    if( incoming_char == 61 )
    {
      message_string += incoming_char;
      delay(40);                                                               //Not sure why I need this, but it needs to be at least 5ms, as per experimentation
      while( message_string.length() <= 11 )                            //end the while loop if the "end of text" char is read or buffer maximum is reached
      {
        incoming_char = KGSerial.read();
        if( incoming_char == 03 ){
        message_string += incoming_char;
        break;
        }
        else
        {
          message_string += incoming_char;
        }
      }
    }
  }
  return message_string;
}
