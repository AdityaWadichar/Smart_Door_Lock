# Smart_Door_Lock

An ESP32 controlled smart door system as a part of home automation is to be designed as follows. A touch button is mounted outside the home which is connected to ESP32 to enter the password in binary. Let the password of
the home be the 4-bit binary equivalent of the last digit of your roll number (If the last digit is 0, consider last but one digit). A user would be notified to enter the password by blinking on board blue LED 3 times. A user would be
given 4 sec time to enter the password; 1 sec per bit (tap). A tap/touch can be considered as 0 and untouched as 1 or vice-versa. The password would be matched with already saved in the code. If password is matched, a greeting should be opened in the browser screen showing
“Welcome Home Student Name ”.

## Result
<img src="serial_monitor.png">
<img src="https://github.com/AdityaWadichar/Smart_Door_Lock/blob/70f698cb924c84dbbb76972039e60a489f5cec81/webpage.png">

## [Demonstration](https://youtu.be/MuNkKupp1k8)
