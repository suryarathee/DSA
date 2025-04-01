/* Quicksort is a sorting algorithm based on Divide and conquer that picks an element and pivot and partisions the given array by placing the pivot at correct position*/
#include<iostream>
#include<vector>
using namespace std;
int partision_hoare(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i = low -1;
    int j = high +1;
    while(true){
    do{
        i++;
    }while(arr[i]<pivot);
    do{
        j--;
    }while(arr[j]>pivot);
    if(i>=j) return j;
    swap(arr[i],arr[j]);
}
}
int partision(vector<int> & arr,int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low ; j <= high -1 ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(vector<int> &arr,int low,int high){
    if(low<high)
    {
        int par = partision(arr,low,high);
        quicksort(arr,low,par-1);
        quicksort(arr,par+1,high);
    }
}
int main()
{
    vector<int> arr = {5,2,9,1,7,3,6};
    quicksort(arr,0,arr.size()-1);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}