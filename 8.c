#include<stdio.h>
#include<stdlib.h>
void *quicksort(int *number,int first,int last)
{
  int i, j, pivot, temp;
  if(first<last){
      pivot=first;
      i=first;
      j=last;
      
      while(i<j){
          while(number[i]<=number[pivot]&&i<last){
              i++;
          }
          while(number[j]>number[pivot]){
              j--;
          }
          if(i<j){
              temp=number[i];
              number[i]=number[j];
              number[j]=temp;
          }  
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
  }
}

int main(){
    char *line;
    ssize_t len=0;
    ssize_t nread;
    FILE *fp;
    int line_count = 0;
    fp=fopen("data.txt","r");
    int ch,linenum =0;
    while((ch=fgetc(fp)) != EOF)
    {
        if(ch == '\n'){
            linenum++;
        }
    }
    fclose(fp);

    int b[linenum];

    fp=fopen("data.txt","r");
    while((nread = getline(&line,&len, fp))!=-1){
        b[line_count]=atoi(line);
        line_count++;
    }
    fclose(fp);

    quicksort(b,0,linenum-1);

    fp=fopen("data_sorted.txt","w");
    for(int j=0;j<line_count;j++){
        fprintf(fp,"%d \n",b[j]);
    }
    fclose(fp);
    return EXIT_SUCCESS;

}
