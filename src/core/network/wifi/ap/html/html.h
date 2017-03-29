/*********************************************************************

Html web page

Use to display html page

*********************************************************************/

/*********************
Display HTML form
**********************/
void displayHtmlForm(WiFiClient myClient){
    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
    // and a content-type so the client knows what's coming, then a blank line:
    myClient.println("HTTP/1.1 200 OK");
    myClient.println("Content-type:text/html");
    myClient.println();

    // the content of the HTTP response follows the header:
    myClient.println("<html><head><title>Energia CC3200 WiFi Web-Server in AP Mode</title></head><body align=center>");
    myClient.println("<h1 align=center><font color=\"green\">LaunchPad CC3200 WiFi Web-Server in AP Mode</font></h1>");
    myClient.print("<form method='get'>");
    myClient.print("SSID :");
    myClient.print("<input type='text' name='ssid' value='Houat'>");
    myClient.println("<br>");
    myClient.print("Key :");
    myClient.print("<input type='text' name='key' value='Houat_WPA2!'>");
    myClient.println("<br>");
    myClient.print("<input type='submit' name='Submit'>");
    myClient.print("</form>");
}
