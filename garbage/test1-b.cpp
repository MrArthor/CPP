#include<bits/stdc++.h>

using namespace std;
string encrypt(string s, int key)
{
     string dec;
     for (int i = 0; i < s.length(); i++)
     {
          int temp = (s[i] * key) % 26;
          dec.push_back((char)temp);
     }
     return dec;
}

string decrypt(string s, int key)
{
     string enc;
     for (int i = 0; i < s.length(); i++)
     {
          int temp = (s[i] / key) % 26;
          enc.push_back((char)temp);
     }
     return enc;
}

int main(){

cout<<encrypt("THIS IS LAB TEST ONE",15);
cout<<endl;
cout<<decrypt(encrypt("THIS IS LAB TEST ONE",15),15);
     return 0;

}
