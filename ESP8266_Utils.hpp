 void ConnectWiFi_STA(bool useStaticIP = false)
{
    Serial.println("Booting");
  
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    if(useStaticIP) WiFi.config(ip, gateway, subnet);
    
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.println("Connection Failed! Rebooting...");
      delay(5000);
      ESP.restart();
    }

    // Log the ESP8266 WiFi IP
    Serial.println("Ready ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

// Connecting as a Soft Access Point (SAP)

void ConnectWiFi_AP(bool useStaticIP = false)
{ 
  Serial.println("");
  WiFi.mode(WIFI_AP);
  while(!WiFi.softAP(ssid, password))
  {
    Serial.println(".");
    delay(100);
  }
  if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

  Serial.println("Ready ");
  Serial.print("Starting AP:\t");
  Serial.println(ssid);
  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());
}
