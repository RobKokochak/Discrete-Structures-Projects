#include <iostream>
using namespace std;
#include <string>

int main()
{
	const int size = 7;
	int arr[size] = {0,0,0,0,0,0,0};

	cout << "Enter 7 numbers: \n";
	for (int i = 0; i < 7; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		int n = i;

		// shuffle array into max heap for each input
		while (arr[(n-1)/2] < arr[n])
		{
			int temp = arr[(n-1)/2]; //parent node
			arr[(n-1)/2] = arr[n]; //swap nodes
			arr[n] = temp;
			n = (n-1)/2;
		}
	}
	cout << "\nMax-Heap of Input:\n";
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	// Order the array using heap sort
	int unsortedSize = size;
	while (unsortedSize > 0)
	{
		int temp = arr[0]; // last element swaps with first
		arr[0] = arr[unsortedSize-1];
		arr[unsortedSize-1] = temp;

		// comments for testing
		// cout << "\nTop and Bottom swapped " << arr[0] << " with " << 
		// arr[unsortedSize-1] << endl;
		// cout << "Sorted Array:\n";
		// 	for (int i = 0; i < 7; i++)
		// 		cout << arr[i] << " ";
		// 	cout << endl;

		unsortedSize -= 1; // increment sorted size 

		// compare new first element to its children - identify bigger of the two children
		int target = 0; //starting with first element

		while ((arr[target] < arr[(2*target)+1] || arr[target] < arr[(2*target)+2]) && 
			(target < unsortedSize && (2*target)+1 < unsortedSize && (2*target)+2 < unsortedSize)) 
		// if parent is smaller than either child and the end of the unsorted part of 
		// the arry isn't reached
		{
			// identify bigger child
			if (arr[(2*target)+1] > arr[(2*target)+2]) 
				{
					int temp = arr[target]; //swap the values at target and left child
					arr[target] = arr[(2*target)+1];
					arr[(2*target)+1] = temp;
					target = (2*target)+1; //reassign target to keep track 
					// cout << "Swapped " << arr[target] << " with " << arr[(target-1/2)+1] << 
					// " Left Child" << endl;
					// cout << "Sorted Array:\n";
					// for (int i = 0; i < 7; i++)
					// 	cout << arr[i] << " ";
					// cout << endl;
				}
			else
				{
					int temp = arr[target]; //swap the values at target and right child
					arr[target] = arr[(2*target)+2];
					arr[(2*target)+2] = temp;
					target = (2*target)+2; //reassign target to keep track 
					// cout << "Swapped " << arr[target] << " with " << arr[(target-1)/2] << 
					// " Right Child" << endl;
					// cout << "Sorted Array:\n";
					// for (int i = 0; i < 7; i++)
					// 	cout << arr[i] << " ";
					// cout << endl;
				}	
		}
	}
	cout << "Sorted Array: \n";
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
}