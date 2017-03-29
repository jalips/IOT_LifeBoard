/**
 * Created by Blaise Cador
 * Configuration station mode
 * SETUP
 */

 void setStationMode(){
     //getTemp();
 }

 /*********************
 Function from ConnectWithWPA (wifi) - energia
 **********************/
 void printCurrentNet() {
   // print the SSID of the network you're attached to:
   Serial.print("SSID: ");
   Serial.println(WiFi.SSID());

   // print the MAC address of the router you're attached to:
   byte bssid[6];
   WiFi.BSSID(bssid);
   Serial.print("BSSID: ");
   Serial.print(bssid[5], HEX);
   Serial.print(":");
   Serial.print(bssid[4], HEX);
   Serial.print(":");
   Serial.print(bssid[3], HEX);
   Serial.print(":");
   Serial.print(bssid[2], HEX);
   Serial.print(":");
   Serial.print(bssid[1], HEX);
   Serial.print(":");
   Serial.println(bssid[0], HEX);

   // print the received signal strength:
   long rssi = WiFi.RSSI();
   Serial.print("signal strength (RSSI):");
   Serial.println(rssi);

   // print the encryption type:
   byte encryption = WiFi.encryptionType();
   Serial.print("Encryption Type:");
   Serial.println(encryption, HEX);
   Serial.println();
 }

 /*********************
 Function from ConnectWithWPA (wifi) - energia
 **********************/
 void printWifiData() {
   // print your WiFi IP address:
   IPAddress ip = WiFi.localIP();
   Serial.print("IP Address: ");
   Serial.println(ip);
   Serial.println(ip);

   // print your MAC address:
   byte mac[6];
   WiFi.macAddress(mac);
   Serial.print("MAC address: ");
   Serial.print(mac[5], HEX);
   Serial.print(":");
   Serial.print(mac[4], HEX);
   Serial.print(":");
   Serial.print(mac[3], HEX);
   Serial.print(":");
   Serial.print(mac[2], HEX);
   Serial.print(":");
   Serial.print(mac[1], HEX);
   Serial.print(":");
   Serial.println(mac[0], HEX);

 }

void initStationMode(String wifiConf) {

    // get indexof & symbol in wifi config string from wifi config file
    int index = wifiConf.indexOf("&");

    // Split string and attribute values to ssid and password strings
    String station_ssid_str = wifiConf.substring(0, index);
    String station_password_str = wifiConf.substring(index + 1);
    station_password_str.replace("%21", "!");

    // get size of ssid and password strings
    int size_station_ssid_str = sizeof(station_ssid_str) + 1;
    int size_station_password_str = sizeof(station_password_str) + 1 ;

    // initialize char arrays for ssid and password
    char station_ssid[size_station_ssid_str];
    char station_password[size_station_password_str];

    // put string values of ssid and password into char arrays
    strcpy(station_ssid, station_ssid_str.c_str());
    strcpy(station_password, station_password_str.c_str());

    // print ssid and password
    Serial.println(station_ssid);
    Serial.println(station_password);

    Serial.print("Attempting to connect to Network named: ");
    // print the network name (SSID);
    Serial.println(station_ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(station_ssid, station_password);
    while ( WiFi.status() != WL_CONNECTED) {
        // print dots while we wait to connect
        Serial.print(".");
        delay(300);
    }
    Serial.println("\nYou're connected to the network");
    Serial.println("Waiting for an ip address");

    while (WiFi.localIP() == INADDR_NONE) {
        // print dots while we wait for an ip addresss
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nIP Address obtained");
}

/*********************
Wifi running in Station Mode
**********************/
int modeStation(){
    // Led On
    digitalWrite(YELLOW_LED, HIGH);

    // Convert String to char[]
    int html_length = html_ssid.length()+1;
    int password_length = html_password.length()+1;
    char ssid[html_length];
    char password[password_length];
    html_ssid.toCharArray(ssid, html_length);
    html_password.toCharArray(password, password_length);

    // Println to know where we are
    Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    Serial.println("        Start station mode");
    Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    Serial.print("Attempting to connect to Network named: ");
    // print the network name (SSID);
    Serial.println(ssid);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, password);
    while ( WiFi.status() != WL_CONNECTED) {
        // print dots while we wait to connect
        Serial.print(".");
        delay(300);

        // Look for a possible Reboot
        button();
        delay(300);
    }

    Serial.println("\nYou're connected to the network");
    Serial.println("Waiting for an ip address");

    while (WiFi.localIP() == INADDR_NONE) {
        // print dots while we wait for an ip addresss
        Serial.print(".");
        delay(300);
    }

    Serial.println("\nIP Address obtained");

    // you're connected now, so print out the status
    printCurrentNet();
    printWifiData();
}
