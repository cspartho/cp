#include<bits/stdc++.h>
using namespace std;
#define MAXN 300
vector<int> g[MAXN];
bool used[30];
vector<int> comp;
void dfs(int v)
{
    used[v] = true ;
    comp.push_back(v);
    for (size_t i = 0; i < (int) g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

void find_comps(int n)
{


    for (int i = 1; i <=n ; ++i)
        used [i] = false;
    for (int i =1; i <= n ; ++i)
    {

        if (!used[i])
        {
            comp.clear();
            dfs(i);
            cout << "Component:" ;
            for (size_t j = 0; j <comp.size(); ++j)
            {

                cout << ' ' << comp[j];
            }
            cout<<endl;
        }

    }

}
int main()
{
    int edg,nod,x,y,n;
    cout<<"Enter node & edge"<<endl;
    cin>>nod;
    cin>>edg;
    for(int i=0; i<edg; i++)
    {
        cin>>x;
        cin>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s;
    cout<<"Enter Source node"<<endl;
    cin>>s;
    dfs(s);
    find_comps(nod);

    return 0;
}



