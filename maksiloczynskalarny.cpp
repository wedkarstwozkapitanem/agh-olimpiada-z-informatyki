/*
    autor: Dominik Łempicki kapitan
    nazwa: Maximal dot product
*/

#include <iostream>
#include <vector>
#include <limits>

long long iloczynskalarny(const std::vector<long long> &a, const std::vector<long long> &b)
{
    std::vector<std::vector<long long>> wynik(a.size() + 1, std::vector<long long>(b.size() + 1, std::numeric_limits<long long>::min()));

    for (size_t i = 1; i <= a.size(); ++i)
    {
        for (size_t j = 1; j <= b.size(); ++j)
        {
            if (wynik[i - 1][j - 1] != std::numeric_limits<long long>::min() && wynik[i - 1][j] != std::numeric_limits<long long>::min() && wynik[i][j - 1] != std::numeric_limits<long long>::min())
                wynik[i][j] = std::max(std::max(wynik[i - 1][j - 1] + a[i - 1] * b[j - 1], a[i - 1] * b[j - 1]),
                                       std::max(wynik[i - 1][j], wynik[i][j - 1]));
            else
                wynik[i][j] = std::max(a[i - 1] * b[j - 1],
                                       std::max(wynik[i - 1][j], wynik[i][j - 1]));
        }
    }
    return wynik[a.size()][b.size()];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    size_t n1, n2;
    std::cin >> n1 >> n2;

    std::vector<long long> nums1(n1, 0), nums2(n2, 0);
    for (auto &i : nums1)
        std::cin >> i;
    for (auto &i : nums2)
        std::cin >> i;

    std::cout << iloczynskalarny(nums1, nums2) << '\n';

    return 0;
}