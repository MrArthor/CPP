#include <iostream>
using namespace std;

template <class T>
class Sort
{
private:
    T *Arr;
    int Size;

public:
    Sort()
    {
        cin >> Size;
        // if (Arr)
        // {
        //     delete[] Arr;
        // }
        Arr = new int[Size + 1];
        for (int i = 0; i < Size; i++)
        {
            Arr[i] = rand() % (Size + 1);
        }
    }

    int QuickSort(T Arr[], int low, int high);
    int Partition(T Arr[], int low, int high);
    int MergeSort(T Arr[], int l, int r);
    int Merge(T Arr[], int l, int m, int r);
    int BubbleSort(int);
    int Swap(T *, T *);
    void SelectionSort(T Arr[], int SIZE);
    void RadixSort(T Arr[], int SIZE);
    int RadixSort();
    int GetMax(T Arr[], int SIZE);
    int *ReturnAddress();
    void CountSort(T Arr[], int SIZE, int exp);
    int ReturnSize()
    {
        return Size;
    }
    void Display();
    ~Sort()
    {
        delete[] Arr;
    }
};
template <class T>
int *Sort<T>::ReturnAddress()
{
    return Arr;
}
template <class T>
void Sort<T>::Display()
{
    for (int i = 0; i < Size; i++)
    {
        cout << this->Arr[i] << " ";
    }
}

template <class T>
int Sort<T>::BubbleSort(int Size)
{
    int i, j;
    for (i = 0; i < Size - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < Size - i - 1; j++)
            if (Arr[j] > Arr[j + 1])
                Swap(&Arr[j], &Arr[j + 1]);
    return 0;
}
template <class T>
int Sort<T>::Swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
    return 0;
}
template <class T>
int Sort<T>::Merge(T Arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = Arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = Arr[m + 1 + j];

    int i = 0;

    int j = 0;

    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            Arr[k] = L[i];
            i++;
        }
        else
        {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        Arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        Arr[k] = R[j];
        j++;
        k++;
    }
    return 0;
}
template <class T>
int Sort<T>::MergeSort(T Arr[], int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    MergeSort(Arr, l, m);
    MergeSort(Arr, m + 1, r);
    Merge(Arr, l, m, r);
    return 0;
}

template <class T>
int Sort<T>::Partition(T Arr[], int low, int high)
{
    int pivot = Arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (Arr[j] < pivot)
        {
            i++;
            Swap(&Arr[i], &Arr[j]);
        }
    }
    Swap(&Arr[i + 1], &Arr[high]);
    return (i + 1);
}
template <class T>
int Sort<T>::QuickSort(T Arr[], int low, int high)
{

    {
        if (low < high)
        {

            int pi = Partition(Arr, low, high);

            QuickSort(Arr, low, pi - 1);
            QuickSort(Arr, pi + 1, high);
        }
    }
    return 0;
}

template <class T>
void Sort<T>::SelectionSort(T Arr[], int SIZE)
{
    int i, j, min_idx;

    for (i = 0; i < SIZE - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < SIZE; j++)
            if (Arr[j] < Arr[min_idx])
                min_idx = j;

        Swap(&Arr[min_idx], &Arr[i]);
    }
}
template <class T>
int Sort<T>::GetMax(T Arr[], int SIZE)
{
    int mx = Arr[0];
    for (int i = 1; i < SIZE; i++)
        if (Arr[i] > mx)
            mx = Arr[i];
    return mx;
}
template <class T>

void Sort<T>::CountSort(T Arr[], int SIZE, int exp)
{
    int output[SIZE];
    int i, count[10] = {0};

    for (i = 0; i < SIZE; i++)
        count[(Arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = SIZE - 1; i >= 0; i--)
    {
        output[count[(Arr[i] / exp) % 10] - 1] = Arr[i];
        count[(Arr[i] / exp) % 10]--;
    }

    for (i = 0; i < SIZE; i++)
        Arr[i] = output[i];
}
template <class T>
void Sort<T>::RadixSort(T Arr[], int SIZE)
{
    int m = GetMax<T>(Arr, SIZE);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort<T>(Arr, SIZE, exp);
}

int main()
{
    Sort<int> Sorting;
    Sorting.Display();

    Sorting.SelectionSort(Sorting.ReturnAddress(), Sorting.ReturnSize());
    cout << endl;

    Sorting.Display();
    cout << "\nHello Death ";
    return 0;
}
