#include <stdio.h>
#include <stack>
#include <vector>
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

int main()
{
    int n;
    Get(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        Get(a[i]);
    }

    vector<int> result(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            result[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", result[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
