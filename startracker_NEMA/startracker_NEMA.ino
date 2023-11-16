#define DIR_PIN 2
#define STEP_PIN 3

const int numSteps = 8;
int delays[numSteps];
int totalDelay = 168;

void setup()
{
	pinMode(DIR_PIN, OUTPUT);
	pinMode(STEP_PIN, OUTPUT);
	digitalWrite(DIR_PIN, LOW);	// HIGH or LOW to change direction
	
	for (int i = 0; i < numSteps; ++i)	// distributes totalDelay over numSteps number of steps as evenly as possible
		delays[i] = totalDelay / numSteps + (i < totalDelay % numSteps ? 1 : 0);
}

void loop()
{
	for (int i = 0; i < numSteps; ++i)
	{		
		digitalWrite(STEP_PIN, HIGH);
		delay(delays[i]);
		digitalWrite(STEP_PIN, LOW);
		delay(delays[i]);
	}
}