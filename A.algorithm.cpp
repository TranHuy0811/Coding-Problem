#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a2,b1,b2,xnode,ynode,A[100001][100001],heu[100001][1000001]
int main()
{
    vector<int> F(n*m,0);
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> H;
    map<pair<int,int>,int> B;
    cin >> n >> m;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> A[j][i];
            int huy=sqrt((a2-j)*(a2-j)+(b2-i)*(b2-1));
            heu[j][i]=huy;
           // H.push(make_tuple(huy,j,i));
        }

    }
       while(H.empty()==0)
       {
          xnode=get<1>(H.top());
          ynode=get<2>(H.top());
          cost=get<0>(H.top());
          B.insert({xnode,ynode,1});
          H.pop();
          if(F[xnode+ynode*n]<F[xnode+(ynode-1)*n]+1&&A[xnode][ynode+1]==0&&B.count(xnode,ynode)==0)
          {
             F[xnode+ynode*n]=F[xnode+(ynode-1)*n]+1
             H.push(make_tuple())
          }

       }

}
