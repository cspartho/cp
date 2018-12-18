#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mat[100][100];
    int n1,n2,cost,edje,node;
    printf("Enter edje and node list:\n");
    scanf("%d %d",&node,&edje);
    for(int i=0;i<edje;i++)
    {
        printf("Enter n1 n2 cost:\n");
        scanf("%d %d %d",&n1,&n2,&cost);

        mat[n1][n2]=cost;
        mat[n2][n1]=cost;
        printf("mat[%d][%d]=%d\n",n1,n2,cost);
    }


    return 0;
}
