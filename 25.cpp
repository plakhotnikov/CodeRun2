// 25. Парные коды


#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <unordered_map>

int toBitmask(int number) {
    int mask = 0;
    do {
        int digit = number % 10;
        mask |= (1 << digit);
        number /= 10;
    } while (number > 0);
    return mask;
}

using LLI = long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
	std::vector<int> bitmasks(1024);
    LLI rep = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        int bitmask = toBitmask(x);
        for (int j = 0; j < 1024; ++j)
            if (j & bitmask)
                rep += bitmasks[j];
		++bitmasks[bitmask];
    }
    std::cout << rep;

}
