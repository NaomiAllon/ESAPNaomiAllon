
#define SIGNALPIN 4
#define ONEmS_COUNTS ((1<<12)*50/1000) // 2^12 bit resolution * freq / 1000 (ms/s)
void setup() {
  ledcAttach (SIGNALPIN, 50, 12); // GPIO 4 assigned to channel 1
}
void loop() {
  int a=0;
  int min_counts = 0.5*ONEmS_COUNTS; // conservative is 0.5 ms for minimum
  int max_counts = 2.5*ONEmS_COUNTS; // conservative is 2.5 ms for max duty cycle
  for (int i=min_counts ; i < max_counts ; i+=1) {
    ledcWrite(SIGNALPIN, i); // sweep servo forward
    delay(2.5); // 2.5 ms delay
    a++;
    
  }
  delay(1000); //1 second delay
  for (int i=max_counts ; i > min_counts ; i-=1) {
    ledcWrite(SIGNALPIN, i); // sweep servo back
    delay(2.5); // need this 20mS for 1 cycle at 50Hz
  }
}

