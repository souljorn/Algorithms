
#include <iostream>
#include <string>

using namespace std;

//Node Class
struct Node {
	int data = 0;
	Node* next = NULL;
};

//LinkedList class
class LinkedList
{
private:
	Node* head;
	int listLength;
public:

	LinkedList();
	void insert(Node* newNode, int index);
	void remove(Node* pos, int data);
	int pop();
	void push(int data);
	int getLength();
	void setLength(int length);
	Node* getHead();
	void printList();
	bool isEmpty();
	~LinkedList();
};
LinkedList::LinkedList()
{
	head = new Node;	
}
LinkedList::~LinkedList()
{
}

void LinkedList::insert(Node* iNode, int index)
{
	int length = getLength();
	index = index + 1;//Due to offset of head not containing any data 
	//check if index is less than zero or greater than listLength plus an
	//added node
	if (index < 1 || index > length + 1)
	{
		cout << " Please enter a valid index" << endl;
	}
	//check if it is the first node in the list
	else if (isEmpty() && index == 1)
	{
		head->data = iNode->data;
		
	}
	//traverse the list until the correct index is found
	else
	{
		int count = 1;
		Node* tempNode = getHead();	//Temp Node
		Node* tailNode = getHead();	//Tail Node
		while (count < index)
		{
			if (count == index)
			{
				tempNode->next = iNode;
				iNode->next = tailNode;
			}
			//traverse temp to position in index
			tempNode = tailNode;
			tailNode = tempNode->next;
			count++;
		}
	}
}//func
void LinkedList::push(int data)
{
	Node* iNode = new Node;
	iNode->data = data;
	Node* cNode;	//creator node 
	Node* tNode = getHead();	//temp node
	Node* tailNode = new Node;
	tailNode = head->next;
	// traverse to end of list
	while (tailNode != NULL)
	{
		tNode = tailNode;
		tailNode = tNode->next;
	}
	tNode->next = iNode;	//Takes last element 
	iNode->next = NULL;		// pointed at by temp and points to
							// new element iNode and point inode->next to NULL
}

Node* LinkedList::getHead() {
	return this->head;
}
void LinkedList::setLength(int length)
{
	listLength = length;
}
int LinkedList::getLength() {
	Node* tempNode = getHead();
	int count = 0;
	while(tempNode != NULL)
	{	
		setLength(count++);
		tempNode = tempNode->next;
	}
	return listLength;
}

void LinkedList::printList() {
	Node* tempNode = head->next;
	if (head->next == NULL)
	{
		cout << "List is empty" << endl;
	}
	else {
		while (tempNode != NULL) {
			cout << tempNode->data << endl;
			tempNode = tempNode->next;
		}
	}
}

bool LinkedList::isEmpty()
{
	if (head->next== NULL)
		return true;
	else
		return false;
}
int main() {
	LinkedList list;
	cout << "Is List Empty: " << (list.isEmpty() ? "true" : "false")  << endl;
	//Node* n1 = new Node;
	//n1->data = 15;
	//list.insert(n1, 0);
	list.printList();
	for (int i = 1; i < 10; i++)
	list.push(i);
	list.printList();
	
	//list.insert(n1, 5);
	list.printList();
	cout << "List Length: "<<list.getLength() << endl;
	
	system("pause");

}
