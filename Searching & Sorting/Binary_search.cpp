#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a = 10;
    vector<int> arr = { 2, 3 ,4, 7 ,10, 11};
    int n = arr.size();
    int low = 0;
    int high = n -1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == a){
            cout<<"Element found at :"<<mid;
            return 0;
        }
        else if(arr[mid]>a){
            high = mid - 1;
        }
        else if(arr[mid]<a){
            low = mid + 1;
        }
    }
    cout<<"Number not found";
    return 0;
}