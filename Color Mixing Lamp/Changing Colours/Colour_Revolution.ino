const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redOffset = 10;
int greenOffset = 12;
int blueOffset = 14;

void setup()
{
    Serial.begin(9600);
    pinMode(greenLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
}

void loop()
{

    if (redValue + redOffset >= 255 || redValue + redOffset < 0)
    {
        redOffset *= -1;
    }

    if (greenValue + greenOffset >= 255 || greenValue + greenOffset < 0)
    {
        greenOffset *= -1;
    }
    if (blueValue + blueOffset >= 255 || blueValue + blueOffset < 0)
    {
        blueOffset *= -1;
    }

    redValue += redOffset;
    greenValue += greenOffset;
    blueValue += blueOffset;

    Serial.print("RGB: \t");
    Serial.print(redValue);
    Serial.print(" \t");
    Serial.print(greenValue);
    Serial.print(" \t");
    Serial.println(blueValue);

    analogWrite(redLEDPin, redValue);
    analogWrite(greenLEDPin, greenValue);
    analogWrite(blueLEDPin, blueValue);

    delay(250);
}