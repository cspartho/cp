#include<bits/stdc++.h>
using namespace std;
#define INF 100000
vector<vector<pair<int,int> > >adjlist(1000);
vector<int>dist;
vector<int>par;
int source;
int pathfind(int dest)
{
    if(dest!=source&&par[dest]==-1)
    {
        cout<<"Path Not found"<<endl;
        return 0;
    }
    else if(dest==source)
    {
        cout<<source;
        return 0;
    }
    pathfind(par[dest]);
    cout<<" " <<dest;
}
int main()
{
    int totalnode,node1,node2,weight;
    cout<<"Enter TotalNode"<<endl;
    cin>>totalnode;
    for(int i=0; i<totalnode*2; i++)
    {
        cin>>node1>>node2>>weight;
        adjlist[node1].push_back(make_pair(node2,weight));
    }
    cout<<"Enter Source:"<<endl;
    cin>>source;
    dist.assign(totalnode,INF);
    par.assign(totalnode,-1);
    dist[source]=0;
    for(int i=0; i<totalnode-1; i++)
    {
        for(int u=0; u<totalnode; u++)
        {
            for(int j=0; j<adjlist[u].size(); j++)
            {
                pair<int,int>v=adjlist[u][j];
                if(dist[u]==INF)
                    continue;
                if(dist[u]+v.second<dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    par[v.first]=u;
                }
            }
        }
    }
    bool hascycle=false;
    for(int u=0; u<totalnode; u++)
    {
        for(int j=0; j<adjlist[u].size(); j++)
        {
            pair<int,int>v=adjlist[u][j];
            if(dist[u]=INF)
            {
                continue;
            }
            if(dist[u]+v.second<dist[v.first])
            {
                hascycle=true;
                break;
            }
        }
        if(hascycle)
            break;
    }
    if(hascycle)
    {
        cout<<"The graph has negative cycle"<<endl;
    }
    else
    {
        int dest;
        cout<<"Enter destination";
        cin>>dest;
        cout<<"distance:"<<dist[dest]<<endl;
        pathfind(dest);
    }
    return 0;
}
