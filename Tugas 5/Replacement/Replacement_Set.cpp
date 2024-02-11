#include <stdio.h>
#include <set>
#include <vector>
#define MAX 100001
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

set<int> s;
set<int>::iterator it;
int in[MAX], out[MAX], i, n;

int main() {
    Get(n);
    for (i = 0; i < n; i++) {
        Get(in[i]);
    }
    for (i = n - 1; i >= 0; i--) {
        s.insert(in[i]);
        it = s.find(in[i]);
        s.erase(s.begin(), it);
        it++;
        if (it == s.end()) out[i] = 0;
        else out[i] = *it;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    
    printf("\n");

    return 0;
}
