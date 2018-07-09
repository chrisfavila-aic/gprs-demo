/* This sketch demonstrates accessing the Thingspeak API
* via an Arduino Uno with an Elecrow GSM/GPRS v1.0 shield and a Smart sim card.
* Code is based mostly on the reference code found in 
* https://www.elecrow.com/wiki/index.php?title=GPRS/GSM_Shield_v1.0
* 
* 
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8);

//Input your Thingspeak Write API Key here:
String api_key="";

void setup()
{
  mySerial.begin(19200);
  Serial.begin(19200);
  delay(500);
}

void loop()
{

  if (Serial.available())
    switch (Serial.read()) {

      case 'h':
        SubmitHttpRequest();
        break;
    }

  if (mySerial.available())
    Serial.write(mySerial.read());
}

///SubmitHttpRequest()
///this function is submit a http request
///attention:the time of delay is very important, it must be set enough
void SubmitHttpRequest()
{
  mySerial.println("AT+CSQ");
  delay(100);

  ShowSerialData();// this code is to show the data from gprs shield, in order to easily see the process of how the gprs shield submit a http request, and the following is for this purpose too.

  mySerial.println("AT+CGATT=1");
  delay(100);

  ShowSerialData();

  mySerial.println("AT+CGATT?");
  delay(100);

  ShowSerialData();


  mySerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");//setting the SAPBR, the connection type is using gprs
  delay(1000);

  ShowSerialData();

  mySerial.println("AT+SAPBR=3,1,\"APN\",\"internet\"");//setting the APN, the second need you fill in your local apn server
  delay(4000);

  ShowSerialData();

  mySerial.println("AT+SAPBR=1,1");//setting the SAPBR, for detail you can refer to the AT command mamual
  delay(2000);

  ShowSerialData();

  mySerial.println("AT+HTTPINIT"); //init the HTTP request

  delay(2000);
  ShowSerialData();

  mySerial.println("AT+HTTPPARA=\"URL\",\"api.thingspeak.com/update?api_key="+api_key+"&field1=0\"");// setting the httppara, the second parameter is a Thingspeak API endpoint where we update a field with a reading
  delay(1000);

  ShowSerialData();

  mySerial.println("AT+HTTPACTION=0");//submit the request
  delay(10000);//the delay is very important, the delay time is base on the return from the website, if the return datas are very large, the time required longer.
  //while(!mySerial.available());

  ShowSerialData();

  mySerial.println("AT+HTTPREAD");// read the data from the website you access
  delay(300);

  ShowSerialData();

  mySerial.println("");
  delay(100);
}

void ShowSerialData()
{
  while (mySerial.available() != 0)
    Serial.write(mySerial.read());
}
