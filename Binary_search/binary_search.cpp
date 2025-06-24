#include<iostream>
using namespace std;
#include<vector>
// Binary search implementation in C++
// Time Complexity: O(log n)
int binary_search(vector<int> arr,int target)
{
    int left = 0,right = arr.size()-1;
    int mid = left+(right-left)/2;
    while(left <= right)
    {
        if(arr[mid] == target)
        {
            return mid; // Target found
        }
        else if(arr[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
        mid = left + (right - left) / 2; // Update mid
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;
    cout << "Enter the element to search: ";
    cin >> target;
    int result = binary_search(arr, target);
    if(result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }
}