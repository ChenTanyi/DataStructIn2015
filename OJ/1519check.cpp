#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MAXN (100000+10)
char s[MAXN];
int n,m;
struct comm
{
    int x,y,no;
    friend bool operator<(comm a,comm b){return a.y<b.y;  }
}ask[MAXN];
int ans[MAXN];
struct node
{
    node *ch[26],*fail,*fa;
    int no;
    node(){Rep(i,26) ch[i]=NULL;fail=NULL;fa=NULL;}
    node(int _no,node *_fa):no(_no),fa(_fa){Rep(i,26) ch[i]=NULL;fail=NULL;}
    node(int _no):no(_no){Rep(i,26) ch[i]=NULL;fail=NULL;fa=NULL;}
}*root=new node(1);
int tot=1;
void ins(node *&x,char c)
{
    if (x->ch[c-'a']==NULL) x->ch[c-'a']=new node(++tot,x);
    x=x->ch[c-'a'];
}
node *q[MAXN];
int stail[MAXN];
int stot=0;
int edge[MAXN],pre[MAXN]={0},next[MAXN]={0},size=0;
void addedge(int u,int v)
{
//  cout<<u<<' '<<v<<endl;
    edge[++size]=v;
    next[size]=pre[u];
    pre[u]=size;
}
void getfail()
{
    int head=1,tail=1;q[1]=root;
    while (head<=tail)
    {
        node *now=q[head];
        Rep(i,26)
            if (now->ch[i])
            {
                q[++tail]=now->ch[i];
                if (now==root) {q[tail]->fail=root;addedge(root->no,q[tail]->no);continue;}
                node *p=now->fail;
                while (p!=root&&!p->ch[i]) p=p->fail;
                if (p->ch[i]==NULL) q[tail]->fail=root,addedge(root->no,q[tail]->no);
                else
                {
                    q[tail]->fail=p->ch[i];
                    addedge(p->ch[i]->no,q[tail]->no);
                }
            }
        head++;
    }
}
int tim=0,l[MAXN],r[MAXN];
void dfs(int x,int fa)
{
//  cout<<"in:"<<x<<' ';
    l[x]=++tim;
    Forp(x)
        if (edge[p]!=fa) dfs(edge[p],x);
    r[x]=++tim;
//  cout<<"out:"<<x<<' ';
}
int lowbit(int x){return x&(-x);}
struct arr_tree
{
    int a[MAXN*2];
    arr_tree(){memset(a,0,sizeof(a));}
    void add(int x,int c)
    {
        for(;x<=tim;x+=x&(-x))
            a[x]+=c;
    }
    int qur(int x)
    {
        int ans=0;
        for(;x;x-=x&(-x))
            ans+=a[x];
        return ans;
    }

}a;
int main()
{
//  freopen("bzoj2434.in","r",stdin);
//  freopen(".out","w",stdout);
    scanf("%s",s+1);n=strlen(s+1);
    root->fa=root->fail=root;
    node *now=root;
    For(i,n)
    {
        switch (s[i])
        {
            case 'P':stail[++stot]=tot;break;
            case 'B':now=now->fa;break;
            default:ins(now,s[i]);
        }
    }
    getfail();
    dfs(root->no,0);
    scanf("%d",&m);
    For(i,m) {scanf("%d%d",&ask[i].x,&ask[i].y);ask[i].no=i;}sort(ask+1,ask+1+m);ask[m+1].no=n+1;
    now=root;
    int now_ask=1,now_str=0;
    For(i,n)
    {
        switch (s[i])
        {
            case 'P':
                {
                    now_str++;
                    while (ask[now_ask].y==now_str)
                    {
                        int x=stail[ask[now_ask].x];
                        ans[ask[now_ask].no]=a.qur(r[x])-a.qur(l[x]-1);
                        now_ask++;
                    }
                    break;
                }
            case 'B':a.add(l[now->no],-1);now=now->fa;break;
            default:now=now->ch[s[i]-'a'];a.add(l[now->no],1);
        }
    }
    For(i,m) printf("%d\n",ans[i]);
    return 0;
}
