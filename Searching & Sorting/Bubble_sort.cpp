#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int> & nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int flag = true;
        for(int j= 0 ;j<n-i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                flag = false;
                int n = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = n;
            }
        }
        if(false) break;
    }
}
int main()
{
    vector<int> nums={1,3,4,9,1,1,5,6,6};
    nums.push_back(11);
    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
    bubble_sort(nums);
    for(auto i:nums){
        cout<<i<<" ";
    }
    return 0;
}