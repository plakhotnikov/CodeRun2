// 27. Комбо


#include <iostream>
#include <string>
#include <vector>

int func(std::vector<int>& gds, std::vector<int>& combo,
        int combo_price, std::vector<int>& my_gds) {
    int total_price = 0;
    int n = gds.size();
    for (int i = 0; i < n; ++i) {
        total_price += my_gds[i] * gds[i];
    }
    int benefit = 0;
    do {
        total_price -= benefit;
        int price = 0;
        for (int i = 0; i < 4; ++i)
            if (my_gds[combo[i] - 1]) {
                price += gds[combo[i] - 1];
             	--my_gds[combo[i] - 1];
			}
        benefit = price - combo_price;

    } while (benefit > 0);
    return total_price;


}


int main()
{
	int n;
    std::cin >> n;
    std::vector<int> gds(n);
    for (int& el : gds)
		std::cin >> el;

    int combo_price;
    std::cin >> combo_price;
    std::vector<int> combo(4);
    for (int& e : combo)
        std::cin >> e;
    int x;
    std::cin >> x;
    std::vector<int> my_gds(n);

    for (int i = 0; i < x; ++i) {
        int temp;
        std::cin >> temp;
        ++my_gds[temp - 1];
    }

	std::cout << func(gds, combo, combo_price, my_gds);

	return 0;
}
