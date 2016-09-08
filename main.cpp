#include "mbed.h"
#include "Serial.h"
 
//Virtual serial port over USB
Serial pc(USBTX, USBRX);
DigitalOut myled(LED2);
AnalogIn Luminosidade(PTB0);
DigitalOut led_ext(PTA1);

 
int main(void) {
    double lum = Luminosidade.read();
    int i=0;
    pc.printf("\r\nT: i, Lum\r\n");
    wait(0.5);
    while(1){
        lum = Luminosidade.read()*10000;
        pc.printf("A: %d, %lf\r\n",i,lum);
        i++;
        if(lum<600){
            myled=0;
            led_ext=1;
        }
        else{
            myled=1; 
            led_ext=0; 
        } 
        
        wait(0.5);    
        
        
    }
    
}
