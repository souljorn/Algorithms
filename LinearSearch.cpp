//linear search algorithm

#include <iostream>

using namespace std;

int linearSearch(int array[], int size, int searchValue)
{
	for (int i = 0; i < size; i++)
	{
		if (searchValue == array[i])
		{
			return i;
		}
	}
	return -1;
}//linearSearch

int main()
{
	int a[] = { 15, 23, 7, 45, 87, 16 };

	int userValue;

	cout << "Enter an integer: " << endl;
	cin >> userValue;

	int result = linearSearch(a, 6, userValue);

	if (result >= 0)
	{
		cout << "The number " <<
			a[result] << " was found";
	}
	else
	{
		cout << "The number " << userValue << " was not found." << endl;
	}

}
