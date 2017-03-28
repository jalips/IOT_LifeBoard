/*********************
Function from HelloWifi (MQTT) - energia
**********************/
void connect() {
  sprintf(printbuf, "Connecting to %s:%d\n", hostname, port);
  Serial.print(printbuf);
  int rc = ipstack.connect(hostname, port);
  if (rc != 1)
  {
    sprintf(printbuf, "rc from TCP connect is %d\n", rc);
    Serial.print(printbuf);
  }

  Serial.println("MQTT connecting");
  MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
  data.MQTTVersion = 3;
  data.clientID.cstring = (char*)"julien";
  rc = client.connect(data);
  if (rc != 0)
  {
    sprintf(printbuf, "rc from MQTT connect is %d\n", rc);
    Serial.print(printbuf);
  }
  Serial.println("MQTT connected");
}


/*********************
Send Message to MQTT Brocker
**********************/
void sendMQTTMessage(float text_message, const char* topic){

    Serial.print("FUNCTION Temperature: "); Serial.print(text_message);

    if (!client.isConnected()){
        connect();
    }

    MQTT::Message message;

    // Send and receive QoS 0 message
    char buf[50];
    sprintf(buf, "%f", (float)text_message);

    //char buf[500];
    //sprintf(buf, "%f", text_message);

    Serial.print(buf);

    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;
    message.payload = (void*)buf;
    message.payloadlen = strlen(buf)+1;
    int rc = client.publish(topic, message);
    if (rc != 0) {
        Serial.print("Message publish failed with return code : ");
        Serial.println(rc);
    }else{
        Serial.print("Message send");
    }
}

/*********************
Function from HelloWifi (MQTT) - energia
**********************/
void connect() {
  sprintf(printbuf, "Connecting to %s:%d\n", hostname, port);
  Serial.print(printbuf);
  int rc = ipstack.connect(hostname, port);
  if (rc != 1)
  {
    sprintf(printbuf, "rc from TCP connect is %d\n", rc);
    Serial.print(printbuf);
  }

  Serial.println("MQTT connecting");
  MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
  data.MQTTVersion = 3;
  data.clientID.cstring = (char*)"julien";
  rc = client.connect(data);
  if (rc != 0)
  {
    sprintf(printbuf, "rc from MQTT connect is %d\n", rc);
    Serial.print(printbuf);
  }
  Serial.println("MQTT connected");
}

/*********************
Send Message to MQTT Brocker
**********************/
void sendMQTTMessage(float text_message){

    Serial.print("FUNCTION Temperature: "); Serial.println(text_message);

    if (!client.isConnected()){
        connect();
    }

    MQTT::Message message;

    // Send and receive QoS 0 message
    char buf[50];
    sprintf(buf, "%d", (int)text_message);

    Serial.println(buf);

    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;

    // V1
    message.payload = (void*)buf;
    message.payloadlen = strlen(buf)+1;

    int rc = client.publish(topic, message);
    if (rc != 0) {
        Serial.println("Message publish failed with return code : ");
        Serial.println(rc);
    }else{
        Serial.println("Message send");
    }
}
