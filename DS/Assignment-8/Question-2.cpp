#include <iostream>
#include <vector>
using namespace std;
using Vector = vector<int>;
void printVector(const Vector &a)
{
    for (int e : a)
    {
        cout << e << " ";
    }
}
Vector mergeThree(Vector &A, Vector &B, Vector &C, int x)
{
    int i, j, k;
    Vector D;
    D.reserve(x + x + x);
    i = j = k = 0;
    while (i < x && j < x && k < x)
    {
        int m = min(min(A[i], B[j]), C[k]);
        D.push_back(m);
        if (m == A[i])
            i++;
        else if (m == B[j])
            j++;
        else
            k++;
    }
    while (i < x && j < x) //C exhausted
    {
        if (A[i] <= B[j])
        {
            D.push_back(A[i]);
            i++;
        }
        else
        {
            D.push_back(B[j]);
            j++;
        }
    }
    while (i < x && k < x) //B exhausted
    {
        if (A[i] <= C[k])
        {
            D.push_back(A[i]);
            i++;
        }
        else
        {
            D.push_back(C[k]);
            k++;
        }
    }
    while (j < x && k < x) //A exhausted
    {
        if (B[j] <= C[k])
        {
            D.push_back(B[j]);
            j++;
        }
        else
        {
            D.push_back(C[k]);
            k++;
        }
    }
    while (k < x) //A and B exhausted
        D.push_back(C[k++]);
    while (i < x) //B and C exhausted
        D.push_back(A[i++]);
    while (j < x) //A and C exhausted
        D.push_back(B[j++]);
    return D;
}
int main()
{
    Vector A = {5, 10, 12, 15, 20};
    Vector B = {1, 3, 17, 19, 23};
    Vector C = {4, 9, 13, 18, 21};
    int y = 5; //size of the arrays
    printVector(mergeThree(A, B, C, y));
    return 0;
}