#include <bits/stdc++.h>
#include <climits>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
	int *harr;
	int capacity;
	int heap_size;

public:
	MinHeap(int capacity);

	void MinHeapify(int);

	int parent(int i) { return (i - 1) / 2; }

	int left(int i) { return (2 * i + 1); }

	int right(int i) { return (2 * i + 2); }

	int DeleteMin();

	void Insert(int k);
	int Size()
	{
		return heap_size;
	}
};

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::Insert(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not Insert\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap::DeleteMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

void swap(int *x, int *y)
{
	int Temp = *x;
	*x = *y;
	*y = Temp;
}

int main()
{
	int m, n;
	cin >> m >> n;
	int arr[m][n];
	MinHeap MHeap(m * n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)

			MHeap.Insert(arr[i][j]);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = MHeap.DeleteMin();
	}
	return 0;
}
