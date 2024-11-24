/*
    autor:Dominik Łempicki kapitan
    nazwa: Number of islands
*/

#include <iostream>
#include <vector>

void dfs(int i, int j, const std::vector<std::string> &siatka, std::vector<std::vector<bool>> &odwiedzone, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || siatka[i][j] == 's' || odwiedzone[i][j])
        return;

    odwiedzone[i][j] = true;

    dfs(i + 1, j, siatka, odwiedzone, m, n);
    dfs(i - 1, j, siatka, odwiedzone, m, n);
    dfs(i, j + 1, siatka, odwiedzone, m, n);
    dfs(i, j - 1, siatka, odwiedzone, m, n);
}

int main()
{
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    size_t m, n;
    std::cin >> m >> n;
    std::vector<std::string> plansza(m);
    for (auto &i : plansza) std::cin >> i;
    

    std::vector<std::vector<bool>> odwiedzone(m, std::vector<bool>(n, false));


    for (size_t i = 0; i < m; ++i)
    {
        if (plansza[i][0] == 'l' && !odwiedzone[i][0])
            dfs(i, 0, plansza, odwiedzone, m, n);
        if (plansza[i][n - 1] == 'l' && !odwiedzone[i][n - 1])
            dfs(i, n - 1, plansza, odwiedzone, m, n);
    }
    for (size_t j = 0; j < n; ++j)
    {
        if (plansza[0][j] == 'l' && !odwiedzone[0][j])
            dfs(0, j, plansza, odwiedzone, m, n);
        if (plansza[m - 1][j] == 'l' && !odwiedzone[m - 1][j])
            dfs(m - 1, j, plansza, odwiedzone, m, n);
    }


    long long licznik = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (plansza[i][j] == 'l' && !odwiedzone[i][j]) {
                ++licznik;
            }
        }
    }

    std::cout << licznik << '\n';
    return 0;
}