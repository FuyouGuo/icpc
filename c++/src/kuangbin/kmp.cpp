#ifndef _GLIBCXX_CUSTOM_KUANGBIN_KMP
// next[i-next[i]...i-1] == next[0...next[i]-1]
// next[i-z...i-1] == next[0...z-1]
void kmp_pre(char x[], int m, int next[]){
    int i,j;
    j=next[0]=-1;
    while(i<m){
        while(j!=-1&&x[i]!=x[j]) j=next[j];
        x[++i]=++j;
    }
}

// kmp_next[i]的意思是kmp_next[i]=next[next[...next[i]]](直到next[i]=-1或next[next'[i]]!=x[i])
void pre_kmp(char x[], int m, int kmp_next[]){
    int i,j;
    j=x[0]=-1;
    while(i<m){
        while(-1!=j&&x[i]!=x[j]) j=kmp_next[j];
        if(x[++i]==x[++j]) kmp_next[i]=kmp_next[j];
        else kmp_next[i]=j;
    }
}

// 返回x在y中出现的次数，可以重叠
int kmp_cnt(char x[], const int m, char y[], const int n, int next[]){
    int i,j;
    int ans;
    pre_kmp(x,m,next);
    while(i<n){
        while(-1!=j&&y[i]!=x[j]) j=next[i];
        i++,j++;
        if(j>=m){
            ans++;
            j=next[j];
        }
    }
    return ans;
}

// next[i]:x[i...m-1]与x[0...m-1]的最长公共前缀
// extend[i]:y[i...n-1]与x[0...m-1]的最长公共前缀
void pre_extend_kmp(char x[],int m,int next[]){
    next[0]=m;
    int j=0;
    while(j+1<m&&x[j]==x[j+1])j++;
    next[1]=j;
    int k=1;
    for(int i=2;i<m;i++){
        
    }
}
#endif
