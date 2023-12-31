#include <WiFi.h>
#include <WiFiClient.h>

const char *ssid = "Red_Mi";
const char *password = "hstsv353WweST3F";
const char *esclavoIP = "192.168.4.2"; // Dirección IP del módulo esclavo en la red generada

void setup()
{
  Serial.begin(9600);
  WiFi.softAP(ssid, password);

  Serial.println("WiFi AP is running");
  Serial.print("Dirección IP del maestro: ");
  Serial.println(WiFi.softAPIP());
}

void loop()
{
  WiFiClient client;
  delay(3000);

  // Conectar con el módulo esclavo
  if (client.connect(esclavoIP, 9600))
  {
  conec:
    Serial.println("Conexión con el módulo esclavo establecida.");

    // Enviar un mensaje al módulo esclavo
    client.println("Hola desde el maestro");
    delay(1000);
    client.println("Mejore la logica");
    delay(1000);



    // Esperar una respuesta del esclavo (opcional)
     while (client.available() == 0);
     String respuesta = client.readStringUntil('\n');
     Serial.println("Respuesta" + respuesta);
    goto conec;
    client.stop(); // Cierra la conexión
  }
  else
  {
    Serial.println("No se pudo conectar con el módulo esclavo.");
  }

  delay(1000);
}
