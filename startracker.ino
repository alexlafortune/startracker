#define DIR_PIN 2
#define STEP_PIN 3

const int stepDelay = 1;

void setup()
{
	pinMode(DIR_PIN, OUTPUT);
	pinMode(STEP_PIN, OUTPUT);
	digitalWrite(DIR_PIN, HIGH);	// HIGH or LOW to change direction
}

void loop()
{
	digitalWrite(STEP_PIN, HIGH);
	delay(stepDelay);
	digitalWrite(STEP_PIN, LOW);
	delay(stepDelay);
}