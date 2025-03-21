#include<iostream>
#include<vector>
using namespace std;
//fibonacci without dynamic programming
int fib(int n)
{
    if(n==0||n==1) {return n;}
    else {
        return (fib(n-1)+fib(n-2));
    }
}
//fibonacci with dynamic programming memoization
int fibdpm(int n,vector<int> &dp)
{
    if(dp[n]!=-1) return dp[n];
    if(n==0||n==1) {
        dp.push_back(n);
        dp[n]= n;
        }
    else {
        dp[n]= (fibdpm(n-1,dp)+fibdpm(n-2,dp));
    }
    return dp[n];
}
//fibonacchi using bottom up approch
int fibbu(int n,vector<int> &dp)
{
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//fibonacci series using space optemization
int fibso(int n)
{
    vector<int> prev;
    prev.push_back(0);
    prev.push_back(1);
    for(int i=2;i<=n;i++)
    {
        int temp = prev[0];
        prev[0]=prev[1];
        prev[1] =prev[0]+temp;
    }
    return prev[1];
}
int main()
{
    int n= 0;
    cout<<"Enter the value of n";
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibso(n)<<"\t";
    return 0;
}