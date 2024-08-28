//5. Ближайшая остановка

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	int k;
	std::cin >> n >> k;
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}
	for (int i = 0; i < k; ++i) {
		int x;
		std::cin >> x;
		auto it = std::lower_bound(vec.begin(), vec.end(), x);
		if (it == vec.end()) {
			std::cout << vec.size() << '\n';
		}
		else {
			if (it != vec.begin()) {
				if (*(it) - x >= x - *(it-1)) {
					std::cout << it - vec.begin() << '\n';
				}
				else {
					std::cout << it - vec.begin() + 1 << '\n';
				}
			}
			else {
				std::cout << 1 << '\n';
			}
		}
	}
	return 0;
}

