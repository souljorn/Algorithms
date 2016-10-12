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

	LinkedList();


	int pop();
	void pushHead(int data);
	void push(int data);
	int getLength();
	void setLength(int length);
	int getNth(int position);
	void printList();
	bool isEmpty();
	void deleteNode(int delData);
	void insertNode(int insertData, int position);
	~LinkedList();
};
LinkedList::LinkedList()
{
	head = NULL;
	m_prev = NULL;
	m_current = NULL;
	listLength = 0;
}
LinkedList::~LinkedList()
{
}


void LinkedList::push(int data)
{
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
	Node* temp = head;

	int i = 0;
	int length = getLength();
	cout << length << endl;
	while (i < length)
	{
		temp = temp->next;
	}

	int tempData = temp->data;
	delete temp;

	return tempData;
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

void LinkedList::setLength(int length)
{
	listLength = length;
}

int LinkedList::getLength() {
	m_prev = head;
	int count = 0;
	while(m_prev != NULL)
	{
		setLength(++count);
		m_prev = m_prev->next;
	}
	return listLength;
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

	list.printList();

}
