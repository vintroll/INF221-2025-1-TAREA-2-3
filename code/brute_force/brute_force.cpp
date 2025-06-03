#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string, string>> comparar_por_fuerza_bruta(const string &s, const string &t) {
    vector<pair<string, string>> resultado;
    int i = 0, j = 0;
    int n = s.size(), m = t.size();

    while (i < n || j < m) {
        if (i < n && j < m && s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            int ini_i = i, ini_j = j;
            while (i < n && (j >= m || s[i] != t[j])) ++i;
            while (j < m && (i >= n || s[i] != t[j])) ++j;

            string a = s.substr(ini_i, i - ini_i);
            string b = t.substr(ini_j, j - ini_j);
            resultado.emplace_back(a, b);
        }
    }

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

        vector<pair<string, string>> diferencias = comparar_por_fuerza_bruta(s, t);
        cout << diferencias.size() << '\n';
        for (auto &[a, b] : diferencias) {
            cout << a << ' ' << b << '\n';
        }
    }

    return 0;
}
