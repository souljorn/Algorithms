#include <iostream>
#include <string>

using namespace std;

//Node Class
class Node{
private:
	int data;
	Node* next;
public:
	Node();
	int getData();
	Node* getNext();
	void setData(int num);
	void setNext(Node* next);
};
	Node::Node()
	{
		Node* next = NULL;
		data= 0;
	}
	int Node::getData()
	{
		return data;
	}
	Node* Node::getNext()
	{
		return next;
	}
	void Node::setData(int num)
	{
		this->data = num;
	}
	void Node::setNext(Node* next)
	{
		this->next = next;
	}

//LinkedList class
class LinkedList
{
private:
	Node* head;
	int listLength;
public:

	LinkedList();
	void insert(Node* newNode ,int index);
	void remove(Node* pos, int data);
	~LinkedList();
};
LinkedList::LinkedList()
{
	head->setData(0);

	listLength = 0;
}

void LinkedList::insert(Node* newNode, int index)
{
	//check if index is less than zero or greater than listLength plus an
	//added node
	if(index < 0 || index > listLength + 1)
	{
		cout << " Please enter a valid index" << endl;
	}
	//check if it is the first node in the list
	else if (index == 0 )
	{
		head= newNode;
		listLength++;
	}
	//traverse the list until the correct index is found
	else
	{
		int count = 0;
		Node* temp = head;
		Node* tail = head;
		while (count < index)
		{
			if (count == index)
			{
				temp->setNext(newNode);
				newNode->setNext(tail);
			}
			//traverse temp to position in index
			temp = tail;
			tail = temp->getNext();

			count++;
		}
	}
}//func
int main(){
	LinkedList list;
	Node* n1 = new Node;
	n1->setData(99);

	list.insert(n1, 0);

}
