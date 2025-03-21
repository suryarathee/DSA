#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int> &nums)
{
    int i= 1;
    int n = nums.size();
    while(i<n)
    {
        int j = i;
        while(j>=0)
        {
            if(nums[j]<nums[j-1])
            {
                swap(nums[j],nums[j-1]);
                j--;
            }
            else{
                break;
            }
        }
        i++;
    }
}
int main()
{
    vector<int> nums = {1,3,54,2,3,53,46,77};
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