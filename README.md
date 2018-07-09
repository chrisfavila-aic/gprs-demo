# gprs-demo
This sketch demonstrates accessing the [Thingspeak](https://www.thingspeak.com) API
via an Arduino Uno with an Elecrow GSM/GPRS v1.0 shield and a Smart sim card.
This is based mostly on the reference code provided by [Elecrow](https://www.elecrow.com/wiki/index.php?title=GPRS/GSM_Shield_v1.0).

# How it Works:
0. Input your Thingspeak Write API key into the sketch and upload to the Uno with the GSM/GPRS shield unattached. Disconnect the USB and stack the GPRS shield into the Uno.
1. Connect the Uno with shield and sim via USB.
2. Turn on the GPRS shield and wait around 10 seconds so the sim can initialize.
3. Open a serial connection w/ baud rate set at 19200.
4. Press "h". Serial terminal should show the status of the HTTP request. This can take up to 20 seconds.
5. If all goes well,  a new point should appear in the Thingspeak chart.
