#include<cstdio>
#include<vector>
#include <cctype>
//适用于正负整数
// 读取标准字符，并将其append到上一次结果中
typedef bool (*append_str_func)(void *ret, char c);

bool append_int_str(void *ret, char c){
    int64_t ret_val = int64_t(ret);
    if(c >='0'&&c<='9'){

    }
    return true;
}

template <class T>
inline bool scan_v(vector<T> &ret, char split, append_func append_str_func){
    char c;
    T cur;
    bool is_read = 0;
    while(c=get_char(); c !='[') {
        if(iswspace(c)) continue;
        return false;
    }
    while(c=getchar(); c!=']'){
        if(is_start){
                if(c==EOF || c==split){
                if(is_read){
                    ret.push_back(cur);
                }
                is_read = false;
                memset(cur, 0, sizeof(cur));
            } else {
                is_read = true;
                append_func(cur, split);
            }
        }
    }
    return true;
}
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='−'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='−')?-1:1;
    ret=(c=='−')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
inline void out(int x) {
    if(x>9) out(x/10);
    putchar(x%10+'0');
}