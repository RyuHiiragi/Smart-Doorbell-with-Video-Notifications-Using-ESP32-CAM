# Smart Doorbell with Video Notifications Using ESP32-CAM  

This repository contains the code and instructions for a **smart doorbell** that uses the ESP32-CAM to capture photos/videos and send real-time alerts to Telegram when motion or a button press is detected <button class="citation-flag" data-index="1"><button class="citation-flag" data-index="4">.  

---

## Features  
- Real-time photo/video capture via ESP32-CAM <button class="citation-flag" data-index="3"><button class="citation-flag" data-index="7">.  
- Motion detection using PIR sensor <button class="citation-flag" data-index="6"><button class="citation-flag" data-index="8">.  
- Notifications sent directly to Telegram <button class="citation-flag" data-index="2"><button class="citation-flag" data-index="4">.  
- Optional relay control for door locks <button class="citation-flag" data-index="8">.  

---

## Components  
- **ESP32-CAM Module** <button class="citation-flag" data-index="1"><button class="citation-flag" data-index="7">  
- **PIR Motion Sensor** <button class="citation-flag" data-index="6"><button class="citation-flag" data-index="8">  
- **Push Button** <button class="citation-flag" data-index="5">  
- **Buzzer** <button class="citation-flag" data-index="6">  
- **Relay Module (Optional)** <button class="citation-flag" data-index="4">  

---

## Setup  
1. **Telegram Bot**:  
   - Create a bot via [BotFather](https://core.telegram.org/bots#botfather) and replace `BOT_TOKEN` and `CHAT_ID` in the code <button class="citation-flag" data-index="4"><button class="citation-flag" data-index="9">.  
2. **Sensor Calibration**:  
   - Adjust the PIR sensor sensitivity to avoid false triggers <button class="citation-flag" data-index="7"><button class="citation-flag" data-index="8">.  
3. **Power Supply**:  
   - Use a 5V adapter to ensure stable operation <button class="citation-flag" data-index="6"><button class="citation-flag" data-index="8">.  

---

## License  
MIT License. See [LICENSE](LICENSE) for details.  

---

<button class="citation-flag" data-index="1"> ESP32-CAM for real-time video streaming <button class="citation-flag" data-index="3"><button class="citation-flag" data-index="7">.  
<button class="citation-flag" data-index="2"> Telegram integration for notifications <button class="citation-flag" data-index="4"><button class="citation-flag" data-index="9">.  
<button class="citation-flag" data-index="6"> Motion detection and buzzer alerts <button class="citation-flag" data-index="8">.  
