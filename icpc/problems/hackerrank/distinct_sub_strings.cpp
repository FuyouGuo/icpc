 #include<cstring>
 #include<cstdlib>
 #include<cstdio>
 #include<cstring>
 #include<iostream>
 using namespace std;
 const int maxn=1010;
 int wa[maxn],wb[maxn],wv[maxn],wq[maxn];
 int rank_arr[maxn],sa[maxn];
 int r[maxn];
 char s[maxn];
 int height[maxn];
 int cmp(int *r,int a,int b,int l)
 {return r[a]==r[b]&&r[a+l]==r[b+l];}
 // 后缀数组并排序，sa[i]=val, 表明排序后第i个后缀数组的起始下标
 // https://discuss.codechef.com/t/a-tutorial-on-suffix-arrays/2950
 // https://blog.csdn.net/OOFFrankDura/article/details/79962585
 // https://zhuanlan.zhihu.com/p/78769816
 void da(int* r,int *sa,int n,int m)
 {
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) wq[i]=0; // 字符个数
     for(i=0;i<n;i++) wq[x[i]=r[i]]++; // 统计字符个数（末尾有个空字符 r[n-1]=0）
     for(i=1;i<m;i++) wq[i]+=wq[i-1];  // 和相加
     for(i=n-1;i>=0;i--) {
         sa[--wq[x[i]]]=i; // 按首位字符排序
        //  cout<<x[i]<<"  "<<wq[x[i]]<<" "<<sa[wq[x[i]]]<<endl;
     }
    for(i=1;i<=n;i++) cout<<sa[i]<<" "; 
    cout<<endl;
 
     for(j=1,p=1;p<n;j*=2,m=p)
     {
         for(p=0,i=n-j;i<n;i++) y[p++]=i;  // y[k]=n-j+k;
         for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        //  for(i=1;i<p;i++){
        //      cout<<y[i]<<" ";
        //  }
        //  cout<<endl;
         // y[i]表明第二个元素下标，wv[i] 表明第二个元素
         for(i=0;i<n;i++) wv[i]=x[y[i]];
         for(i=0;i<m;i++) wq[i]=0;
         for(i=0;i<n;i++) wq[wv[i]]++;
         for(i=1;i<m;i++) wq[i]+=wq[i-1];
         for(i=n-1;i>=0;i--) sa[--wq[wv[i]]]=y[i];
         for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
         x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;

         for(i=1;i<n;i++) cout<<x[sa[i]]<<" ";
         cout<<endl;
     }
     return ;
 }

 // 重复个数
 void callheight(int *r,int n)
 {
     int i,j,k=0;
     for(i=1;i<=n;i++) rank_arr[sa[i]]=i;
     for(i=0;i<n;i++)
        {
            if(k) k--;
            j=sa[rank_arr[i]-1];
            while(r[i+k]==r[j+k]) k++;
            height[rank_arr[i]]=k;
            // cout<<rank_arr[i]<<"  "<<j<<"  "<<height[rank_arr[i]]<<endl;
        }
 }
 int main()
  {
    int n,q;
    cin>>n>>q;
    scanf("%s",s);
    for(int i=0;i<n;i++)
        r[i]=s[i];
    r[n]=0;
    da(r,sa,n+1,130);
    callheight(r,n);
    int ans[n+1];
    ans[0] = 0;
    for(int i=1;i<=n;i++){
        ans[i]=ans[i-1] + (n-sa[i]-height[i]);
        cout<<sa[i]<<" "<<height[i]<<" "<<ans[i]<<endl;
    }
    int i,j;
    // sa[0]=1;    
    // for(int k = 0; k < q; k++){
    //     cin>>i>>j;
    //     cout<<ans[j+1]-sa[i]+1<<endl; 
    // }
    return 0;
  }