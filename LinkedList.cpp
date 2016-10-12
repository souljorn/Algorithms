
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
	Node* m_temp;
	Node* m_current;
	int listLength;
public:

	LinkedList();
	
	
	int pop();
	void push(int data);
	int getLength();
	void setLength(int length);
	int getNth(int position);
	void printList();
	bool isEmpty();
	void deleteNode(int delData);
	~LinkedList();
};
LinkedList::LinkedList()
{
	head = NULL;
	m_temp = NULL;
	m_current = NULL;
	
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
	m_temp = head;
	int count = 0;
	if (position == 0) {
		return m_temp->data;
	}
	else if ((position < 0) || (m_temp == NULL)) {
		return -1;
	}
	else {
		while (position != count)
		{
			m_temp = m_temp->next;
			count++;
			}
		}
	return m_temp->data;
	}
	
void LinkedList::setLength(int length)
{
	listLength = length;
}

int LinkedList::getLength() {
	m_temp = head;
	int count = 0;
	while(m_temp != NULL)
	{	
		setLength(++count);
		m_temp = m_temp->next;
	}
	return listLength;
}


void LinkedList::printList() {
	m_temp = head;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else {
		while (m_temp != NULL) {
			cout << m_temp->data << endl;
			m_temp = m_temp->next;
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

void LinkedList::deleteNode(int delData) {
	Node* delPtr = NULL;
	m_temp = head;
	m_current = head;
	while (m_current != NULL && m_current->data != delData)
	{	
		m_temp = m_current;
		m_current = m_current->next;
	}
	if (m_current == NULL) {
		cout << delData << "Was not in the list\n";
		delete delPtr;
	}
	else {
		delPtr = m_current;
		m_current = m_current->next;
		m_temp->next = m_current;
		if (delPtr == head)
		{
			head = head->next;
			m_temp = NULL;
		}

		delete delPtr;
		cout << "The value " << delData << " was deleted \n";
	}
}
int main() {
	LinkedList list;
	int numberOfNodes = 10;
	cout << "Is List Empty: " << (list.isEmpty() ? "true" : "false")  << endl;
	Node* n1 = new Node;
	n1->data = 15;
	
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
	for (int i = 0; i < list.getLength(); i++)
	cout << "The data in postion " << i << " is " << list.getNth(i) << endl;
	system("pause");

}
