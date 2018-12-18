#include<bits/stdc++.h>
using namespace std;
int main()
{
    int edg,nod,x,y;
    cout<<"Enter edge and node numbers:"<<endl;
    cin>>edg>>nod;
    vector<int>adj[2*edg+1];
    for(int i=0; i<edg; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=nod; i++)
    {

        cout<<"Adjancy list of node"<<i<<":";
        for(int j=0; j<adj[i].size(); j++)
        {

            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
