#include <bits/stdc++.h>

using namespace std;

class Mobile
{
    string company;
    int memory, fCamera, rCamera, battery;
    float price;
    vector<long int> mList;

public:
    Mobile(string a, int b, int c, int d, int e, float f, vector<long int> g)
    {
        company = a;
        memory = b;
        fCamera = c;
        rCamera = d;
        battery = e;
        price = f;
        mList = g;
    }

    float getPrice()
    {
        return price;
    }

    vector<long int> getMobContactList()
    {
        return mList;
    }

    void getMobProperties()
    {
        cout << "\nCompany : " << company;
        cout << "\nMemory : " << memory << " GB";
        cout << "\nFront Camera : " << fCamera << " MP";
        cout << "\nRear Camera : " << rCamera << " MP";
        cout << "\nBattery Backup : " << battery << " Hr.";
        cout << "\nPrice(in Rupees) : " << price << endl;
    }
};

class Sim
{
    string provider;
    int storage;
    long int number;
    vector<long int> sList;

public:
    Sim(string s, int t, long int n, vector<long int> m)
    {
        provider = s;
        storage = t;
        number = n;
        sList = m;
    }

    void getProvider()
    {
        cout << "\nService Provider: " << provider << endl;
    }

    long int getNumber()
    {
        return number;
    }

    void getSimProperties()
    {
        cout << "\nService Provider: " << provider;
        cout << "\nStorage : " << storage << " GB";
        cout << "\nYour Contact Number : " << number << endl;
    }

    vector<long int> getSimContactList()
    {
        return sList;
    }
};

class BankAccount
{
    float balance;

public:
    BankAccount(float y = 0.0)
    {
        balance = y;
    }
    float getBalance()
    {
        return balance;
    }
};

class User : public Mobile, public Sim
{
public:
    vector<BankAccount> b;
    User(string a, int x, int c, int d, int e, float f, vector<long int> g, string s, int t, long int n, vector<long int> m, vector<BankAccount> o) : Mobile(a, x, c, d, e, f, g), Sim(s, t, n, m)
    {
        b = o;
    }
    void incoming(string x, long int y)
    {
        cout << "\n\n___________Incoming Call____________\n\n";
        cout << "\t" << x;
        cout << "\n\n\t" << y;
    }
    void outgoing()
    {
        long int s;
        cout << "Enter Contact Number....::";
        cin >> s;
        cout << "\n\n_______________Calling________________\n\n";
        cout << "\t" << s;
    }
    void getUserDetails()
    {
        float sum = 0;
        getMobProperties();
        getSimProperties();
        cout << "Bank Account Total Sum :";
        for (int i = 0; i < b.size(); i++)
            sum = sum + b[i].getBalance();
        cout << sum;
    }
    float getTotalSum()
    {
        float sum = 0;
        for (int i = 0; i < b.size(); i++)
            sum = sum + b[i].getBalance();
        return sum;
    }
};

vector<User> u;
vector<Mobile> m;

void initialize()
{
    vector<long int> g, h;
    g.push_back(123456);
    g.push_back(123488);
    g.push_back(109856);
    vector<BankAccount> b;
    BankAccount q(5000.76);
    BankAccount r(45000.76);
    BankAccount s(55000.6);
    b.push_back(q);
    b.push_back(r);
    b.push_back(s);

    User x("Apple", 128, 128, 64, 20, 100000, g, "Airtel", 4, 976554, g, b);
    User y("Samsung", 64, 64, 32, 24, 85000, g, "Vodafone", 4, 004354, g, b);
    User z("Oppo", 128, 32, 8, 28, 14000, g, "Airtel", 4, 908654, g, b);

    u.push_back(x);
    u.push_back(y);
    u.push_back(z);

    Mobile a("Apple", 128, 128, 64, 20, 100000, h);
    Mobile c("Samsung", 64, 64, 32, 24, 85000, h);
    Mobile d("Oppo", 128, 32, 8, 28, 14000, h);

    m.push_back(a);
    m.push_back(d);
    m.push_back(c);
}

int main()
{
    initialize();
    int x;

    cout << "\nMenu::\n1)Get User Details\n2)Get Mobile Details\n3)Buy Mobile";
    cout << "\nChoose one:: ";
    cin >> x;

    if (x == 1)
    {
        for (int i = 0; i < u.size(); i++)
        {
            u[i].getUserDetails();
            cout << endl;
        }
    }
    else if (x == 2)
    {
        for (int i = 0; i < m.size(); i++)
        {
            u[i].getMobProperties();
            cout << endl;
        }
    }
    else if (x == 3)
    {
        char ch;
        long int x;
        int i;
        cout << "\nAre you a User??(y/n): ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "\nEnter your number:: ";
            cin >> x;

            for (i = 0; i < u.size(); i++)
            {
                if (u[i].getNumber() == x)
                    break;
            }

            cout << "\n\nYour details:: ";
            u[i].getUserDetails();

            cout << "\n\nMobile Details Which can be Brought:: \n";
            for (i = 0; i < m.size(); i++)
            {
                if (u[i].getTotalSum() >= u[i].getPrice())
                {
                    u[i].getMobProperties();
                    cout << endl;
                }
            }
        }
        else if (ch == 'n' || ch == 'N')
        {
            float r;
            int i;
            cout << "\n\nEnter your maximum range:: ";
            cin >> r;

            cout << "\n\nMobile Details Which can be Brought:: \n";
            for (i = 0; i < m.size(); i++)
            {
                if (r >= u[i].getPrice())
                {
                    u[i].getMobProperties();
                    cout << endl;
                }
            }
        }
        else
            cout << "\n\nWrong Choice...\n";
    }
    else
        cout << "\n\nInvalid Choice...";

    return 0;
}
