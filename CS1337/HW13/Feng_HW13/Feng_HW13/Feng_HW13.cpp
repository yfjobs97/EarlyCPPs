//HW13
//Linked list
//
#include <iostream>
#include <cstdlib>

using namespace std;

class NumList
{
private:
	struct ListNode
	{
		int value;
		struct ListNode* next;
	};
	ListNode* head;
public:
	NumList()
	{
		head = nullptr;
	}
	NumList(NumList& obj)
	{
		ListNode* nodePtr;

		nodePtr = obj.head;

		while (nodePtr)
		{
			appendNode(nodePtr->value);

			nodePtr = nodePtr->next;
		}
	}

	~NumList() {};

	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;
	void reverse();
	void search(int);
};

void NumList::appendNode(int num)
{
	ListNode *newNode; // To point to a new node
	ListNode *nodePtr; // To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodePtr = head;

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}

	return;
}

//Insert the value according to the accending order of numbers
void NumList::insertNode(int num)
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = num;


	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}
}

void NumList::deleteNode(int num)
{
	ListNode *nodePtr = nullptr; // To traverse the list
	ListNode *previousNode = nullptr; // To point to the previous node
	// If the list is empty, do nothing.
	if (!head)
		 return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void NumList::displayList() const
{
	ListNode *nodePtr;

	// Position nodePtr at the head of the list
	nodePtr = head;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << "\t";

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	cout << endl;
	return;
}

void NumList::reverse() 
{
	ListNode* nodePtr;

	//Counting the length of the list
	nodePtr = head;
	int SIZE = 0;
	for (SIZE = 0; nodePtr; SIZE++)
	{
		nodePtr = nodePtr->next;

	}

	//Storing the length to an array and store in a reverse order
	nodePtr = head;
	int* values = new int[SIZE];
	for (int i = SIZE -1; i>=0; i--)
	{
		values[i] = nodePtr->value;
		nodePtr = nodePtr->next;
	}

	//Assign the values in the array back to the list
	nodePtr = head;
	for (int i = 0; i < SIZE; i++)
	{
		nodePtr->value = values[i];
		nodePtr = nodePtr->next;
	}
	
	


}

void NumList::search(int target)
{
	ListNode* nodePtr;

	//Counting the length of the list
	nodePtr = head;
	int SIZE = 0;
	for (SIZE = 0; nodePtr; SIZE++)
	{
		nodePtr = nodePtr->next;

	}

	//Storing the length to an array and store in order
	nodePtr = head;
	int* values = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		values[i] = nodePtr->value;
		nodePtr = nodePtr->next;
	}

	//Linear Search
	int found = 0;
	bool searchSTOP = false;
	for (int i = 0; i < SIZE && searchSTOP == false; i++)
	{
		if (values[i] == target)
		{
			found = i;
			searchSTOP = true;
		}
		else
		{
			found = -1;

		}
	}

	//Message of found
	if (found != -1)
	{
		cout << "Number " << target << " is at position " << found << endl;
	}
	else
	{
		cout << found << endl;
		cout << "The result cannot be found." << endl;
	}
		
}


int main()
{
	NumList a;
	//Assign number into the list
	for (int i = 0; i <= 9; i++)
	{
		a.insertNode(i);
	}
	//display the number
	a.displayList();

	//Copy the list to another one
	NumList b(a);
	//Delete several numbers from the list
	for (int i = 0; i <= 5; i++)
	{
		b.deleteNode(i);
	}
	//Reverse the order
	b.reverse();
	//Display the list after operation
	b.displayList();

	//Searching numbers
	b.search(9);
	b.search(3);

	system("pause");
	return 0;
}
