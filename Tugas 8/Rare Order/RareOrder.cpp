#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

const int INF = 1e9;

void buildCollatingSequence(vector<string>& strings) {
    set<char> uniqueChars;
    for (const string &s : strings)
        for (char c : s)
            uniqueChars.insert(c);

    map<char, int> charOrder;
    int order = 0;
    for (char c : uniqueChars)
        charOrder[c] = order++;

    int n = uniqueChars.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < strings.size() - 1; i++) {
        const string &s1 = strings[i];
        const string &s2 = strings[i + 1];
        int len = min(s1.length(), s2.length());

        for (int j = 0; j < len; j++) {
            char c1 = s1[j];
            char c2 = s2[j];
            if (c1 != c2) {
                dist[charOrder[c1]][charOrder[c2]] = 1;
                break;
            }
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    string collatingSequence;
    for (int i = 0; i < n; i++) {
        char currentChar = ' ';
        int minIncomingEdges = INF;
        for (const pair<char, int> &p : charOrder) {
            char c = p.first;
            int charIndex = p.second;
            int incomingEdges = 0;
            for (int j = 0; j < n; j++)
                if (j != charIndex && dist[j][charIndex] != INF)
                    incomingEdges++;

            if (incomingEdges < minIncomingEdges) {
                minIncomingEdges = incomingEdges;
                currentChar = c;
            }
        }
        collatingSequence += currentChar;
        charOrder.erase(currentChar);
    }

    cout << collatingSequence << endl;
}

int main() {
    char line[22];
    while (true) {
        vector<string> strings;
        while (true) {
            scanf("%s", line);
            if (line[0] == '#') break;
            strings.push_back(string(line));
        }

        if (strings.empty()) break;

        buildCollatingSequence(strings);
    }

    return 0;
}
