/*********************
Button
**********************/
void button(){
    Serial.println("You can delete file, push button2!");
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
        // turn LED on:
        digitalWrite(RED_LED, HIGH);

        if(cpt_button > 1){
            Serial.println("REBOOOoooOOOoooOOOOT");
            deleteFile();
        }

        cpt_button++;
    }
}
