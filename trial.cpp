#include <bits/stdc++.h>

using namespace std;
string En(string PlainText, int K)
{
     string Final = "";

     
     for (int i = 0; i < PlainText.length(); i++)
     {
          
          if (isupper(PlainText[i]))
               Final += char(int(PlainText[i] + K - 65) % 26 + 65);

          
          else
               Final += char(int(PlainText[i] + K- 97) % 26 + 97);
     }

    
     return Final;
}

string De(string PlainText, int Key)
{
     string Final = "";

     
     for (int i = 0; i < PlainText.length(); i++)
     {
          
          if (isupper(PlainText[i]))
               Final += char(int(PlainText[i] - Key - 65 + 26) % 26 + 65);

          
          else
               Final += char(int(PlainText[i] - Key - 97 + 26) % 26 + 97);
     }

    
     return Final;
}

int main()
{
     cout << "The Plain Text Is THIS IS LAB TEST ONE " << endl;
     cout << "Encrypted Text Is: - ";
     cout << En("THIS IS LAB TEST ONE", 20);
     cout << endl;
     cout << "The Decrypted Version Of Encrption Is : -";
     cout << De(En("THIS IS LAB TEST ONE", 20), 20);
     return 0;
}