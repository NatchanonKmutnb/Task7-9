#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int N;
    FILE *fp;
    fp=fopen("data.txt","w");
    printf("Input N :");
    scanf("%d",&N);
    srand(time(NULL));
    for(int i=1;i<=N;i++){
        fprintf(fp,"%d \n",rand()%1000);
    }
    fclose(fp);
    return(0);
}