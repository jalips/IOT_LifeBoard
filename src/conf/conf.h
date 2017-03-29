


/*********************************************************************

Configuration file

Use to list all necessary variables

*********************************************************************/

// Global
int firstLaunch = 1;
int firstLaunch_sensor = 1;

const int buttonPin = PUSH2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

/**** CONF MQTT *****/
#define MQTTCLIENT_QOS2 1

char hostname[] = "10.3.5.66";
//char hostname[] = "192.168.1.32";
int port = 1883;

char printbuf[100];
int arrivedcount = 0;

int cpt_button = 0;

// Define variables and constants
char wifi_name[] = "arpanet";
char wifi_password[] = "sarahConnor";

String html_ssid = "";
String html_password = "";

WiFiServer myServer(80);
uint8_t oldCountClients = 0;
uint8_t countClients = 0;

String wifi_file_name = "/storage/wifi.txt";

//Adafruit_TMP006 tmp006;
Adafruit_TMP006 tmp006(0x41);

WifiIPStack ipstack;
MQTT::Client<WifiIPStack, Countdown> client = MQTT::Client<WifiIPStack, Countdown>(ipstack);

const char* topic = "/julien";

/************ API CONF ***************/
// server address:
char server_api[] = "10.3.3.75";
int port_api = 80;
// Initialize the Wifi client library
WiFiClient wifi;
HttpClient client_api = HttpClient(wifi, server_api, port_api);
int status = WL_IDLE_STATUS;
String response;
int statusCode = 0;
