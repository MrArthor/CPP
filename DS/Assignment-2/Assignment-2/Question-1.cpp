#include <bits/stdc++.h>

using namespace std;

class Invoice
{
private:
    string ItemName, ItemDescription, ItemNumber;
    int QuantityPurchased, PricePerUnit, CopyCount;

public:
    Invoice()
    {
        ItemName = ItemDescription = ItemNumber = "X";
        QuantityPurchased = PricePerUnit = 0;
    }
    Invoice(Invoice &Copy)
    {
        if (Copy.CopyCount == 0)
        {
            CopyCount = Copy.CopyCount = 1;
        }
        else
        {
            CopyCount = Copy.CopyCount + 1;
            Copy.CopyCount += 1;
        }
    }
    int ReturnQuantity()
    {
        return QuantityPurchased;
    }
    void UpdateName(string name)
    {
        ItemName = name;
    }
    void UpdateDescrption(string descrption)
    {
        ItemDescription = descrption;
    }
    void UpdateItemNumber(string ItemNumber)
    {
        this->ItemNumber = ItemNumber;
    }

    void UpdatePrice(int PricePerUnit)
    {
        this->PricePerUnit = PricePerUnit;
    }
    void UpdateQuantity(int QuantityPurchased)
    {
        this->QuantityPurchased = QuantityPurchased;
    }
    int GetInvoiceAmount()
    {
        return PricePerUnit * QuantityPurchased;
    }
  
};
int MaxQuantity(Invoice &One, Invoice &Two)
{
    return One.ReturnQuantity() > Two.ReturnQuantity() ? One.ReturnQuantity() : Two.ReturnQuantity();
}
int main()
{

    //Test Bench
    Invoice inc, inc1;
    //inserting Values
    inc.UpdateDescrption("Max");
    inc.UpdateItemNumber("qw321w");
    inc.UpdateName("Iphone");
    inc.UpdatePrice(100000);
    inc.UpdateQuantity(5);
    cout<<"Invoice -0 Total Amount= "<<inc.GetInvoiceAmount();
    inc1.UpdateDescrption("min");
    inc1.UpdateItemNumber("sfvlkefjowinh");
    inc1.UpdateName("OnePlus Nord");
    inc1.UpdatePrice(10000);
    inc1.UpdateQuantity(10);
    cout<<"\nInvoice -1 Total Amount= "<<inc1.GetInvoiceAmount();
    cout << endl<<endl<<MaxQuantity(inc1, inc);
    return 0;
}