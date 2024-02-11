#include <cstdio>
#include <vector>

const int MOD = 1e7 + 9;

long long new_balance(long long x, long long y)
{
    return (x * y + x + y) % MOD;
}

int main()
{
    int n;
    scanf("%d", &n);

    std::vector<long long> a(n);
    std::vector<long long> b(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
    }

    long long balance = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            // Perform modular arithmetic at each step
            balance = new_balance(balance, a[i]) % MOD;
        }
    }

    printf("%lld\n", balance);

    return 0;
}
