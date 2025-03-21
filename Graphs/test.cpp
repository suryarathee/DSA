#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,vector<int>> map;
    map[1] = {1,2,3};
    map[2] = {1};
    for(auto i:map)
    {
        cout<<map[i];
    }
    return 0;


}

