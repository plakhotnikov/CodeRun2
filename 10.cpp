// 10. График работ
#pragma GCC optimize("O3")
#include <map>
#include <iostream>
#include <vector>
#include <queue>

using LLI = long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::map<int, std::vector<int>, std::greater<int>> tasks;
	LLI sum = 0;
	for (int i = 0; i < n; ++i) {
		int d, w;
		std::cin >> d >> w;
		tasks[d].push_back(w);
		sum += w;
	}
	//учесть после перебора последнего (первого) листа, что есть ещё дни от 1 до листа
	int cur_day = tasks.begin()->first + 1;
	std::priority_queue<int> prior;
	for (auto& p : tasks) {
		int dif = cur_day - p.first;
        auto it_max_el = p.second.begin();
		for (auto it = p.second.begin(); it != p.second.end(); ++it) 
         	if (*it_max_el <= *it)
				it_max_el = it;
		prior.push(*it_max_el);	
		p.second.erase(it_max_el);
		while (dif-- && !prior.empty()) {
			sum -= prior.top();
			prior.pop();
		}
		for (int a : p.second) {
			prior.push(a);
		}
		cur_day = p.first;
	}

	while (--cur_day && !prior.empty()) {
 		sum -= prior.top();
		prior.pop();
	}
	std::cout << sum;


}
