#include <iostream>
#include <string>
using namespace std;

#define d 256  // number of characters in input alphabet

void rabinKarp(string text, string pattern, int q) {
    int n = text.length();
    int m = pattern.length();

    int p = 0; // hash value for pattern
    int t = 0; // hash value for current text window
    int h = 1;

    // h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // slide the pattern over text
    for (int i = 0; i <= n - m; i++) {

        // check hash match
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // compute next window hash
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // handle negative hash
            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    int q = 101; // a prime number

    rabinKarp(text, pattern, q);

    return 0;
}