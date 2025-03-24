#include<iostream>
#include<cmath>
#include<fstream>

long long answer(long long x, int k) {
    long long tmp = (long long) k * k;
    if (x <= tmp) {
        return x % k == 0 ? x / k : -1;
    } else {
        long long sqrtx = sqrtl(x);
        long long tmpx = sqrtx * sqrtx;
        if (tmpx + k > x && tmpx > k * k) {
            return (sqrtx << 1) - k;
        } else {
            return (sqrtx << 1) - k + 1;
        }
    }
}

int main() {
#ifdef DEBUG
    std::streambuf *backup;
    backup = std::cin.rdbuf();
    std::ifstream fin("/Users/dave/CLionProjects/51nod/1859/data/data.txt");
    std::cin.rdbuf(fin.rdbuf());
#endif
    int T, k;
    long long x;
    std::cin >> T;
    while (T--) {
        std::cin >> x >> k;
        std::cout << answer(x, k) << std::endl;
    }
#ifdef DEBUG
    std::cin.rdbuf(backup);
#endif
    return 0;
}