#include "builtin.cpp"
#ifndef _GLIBCXX_CUSTOM_KUANGBIN_MANACHEER
    // Ma和Mp是辅助数组，大小至少为s的两倍, 最长回文子串是max(mp[i]-1)
    void Manacher(char s[], int len, char Ma[], int Mp[]){
        int l = 0;
        Ma[l++]='$'; // 开始标志元素
        Ma[l++]='#'; // 占位元素
        for(int i=0;i<len;i++){
            Ma[l++]=s[i]; 
            Ma[l++]='#'; // 占位元素
        } 
        Ma[l]=0; // 终结元素，最小
        int mx=0,id=0;
        for(int i=0;i<l;i++){
            Mp[i]=mx>i?min(Mp[2*id-1],mx-i):1;
            while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
            if(i+Mp[i]>mx){
                mx=i+Mp[i];
                id=i;
            }
        }
    }
#endif