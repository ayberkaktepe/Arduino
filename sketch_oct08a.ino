/*
 Planted aquarium day simulator.
 I used 7W power LED module.
 I drive LED with constant current 7w adaptor.
 I used IRFZ44 N-Channel mosfet for fading LED's.
*/

int led = 9; // the PWM pin the mosfet is attached to


void setup() {
   pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  for(int i=1; i<=255; i++){//LED reachs maximum brightness in  510 seconds
       analogWrite(led, i);
       delay(2000);
  }
  delay(13890000);
  for(int i=254; i>=0; i--){//LED reachs minimum brightness in  510 seconds
       analogWrite(led, i);
       delay(2000);
  }

    delay(14400000);//Wait 4 hours

      for(int i=1; i<=255; i++){//LED reachs maximum brightness in  510 seconds
       analogWrite(led, i);
       delay(2000);
  }
  delay(13890000);
  for(int i=254; i>=0; i--){//LED reachs minimum brightness in  510 seconds
       analogWrite(led, i);
       delay(2000);
  }
  
    delay(42280000);//wait for next morning

  
}
