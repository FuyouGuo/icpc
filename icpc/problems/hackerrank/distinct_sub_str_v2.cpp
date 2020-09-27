#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
 
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
 
const int MAXN = 1000000+5;
 
char str[MAXN];
int N,sa[MAXN],tax[MAXN],M;
int pool1[MAXN],*rk = pool1,pool2[MAXN],*tp = pool2;
int height[MAXN];
int heightSUM[MAXN];
int saSUM[MAXN];
int ansSUM[MAXN];
 
inline void sort(){
    FOR(i,0,M) tax[i] = 0;
    FOR(i,1,N) tax[rk[i]]++;
    FOR(i,1,M) tax[i] += tax[i-1];
    ROF(i,N,1) sa[tax[rk[tp[i]]]--] = tp[i];
}
 
inline void SuffixSort(){
    M = 75;
    FOR(i,1,N) rk[i] = str[i]-'0'+1,tp[i] = i;
    sort();
    for(int w = 1,p = 0;p < N;w <<= 1,M = p){
        p = 0;
        FOR(i,1,w) tp[++p] = N-w+i;
        FOR(i,1,N) if(sa[i] > w) tp[++p] = sa[i]-w;
        sort();
        std::swap(tp,rk);
        rk[sa[1]] = p = 1;
        FOR(i,2,N) rk[sa[i]] = (tp[sa[i-1]] == tp[sa[i]] && tp[sa[i-1]+w] == tp[sa[i]+w]) ? p : ++p;
    }
}

inline void getHeight(){
    int j,k = 0;
    FOR(i,1,N){
        if(k) --k;
        int j = sa[rk[i]-1];
        while(str[i+k] == str[j+k]) ++k;
        height[rk[i]] = k;
    }
}
 
int main(){
    int q;
    scanf("%d%d",&N,&q);
    scanf("%s",str+1);
    SuffixSort();
    getHeight();
    FOR(i,1,N) {
        heightSUM[i] = height[rk[i]];
        saSUM[i] = i;
        // printf("%d %d %d\n", rk[i], height[rk[i]], sa[rk[i]]);
    }
    FOR(i,1,N) {
        ansSUM[i] = ansSUM[i-1] + N-saSUM[i] + 1 - heightSUM[i]; 
        heightSUM[i] += heightSUM[i-1];
        saSUM[i] += saSUM[i-1];
        printf("%d %d %d\n", heightSUM[i], saSUM[i], ansSUM[i]);
    }
    int st,et;

    printf("%d\n", N);

    FOR(i,1,q) {
        scanf("%d%d",&st,&et);
        et++;
        printf("%d %d %d %d %d %d\n", et, st, saSUM[et], saSUM[st], heightSUM[et], heightSUM[st]);
        printf("%d\n",(et-st)*(N+1)-(saSUM[et]-saSUM[st])-(heightSUM[et]-heightSUM[st]));
    }
    return 0;
}