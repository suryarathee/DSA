/*An Equilibrium index is an index in an arr where sum of elements at lower indices is equal to sum of elements at higher indices*/
#include<iostream>
#include<vector>
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
}

int main()
{
    vector<int> arr = {1,3,0,4,-1,1};
    cout<<equilibrium_index(arr);
    return 0;
}
