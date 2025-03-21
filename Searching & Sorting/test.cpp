#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> dp(10,vector<int>(0,10));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}