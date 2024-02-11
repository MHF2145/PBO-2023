#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;
const int MOD = 1e9 + 7;


ll fast_pow(ll base, ll n, ll M)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

ll findMMI_fermat(ll n, ll M)
{
    return fast_pow(n, M - 2, M);
}

vector<ll> factorial(1000009);
int main(int argc, char const *argv[])
{

    factorial[0] = 1;
    for (ll i = 1; i < 1000009; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    int t;
    scanf("%d", &t);

    ll m, n;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &m, &n);

        ll man = m - n;

        if (man + 1 < n)
        {
            printf("0\n");
            continue;
        }

        ll first = factorial[man];

        ll y = findMMI_fermat(factorial[man + 1 - n], MOD);
        y = (factorial[man + 1] * y) % MOD;

        printf("%lld\n", (first * y) % MOD);
    }
    return 0;
}