#include <iostream>

using namespace std;

//=====================================================================
struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l = 0, Node* r = 0)
    {
    	data = d;
    	left = l;
    	right = r;
	}
};

void print(Node *n)
{
	if(!n) return;
	print(n->left);
	cout << " " << n->data;
	print(n->right);
}

void serial(Node *n)
{
	if (n == 0)
	{
		cout << " NULL";
	}
	else
	{
		cout << '(' << n->data << ' ';
		serial(n->left);
		serial(n->right);
		cout << ')'; 
	}
}

//=====================================================================
int main()
{
	
	//Node* left_child = new Node(3);
	//Node* right_child = new Node(9);
	//Node* root = new Node(5, left_child, right_child);
	//root = new Node(5, new Node(3), new Node(9));
	//print(root);
	
	//============================================
	// Build the tree here:
	Node* node_1 = new Node(1);
	Node* node_4 = new Node(4);
	Node* node_6 = new Node(6);
	Node* node_9 = new Node(9, node_6);
	Node* node_3 = new Node(3, node_1, node_4);
	
	Node* root = new Node(5, node_3, node_9);
	
	print(root);
	//============================================
	
	serial(root); cout << endl;
    system("pause");
	return 0;
}
/*
Serialized tree:

(5 (3 (1 NULL NULL) (4 NULL NULL)) (9 (6 NULL NULL) NULL))

*/
