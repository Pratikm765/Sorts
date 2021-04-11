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

void printArray(int arr[],int n)
{
	cout<<"Array Contents: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void copyArray(int arr[], int temp[], int n)
{
	for(int i=0;i<n;i++)
		temp[i]=arr[i];
}

void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(int arr[], int n)
{
	int temp[n];
	copyArray(arr,temp,n);

	bool swapped;
	for(int i=0;i<n-1;i++)
	{
		swapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(temp[j]>temp[j+1])
			{
				swap(&temp[j],&temp[j+1]);
				swapped=true;
			}
		}
		if(swapped== false)
			break;
	}
	printArray(temp,n);
}

void selectionSort(int arr[], int n)
{
	int temp[n];
	copyArray(arr,temp,n);

	int min_idx;
	for(int i=0;i<n;i++)
	{
		min_idx=i;
		for(int j=i+1;j<n;j++)
		{
			if(temp[min_idx]>temp[j])
				min_idx=j;
		}
		swap(&temp[i],&temp[min_idx]);
	}
	printArray(temp,n);
}

void insertionSort(int arr[], int n)
{
	int temp[n];
	copyArray(arr,temp,n);

	for(int i=1;i<n;i++)
	{
		int key=temp[i];
		int j;
		for(j=i-1;j>=0 && temp[j]>key;j--)
		{
			temp[j+1]=temp[j];
		}
		temp[j+1]=key;
	}

	printArray(temp,n);
}

void mergeOptimized(int arr[],int l, int m, int r)
{
	for(int i=r;i>=m+1;i--)
	{
		int last=arr[m];
		int j;
		for(j=m-1;j>=l && arr[j]>arr[i];j--)
		{
			arr[j+1]=arr[j];
		}
		if(j!=m-1 || last>arr[i])
		{
			arr[j+1]=arr[i];
			arr[i]=last;
		}
	}
}

void merge(int arr[],int l, int m, int r)
{
	int n1=m-l+1;
	int n2=r-m;

	int left[n1];
	int right[n2];

	for(int i=0;i<n1;i++)
		left[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[m+1+j];

	int i=0;
	int j=0;
	int k=l;

	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k]=left[i];
		k++;
		i++;
	}

	while(j<n2)
	{
		arr[k]=right[j];
		k++;
		j++;
	}

}

void mergeMoreOptimized(int arr[], int l, int m, int r, int maxele)
{
	int i=l;
	int j=m+1;
	int k=l;

	while(i<=m && j<=r)
	{
		if(arr[i]%maxele<=arr[j]%maxele)
		{
			arr[k]+=(arr[i]%maxele)*maxele;
			i++;
		}
		else
		{
			arr[k]+=(arr[j]%maxele)*maxele;
			j++;
		}
		k++;
	}

	while(i<=m)
	{
		arr[k]+=(arr[i]%maxele)*maxele;
		k++;
		i++;
	}

	while(j<=r)
	{
		arr[k]+=(arr[j]%maxele)*maxele;
		k++;
		j++;
	}

	for(int i=l;i<=r;i++)
		arr[i]/=maxele;
}
void MergeSort(int arr[],int l, int r, int maxele)
{
	if(l>=r)
		return;

	int mid=l+(r-l)/2;
	MergeSort(arr,l,mid,maxele);
	MergeSort(arr,mid+1,r,maxele);
	mergeMoreOptimized(arr,l,mid,r,maxele);
}

void mergeSort(int arr[],int n)
{
	int temp[n];
	copyArray(arr,temp,n);
	int maxele = *max_element(arr, arr+n) + 1;

	MergeSort(temp,0,n-1,maxele);

	printArray(temp,n);
}

int partition(int arr[], int l, int r)
{
	int pivot=arr[r];
	int i= l-1;

	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}

int partitionNew(int arr[],int l, int r)
{
	int pivot=arr[l];
	int i=l;
	int j=r;

	while(i<j)
	{
		do
		{
			i++;
		}while(arr[i]<=pivot);

		do
		{
			j--;
		}while(arr[j]>pivot);

		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[l],&arr[j]);
	return j;
}

void QuickSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int pi=partitionNew(arr,l,r);
		QuickSort(arr,l,pi-1);
		QuickSort(arr,pi+1,r);
	}
}

