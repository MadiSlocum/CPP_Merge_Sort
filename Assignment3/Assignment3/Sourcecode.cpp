//MADI SLOCUM
//MERGE SORT ASSIGNMENT
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 3; //number of elements in array

void merge(int list[], int low, int upper, int mid);
void mergeSort(int list[], int low, int upper);

int main()
{
	int list[MAX] = { 3, 2 , 5 };

	

	cout << "Before Sort: " << endl;

	for (int index = 0; index < MAX; index++)
	{
		cout << list[index] << endl;
	}
	cout << endl << endl;


	merge(list, 0, 2, 1);
	mergeSort(list, 0, 1);

	cout << "After Sort:  " << endl;
	for (int index = 0; index < MAX; index++)
	{
		cout << list[index] << endl;
	}
	cout << endl << endl;



	char letter;
	cin >> letter;


	return 0;
}

void merge(int list[], int low, int upper, int mid)
{
	int p1 = low;
	int p2 = upper;
	int p3 = 1;
	int p4 = mid + 1;
	int temp[MAX];

	while ((p1 <= mid) && ((mid + 1) <= upper))
	{
		if (list[p1] < list[(mid + 1)])
		{
			temp[p3] = list[p1];
			p1 += 1;

		}
		else
		{
			temp[p3] = list[(mid + 1)];
		}
		p3 += 1;
	} //end of while loop

	if (p1 > mid)
	{
		for (int count = (mid + 1); count <= upper; count++)
		{
			temp[p3] = list[count];
			p3 += 1;
		}
	}
	else
	{
		for (int count = p1; count <= mid; count++)
		{
			temp[p3] = list[count];
			p3 += 1;

		}
	}

	for (int count = low; count <= upper; count++)
	{
		list[count] = temp[count];
	}

}

void mergeSort(int list[], int low, int upper)
{
	int mid;
	if (low > upper)
	{
		mid = (low + upper) / 2;
		mergeSort(list, low, mid);
		mergeSort(list, (mid + 1), upper);
		merge(list, low, upper, mid);
	}
}