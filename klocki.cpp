/*
    autor: Dominik Łempicki kapitan
    nazwa:  Square flips
*/

#include <iostream>
#include <vector>

long long liczbaodwrocen(const std::vector<bool> &klocki,const int k) {
    long long licznik = 0;
    std::vector<bool> odwrocenie(klocki.size(),false);
    bool czyodwrocone{false};
    for(size_t i{};i<klocki.size();++i){
        if (i >= k)  czyodwrocone ^= odwrocenie[i - k]; 
        if(klocki[i]==czyodwrocone) {
            if (i + k > klocki.size()) return -1;
            czyodwrocone ^= true;
            odwrocenie[i] = true;
            ++licznik;
        }
    }
    return licznik;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<bool> klocki(n);

    for (int i = 0; i < n; ++i) {
        char tmp;std::cin >> tmp;
        klocki[i] = (tmp == 'w');
    }

    std::cout << liczbaodwrocen(klocki, k) << '\n';

    return 0;
}
