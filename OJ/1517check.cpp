#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAX 110000
using namespace std;
char d[2][MAX]={0};
int t[2]={0};
bool check(char &ch){
    return (ch>='0' && ch<='9')?(ch-='0')+1:0;
}

void res(){
    for (int i=0; i<2; ++i)
        for (int j=0; j<t[i]/2; ++j)
            swap(d[i][j],d[i][t[i]-j-1]);
}

void init(){
    char ch;
    while (!check(ch=cin.get()));
    for (int i=0; i<2; ++i){
        d[i][t[i]++]=ch;
        while (check((d[i][t[i]++]=cin.get()))); t[i]--;
        if (!i)while (!check(ch=cin.get()));
    }
    res();
}

bool cmp()
{
    if (t[0]!=t[1]) return t[0]>t[1];
    for (int i=t[1]-1; i>=0; --i)
        if (d[0][i]!=d[1][i])
            return d[0][i]>d[1][i];
    cout<<0 << endl;
    fclose(stdin);
    fclose(stdout);exit(0);
}

void work(){
    int f[2]={!cmp(),cmp()};
    for (int i=0; i<t[f[0]]; ++i)
    {
        int tmp=(i<t[f[1]])?10-d[f[1]][i]:10;
        d[f[0]][i]+=tmp;
        d[f[0]][i+1]+=d[f[0]][i]/10-1;
        d[f[0]][i]%=10;
    }
    for (int i=t[f[0]]-1; i>=0; --i)
        if (d[f[0]][i]){
            t[f[0]]=i+1; break;
        }
    if (f[0]) cout<<'-';
    for (int i=t[f[0]]-1; i>=0; --i)
        cout<<char(d[f[0]][i]+48);
    cout<<endl;
}

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    init();
    work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
