#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 100010
#define rank rank233
#define son(x) (s[f[x]][1]==x)
using namespace std;
int f[N],s[N][2],sz[N],v[N],l[N],t[N]; // t表示最大空闲空间
int n,m,cnt=0,rt=0;
inline int newnode(int p,int len){
    ++cnt; sz[cnt]=1;
    v[cnt]=p; l[cnt]=t[cnt]=len;
    return cnt;
}
inline int ps(int x){
    sz[x]=sz[s[x][0]]+sz[s[x][1]]+1;
    t[x]=max(l[x],max(t[s[x][0]],t[s[x][1]]));
}
inline void rot(int x){
    int p=f[x],g=f[p],d=son(x);
    s[p][d]=s[x][!d]; f[s[p][d]]=p;
    s[x][!d]=p; f[p]=x; f[x]=g;
    if(g) s[g][p==s[g][1]]=x; ps(p); ps(x);
}
inline void splay(int x,int r=0){
    for(int p;(p=f[x])!=r;rot(x))
        if(f[p]!=r && son(x)==son(p)) rot(p);
    if(!r) rt=x;
}
inline int select(int k,int x=rt){
    for(int w;;){
        w=sz[s[x][0]]+1;
        if(w==k) return x;
        if(k<w) x=s[x][0];
        else k-=w,x=s[x][1];
    }
}
inline int rank(int x){
    int r=sz[s[x][0]]+1;
    for(;x;x=f[x])
        if(son(x)) r+=sz[s[f[x]][0]]+1;
    return r;
}
inline int merge(int x,int y){
    if(x&&y){
        y=select(1,y);
        splay(y,rt);
        s[y][0]=x; f[x]=y; ps(y);
        return y;
    } return x+y;
}
inline void insert(int p,int len){
    if(!rt) { rt=newnode(p,len); return; }
    for(int x=rt,d;;){
        d=(p>=v[x]);
        if(!s[x][d]){
            s[x][d]=newnode(p,len);
            f[cnt]=x; splay(cnt); break;
        } else x=s[x][d];
    }
}
inline void link(int x,int y){
    l[x]=max(l[x],v[y]+l[y]-v[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    rt=newnode(0,n);
    for(int o,x,y,z;m--;){
        scanf("%d%d",&o,&x);
        if(o==1){
            if(t[rt]<x) puts("-1");
            else{
                y=x; x=rt;
                for(;;)
                    if(t[s[x][0]]>=y) x=s[x][0];
                    else if(l[x]>=y) break; else x=s[x][1];
                printf("%d\n",v[x]);
                splay(x);
                l[x]-=y; v[x]+=y; ps(x);
                if(l[x]==0) rt=merge(s[x][0],s[x][1]);
            }
        } else {
            scanf("%d",&y);
            o=x; x=rt; z=0;
            for(;x;)
                if(v[x]+l[x]>=o) z=x,x=s[x][0];
                else x=s[x][1];
            if(!z||v[z]>o){ insert(o,y); z=rt; }
            x=z; z=rank(x); splay(x); l[x]+=max(0,(o+y)-(v[x]+l[x]));
            o+=y;
            for(;;){
                if(z==sz[x]) break;
                splay(select(z+1),rt); y=s[x][1];
                if(v[y]>o) break;
                else{ link(x,y); s[x][1]=s[y][1]; f[s[y][1]]=x; ps(x); }
            }
            ps(x);
        }
    }
}