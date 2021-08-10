#include<stdio.h>
int main() {
   int n;
   char hex_string[1];
   printf("Enter number : ");
   scanf("%d",&n);
   sprintf(hex_string, "0x%x-", n); 
   printf("%s",hex_string);
}