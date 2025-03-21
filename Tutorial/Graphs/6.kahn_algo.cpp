#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
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
    vector<int> topologicalsort()
    {
        vector<int> ans;
        queue<int> q;
        unordered_map<int,int> indegree;
        unordered_map<int,bool> visited;
        for(auto i:adj)
        {
            if(!indegree[i.first])
            {
                indegree[i.first]=0;
            }
            for(auto entry:i.second)
            {
                indegree[entry]++;
            }
        }
        
        for(auto i:indegree){
            if(i.second==0)
            {
                q.push(i.first);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node]=true;
            cout<<node;
            ans.push_back(node);
            for(auto i:adj[node])
            {
                --indegree[i];
                if(visited[i]==false&&indegree[i]==0)
                    {
                        q.push(i);
                    }
            }
        }
        return ans;
    }
    vector<int> kahn_algo()//kahn algo use bfs
    {
        vector<int> ans;
        unordered_map<int,bool> visited;
        unordered_map<int,int> indegree;
        queue<int> q;
        for(auto i:adj)
        {
            if(!indegree[i.first])
            {
                indegree[i.first]=0;
            }
            for(auto j:i.second)
            {
                indegree[j]++;
            }
        }
        for(auto i:indegree)
        {
            if(i.second==0)
            {
                q.push(i.first);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visited[node]=true;
            ans.push_back(node);
            for(auto i:adj[node])
            {
                if(!visited[i])
                {
                    indegree[i]--;
                    if(indegree[i]==0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    graph<int> g;
    g.buildgraph(true);
    g.printadjlist();
    vector<int> a=g.kahn_algo();
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    return 0;
}