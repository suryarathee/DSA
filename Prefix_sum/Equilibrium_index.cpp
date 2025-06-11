/*An Equilibrium index is an index in an arr where sum of elements at lower indices is equal to sum of elements at higher indices*/
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*Implementation using prefixsum for O(n) time complexity and O(n) space complexity*/
int equilibrium_index(vector<int> arr)
{
    int n = arr.size();
    vector<int> prev_sum(n,0);
    vector<int> post_sum(n,0);
    for(int i=1;i<n;i++)
    {
        prev_sum[i] = prev_sum[i-1]+arr[i-1];
        post_sum[n-i-1] = post_sum[n-i]+arr[n-i];
    }
    for(int i=0;i<n;i++)
    {
        if((prev_sum[i]-post_sum[i])==0)
        {
            return i;
        }
    }
    return -1;
}
/* IMplementation using prefixsum for Time Complexity:O(n) and Space Comlexity O(1)*/
int optimal_equilibrium_index(vector<int> arr)
{
    int sum = accumulate(arr.begin(),arr.end(),0);
    int n = arr.size();
    for(int i=1;i<n;i++)
    {
        arr[i] = arr[i]+arr[i-1];
    }
    if(arr[0] == sum) return 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]==(sum-arr[i]))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1,3,0,4,-1,1};
    cout<<optimal_equilibrium_index(arr);
    return 0;
}
