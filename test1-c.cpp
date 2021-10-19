#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int CalcGCD(int);
int main()
{
 int i,j,k,gcd,Alpha,Beta,NumStringing[100],NumCipher[100];
 char String[100],cipher[100];
 printf("Enter a Stringing\n");
 gets(String);
 for(i=0,j=0;i<strlen(String);i++)
 {
  if(String[i]!=' ')
  {
   String[j]=toupper(String[i]);   
   j++;
  }
  else
  {
   String[j]=' ';
   j++;
  }
 }
 String[j]='\0';
 printf("Entered String is : %s \n",String);
 printf("Enter Alpha value and must be between 1 and 25 both included\n");
 scanf("%d",&Alpha); 
 if(Alpha<1 || Alpha>25)
 {
  printf("Alpha should lie in between 1 and 25\nSorry Try again !\n");
  exit(0);
 } 
 gcd=CalcGCD(Alpha);
 if(gcd!=1)
 {
  printf("gcd(Alpha,26)=1 but \n gcd(%d,26)=%d\nSorry Try again !\n",Alpha,gcd);
  exit(0);
 }
 printf("Enter Beta value and must be between 0 and 25 both included\n");
 scanf("%d",&Beta);
 if(Beta<0 || Beta>25)
 {
  printf("Beta value should lie between 0 and 25\nSorry Try again !\n");
  exit(0);
 }
 
 for(i=0;i<strlen(String);i++)
 {
  if(String[i]!=' ')
  NumStringing[i]=String[i]-'A';
  else
  NumStringing[i]=-20;
 }
    printf("Affine Cipher text is\n");   
    for(i=0;i<strlen(String);i++)
    {
     if(NumStringing[i]!=-20)
     {
     NumCipher[i]=((Alpha*NumStringing[i])+Beta)%26;
          printf("%c",(NumCipher[i]+'A'));         
     }
     else
     {
          printf(" ");      
     }
    }
printf("\n");
 
}

int CalcGCD(int Alpha)
{
 int x;
   int Temp1=Alpha;
   int Temp2=26;

     while(Temp2!=0)
      {
        x=Temp2;
        Temp2=Temp1%Temp2;
        Temp1=x;
      }
     return(Temp1);
}