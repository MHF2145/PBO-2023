#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int c, k;
        cin >> c >> k;

        vector<int> chosenNumbers; // Use a vector to store chosen numbers

        for (int i = 0; i < c; i++)
        {
            int num;
            cin >> num;

            if (num == 0)
            { // Martin is asking for the kth smallest number
                if (chosenNumbers.size() < k)
                {
                    cout << "-1" << endl;
                }
                else
                {
                    stable_sort(chosenNumbers.begin(), chosenNumbers.end());
                    cout << chosenNumbers[k - 1] << endl; // Access k-1th element (0-based index)
                }
            }
            else
            {
                chosenNumbers.push_back(num);
            }
        }
    }

    return 0;
}
