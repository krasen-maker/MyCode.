/******************************************************************************

                 Программа предназначена для перевода hex в dec.

*******************************************************************************/
#include <stdio.h>
#include <math.h>


int hex_to_int(char i){
    int num;
    if ((i>=48) && (i<=57))
        num=i-48;
    else if((i>=65) && (i<=70))
        num=10+i-65;
    else if((i>=97) && (i<=102))
        num=10+i-97;
    else{
        return -1;
    }

    return num;
    
}

int main()
{
    char hex[] = "1b";
    int out=0;
    for(int i= sizeof(hex); i>0;  i--){
        if (hex[i-1]=='\0')
        {
            continue;
        }
        int n = hex_to_int(hex[i-1]);
        if(n==-1){
            printf("out=%d\nError!",out);
            return 0;
        }
        out+=pow(16.0,(sizeof(hex)-i-1))*n;
    }
    printf("%s в десятичной: %d", hex,out);
    return 0;
}

