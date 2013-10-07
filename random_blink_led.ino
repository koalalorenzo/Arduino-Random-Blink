/*
  Random Blink 
  Turns on and off the LED in base of the random numbers generated:

  It picks 2 numbers from 0 to 100. If the first divided by 2
  is greater than the secondo, the led will be turned on and off.

  Author: Lorenzo Setale ( koalalorenzo@gmail.com )
  Author Website: http://who.is.lorenzo.setale.me/?
  Italian blog post about this script: http://wp.me/p2OW0y-4H3
 */
 
int random_int_in_range (unsigned int min, unsigned int max)
{
  int base_random = rand();

  if (RAND_MAX == base_random) 
    return random_int_in_range(min, max);
  
  int range       = max - min;
  int remainder   = RAND_MAX % range,
  int bucket      = RAND_MAX / range;
  if (base_random < RAND_MAX - remainder) {
    return min + base_random/bucket;
  } else {
    return random_int_in_range(min, max);
  }

} 
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int attesa = random_int_in_range(10,20);

// the setup routine runs once when you press reset:
void setup() {                
    // initialize the digital pin as an output.
    pinMode(led, OUTPUT);
    Serial.begin(9600);
    Serial.println("Tempo di attesa");
    Serial.println(attesa);
}

// the loop routine runs over and over again forever:
void loop() {
    int primo_numero_casuale = random_int_in_range(1,100);
    int secondo_numero_casuale = random_int_in_range(1,100);
    
    if( (primo_numero_casuale / 2) > secondo_numero_casuale) {
      Serial.println("[N] Primo/2 maggiore del secondo");
      
      digitalWrite(led, HIGH);
      delay(attesa*10);
      digitalWrite(led, LOW);
      delay(attesa*10);
    }else{
      Serial.println("[Y] Primo maggiore del secondo/2");
      delay(attesa*10);
    }
}
