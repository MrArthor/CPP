#include <bits/stdc++.h>

using namespace std;

class Products
{
private:
    string ProductId, Prize, Name, ManufacturingDate, ExpiryDate;
    bool IsConsumable;

public:
    Products()
    {
        ProductId = Prize = Name = ManufacturingDate = ExpiryDate = "XYZ";
        IsConsumable = false;
    }
};
class Customer
{
    string CustomerName, CustomerAddress;
    union
    {
        int MembershipId;
        int MobileNumber;
    } Identification;
    bool IsMember;

public:
    Customer()
    {
        IsMember = false;
        CustomerName = CustomerAddress = "Raj @@ Raj";
        Identification.MembershipId = 0;
    }
};

class Grocery : public Customer, Products
{
private:
    float Discount;

public:
};
int main()
{

    cout << "Hie Death";
    return 0;
}