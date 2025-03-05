#include <WiFi.h>  
#include <esp_camera.h>  
#include <UniversalTelegramBot.h>  

// Wi-Fi credentials  
const char* ssid = "YOUR_WIFI_SSID";  
const char* password = "YOUR_WIFI_PASSWORD";  

// Telegram Bot credentials  
#define BOT_TOKEN "YOUR_BOT_TOKEN"  
#define CHAT_ID "YOUR_CHAT_ID"  

// Pins  
#define PIR_PIN 12  
#define BUZZER_PIN 13  

WiFiClient client;  
UniversalTelegramBot bot(BOT_TOKEN, client);  

void setup() {  
  Serial.begin(115200);  
  pinMode(PIR_PIN, INPUT);  
  pinMode(BUZZER_PIN, OUTPUT);  

  // Initialize camera  
  camera_config_t config;  
  config.ledc_channel = LEDC_CHANNEL_0;  
  config.ledc_timer = LEDC_TIMER_0;  
  config.pin_d0 = Y2_GPIO_NUM;  
  config.pin_d1 = Y3_GPIO_NUM;  
  config.pin_d2 = Y4_GPIO_NUM;  
  config.pin_d3 = Y5_GPIO_NUM;  
  config.pin_d4 = Y6_GPIO_NUM;  
  config.pin_d5 = Y7_GPIO_NUM;  
  config.pin_d6 = Y8_GPIO_NUM;  
  config.pin_d7 = Y9_GPIO_NUM;  
  config.pin_xclk = XCLK_GPIO_NUM;  
  config.pin_pclk = PCLK_GPIO_NUM;  
  config.pin_vsync = VSYNC_GPIO_NUM;  
  config.pin_href = HREF_GPIO_NUM;  
  config.pin_sscb_sda = SIOD_GPIO_NUM;  
  config.pin_sscb_scl = SIOC_GPIO_NUM;  
  config.pin_pwdn = PWDN_GPIO_NUM;  
  config.pin_reset = RESET_GPIO_NUM;  
  config.xclk_freq_hz = 20000000;  
  config.pixel_format = PIXFORMAT_JPEG;  

  if (psramFound()) {  
    config.frame_size = FRAMESIZE_UXGA;  
    config.jpeg_quality = 10;  
  } else {  
    config.frame_size = FRAMESIZE_SVGA;  
    config.jpeg_quality = 12;  
  }  

  esp_camera_init(&config);  

  // Connect to Wi-Fi  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);  
    Serial.print(".");  
  }  
  Serial.println("Wi-Fi connected");  
}  

void loop() {  
  if (digitalRead(PIR_PIN) == HIGH) {  
    digitalWrite(BUZZER_PIN, HIGH);  
    delay(100);  
    digitalWrite(BUZZER_PIN, LOW);  

    // Capture photo and send to Telegram  
    camera_fb_t* fb = esp_camera_fb_get();  
    if (fb) {  
      bot.sendPhoto(CHAT_ID, fb->buf, fb->len, "Visitor detected!");  
      esp_camera_fb_return(fb);  
    }  
  }  
}  
