#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            max_heap.push(A[i]);
            min_heap.push(A[i]);
            sum += A[i];
        }

        if (sum % N != 0)
        {
            cout << "-1" << endl;
            continue;
        }

        int target = sum / N;
        int steps = 0;

        while (!max_heap.empty() && max_heap.top() > target && !min_heap.empty() && min_heap.top() < target)
        {
            int max_top = max_heap.top();
            int min_top = min_heap.top();

            int diff = max_top - min_top;
            int lif = ceil((double)diff / 2.0);

            max_heap.pop();
            min_heap.pop();

            max_heap.push(max_top - lif);
            min_heap.push(min_top + lif);

            steps++;
        }

        cout << steps << endl;
    }

    return 0;
}
