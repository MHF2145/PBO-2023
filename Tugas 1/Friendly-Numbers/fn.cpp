#include <stdio.h>
using namespace std;
const int MXN = 1000000;
int sieve[MXN+1];

int main(){
    int m, n;
    for(int i = 0; i <= MXN; i++) sieve[i] = 0;
    for(int i = 1; i <= MXN; i++){
        for(int j = 2*i; j <= MXN; j+=i){
            sieve[j] += i;
        }
    }
    while(scanf("%d %d", &m, &n) != EOF){
        bool ok = 0;
        for(int i = m; i <= n; i++){
            int j = sieve[i];
            if(i < j && m <= j && j <= n && sieve[j] == i){
                printf("%d %d\n", i, j);
                ok = 1;
            }
        }
        if(!ok) puts("Absent");
    }
    return 0;
}
