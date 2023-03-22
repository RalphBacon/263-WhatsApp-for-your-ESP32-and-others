#include <HTTPClient.h>
#include <UrlEncode.h>
// Above URLEncode library by Masayuki Sugahara v 1.0.1

/*
    This is the simplest WhatsApp interface for testing in a browser (as well as from your sketch)
*/
namespace whatsApp {

// Change these values to your own!
String telephoneNumber = "07234098765";
String whatsappAPIKey = "abc1234";

void sendWhatsAppMsg() {
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + telephoneNumber + "&apikey=" + whatsappAPIKey + "&text=" + urlEncode("[Smart Htr Ctlr] Workshop power is ON.");

  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    log_d("WhatsApp message sent successfully");
  } else {
    log_w("Error sending WhatsApp message. HTTP response code: %d", httpResponseCode);
  }

  // Free resources
  http.end();
}

// This is a better way with the payload (the data) part of the body, but it's still not encrypted (secure) comms
void sendWhatsAppMsg2() {
  String url = "https://api.callmebot.com/whatsapp.php";

  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Send HTTP POST request
  String httpRequestPayLoad = "phone=" + telephoneNumber + "&apikey=" + whatsappAPIKey + "&text=" + urlEncode("[Smart Htr Ctlr] Workshop power is ON.");

  int httpResponseCode = http.POST(httpRequestPayLoad);
  if (httpResponseCode == 200) {
    log_d("WhatsApp message sent successfully");
  } else {
    log_w("Error sending WhatsApp message. HTTP response code: %d", httpResponseCode);
  }

  // Free resources
  http.end();
}
} // namespace WhatsApp

void setup() {
  // Try running the WhatsApp function from HERE not the loop.
  whatsApp::sendWhatsAppMsg();
}

void loop() {
}