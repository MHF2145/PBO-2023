#include <stdio.h>
typedef long long ll;

int main()
{
    int cases;
    scanf("%d",&cases);
    
    while (cases--)
    {
        ll n, m, res = 0, b = 1;
        scanf("%lld %lld", &n, &m);
        m++;
        while (n||m)
        {
            ll N = n & 1, M = m & 1;
            if (!N && M) res | b;
            else if (N && !M) res = 0;
            b <<= 1; n >>= 1; m >>= 1;
            
             
        }
        printf("%lld\n", res);
        
    }
    return 0;
}