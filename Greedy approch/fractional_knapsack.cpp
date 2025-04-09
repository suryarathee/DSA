#include<iostream>
#include<vector>
#include<unordered_map>
#include<float.h>
#include<algorithm>
using namespace std;
float  fractional_knapsack(vector<int> &weight,vector<int> &profit,int Max_weight)
{
    float pro = 0;
    int n = weight.size();
    vector<pair<int,float>> mp;
    for(int i=0;i<n;i++)
    {
        int ratio = profit[i]/weight[i];
        pair<int,float> p = make_pair(i,ratio);
        mp.push_back(p);
    }
    sort(mp.begin(),mp.end(),[](pair<int,float> &a,pair<int,float> &b){return a.second>b.second;});
    int start = 0;
    while(Max_weight>0){
        int i = mp[start].first;
        int w = weight[i];
        if(w<=Max_weight){
            pro += profit[i];
            start++;
            Max_weight-=w;
        }
        else{
            pro+=Max_weight*mp[start++].second;
            Max_weight = 0;
        }
    }
    
    return pro;
}
int main()
{
    vector<int> profits = {60,100,120};
    vector<int> weights = {10,20,30};
    cout<<"Total pofit is -> "<<fractional_knapsack(weights,profits,30);
    return 0;
}