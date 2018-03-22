#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char map[200][200];
    int a=100;
    int r=50;
    int d=0;
    int x,y,k,l;
    memset(map,0,sizeof(map));
    for(k=0;k<200;k++){
        for(l=0;l<200;l++){
            map[k][l]='#';
        }
    }
    x=0;
    y=r;
    d=3-2*r;
    while(x<y){
        if(d>=0){
            y=y-1;
            d=d+4*(x-y)+10;
        }
        else {
            d=d+4*x+6;
        }
        map[a+x][a+y]=map[a+x][a-y]=map[a-x][a+y]=map[a-x][a-y]=map[a+y][a+x]=map[a+y][a-x]=map[a-y][a+x]=map[a-y][a-x]='0';
        x++;
    }
    for(k=0;k<200;k++){
        for(l=0;l<200;l++){
            printf("%c",map[k][l]);
        }
        printf("\n");
    }
    return 0;
}

