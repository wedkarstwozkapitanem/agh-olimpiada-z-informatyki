/*
* autor: Dominik Łempicki kapitan
* nazwa: Uncrossed lines
*/

#include <iostream>
#include <vector>

size_t liczodcinki(const std::vector<int>& liczbyjeden, const std::vector<int>& liczbydwa) {
    size_t n = liczbyjeden.size(),m = liczbydwa.size();
    
    std::vector<std::vector<int>> wynik(n + 1, std::vector<int>(m + 1, 0));

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (liczbyjeden[i - 1] == liczbydwa[j - 1]) wynik[i][j] = wynik[i - 1][j - 1] + 1;
            else wynik[i][j] = std::max(wynik[i - 1][j], wynik[i][j - 1]);
        }
    }

    return wynik[n][m];
}

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);

    size_t n, m;
    std::cin >> n >> m;
    
    std::vector<int> liczbynrjeden(n);
    for (auto& i : liczbynrjeden) std::cin >> i;

    std::vector<int> liczbydwa(m);
    for (auto& i : liczbydwa) std::cin >> i;

    std::cout << liczodcinki(liczbynrjeden, liczbydwa) << '\n';
    return 0;
}