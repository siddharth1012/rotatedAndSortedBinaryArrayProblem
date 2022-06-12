#include<iostream>
using namespace std;

//Recursive function for binary search
int binarySearch(int arr[], int low, int high, int key)
{
    if(high<low)
        return -1;
    
    int mid = low + (high-low)/2;
    
    if(arr[mid]==key)
        return mid;
        
    if(arr[mid]>key)
        return binarySearch(arr, low, mid-1, key);
    
    return binarySearch(arr, mid+1, high, key);
} 

//function to get pivot
int findPivot(int arr[], int low, int high)
{   
    //base case
    if(high<low)
        return -1;
    if(high==low)
        return low;
    int mid = low + (high - low)/2;
    
    if(mid > low && arr[mid]<arr[mid-1])
        return mid;
    if(mid < high && arr[mid+1]<arr[mid])
        return mid+1;
    if(arr[low]>=arr[mid])
        return findPivot(arr, low, mid-1);
    
    return findPivot(arr, mid+1, high);
}

//function to find key in pivoted sorted array
int findKey(int arr[], int n, int key)
{
    int pivot = findPivot(arr,0,n-1);
    
    if(pivot == -1)
        return binarySearch(arr,0,n-1,key);
        
    if(arr[pivot] == key)
        return pivot;
    
    if(arr[0]<=key)
        return binarySearch(arr,0,pivot-1, key);
    return binarySearch(arr,pivot+1,n-1,key);
}

int main()
{
    int arr_size, data;
    
    cin >> arr_size;
    
    cout << endl;
    
    int arr[arr_size];
    
    for (int i=0;i<arr_size;i++)
        cin >> arr[i];
    
    cin >> data; 
    
    
    int index_data = findKey(arr, arr_size, data);
    
    cout << "index of the data is: " << index_data;
    
    return 0;
}