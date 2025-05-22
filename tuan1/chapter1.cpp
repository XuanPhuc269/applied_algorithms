#include <bits/stdc++.h>
using namespace std;

string line, text, word;
map<string, int> word_count;


void input() {
    while(getline(cin, line)) {
        text += line + " ";
    }
}

int main() {
    // Set up the environment
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // Read input
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();

    for (int i = 0; i < text.length(); i++) {
        if (isalnum(text[i])) {
            word += tolower(text[i]);
        } else if (!word.empty()) {
            word_count[word]++;
            word.clear();
        }
    }

    if (!word.empty()) {
        word_count[word]++;
    }

    for (const auto& i : word_count) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}