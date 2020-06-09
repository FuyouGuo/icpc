#ifndef _GLIBCXX_NO_CUSTOM_STDDEF 
    // type
    #define Re register
    #define LL long long
    #define U unsigned
    // variable
    #define fi first
    #define se second
    #define BR printf("--------------------\n")
    // func
    #define FOR(i,a,b) for(Re int i = a;i <= b;++i)
    #define ROF(i,a,b) for(Re int i = a;i >= b;--i)
    #define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
    #define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
    #define CLR(i,a) memset(i,a,sizeof(i))
    #define DEBUG(x) std::cerr << #x << '=' << x << std::endl
    #define MAX3(a,b,c) max(a,max(b,c))
    #define MIN3(a,b,c) min(a,min(b,c))
#endif