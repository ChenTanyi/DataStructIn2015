#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#define MAXN 110000*2
using namespace std;
struct node
{
    int y,next;
    long long l;
};
int flag[MAXN]={0};
int n,p;
int next[MAXN]={0};
node ee[MAXN];
int t=0;
node e[MAXN]={0};
int top=0;
long long ans=0;
int pp[MAXN];
void linkk(int x,int y,long long l)
{
    e[++top].y=y;
    e[top].l=l;
    e[top].next=next[x];
    next[x]=top;
}

bool cmp(node a,node b)
{
    if (a.next!=b.next) return (a.next>b.next);
    return (a.l>b.l);
}

void init()
{
    int x,y;
    long long l;
    cin>>n>>p;
    for (int i=0; i<n-1; ++i)
    {
        cin>>x>>y>>l;
        ee[t].y=x;
        ee[t].l=y;
        ee[t].next=l;
        t++;
        ee[t].y=y;
        ee[t].l=x;
        ee[t].next=l;
        t++;
    }
    sort(ee,ee+t,cmp);
   // for (int i=0; i<t; ++i)
   //     cout<<ee[i].y<<' '<<ee[i].l<<' '<<ee[i].next<<endl;
    for (int i=0; i<t; ++i)
        linkk(ee[i].y,ee[i].l,ee[i].next);
   // for (int i=0; i<n; ++i)
     //   for (int j=next[i];j;j=e[j].next)
       //     cout<<i<<' '<<e[j].y<<' '<<e[j].l<<endl;
   // for (int i=1; i<=top; ++i)
     //   cout<<e[i].y<<' '<<e[i].l<<' '<<e[i].next<<endl;
}

void Search(int now,int pa)
{
    if (now<0) return;
    flag[now]=1;
    pp[now]=pa;
    if (now==p){cout<<ans<<endl;exit(0);}
    for (int i=next[now];i;i=e[i].next)
    if (!flag[e[i].y])
    {
        ans+=e[i].l;
        Search(e[i].y,now);
        ans+=e[i].l;
    }
}

void work()
{
    Search(0,-1);
}

int main()
{
    init();
    work();
    return 0;
}
