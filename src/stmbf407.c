#include "stmbf407.h"


//Waiting during time secondds (warning, it's in fonction of the clock, you need to adapt it !!)
void stmbf407_wait(uint32_t time){
    int i ; 
    for (i=0;i<time*1000000;i++) 
    asm("NOP") ; 
}
