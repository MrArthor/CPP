#include <bits/stdc++.h>
using namespace std;
 
// function to convert Celsius
// scale to Fahrenheit scale
float Cel_To_Fah(float N)
{
    return ((N * 9.0 / 5.0) + 32.0);
}
 
// Driver code
int main()
{
    float N = 0;
   
      for(int i=0;i<21;i++){
    cout <<i<<" "<<  Cel_To_Fah(N+i)<<endl;
      }
    return 0;
}