#include<bits/stdc++.h>
using namespace std;
int parent[100];
int find_set(int x)
{
    if(parent[x]==x)
        return x;
    else
        find_set(parent[x]);
}
int unite(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fy]=fy;
    return 0;
}
int main()
{
    int tedge,tnode,node1,node2,weight;
    cout<<"Enter edge and node numbers:"<<endl;
    cin>>tedge>>tnode;
    for(int i=1; i<=tedge; i++)
    {
        parent[i]=i;
    }
    vector< pair <int, pair<int,int> > >edges;
    for(int i=0; i<=tedge; i++)
    {
        cin>>node1>>node2>>weight;
        edges.push_back(make_pair(weight,make_pair(node1,node2)));
    }
    sort(edges.begin(),edges.end());
    int mst_edges=0,edge_count=0,mst_weight=0;
    cout<<endl;
    while(mst_edges<tnode-1 || edge_count<tedge)
    {
        node1=edges[edge_count].second.first;
        node2=edges[edge_count].second.second;
        weight=edges[edge_count].first;
        if(find_set(node1)!=find_set(node2))
        {
            mst_weight+=weight;
            cout<<node1<<" "<<node2<<" "<<weight<<endl;
            unite(node1,node2);
            mst_edges++;
        }
        edge_count++;
    }
    cout<<"Minimum cost ="<<mst_weight<<endl;
    return 0;
}
