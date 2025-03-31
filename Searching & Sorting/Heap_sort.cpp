/* This is the technique based on binary heap data-structure and optemizaion of selection sort
Time Complexity:-O(nLogn)
We can find the max element in O(log n)*/
#include<iostream> 
#include<vector>
using namespace std;
void heapify( vector<int>&arr,int n,int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if( l<n && arr[l] > arr[largest]) largest = l;
    if( r<n && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0;i--){
        heapify(arr,n,i);
    }
    for(int i = n - 1;i > 0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
int main()
{
    vector<int> arr = {3,65,34,7,32,0,1};
    heap_sort(arr);
    for(size_t i =  0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}