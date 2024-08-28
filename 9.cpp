//9. НОД

#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using LLI = long long int;

void update_div(std::vector<int>& divs, int new_div) {
    int d = 2;
    while (new_div % d == 0) {
        divs.push_back(d);
        new_div /= d;
    }
    ++d;
    while (d * d <= new_div) {
        while (new_div % d == 0) {
            divs.push_back(d);
            new_div /= d;
        }
        d+=2;
    }
    if (new_div != 1)
        divs.push_back(new_div);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
	LLI p = 1;
    bool nine = false;
    int n, m;
    std::cin >> n;
    std::vector<int> f;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        update_div(f, x);
    }

    std::cin >> m;
    std::vector<int> s;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        update_div(s, x);
    }

    std::sort(f.begin(), f.end());
    std::sort(s.begin(), s.end());

    n = f.size();
    m = s.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (f[i] == s[j]) {
            p *= f[i];
            if (p > 1e9) {
                p %= (int)1e9;
                nine = true;
            }
            ++i;
            ++j;
        }
        else if (f[i] < s[j])
            ++i;
        else
            ++j;
    }
    if (nine) {
		std::cout << std::setw(9) << std::setfill('0');
	}
	std::cout << p;

	return 0;
}
