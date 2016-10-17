#include <iostream>
#include <string>
#include <ctime>

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
	Node* m_prev;
	Node* m_current;
	int listLength;

public:
	LinkedList();						//Constructor
	int pop();							//Function to remove tail node of linked list
	void pushHead(int data);	//Adds a node to the head
	void push(int data);			//Adds a node to the tail
	int getLength();				//Gets length
	int getNth(int position);		//Gets value in nth position
	void printList();				//Prints Linked List
	bool isEmpty();				//returns a bool if empty
	void deleteNode(int delData);	//deletes node with passed value
	void insertNode(int insertData, int position);	//inserts node with data at position passed
	~LinkedList();					//destructor
};

LinkedList::LinkedList()		//Constructor
{
	head = NULL;						//initialize all member variables
	m_prev = NULL;
	m_current = NULL;
	listLength = 0;
}

LinkedList::~LinkedList()		//Destructor
{
	Node *n = this->m_prev, *current = NULL; //initialization part

	    while(n)                               //start cleanup of nodes of the list
	    {
	        current = n;
	        n=n->next;
	        delete(current);
	    }

	    delete head, m_prev, m_current, listLength ;

}

void LinkedList::push(int data)		//Push Function
{													//Pushes a value data onto the end of the list
	Node* n = new Node;
	n->next = NULL;
	n->data = data;

	if (head != NULL)
	{
		m_current = head;
		while (m_current->next != NULL)
		{
			m_current = m_current->next;
		}
		m_current->next = n;
	}
	else
	{
		head = n;
	}
}

void LinkedList::pushHead(int data){
	Node* n = new Node;

	n->data = data;
	n->next = head;
	head = n;
}

int LinkedList::pop() {
	{
		Node* delPtr = NULL; //initialize nodes
		m_prev = head;
		m_current = head;

		if (head == NULL){		//Test to make sure the list is not empty
			cout << "List is empty" << endl;
			return NULL;
		}

		else if(head->next == NULL){
			delPtr = head;					// set delPtr to  current pointer
			int temp = delPtr->data;				//set temp to the value of the data held
			head = NULL;					//delete the

			cout << "The value " << temp << " was deleted and list is now empty \n";
			return temp;
		}
		else{
			while (m_current->next != NULL)	//traverse list till we m_current next hits null
			{
				m_prev = m_current;
				m_current = m_current->next;
			}
		}

		m_prev->next = NULL;				//set prev node to be the new tail
		delPtr = m_current;					// set delPtr to  current pointer
		int temp = delPtr->data;				//set temp to the value of the data held
		delete delPtr;							//delete the popped value
		cout << "The value " << temp << " was deleted \n";
		return temp;
	}
}

int LinkedList::getNth(int position)
{
	m_prev = head;
	int count = 0;
	if (position == 0) {
		return m_prev->data;
	}
	else if ((position < 0) || (m_prev == NULL)) {
		return -1;
	}
	else {
		while (position != count)
		{
			m_prev = m_prev->next;
			count++;
		}
	}
	return m_prev->data;
}

int LinkedList::getLength() {
	m_prev = head;
	int count = 0;
	if(head == NULL)
	{
		return 0;
	}
	else{
	while(m_prev != NULL)
	{
		listLength = ++count;
		m_prev = m_prev->next;
	}
	return listLength;
	}
}

void LinkedList::printList() {
	m_prev = head;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else {
		while (m_prev != NULL) {
			cout << m_prev->data << endl;
			m_prev = m_prev->next;
		}
	}
}

bool LinkedList::isEmpty()
{
	if (head== NULL)
		return true;
	else
		return false;
}

void LinkedList::insertNode(int insertData, int position){
	Node* n = new Node();
	n->data = insertData;
	int currentPos = 0;
	if(position == 0)
	{
		pushHead(insertData);
	}
	else  if(head != NULL)
	{
		m_current = head;
		while (m_current->next != NULL && currentPos != position )
		{
			m_prev = m_current;
			m_current = m_current->next;
			currentPos++;
		}
		if(currentPos == position)
		{
			m_prev->next = n;
			n->next  = m_current;
		}
		else if(position==getLength())
		{
			push(insertData);
		}
		else
		{
			cout << "error";
		}
	}
	else
	{
		cout<< "some error\n";
	}
}

void LinkedList::deleteNode(int delData) {
	Node* delPtr = NULL;
	m_prev = head;
	m_current = head;
	while (m_current != NULL && m_current->data != delData)
	{
		m_prev = m_current;
		m_current = m_current->next;
	}
	if (m_current == NULL) {
		cout << delData << "Was not in the list\n";
		delete delPtr;
	}
	else {
		delPtr = m_current;
		m_current = m_current->next;
		m_prev->next = m_current;
		if (delPtr == head)
		{
			head = head->next;
			m_prev = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted \n";
	}
}
int main() {
	LinkedList list;
	int numberOfNodes = 10;
	cout << "Is List Empty: " << (list.isEmpty() ? "true" : "false")  << endl;

	list.printList();

	int start_s = clock();
	for (int i = 1; i < numberOfNodes; i++)
		list.push(i);
	int stop_s = clock();
	cout << "time to create " << numberOfNodes << " nodes: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << " miliseconds"<<endl;
	list.printList();
	list.deleteNode(9);
	list.deleteNode(8);
	list.deleteNode(7);
	list.deleteNode(1);

	list.printList();
	start_s = clock();
	list.printList();
	stop_s = clock();
	cout << "time to print "<< numberOfNodes <<" nodes: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << " miliseconds" << endl;

	list.printList();
	cout << "List Length: "<<list.getLength() << endl;

	list.insertNode(11,0);
	for(int i = 0; i < 100; i++)
	{
		list.insertNode(i,i);
	}

	for(int i = 0; i < 100; i++)
	{
		list.deleteNode(i);
	}

	list.printList();
	while(list.getLength() >0){
	list.pop();
	list.printList();
	}
}
