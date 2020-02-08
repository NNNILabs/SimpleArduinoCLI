# SimpleArduinoCLI
A simple command line interface that runs commands from the serial monitor.
Initially, the processor is in 'menu' mode, which allows for the following commands:
1. reset - software resets the processor.
2. time - prints the seconds since the processor was last reset to the serial monitor.
3. int - enters the interpreter.
The interpreter has the following commands:
1. digitalWrite <pin> <state> - writes 'pin' to 'state' 0 or 1.
2. digitalRead <pin> - prints the value of 'pin' to the serial monitor.
3. toggle <pin> - inverts the state of 'pin'.
4. delay <milliseconds> - delays further execution for the specified 'milliseconds'.
5. analogRead <pin> - prints the 10 bit value of 'pin' to the serial monitor.
6. pullup <pin> - enables a pullup resistor on 'pin'.
7. disablePullup <pin> - disables pullup resistor on 'pin'.
8. pulse <pin> <time> - pulses 'pin' high for 'time' milliseconds.
9. pulseMicroseconds <pin> <time> - pulses 'pin' high for 'time' microseconds (not very accurate).
  
This interpreter was intended to be part of a larger system. I understand that there are a lot of improvements that can be made, feel free to do so! :)
