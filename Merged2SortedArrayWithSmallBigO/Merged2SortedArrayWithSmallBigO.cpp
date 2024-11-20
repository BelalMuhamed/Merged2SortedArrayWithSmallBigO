
#include <iostream>
#include <algorithm>
using namespace std;
//Merge Two Sorted Arrays
void MergedTwoSortedArray(int Arr01[], int Arr02[], int Sz01, int Sz02, int Result[], int SzResult)
{
	SzResult = Sz01 + Sz02;
	int Indx01 = 0;
	int Indx02 = 0;
	int Res = 0;
	while (Indx01 < Sz01 && Indx02 < Sz02)
	{
		if (Arr01[Indx01] < Arr02[Indx02])
		{
			Result[Res++] = Arr01[Indx01++];
		}
		else
		{
			Result[Res++] = Arr02[Indx02++];
		}

	}
	while (Indx01 < Sz01)
	{

		Result[Res++] = Arr01[Indx01++];
	}
	while (Indx02 < Sz02)
	{

		Result[Res++] = Arr02[Indx02++];
	}




}
//Take Number From The User  
int TakeNumber()
{
	int num;
	bool flag = true;
	do
	{
		cin >> num;
		flag = true;
		if (cin.fail())
		{

			flag = !(cin.fail());
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid number." << endl;
		}
	} while (!flag);
	return num;
}
//Check if the array is sorted
bool CheckTheArraySortedOrNot(int arr[], int size)
{
	bool flag = true;
	int* Cpy = new int[size];
	Cpy = arr;
	sort(arr, arr + size);
	for (int i = 0;i < size;i++)
	{
		flag &= (Cpy[i] == arr[i]);
	}
	return flag;
}
//fill the array 
int* createArray(int size) {
	int* arr = new int[size];

	for (int i = 0; i < size; ++i) {
		cout << "Enter the " << i + 1 << "element \n";
		arr[i] = TakeNumber();
	}
	return arr;
}

int main()

{
	int Sz01, Sz02, Res;

	cout << "Enter the size of the first array \n ";
	Sz01 = TakeNumber();
	cout << "Enter the size of the first array \n ";
	Sz02 = TakeNumber();
	if (Sz01 > 0 && Sz02 > 0)
	{
		Res = Sz01 + Sz02;
		cout << "let 's fill the first array \n";
		int* Arr01 = new int[Sz01];
		Arr01 = createArray(Sz01);
		cout << "let 's fill the seconf array \n";
		int* Arr02 = new int[Sz02];
		Arr02 = createArray(Sz02);
		bool flag = true;
		flag &= CheckTheArraySortedOrNot(Arr01, Sz01);
		flag &= CheckTheArraySortedOrNot(Arr02, Sz02);
		if (flag)
		{
			int* Result = new int[Res];
			MergedTwoSortedArray(Arr01, Arr02, Sz01, Sz02, Result, Res);
			for (int i = 0;i < Res;i++)
			{
				cout << Result[i] << "\n";
			}
		}
		else
		{
			cout << "there aren't sorted array";
		}
	}
	else
	{
		cout << "there is empty array we can't sort it ";
	}

}

