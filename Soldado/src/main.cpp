#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "Red_Mi";
const char* password = "12345678";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
  }
  Serial.println("Conectado a la red Wi-Fi");
  Serial.print("Dirección IP del esclavo: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiServer server(9600); // Crea un servidor en el puerto 9600
  server.begin();

  WiFiClient client = server.available();
  if (client) {
    Serial.println("Cliente conectado");

    while (client.connected()) {
      if (client.available()) {
        String mensaje = client.readStringUntil('\n');
        Serial.println("Mensaje recibido del maestro: " + mensaje);

        // Aquí puedes realizar alguna acción en respuesta al mensaje recibido

        // Envía una respuesta al maestro (opcional)
        client.println("Respuesta desde el esclavo");
      }
    }

    client.stop();
    Serial.println("Cliente desconectado");
  }
}