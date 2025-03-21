#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map< T, list<T> > adj;
    int vertex=0,edges=0;
    void buildgraph(bool direction)
    {
        cout<<"Enter the number of Nodes";
        cin>>vertex;
        cout<<"Enter thr number of Edges";
        cin>>edges;
        for(int i=0;i<edges;i++)
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
    void bfs(T source)
    {
        unordered_map<T,bool> visited;
        queue<T> q;
        vector<T> ans;
        q.push(source);
        visited[source]==true;
        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            //store front node in ans;
            ans.push_back(frontnode);
            // transverse all neighbours of front node
            for(auto i:adj[frontnode])
            {
                if(!visited[i]) q.push(i);
                visited[i]=true;
            }
        }
        ans.pop_back();
        for( auto j:ans)
        {
            cout<<j<<" ";
        }
    }
};
int main()
{
    graph<char> g;
    g.buildgraph(false);
    //g.printadjlist();
    char a;
    cout<<"enter source node";
    cin>>a;
    g.bfs(a);
    return 0;
}