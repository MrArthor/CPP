#include <bits/stdc++.h>

using namespace std;
string Encryptor(string PlainText, int Key)
{
     string Final = "";

     // traverse PlainText
     for (int i = 0; i < PlainText.length(); i++)
     {
          // apply transformation to each character
          // Encryptor Uppercase letters
          if (isupper(PlainText[i]))
               Final += char(int(PlainText[i] + Key - 65) % 26 + 65);

          // Encryptor Lowercase letters
          else
               Final += char(int(PlainText[i] + Key - 97) % 26 + 97);
     }

     // Return the Finaling string
     return Final;
}

string Decryptor(string PlainText, int Key)
{
     string Final = "";

     // traverse PlainText
     for (int i = 0; i < PlainText.length(); i++)
     {
          // apply transformation to each character
          // Encryptor Uppercase letters
          if (isupper(PlainText[i]))
               Final += char(int(PlainText[i] - Key - 65 + 26) % 26 + 65);

          // Encryptor Lowercase letters
          else
               Final += char(int(PlainText[i] - Key - 97 + 26) % 26 + 97);
     }

     // Return the Finaling string
     return Final;
}

int main()
{
     cout << "The Plain Text Is THIS IS LAB TEST ONE " << endl;
     cout << "Encrypted Text Is: - ";
     cout << Encryptor("THIS IS LAB TEST ONE", 20);
     cout << endl;
     cout << "The Decrypted Version Of Encrption Is : -";
     cout << Decryptor(Encryptor("THIS IS LAB TEST ONE", 20), 20);
     return 0;
}