byte RedBrightness;
byte GreenBrightness;
byte BlueBrightness;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;
#define COMMON_ANODE
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  
}

void setTargetColor() {
  byte  colors[3]; //first byte is red second is green third is blue
  int bytesRead = Serial.readBytes(colors,3);
  if (bytesRead != 3) {
    Serial.println('N');
    }
  else {
    Serial.println('A');
    RedBrightness = colors[0];
    GreenBrightness = colors[1];
    BlueBrightness = colors[2];
    }
  //}

  return;
  }
  void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void getColors() {
    //Serial.print("Red:");
    Serial.write(RedBrightness);
    //Serial.print("Green:",DEC);
    Serial.write(GreenBrightness);
    //Serial.print("Blue:");
    Serial.write(BlueBrightness);
  }
 
void loop() {


//check for communication from python/Raspberry Pi
if(Serial.available() > 0) {   
 byte func_byte = Serial.read();
    switch(func_byte) {
      case ('j'):
        setTargetColor();
        break;
      case('g'):
        getColors();
        break;
      default :
        while (Serial.available() > 0) {
          Serial.read();
          }
        break;
  }
  }

  setColor((int)RedBrightness,(int)GreenBrightness,(int)BlueBrightness);
 

}


