#include <iostream>
using namespace std;
#define SIZE 30

int Hash(int key)
{
    return key % SIZE;
}
int probe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i*i) % SIZE] != 0)
        i++;
    return (index + i*i) % SIZE;
}
void Insert(int H[], int key)
{
    int index = Hash(key);

    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}
int Search(int H[], int key)
{
    int index = Hash(key);

    int i = 0;

    while (H[(index + i*i) % SIZE] != key)
        i++;

    return (index + i*i) % SIZE;
}
int main()
{
    int HT[30] = {0};
 Insert(HT, 5);
    Insert(HT, 2);
    Insert(HT, 15);
    Insert(HT, 25);
    Insert(HT, 11);
    Insert(HT, 19);
    Insert(HT, 65);
    Insert(HT, 23);
    Insert(HT, 34);
    Insert(HT, 44);
    Insert(HT, 64);
    Insert(HT, 74);
    Insert(HT, 73);
    Insert(HT, 2);
    Insert(HT, 15);
    Insert(HT, 29);
    Insert(HT, 55);
    Insert(HT, 65);
    Insert(HT, 26);
    Insert(HT, 64);
    Insert(HT, 34);
    Insert(HT, 38);
    Insert(HT, 12);
    Insert(HT, 49);
    Insert(HT, 11);
    Insert(HT, 78);
    Insert(HT, 65);
    Insert(HT, 63);
    Insert(HT, 57);
    Insert(HT, 42);

    cout << "\nKey found at \n"
         << Search(HT, 44);
    cout << "\nKey found at \n"
         << Search(HT, 94);
    cout << "\nKey found at \n"
         << Search(HT, 65);

 cout<<"\nKey found at \n"<<Search(HT,35);
 return 0;
}