#include <bits/stdc++.h>
using namespace std;
// Function to compute Z array
vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> Z(n, 0);

    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {

        if (i <= R) {
            Z[i] = min(R - i + 1, Z[i - L]);
        }

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }

        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }

    return Z;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    string combined = pattern + "$" + text;

    vector<int> Z = computeZ(combined);
    int m = pattern.length();

    vector<int> matches;

    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == m) {
            matches.push_back(i - m - 1);
        }
    }

    if (matches.empty()) {
        cout << "No Occurrences";
    } else {
        cout << matches.size() << endl;
        for (int idx : matches) {
            cout << idx << " ";
        }
    }

    return 0;
}