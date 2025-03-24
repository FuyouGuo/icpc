#include<iostream>
#include<ctime>
#include <sys/time.h>
using namespace std;

void testMulti1(long long n){
    int val = 10;
    for (int i = 0;i < n; i++) {
        int t = (val << 3) + (val << 1);  
    }
}

void testMulti2(long long n){
    int val = 10;
    for (int i = 0;i < n; i++) {
        int t = val * 10;  
    } 
}

long long get_time(){
    struct timeval tv;  
    gettimeofday(&tv,NULL);
    return tv.tv_usec; 
}

int main(){
    long long n = 1000000000;
    long long t1 = get_time();
    testMulti1(n);
    long long t2 = get_time();

    cout<<INT32_MAX<<endl;

    long long t3 = get_time();
    testMulti2(n);
    long long t4 = get_time();
    cout<<t2-t1<<"   "<<t4-t3<<endl;
}