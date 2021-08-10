#include <stdio.h>
#include <stdlib.h>


int main() {
    
    FILE *f = fopen("data.txt", "w"); //write file
    

    

    for(int i =0; i<1000; i++) // range
    {
        fprintf(f, "%d\n",rand()%(1000)); //this one i want to test something it got a same result with %1000
    }
    fclose(f);
    return(0);
    
}