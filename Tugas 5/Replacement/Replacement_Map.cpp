#include <cstdio>
#include <map>

using namespace std;

#define gc getchar_unlocked

void Get(int &ret) {
    ret = 0; char inp = gc(); int kl = 1;
    while (inp < '0' || inp > '9') {
        if (inp == '-') kl = -1; inp = gc();}
    while ('0' <= inp && inp <= '9')
        ret = (ret << 3) + (ret << 1) + (int)(inp - '0'), inp = gc();
        if (kl < 1) ret = -ret;
}


int main() {
    int n;
    Get(n);
    map<int, int> nextLarger;
    for (int i = 0; i < n; i++) {
        int a;
        Get(a);

        auto it = nextLarger.upper_bound(a);
        if (it != nextLarger.end()) {
            printf("%d ", it->second);
        } else {
            printf("0 ");
        }
        nextLarger[a] = (it != nextLarger.end()) ? it->second : a;
    }

    printf("\n");

    return 0;
}
