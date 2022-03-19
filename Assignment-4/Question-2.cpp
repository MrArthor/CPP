#include <bits/stdc++.h>

using namespace std;

int RegexReplace()
{
    string s = "I am looking for SomeWordsHere \n";

    regex r("Some[a-zA-z]+");

    cout << std::regex_replace(s, r, "HieBroWhats up");

    string result;

   

    cout << result;

    return 0;
}

int RegexSearch()
{
    string s = "I am looking for SomeWordsHere "
               "articles";

    regex r("Some[a-zA-Z]+");

    smatch m;

    regex_search(s, m, r);

    // for each loop
    for (auto x : m)
        cout << endl
             << endl
             << x << " ";

    return 0;
}
int regexMatch()
{
    string a = "Vansh Sachdeva";
    regex b("(Vansh)(.*)");

    if (regex_match(a, b))
        cout << "String 'a' matches regular expression 'b' \n";

    if (regex_match(a.begin(), a.end(), b))
        cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n";

    return 0;
}
int main()
{
    regexMatch();
    RegexSearch();
    cout << endl
         << endl;
    RegexReplace();
    cout << "hie bro";

    return 0;
}