//Author:shyyhs
//Data:2015/10/11

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n,xx,yy;
int w[30][30];
int dx[4]={-1,-1,1,1};
int dy[4]={-1,0,0,1};
int ww[1000][1000];

class BCJ
{
    private:
        int size;
        int *fa;
    public:
        BCJ(int s):size(s)
        {
            fa=new int[s+10];
            for (int i=0; i<=size; ++i)
                fa[i]=-1;
        }
        ~BCJ(){delete []fa;}
        void Union(int a,int b)
        {
            a=find(a); b=find(b);
            if (a==b) return;
            if (fa[a]>fa[b])
            {
                fa[b]+=fa[a];
                fa[a]=b;
            }else
            {
                fa[a]+=fa[b];
                fa[b]=a;
            }
        }
        int find(int x)
        {
            int k,j,r;
            r=x;
            while (fa[r]>=0) r=fa[r];
            k=x;
            while (k!=r)
            {
                j=fa[k];
                fa[k]=r;
                k=j;
            }
            return r;
        }
};

void change(int x,int &i,int &j)
{
    for (int k=1; k<=n; ++k)
        if (w[k][1]<=x && w[k][k]>=x)
            for (int l=1; l<=k; ++l)
                if (w[k][l]==x)
                {
                    i=k;
                    j=l;
                    return;
                }
}

int q[10000],head=0,tail=0;
int flag[10000];
int pre[10000];

void print()
{
    int now=tail-1;
    int s[100],len=0;
    while (now>=0)
    {
        s[len++]=q[now];
        now=pre[now];
    }
    for (int i=len-1; i>=0; --i)
        cout<<s[i]<<' ';
    exit(0);
}

void bfs(BCJ &U)
{
    flag[xx]=1;
    q[0]=xx;
    tail++;
    pre[0]=-1;
    while (head<tail)
    {
        int i,j,i1,j1;
        int now=q[head++];
        change(now,i,j);
        for (int k=0; k<4; ++k)
        {
            i1=i+dx[k]; j1=j+dy[k];
            if (w[i1][j1]&& (ww[now][w[i1][j1]])&& !flag[w[i1][j1]])
            {
                flag[w[i1][j1]]=1;
                q[tail++]=w[i1][j1];
                pre[tail-1]=head-1;
                if (w[i1][j1]==yy) print();
            }
        }
    }
}


int main()
{
    int x,d;
    cin>>n>>xx>>yy;
    BCJ U(n*n+100);
    int now=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
            w[i][j]=++now;
    int i,j,i1,j1;
    while (1)
    {
        cin>>x>>d;
        change(x,i,j);
        i1=i+dx[d];
        j1=j+dy[d];
        if (w[i1][j1])
        {

            U.Union(x,w[i1][j1]);
            ww[x][w[i1][j1]]=1;
            ww[w[i1][j1]][x]=1;
        }
        if (U.find(xx)==U.find(yy))
        {
            bfs(U);
            return 0;
        }
    }
    return 0;
}
