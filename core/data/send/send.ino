/*********************************************************************

Main send

Use to manage all data before they be send by network

*********************************************************************/


/*********************
Loop to send data
**********************/
int modeSendData(){
    // Blink Red Led
    digitalWrite(RED_LED, HIGH);
    delay(300);
    digitalWrite(RED_LED, LOW);
    delay(300);

    if(firstLaunch_sensor){
        // Only for setup
        firstLaunch_sensor = 0;

        Serial.println("Ok ready to send data.");

        if (! tmp006.begin()) {
            Serial.println("No sensor found");
            while (1);
        }

        // Check for sleep/wake command.
        while (Serial.available() > 0) {
            char c = Serial.read();
            if (c == 'w') {
                Serial.println("Waking up!");
                tmp006.wake();
            }
            else if (c == 's') {
                Serial.println("Going to sleep!");
                tmp006.sleep();
            }
        }
    }

    // Grab temperature measurements and print them.
    float objt = tmp006.readObjTempC();
    Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
    float diet = tmp006.readDieTempC();
    Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C");

    sendMQTTMessage(diet);

    delay(4000); // 4 seconds per reading for 16 samples per reading

    // Try to register (API Call)
    //httpRequest();

    return 1;
}
