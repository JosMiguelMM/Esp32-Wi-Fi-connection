#include <WiFi.h>
#include <WiFiClient.h>

const char *ssid = "Red_Mi";
const char *password = "12345678";
WiFiServer server(9600);

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
  }
  Serial.println("Conectado a la red Wi-Fi");
  Serial.print("Dirección IP del esclavo: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop()
{
  WiFiClient client = server.available();
  Serial.println("Esperando cliente..." + client);
  delay(2000);
  if (client)
  {
    Serial.println("Cliente conectado");
  regreso:
    while (client.connected())
    {
      if (client.available())
      {
        String mensaje = client.readStringUntil('\n');
        Serial.println("Mensaje recibido del maestro: " + mensaje);

        // Aquí puedes realizar alguna acción en respuesta al mensaje recibido

        // Envía una respuesta al maestro (opcional)
        // client.println("Respuesta desde el esclavo");
      }
    }
    goto regreso;
    client.stop();
    Serial.println("Cliente desconectado");
  }
  else
  {
    Serial.println("No se ha establecido coneccion");
  }
}
