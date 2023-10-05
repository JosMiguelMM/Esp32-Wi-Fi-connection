#include <WiFi.h>

const char *ssid = "Red_Mi";
const char *password = "12345678";
const char *esclavoIP = "192.168.4.2";

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP(ssid, password);

  Serial.println("WiFi AP is running");
  Serial.print(WiFi.softAPIP());
}

void loop()
{
  WiFiClient client;

  // Conectar con el módulo esclavo
  if (client.connect(esclavoIP, 9600))
  {
    Serial.println("Conexión con el módulo esclavo establecida.");

    // Enviar un mensaje al módulo esclavo
    client.println("Hola desde el maestro");

    // // Esperar una respuesta del esclavo (opcional)
    // while (client.available() == 0);
    // String respuesta = client.readStringUntil('\n');
    // Serial.println("Respuesta del esclavo: " + respuesta);
    //client.stop(); // Cierra la conexión
  }
  else
  {
    Serial.println("No se pudo conectar con el módulo esclavo.");
  }
  delay(3000);
}
