#include <iostream>
using namespace std;
struct Information
{
	int Id;
	string Name, Address;
	string Type;
} Info[11] = {{0, "SJM", "Sector 63", "h"},
			  {1, "Prakash", "Sector, 33", "h"},
			  {2, "Jaypee", "Sector 128", "h"},
			  {3, "Max", "Sector 19", "h"},
			  {4, "Yatharth", "Sector 110", "h"},
			  {5, "NMC", "Sector 30", "h"},
			  {6, "Kailash", "Sector 27", "h"},
			  {7, "Apollo", "Sector 26", "h"},
			  {8, "Singh", " Sector 4", " W "},
			  {9, "Mathura", "Sector 62", " W "},
			  {10, "Maheshwari", "Sector 69", "w"}};

struct Node
{
	int Val;
	Information *Data;
	Node *Next;
};

// Data structure to store a graph edge
struct Edge
{
	int Source, Destination;
};

class Graph
{
	// Function to allocate a new node for the adjacency list
	Node *GetAdjListNode(int Destination, Node *Head)
	{
		Node *newNode = new Node;
		newNode->Val = Destination;

		// point new node to the current Head
		newNode->Next = Head;
		newNode->Data = &Info[Destination];
		return newNode;
	}

	int N; // total number of nodes in the graph

public:
	// An array of pointers to Node to represent the
	// adjacency list
	Node **Head;

	// Constructor
	Graph(Edge Edges[], int n, int N)
	{
		// allocate memory
		Head = new Node *[N]();
		this->N = N;

		// initialize Head pointer for all vertices
		for (int i = 0; i < N; i++)
		{
			Head[i] = nullptr;
		}

		// add Edges to the directed graph
		for (unsigned i = 0; i < n; i++)
		{
			int Source = Edges[i].Source;
			int Destination = Edges[i].Destination;

			// insert at the beginning
			Node *newNode = GetAdjListNode(Destination, Head[Source]);

			// point Head pointer to the new node
			Head[Source] = newNode;

			// uncomment the following code for undirected graph

			newNode = GetAdjListNode(Source, Head[Destination]);

			// change Head pointer to point to the new node
			Head[Destination] = newNode;
		}
	}

	// Destinationructor
	~Graph()
	{
		for (int i = 0; i < N; i++)
		{
			delete[] Head[i];
		}

		delete[] Head;
	}
};

// Function to print all neighboring vertices of a given vertex
void printList(Node *ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->Data->Name << " ";
		ptr = ptr->Next;
	}
	cout << endl;
}

Graph *GraphInsert()
{

	Edge Edges[19] =
		{
			// pair `(x, y)` represents an edge from `x` to `y`
			{0, 5},
			{1, 5},
			{1, 2},
			{2, 3},
			{2, 4},
			{3, 5},
			{3, 6},
			{4, 7},
			{4, 8},
			{5, 9},
			{5, 10},
			{6, 5},
			{7, 6},
			{7, 10},
			{8, 7},
			{8, 0},
			{9, 2},
			{9, 3},
			{10, 9}};

	// total number of nodes in the graph
	int N = 11;

	// calculate the total number of Edges
	int n = 19;

	// construct graph
	Graph *Graphic= new Graph(Edges, n, N);

	// print adjacency list representation of a graph
	for (int i = 0; i < N; i++)
	{
		// print given vertex
		cout << Info[i].Name << " --";

		// print all its neighboring vertices
		printList(Graphic->Head[i]);
	}
return Graphic;
}
// Graph implementation in C++ without using STL
int main()
{
	Graph *G=GraphInsert();
	
	return 0;
}