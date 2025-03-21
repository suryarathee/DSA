#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map< T, list<T> > adj;
    void buildgraph(bool direction)
    {
        int n,m;
        cout<<"Enter the number of Nodes";
        cin>>n;
        cout<<"Enter thr number of Edges";
        cin>>m;
        for(int i=0;i<m;i++)
        {
            T u,v;
            cin>>u>>v;
            addEdge(u,v,direction);
        }
    }
    void addEdge(T u,T v,bool direction)
    {
        //direction false->undirected;
        //direction true->directed;
        adj[u].push_back(v);
        if(!direction)
        {
          adj[v].push_back(u);  
        }
    }
    void printadjlist()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto entry:i.second)
            {
                cout<<entry<<" "; 
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph<char> g;
    g.buildgraph(false);
    g.printadjlist();
    return 0;
}