#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//change int --> 16 HEX
char* tohex(int64_t value)  // value 64 bit
{
    char* HEX_DIGITS = "0123456789abcdef";
    char* s =malloc(sizeof(char)*10); // set Memory for char 10

    if(value<0) //check negative number
    {
        value += ((int64_t)1<<32); // use 64 bit to shiff 32

    }
    int lim = 0;
    while(1){
        char d[2] = {HEX_DIGITS[value & 0xf],'\0'}; //chang to Str
        char *temp = strdup(s);
        strcpy(s,d); //copy d to s
        strcat(s,temp);// temp + d 

        value >>=4 ;// coz change to 16 bit
        lim++;
        if (value ==0 || lim == 8) // Find breakpoint
        {
            break;
        }
    }
    char front[] = "0x";
    char* tmp2= strdup(s);
    strcpy(s,front);// copy front to s
    strcat(s,tmp2);// front +s

    return s;
}
int main(){ //display output
    int val_1 =33;
    printf("%d = %s\n",val_1,tohex(val_1));
    int val_2 = -1;
    printf("%d = %s" ,val_2,tohex(val_2));
    return 0;
}