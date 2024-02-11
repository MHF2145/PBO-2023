#include <stdio.h>
// #include <iostream>

int main()
{
    unsigned long long l;
    scanf("%llu\n",&l);
    // std::cin>>l;

    while (l--)
    {
        unsigned long long n, m;
        scanf("%llu %llu", &n, &m);
        // std::cin >> n >> m;

        unsigned long long k = 0;
        while ((n ^ k) <= m)
        {
            k++;
        }

        printf("%llu\n", k);
        // std::cout << k << std::endl;
    }
}
