#include<stdio.h>
int main()
{
    int  a,b,mod=5,k,i,z,c;
    a=1;
    printf("\n\n\n");
    while(a<=6)
    {
        printf("\t\t");
        b=0;
        printf("              ");
        while(b<6-a)
        {
            printf(" ");
            b=b+1;
        }
        b=0;
        while(b<a)
        {
            printf("*");
            printf(" ");
            b=b+1;
        }
        printf("\n");
        a=a+1;
    }
    a=5;
    b=19;
    i=0;
    while(a<=10){
        printf("\t\t");
        k=b;
        z=i;
        for(z;z>0;z--){
            printf("  ");
        }
        for(k;k>=0;k--){
            printf("* ");
        }
        printf("\n");
        i = i+1;
        b = b-2;
        a = a+1;
    }
    while(mod>=0){
        printf("\t\t");
        z=mod+3;
        while(z>0){
            printf(" ");
            z = z-1;
        }
        printf(" ");
        for(k=1;k<=mod;k++){
            printf("* ");
        }
        for(i=1;i<=2*(a-2*mod);i++){
            printf(" ");
        }
        for(k=1;k<=mod;k++){
            printf("* ");
        }
        printf("\n");
        mod=mod-1;
        a = a+1;
    }
    return 0;
}
