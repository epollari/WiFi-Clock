/*
   This sketch dumps data received from a GPS receiver into Serial Monitor.
   For this to work, the MPU on the LinkIt Smart 7688 Duo must receive and 
   pipe the GPS datastream to /dev/ttyS0. This is achieved with following
   commands:

   gpsd -b -G -n /dev/ttyUSB0
   gpspipe -r -s /dev/ttyS0

   On a LinkIt Smart 7688 Duo lacking the GPS receiver, but connected to the
   GPS-equipped LinkIt -- the master clock -- over Wi-Fi, the following
   command is needed:

   gpspipe -r -s /dev/ttyS master.local

   Here, master.local is the zeroconf hostname of the master clock.
*/

void setup()
{
// The serial connections to the GPS receiver and Serial Monitor
   Serial1.begin(4800);
   Serial.begin(9600);

   Serial.println(F("GPS_Dump.ino"));
   Serial.println();
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (Serial1.available() > 0)
     Serial.write(Serial1.read());
}
