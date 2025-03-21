/*Selection sorting algorithm finds the smallest element and move it to  the front*/
#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int> &nums)
{
    int i=0;
    int min = INT_MAX;
    int minindex = -1;
    while(i<nums.size())
    {
        for(int j=i;j<nums.size();j++)
        {
            if(nums[j]<min){
                min = nums[j];
                minindex = j;
            }
        }
        swap(nums[i],nums[minindex]);
        i++;
    }
}
int main()
{
    vector<int> nums = {64, 34, 25, 12, 22};
    for(auto i:nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    selection_sort(nums);
    for(auto i:nums)
    {
        cout<<i<<" ";
    }
    return 0;
}