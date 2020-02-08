#define BUF_WIDTH 30
#define newline Serial.print('\n')

char input[BUF_WIDTH], holder[3][BUF_WIDTH];

void(* reset) (void) = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Railgun Mk.II Computer System V3");
  newline;
}

void loop() {
  // put your main code here, to run repeatedly:
  handleMenu();
}

void tokenize(char string[BUF_WIDTH])
{
  char * valPosition = strtok(string, " ");
  strcpy(holder[0], valPosition);
  int i = 1;
  while (valPosition != NULL)
  {
    valPosition = strtok(NULL, " ");
    strcpy(holder[i], valPosition);
    i = i + 1;
  }
}

void interpret(char opcode[BUF_WIDTH], int operandOne, int operandTwo)
{
  if (strcmp(opcode, "digitalWrite") == 0)
  {
    digitalWrite(operandOne, operandTwo);
  }

  else if (strcmp(opcode, "digitalRead") == 0)
  {
    Serial.print(digitalRead(operandOne));
    newline;
  }

  else if (strcmp(opcode, "toggle") == 0)
  {
    if(digitalRead(operandOne) == LOW)
    {
      digitalWrite(operandOne, HIGH);
    }
    else
    {
      digitalWrite(operandOne, LOW);
    }
  }

  else if (strcmp(opcode, "delay") == 0)
  {
    delay(operandOne);
  }

  else if (strcmp(opcode, "analogRead") == 0)
  {
    Serial.print(analogRead(operandOne));
    newline;
  }

  else if (strcmp(opcode, "pullup") == 0)
  {
    pinMode(operandOne, INPUT_PULLUP);
    Serial.print("Pullup ");
    Serial.print(operandOne);
    newline;
  }

  else if (strcmp(opcode, "disablePullup") == 0)
  {
    pinMode(operandOne, INPUT);
    Serial.print("No pullup ");
    Serial.print(operandOne);
    newline;
  }

  else if (strcmp(opcode, "pulse") == 0)
  {
    digitalWrite(operandOne, HIGH);
    delay(operandTwo);
    digitalWrite(operandOne, LOW);
  }

  else if (strcmp(opcode, "pulseMicroseconds") == 0)
  {
    digitalWrite(operandOne, HIGH);
    delayMicroseconds(operandTwo);
    digitalWrite(operandOne, LOW);
  }

  else if (strcmp(opcode, "exit") == 0)
  {
    
  }

  else
  {
    Serial.print("Invalid!");
    newline;
  }
}

void getString(char output[BUF_WIDTH])
{
  while (!Serial.available());
  String in = Serial.readStringUntil('\n');
  in.trim();
  in.toCharArray(output, BUF_WIDTH);
}

void handleMenu()
{
  Serial.print(">> ");
  getString(input);
  Serial.print(input);
  newline;
  if (strcmp(input, "reset") == 0)
  {
    delay(50);
    reset();
  }

  else if (strcmp(input, "time") == 0)
  {
    Serial.print(millis() / 1000);
    Serial.print(" seconds");
    newline;
  }

  else if (strcmp(input, "int") == 0)
  {
    handleInterpreter();
  }

  else if (strcmp(input, "script") == 0)
  {
    handleScript();
  }

  else
  {
    Serial.print("Invalid!");
    newline;
  }
}

void handleInterpreter()
{
  strcpy(input, '\0');
  while (strcmp(input, "exit") != 0)
  {
    Serial.print("-> ");
    getString(input);
    Serial.print(input);
    newline;
    tokenize(input);
    interpret(holder[0], atoi(holder[1]), atoi(holder[2]));
  }
}

void handleScript()
{
  strcpy(input, '\0');
  int i = 0;
  while (strcmp(input, "finished") != 0)
  {
    Serial.print(": ");
    getString(input);
    Serial.print(input);
    tokenize(input);
    newline;
  }
}
