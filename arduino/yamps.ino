/* (c) Felpe Astroza Araya - 2014
 * under BSD license
 */
#include <Servo.h>

Servo servo;

int servo_pos = 0;
char servo_pos_str[4];
int str_idx = 0;
#define ROTATION_TIME 3000

void setup()
{
 Serial.begin(9600);
}


void loop()
{
  int byte;
  if(Serial.available() > 0) {
    byte = Serial.read();
    if(byte == '\n') {
      servo_pos_str[str_idx % 4] = 0;
      if(str_idx > 0) {
        servo_pos = max(min(atoi(servo_pos_str), 180), 0);
        servo.attach(9);
        servo.write(servo_pos);
        delay(ROTATION_TIME);
        servo.detach();
        str_idx = 0;
      }
      Serial.println(servo_pos);
    } else if(byte >= '0' && byte <= '9')
      servo_pos_str[str_idx++ % 3] = (char)byte;
  }
}
