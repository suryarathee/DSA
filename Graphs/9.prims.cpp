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
    void dijkstra(int src)
    {
        vector<int> dist(vertex,INT_MAX);
        set<pair<int,int>> st;
        st.insert(make_pair(0,src));
        dist[src]=0;
        while(!st.empty())
        {
            auto top =*(st.begin());
            int u = top.second;
            int w= top.first;
            st.erase(st.begin());
            for(auto i: adj[u])
            {
                if(w+i.second<dist[i.first]){
                    auto record = st.find(make_pair(dist[i.first],i.first));
                    if(record!=st.end()){
                        st.erase(record );
                    }
                    dist[i.first]=w+i.second;
                    st.insert(make_pair(dist[i.first],i.first));
                }
            }

        }
        for(auto i:dist)
        {
            cout<<i<<" ";
        }
        
        }

};
int main()
{
    graph g;
    g.buildgraph();
    g.printadjlist();
    g.dijkstra(0);
    return 0;
}