#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int solveMemo(vector<int> &arr,int x,vector<int> &dp)
{
    if (x == 0) return 0;
    if(x<0) return INT_MAX;
    if(dp[x]!= -1) return dp[x];
    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        int ans = solveMemo(arr,x-arr[i],dp);
        if(ans != INT_MAX){
            mini = min( mini,1+ans);
        }
    }
    return mini;
    
}
int solve_recursion(vector<int> arr,int x)
{
    if (x == 0) return 0;
    if(x<0) return INT_MAX;
    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        int ans = solve_recursion(arr,x-arr[i]);
        if(ans != INT_MAX){
            mini = min( mini,1+ans);
        }
    }
    return mini;
    
}
int main()
{
    int x = 10;
    vector<int> num = {2,4,5};
    vector<int> dp(x+1,-1);
    int ans = solveMemo(num,x,dp); 
    if( ans == INT_MAX)
       return -1;
    else 
       cout<<ans;  
    return 0;    
}