int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int piezoPin = 8;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    while (millis() < 5000)
    {
        sensorValue = analogRead(A0);
        if (sensorValue > sensorHigh)
        {
            sensorHigh = sensorValue;
        }
        if (sensorValue < sensorLow)
        {
            sensorLow = sensorValue;
        }
    }

    digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
    sensorValue = analogRead(A0);
    // int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 2000);
    tone(8, pitch, 20);
    delay(10);
}