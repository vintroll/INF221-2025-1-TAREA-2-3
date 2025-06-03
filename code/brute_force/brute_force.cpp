#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>




using namespace std;
using namespace chrono;
// Fuerza bruta para calcular la LCS (sin memoización)
string calcular_lcs_brute(const string &s, const string &t) {
    if (s.empty() || t.empty())
        return "";

    if (s[0] == t[0])
        return s[0] + calcular_lcs_brute(s.substr(1), t.substr(1));
    else {
        string lcs1 = calcular_lcs_brute(s.substr(1), t);
        string lcs2 = calcular_lcs_brute(s, t.substr(1));
        return (lcs1.size() > lcs2.size()) ? lcs1 : lcs2;
    }
}

vector<pair<string, string>> diferencias_por_lcs(const string &s, const string &t) {
    string lcs = calcular_lcs_brute(s, t);
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
    ifstream input("brute_force_input/input.txt");
    ofstream output("measurements/brute_force/output.txt");
    ofstream timing("measurements/brute_force/time.txt");

    int K;
    input >> K;
    output << K << '\n';
    input.ignore();

    auto start = high_resolution_clock::now();

    while (K--) {
        string s_line, t_line, s, t;
        int n, m;

        getline(input, s_line);
        getline(input, t_line);

        n = stoi(s_line.substr(0, s_line.find(' ')));
        s = s_line.substr(s_line.find(' ') + 1);
        m = stoi(t_line.substr(0, t_line.find(' ')));
        t = t_line.substr(t_line.find(' ') + 1);

        vector<pair<string, string>> diferencias = diferencias_por_lcs(s, t);

        output << diferencias.size() << '\n';
        for (auto &[a, b] : diferencias) {
            output << a << ' ' << b << '\n';
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    timing << "Tiempo de ejecución (ms): " << duration.count() << endl;

    return 0;
}
