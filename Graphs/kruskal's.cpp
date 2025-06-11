#include<iostream>
#include<unordered_map>
#include<set>
#include<stack>
#include<vector>
#include<list>
using namespace std;
class graph
{
    public:
    int edges,vertex;
    bool is_weighted=false,is_directed=false;
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u,int v,bool directed,int w)
    {
        adj[u].push_back(make_pair(v,w));
        if(!directed)
        {
           adj[u].push_back(make_pair(u,w)); 
        }
    }
    void buildgraph()
    {
        cout<<"enter the number of veterices";
        cin>>vertex;
        cout<<"enter the number of Edges";
        cin>>edges;
        cout<<"Is the graph directed enter false->0,true->1";
        cin>>is_directed;
        cout<<"Is the graph weighted enter false->0,true->1";
        cin>>is_weighted;
        for(int i=0;i<edges;i++)
        {
            int u,v,w=1;
            cin>>u>>v;
            if(is_weighted) cin>>w;
            addEdge(u,v,is_directed,w);
        }
    }
    void printadjlist()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<"["<<j.first<<","<<j.second<<"]"<<endl;
            }
        }
    }
    
};