void quickSort(int arr[], int n)
{
	int temp[n];
	copyArray(arr,temp,n);

	QuickSort(temp,0,n-1);

	printArray(temp,n);
}

void threeWayPartitioning(int arr[], int l, int r,int& i, int& j)
{
	i=l-1;
	j=r;

	int p=l-1;
	int q=r;

	int pivot=arr[r];

	while(true)
	{
		while(arr[++i]<pivot)
			;

		while(arr[--j]>pivot)
			if(j==l)
				break;

		if(i>=j)
			break;

		swap(&arr[i],&arr[j]);

		if(arr[i]==pivot)
		{
			p++;
			swap(&arr[i],&arr[p]);
		}

		if(arr[j]==pivot)
		{
			q--;
			swap(&arr[j],&arr[q]);
		}
	}

	swap(&arr[i],&arr[r]);

	j=i-1;
	for(int k=l;k<p;k++,j--)
		swap(&arr[k],&arr[j]);

	i=i+1;
	for(int k=r-1;k>q;k--,i++)
		swap(&arr[k],&arr[i]);

}

void threeWayQuickSort(int arr[],int l,int r)
{
	if(r<=l)
		return;

	int i,j;
	threeWayPartitioning(arr,l,r,i,j);
	threeWayQuickSort(arr,l,j);
	threeWayQuickSort(arr,i,r);
}

void threeWaySort(int arr[],int n)
{
	int l=0;
	int m=0;
	int h=n-1;

	while(m<=h)
	{
		switch(arr[m])
		{
			case 1:
				swap(&arr[l++],&arr[m++]);
				break;
			case 4:
				m++;
				break;
			case 9:
				swap(&arr[h--],&arr[m]);
				break;
		}
	}
}


void threeWayQSort(int arr[],int n)
{
	int temp[n];
	copyArray(arr,temp,n);

	//threeWayQuickSort(temp,0,n-1);
	threeWaySort(temp,n);

	printArray(temp,n);
}

int Cycle_Sort(int arr[], int n)
{
	int swaps=0;
	for(int cycle_start=0;cycle_start<n-1;cycle_start++)
	{
		int item = arr[cycle_start];
		int pos = cycle_start;

		//check number of small element on right side
		for(int i=cycle_start+1;i<n;i++)
			if(arr[i]<item)
				pos++;

		//if no element is there continue cycle
		if(pos==cycle_start)
			continue;

		//duplicate elements
		while(arr[pos]==item)
			pos++;
		
		//if at first dont swap item 
		if (pos != cycle_start)
			swap(&arr[pos],&item);

		while(pos!=cycle_start)
		{
			//begin from cycle again but this time with swapped item
			pos = cycle_start;

			//check number of small element on right side
			for(int i=cycle_start+1;i<n;i++)
				if(arr[i]<item)
					pos++;
			
			//duplicate elements
			while(arr[pos]==item)
				pos++;
			
			//if not eq item swap
			if (item != arr[pos])
			{
			  swaps++;
			  swap(&arr[pos],&item);
			}
		}
	}
	return swaps;
}

void cycleSort(int arr[],int n)
{
	int temp[n];
	copyArray(arr,temp,n);

	Cycle_Sort(temp,n);

	printArray(temp,n);
}

int minSwaps(int arr[], int N){
    /*Your code here */
    int swaps=0;

    pair<int,int> p1[N];
	
	//fill pair with element and position before sorting
    for(int i=0;i<N;i++)
    {
        p1[i].first=arr[i];
        p1[i].second=i;
    }

    sort(p1,p1+N);
    vector<bool> visited(N,false);
	

    for(int i=0;i<N;i++)
    {
    	//continue if already visited or at perfect position
        if(visited[i] || p1[i].second==i)
            continue;

        int cycle_start=0;
        int j=i;
		
		//start cycle and mark elements visited
        while(!visited[j])
        {
            visited[j]=true;
            j=p1[j].second;
            cycle_start++;
        }
		
		//add to swaps 
        if(cycle_start>0)
        {
            swaps+=cycle_start-1;
        }
    }

	return swaps;
}


vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    vector<int> v1;

    int i=0;
    int j=0;
    int prev=-1;

    while(i<n && j<m)
    {
    	//push element from arr1 increase i
        if(arr1[i]<arr2[j])
        {
            if(prev!=arr1[i])
                v1.push_back(arr1[i]);
            prev=arr1[i];
            i++;
        }
        //push element from arr2 increase j
        else if(arr1[i]>arr2[j])
        {
            if(prev!=arr2[j])
                v1.push_back(arr2[j]);
            prev=arr2[j];
            j++;
        }
        //push element from arr1 increase i and j
        else
        {
            if(prev!=arr1[i])
               v1.push_back(arr1[i]);
            prev=arr1[i];
            i++;
            j++;
        }
    }
	
	//Check if any arr still contains elements
	//Push one by one all
    while(i<n)
    {
            if(prev!=arr1[i])
                v1.push_back(arr1[i]);
            prev=arr1[i];
            i++;
    }

    while(j<m)
    {
            if(prev!=arr2[j])
                v1.push_back(arr2[j]);
            prev=arr2[j];
            j++;
    }

    return v1;
}

vector<int> printIntersection(int arr1[], int arr2[], int N, int M)
{
    //Your code here
    vector<int> v1;

    int i=0;
    int j=0;
    int prev=-1;

    while(i<N && j<M)
    {
    	//If greater in arr2 increase i
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        //If greater in arr1 increase j
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
        //push if common and increase i and j
        else
        {
            if(prev!=arr1[i])
               v1.push_back(arr1[i]);
            prev=arr1[i];
            i++;
            j++;
        }
    }
    return v1;
}

int findPlatform(int arr[], int dep[], int n)
{
	// Your code here

	//sort arrival & departure
	sort(arr,arr+n);
	sort(dep,dep+n);

	int maxP=1;
	int currMax=1;
	int i=1;
	int j=0;

	while(i<n && j<n)
	{
		//increase count if dep is higher
	    if(arr[i]<=dep[j])
	    {
	        currMax++;
	        i++;
	    }
	    else if(arr[i]>dep[j])
	    {
	        currMax--;
	        j++;
	    }
		//if curr is greater assign it
	    if(maxP<currMax)
	        maxP=currMax;
	}
	return maxP;
}

int findMedian(int arr[], int n, int brr[], int m)
{
    // code here
    
    //to achieve O(log(min(n, m))) recall if n is greater
    if(m<n)
		return findMedian(brr,m,arr,n);

	int l=0;
	int h=n;

	while(l<=h)
	{
		//make two partition so that it will be equal
		int partition1=(l+h)/2;
		int partition2=((n+m+1)/2)-partition1;

		//check leftmax and rightmin available for both array partition
		int leftMax1=partition1==0?INT_MIN:arr[partition1-1];
		int rightMin1=partition1==n?INT_MAX:arr[partition1];

		int leftMax2=partition2==0?INT_MIN:brr[partition2-1];
		int rightMin2=partition2==m?INT_MAX:brr[partition2];

		//Ideal partitions
		if((leftMax1<=rightMin2) && (leftMax2<=rightMin1))
		{
			//total no is even max+min/2
			if((n+m)%2==0)
				return (max(leftMax1,leftMax2)+min(rightMin1,rightMin2))/2;
			else
				return max(leftMax1,leftMax2);
		}
		//if leftmax1 is greater search in left part of arr1
		else if(leftMax1>rightMin2)
		{
			h=partition1-1;
		}
		//else search in right part of arr1
		else
		{
			l=partition1+1;
		}
	}
}

int main()
{
	int arr[] = {3,7,1,5,4,8,2,6,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int arr2[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	int menu;

	while(1)
	{
		cout<<"Enter Menu: ";
		cin>>menu;

		switch(menu)
		{
		case 0:
			exit(0);
		case 1:
			printArray(arr,n);
			break;
		case 2:
			bubbleSort(arr,n);
			break;
		case 3:
			selectionSort(arr,n);
			break;
		case 4:
			insertionSort(arr,n);
			break;
		case 5:
			mergeSort(arr,n);
			break;
		case 6:
			quickSort(arr,n);
			break;
		case 7:
			threeWayQSort(arr2,n2);
			break;
		case 8:
			cycleSort(arr2,n2);
			break;

		}

	}

    return 0;
}
