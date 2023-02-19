#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
int step_number = 0;

const int read = A0;//set force sensor to A0

const int buzzer = 8;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

int songLength = 32;
char notes[] = "gacaE  E  D     gacaD  D  C     ";
//double beats[] = {0.25,0.25,0.25,0.25,0.75,0.75,1.5,0.25,0.25,0.25,0.25,0.75,0.75,1.5};
double beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int tempo = 114;

int index = 0;

void setup() {
 

  Serial.begin(9600);

  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  pinMode(buzzer, OUTPUT);

}

  unsigned long currentMillis1 = millis();
  unsigned long currentMillis2 = millis();
  unsigned long currentMillis3 = millis();

void loop() {
  int duration = beats[index]*tempo;
  currentMillis1 = millis();
  currentMillis2 = millis();
  currentMillis3 = millis();

  if(index > songLength-1){
    index = 0;
  }
   
  int value = analogRead(read);//read the force sensor value

  if(value < 1)
  {
     if (currentMillis2 - previousMillis2 >= 100)
    {
      previousMillis2 = currentMillis2;
      OneStep(true);
    }

 if (currentMillis1 - previousMillis1 >= duration)
    {
      previousMillis1 = currentMillis1;
      
      noTone(buzzer);
    }
    
  } 

  else if (value < 7) {

      if (currentMillis2 - previousMillis2 >= 10)
    {
      previousMillis2 = currentMillis2;
      OneStep(false);
    }

     if (currentMillis1 - previousMillis1 >= duration)
    {
      previousMillis1 = currentMillis1;
      
      tone(buzzer, frequency(notes[index]), duration);
      tempo = 114;
      duration = beats[index]*tempo;
      index++;
    }
     
  }

  else
  {

     if (currentMillis2 - previousMillis2 >= 2)
    {
      previousMillis2 = currentMillis2;
      OneStep(false);
    }

 if (currentMillis1 - previousMillis1 >= duration)
    {
      previousMillis1 = currentMillis1;

      tempo = 114/1.5;
      duration = beats[index]*tempo;
      
      tone(buzzer, frequency(notes[index]), duration);
      index++;
    }

    delay(tempo/10);
     
  }
}

int frequency(char note)
{
  int j;
  const int numNotes = 11;
  char names[] = {'c','d','e','f','g','a','b','C', 'E','D',' '};
  int frequencies[] = {262,294,330,349,392,440,494,523, 659,587,0};
  for (j = 0; j<numNotes; j++)
  {
    if(names[j] == note)
    {
      return(frequencies[j]);
    }
  }
}

void OneStep(bool dir){
  //unsigned long internal_count = millis();
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
