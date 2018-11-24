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

//0. class 二叉树
//1. 构建二叉树， 顺便找到root（入度为0）
//2. 从root开始宽度搜索， s[i]记录扫过的顺序
//3.s[i]不对，就是N


class BT
{
    struct node
    {
        int depth;
        int lson,rson;
    };
    public:
        int root;
        node d[120000];
    public:
        BT(){root=0;}
        void ins(int now,int l,int r)
        {
            d[now].lson=l;
            d[now].rson=r;
        }
};


int n,l,r;
int ru[120000];
BT t;
void init()
{
    memset(ru,0,sizeof(ru));
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>l>>r;
        t.ins(i,l,r);
        ru[l]++; ru[r]++;
    }
    for (int i=1; i<=n; ++i)
        if (!ru[i])
        {
            t.root=i;
            break;
        }
}

int q[1000000];
int head=0,tail=0;
void bfs()
{
    q[tail++]=t.root;
    while (head<tail)
    {
        int now=q[head++];
        if (now)
        {
            q[tail++]=t.d[now].lson;
            q[tail++]=t.d[now].rson;
        }
    }
    for (int i=0; i<tail; ++i)
        if (q[i]==0 && q[i+1]!=0)
        {
            cout<<"N"<<endl;
            exit(0);
        }
    cout<<"Y"<<endl;
}

int main()
{
    init();
    bfs();
    return 0;
}
