#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

string calcular_lcs(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs += s[i - 1];
            --i; --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

vector<pair<string, string>> diferencias_por_lcs(const string &s, const string &t) {
    string lcs = calcular_lcs(s, t);
    vector<pair<string, string>> resultado;
    int i = 0, j = 0, k = 0;

    while (k < lcs.size()) {
        string a, b;
        while (i < s.size() && s[i] != lcs[k]) a += s[i++];
        while (j < t.size() && t[j] != lcs[k]) b += t[j++];
        if (!a.empty() || !b.empty()) resultado.emplace_back(a, b);
        ++i; ++j; ++k;
    }

    string a_rest = s.substr(i);
    string b_rest = t.substr(j);
    if (!a_rest.empty() || !b_rest.empty())
        resultado.emplace_back(a_rest, b_rest);

    return resultado;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    cout << K << '\n';
    cin.ignore();

    while (K--) {
        string s_line, t_line, s, t;
        int n, m;

        getline(cin, s_line);
        getline(cin, t_line);

        n = stoi(s_line.substr(0, s_line.find(' ')));
        s = s_line.substr(s_line.find(' ') + 1);
        m = stoi(t_line.substr(0, t_line.find(' ')));
        t = t_line.substr(t_line.find(' ') + 1);

        vector<pair<string, string>> diferencias = diferencias_por_lcs(s, t);
        cout << diferencias.size() << '\n';
        for (auto &[a, b] : diferencias) {
            cout << a << ' ' << b << '\n';
        }
    }

    return
