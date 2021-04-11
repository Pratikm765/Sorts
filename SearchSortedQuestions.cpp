//============================================================================
// Name        : BASIC.cpp
// Author      : Pratik Mhatre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <set>

#define MAX 10

using namespace std;

void printArray(int arr[])
{
	for(int i=0;i<MAX;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

bool pairExists(int arr[],int n,int k)
{
	int start=0;
	int end=n-1;

	while(start<end)
	{
		if(arr[start]+arr[end]==k)
		{
			cout<<start<<" "<<end<<endl;
			return true;
		}
		else if(arr[start]+arr[end]>k)
			end--;
		else
			start++;
	}
	return false;
}

void printPairs(int arr[], int arr_size, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr_size; i++) 
    {
        int temp = sum - arr[i];
 
        if (s.find(temp) != s.end())
            cout << "Pair with given sum "
                 << sum << " is (
                           " << arr[i] << ",
                " 
                    << temp << ")" << endl;
 
        s.insert(arr[i]);
    }
}


int totalPair(int arr[],int n,int k)
{
	int count=0;
	int start=0;
	int end=n-1;

	while(start<end)
	{
		if(arr[start]+arr[end]==k)
		{
			cout<<start<<" "<<end<<endl;
			count++;
			start++;
			end--;
		}
		else if(arr[start]+arr[end]>k)
			end--;
		else
			start++;
	}
	return count;
}

bool tripletExists(int arr[],int n, int k)
{
	for(int start=0;start<n-2;start++)
	{
		int second=start+1;
		int end=n-1;

		while(second<end)
		{
			if(arr[start]+arr[second]+arr[end]==k)
			{
				cout<<start<<" "<<second<<" "<<end<<endl;
				return true;
			}
			else if(arr[start]+arr[second]+arr[end]>k)
				end--;
			else
				second++;
		}
	}
	return false;
}

int totalTriplet(int arr[],int n, int k)
{
	int count=0;
	for(int start=0;start<n-2;start++)
	{
		int second=start+1;
		int end=n-1;

		while(second<end)
		{
			if(arr[start]+arr[second]+arr[end]==k)
			{
				cout<<start<<" "<<second<<" "<<end<<endl;
				count++;
				second++;
				end--;
			}
			else if(arr[start]+arr[second]+arr[end]>k)
				end--;
			else
				second++;
		}
	}
	return count;
}

int tripletExistsNew(int arr[],int n)
{
	int count=0;
	for(int end=n-1;end>=2;end--)
	{
		int start=0;
		int second=end-1;

		while(start<second)
		{
			int startSq=arr[start]*arr[start];
			int secondSq=arr[second]*arr[second];
			int endSq=arr[end]*arr[end];
			if(startSq+secondSq==endSq)
			{
				cout<<arr[start]<<" "<<arr[second]<<" "<<arr[end]<<endl;
				start++;
				second--;
				count++;
			}
			else
			{
				if(startSq+secondSq<endSq)
					start++;
				else
					second--;
			}
		}
	}
	return count;
}
int main()
{
	int option;
	int arr[]={11,47,32,23,3,9,67,54,72,99};
	int arr2[]={4,8,13,19,23,37,44,52,58,69};
	int arr3[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
		16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

	while(true)
	{
		cout<<"Enter option: ";
		cin>>option;

		switch(option)
		{
		case 0:
			exit(0);
		case 1:
			printArray(arr);
			break;
		case 2:
			cout<<pairExists(arr2,10,51)<<endl;
			break;
		case 3:
			cout<<tripletExists(arr2,10,129)<<endl;
			break;
		case 4:
			cout<<totalPair(arr2,10,27)<<endl;
			break;
		case 5:
			cout<<totalTriplet(arr2,10,129)<<endl;
			break;
		case 6:
			cout<<tripletExistsNew(arr3,30)<<endl;
			break;
		}
	}
    return 0;
}
