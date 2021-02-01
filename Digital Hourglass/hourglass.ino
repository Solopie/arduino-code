const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;

int led = 2;
// 60mins -> 10mins intervals
// long interval = 600000;

// 3 seconds intervals
long interval = 3000;

boolean flashLights = false;
int flashLightState = HIGH;
long flashInterval = 1000;
unsigned long previousFlashTime = 0;

void setup()
{
    for (int x = 2; x < 8; x++)
    {
        pinMode(x, OUTPUT);
    }

    pinMode(switchPin, INPUT);
}

void loop()
{
    unsigned long currentTime = millis();

    // Flash lights
    if (flashLights && currentTime - previousFlashTime > flashInterval)
    {
        if (flashLightState == HIGH)
        {
            flashLightState = LOW;
        }
        else
        {
            flashLightState = HIGH;
        }

        for (int x = 2; x < 8; x++)
        {
            digitalWrite(x, flashLightState);
        }
        previousFlashTime = currentTime;
    }
    else
    {
        // Incrementing the lights
        if (currentTime - previousTime > interval)
        {
            previousTime = currentTime;
            digitalWrite(led++, HIGH);
            if (led == 7)
            {
                flashLights = true;
                digitalWrite(LED_BUILTIN, HIGH);
            }
        }
    }

    switchState = digitalRead(switchPin);
    if (switchState != prevSwitchState)
    {
        for (int x = 2; x < 8; x++)
        {
            digitalWrite(x, LOW);
        }

        led = 2;
        previousTime = currentTime;
        flashLights = false;
        digitalWrite(LED_BUILTIN, LOW);
    }

    prevSwitchState = switchState;
}