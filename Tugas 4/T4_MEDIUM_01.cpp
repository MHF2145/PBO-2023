#include <stdio.h>
#include <vector>

using namespace std;

#define gc getchar_unlocked

template <typename T>
void Getnum(T &val) {
    char ch;
    bool bo = 0;
    val = 0;
    for (ch = gc(); ch < '0' || '9' < ch; ch = gc()) 
        if (ch == '-') 
            bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - 48, ch = gc());
    if (bo) 
        val = -val;
}

int main() {
    int t;
    Getnum(t); // Read the number of test cases.

    while (t--) {
        char go, goal = 'x';
        vector<int> memgo, memgoal;
        int size;
        Getnum(size); // Read the size of the signal string.

        go = getchar_unlocked();
        char s[size + 1];
        scanf("%s", s); // Read the signal string.

        if (go == goal) {
            printf("0\n");
            continue;
        }

        for (int i = 0; i < size; i++) {
            if (s[i] == go)
                memgo.push_back(i); // Record the positions of the 'go' signal.
            if (s[i] == goal)
                memgoal.push_back(i); // Record the positions of the 'goal' signal.
        }

        int overall = 0;

        for (int i = 0; i < memgo.size(); i++) {
            int nearestgoal = -1;
            for (int j = 0; j < memgoal.size(); j++) {
                if (memgoal[j] > memgo[i]) {
                    nearestgoal = memgoal[j];
                    break;
                }
            }
            if (nearestgoal == -1)
                nearestgoal = memgoal[0] + size;
            int dist = nearestgoal - memgo[i];
            overall = max(overall, dist); // Calculate the minimum waiting time.
        }
        printf("%d\n", overall); // Print the result.
        memgo.clear();
        memgoal.clear();
    }
    return 0;
}
