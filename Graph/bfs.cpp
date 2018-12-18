#include<bits/stdc++.h>
using namespace std;
vector<int>g[10000];
int level[20];
bool visit[20];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    level[s]=0;
    visit[s]=true;
    while(!q.empty())
    {
        int p=q.front();
        cout<<p<<" ";
        q.pop();
        for(int i=0; i<g[p].size(); i++)
        {
            if(visit[g[p][i]]==false)
            {
                q.push(g[p][i]);
                visit[g[p][i]]=true;
                level[g[p][i]]=level[p]+1;
                cout<<level[g[p][i]]<<" ";
            }
        }
    }

}
int main()
{
    int edg,nod,x,y,s;
    cout<<"Enter node and edge numbers:"<<endl;
    cin>>nod;
    cin>>edg;
    for(int i=0; i<edg; i++)
    {
        cin>>x;                             // 0 1
        cin>>y;                             // 0 2
        g[x].push_back(y);                  // 1 3
       // g[y].push_back(x);                 //2 3
        //2 4
        //3 5
    }
    cout<<"Enter source node"<<endl;
    cin>>s;
    cout << "Following is Breadth First Traversal "
         << "(starting from source)"<<s<<endl;
    bfs(s);
    cout<<endl;
    for(int i=0; i<nod+1; i++)
        cout<<level[i]<<" ";
    return 0;
}
