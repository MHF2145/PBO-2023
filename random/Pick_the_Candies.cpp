#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }

        deque<int> window;
        int max_index = 0; // Index of maximum sweetness value in the current window

        // Initialize the first window and find the index of the maximum sweetness value
        for (int i = 1; i < k; i++) {
            if (sweetness[i] > sweetness[max_index]) {
                max_index = i;
            }
        }
        window.push_back(max_index);

        // Print the choice for the first child
        cout << sweetness[max_index] << " ";

        for (int i = 1; i < n - k + 1; i++) {
            // Check if the maximum sweetness value is leaving the window
            if (max_index == i - 1) {
                // Recalculate the maximum sweetness value within the current window
                max_index = i;
                for (int j = i + 1; j < i + k; j++) {
                    if (sweetness[j] > sweetness[max_index]) {
                        max_index = j;
                    }
                }
            } else {
                // Compare the new candy entering the window with the current maximum
                if (sweetness[i + k - 1] > sweetness[max_index]) {
                    max_index = i + k - 1;
                }
            }

            // Add the index of the maximum sweetness value to the window
            window.push_back(max_index);

            // Print the choice for the current child
            cout << sweetness[max_index] << " ";
        }

        cout << endl;
    }

    return 0;
}
