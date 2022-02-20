
const int octave = 4;   // between 2 and 8 with piezo buzzer

const int frequencies[] = {33, 37, 41, 44, 49, 55, 62, 65};     // Cmaj scale starting with C1
const int scale_length = 8;   // 8 notes
const int C_low = 0;
const int D = 1;
const int E = 2;
const int F = 3;
const int G = 4;
const int A = 5;
const int B = 6;
const int C_high = 7;

const int pin_buzzer = 11;
const int pin_button = 7;
const int pin_x = A0;
const int pin_y = A1;

int center_x = 688;
int center_y = 652;

void setup() {

  Serial.begin(9600);

  pinMode(pin_x, INPUT);
  pinMode(pin_y, INPUT);

  pinMode(pin_button, INPUT);

  pinMode(pin_buzzer, OUTPUT);

}

void loop() {
  /*
  if (digitalRead(pin_button) == HIGH) {

    if (octave == max_octave) {
      octave = base_octave;
    }
    else {
      octave++;
    }

  }
  */

  int value_x = analogRead(pin_x);
  int value_y = analogRead(pin_y);
  int note;

  Serial.print("x ");
  Serial.print(value_x);
  Serial.print(",  y ");
  Serial.print(value_y);

  if (!(value_x < (center_x + 8) && value_x > (center_x - 8)  && value_y < (center_y + 32) && value_y > (center_y - 32))) {

      if (value_x >= 520 &&  value_x < 535) {
        if (value_y >= 515 && value_y < 530) {
          note = C_low;
        }
        else {
          note = D;
        }
        
      }
      else if (value_x >= 330 &&  value_x < 375) {
        if (value_y >= 340 && value_y < 385) {
          note = E;
        }
        else {
          note = F;
        }
      }
      else if (value_x >= 900 &&  value_x < 980) {
        if (value_y >= 900 && value_y < 980) {
          note = G;
        }
        else {
          note = A;
        }
      }
      else if (value_x >= 990) {
        if (value_y >= 990) {
          note = B;
        }
        else {
          note = C_high;
        }
      }
    

    int freq =  frequencies[note] * pow(2, octave - 1);      // scale note to octave

    Serial.print(",  freq ");
    Serial.println(freq);
    
    tone(pin_buzzer, freq);
    
  }
  else {
    noTone(pin_buzzer);   // no sound at middle position
  }

  
}
