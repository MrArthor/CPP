#include <iostream> 
#include <string> 
#include <regex> 
#include <iterator> 
using namespace std; 
   
int main() 
{  
    string mystr = "This is software testing Help portal \n"; 
     
    cout<<"Input string: "<<mystr<<endl;
       
    // regex to match string beginning with 'p' 
    regex regexp("+[a-zA-z]+tion"); 
    cout<<"Replace the word 'portal' with word 'website' : "; 
    // regex_replace() for replacing the match with the word 'website'  
    cout << regex_replace(mystr, regexp, ""); 
     
    return 0; 
}