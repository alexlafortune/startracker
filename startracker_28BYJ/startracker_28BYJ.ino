#define PIN_A 4
#define PIN_B 5
#define PIN_C 6
#define PIN_D 7
#define PIN_SWITCH 2
#define STEPS_PER_REV 512

bool isEnabled;
const int numSteps = 8;
int delays[numSteps];
int steps[numSteps] = {
	0b1000,
	0b1100,
	0b0100,
	0b0110,
	0b0010,
	0b0011,
	0b0001,
	0b1001
};

void setup()
{
	pinMode(PIN_A, OUTPUT);
	pinMode(PIN_B, OUTPUT);
	pinMode(PIN_C, OUTPUT);
	pinMode(PIN_D, OUTPUT);
	pinMode(PIN_SWITCH, INPUT);
	
	const int totalDelay = 1160;
	
	for (int i = 0; i < numSteps; ++i)
		delays[i] = totalDelay / numSteps + (i < totalDelay % numSteps ? 1 : 0);
}

void write(int b)
{
	digitalWrite(PIN_A, bitRead(b, 0));
	digitalWrite(PIN_B, bitRead(b, 1));
	digitalWrite(PIN_C, bitRead(b, 2));
	digitalWrite(PIN_D, bitRead(b, 3));
}

void step(bool reverse)
{
	int index;
	
	for (int i = 0; i < numSteps; ++i)
	{
		if (reverse)
			index = numSteps - 1 - i;
		else
			index = i;
		
		write(steps[index]);
		delay(delays[i]);
	}
}

void loop()
{
	isEnabled = digitalRead(PIN_SWITCH);
	
	if (isEnabled)
		step(true);
}