/* merge sort workd on divide and conquer approch it divided the array into subarrya and then sort them and then joind them*/
/* Time complexity = 2T(n/2)+O(n) spacce complexity  O(n)*/
/*Its stable, performes good even in worst cases,suitable for plalled processing*/
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int left,int mid, int right)
{
    int n1  = mid - left  +1 ;
    int n2 = right - mid ;
    vector<int> left_half(n1),right_half(n2);
    for(int i = 0;i<n1;i++){
        left_half[i] = arr[left + i];
    }
    for(int i= 0;i<n2;i++){
        right_half[i] = arr[mid + 1 + i];
    }
    int i = 0,j = 0;
    int k = left ;
    while(i<n1 && j <n2){
        if(left_half[i] <= right_half[j]){
            arr[k] = left_half[i];
            i++;
        }
        else{
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = left_half[i];i++;k++;
    }
    while(j<n2){
        arr[k]= right_half[j];j++;k++;
    }
}
void merge_sort(vector<int> &arr,int left,int right)
{
    if(left >= right) return ;
    int mid = left +(right -left) / 2 ;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
int main()
{
    vector<int> arr = {12,11,13,5,6,7};
    merge_sort(arr,0,arr.size()-1);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}