#include<bits/stdc++.h>

using namespace std;


int SumOfCommonAlpha(char input1[],char input2[]){
    int sum=0;
  
   int a1[26] = {0};
   int a2[26] = {0};
   int i , j;
   char ch;
   char ch1 = 'a';
   int k = (int)ch1, m;
   for(i = 0 ; i < input1[i] ; i++){
      a1[(int)input1[i] - k]++;
   }
   for(i = 0 ; i < input2[i] ; i++){
      a2[(int)input2[i] - k]++;
   }
   for(i = 0 ; i < 26 ; i++){
      if (a1[i] != 0 and a2[i] != 0){
         for(j = 0 ; j < min(a1[i] , a2[i]) ; j++){
            m = k + i;
            ch = (char)(k + i);
            sum+=ch;
         }
      }
   }
   return sum;
}
int main(){

    char input1[] = {'a','b','c','\0'};
    char input2[] = {'b','c','\0'};
   cout<< SumOfCommonAlpha(input1,input2);
    return 0;
}