#include <Servo.h>

#define CLK 23
#define DT 22
#define SERVO 2
#define OFF_SPEED 85

Servo motor;

int counter = 0;
int spinState;
int lastSpinState;

int spinSpeed;

void setup() { 
    Serial.begin (9600);
    
    pinMode(CLK,INPUT);
    pinMode(DT,INPUT);
 
    motor.attach(SERVO);
    motor.write(OFF_SPEED);

    lastSpinState = digitalRead(CLK);  
}

void loop() {
    spinState = digitalRead(CLK);

    // Change the spin of the motor
    if (spinState != lastSpinState) 
    {
        (digitalRead(DT) != spinState) ? counter++ : counter--;
        counter = constrain(counter, -50, 50);

        spinSpeed = map(counter, -50, 50, OFF_SPEED - 5, OFF_SPEED + 5);
        motor.write(spinSpeed);

        lastSpinState = spinState;
    }
}
