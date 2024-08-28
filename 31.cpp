// 31. Плитка
#include <iostream>
#include <string>
#include <vector>

auto func() -> std::pair<int,int> {
    int perimetr, square;
    std::cin >> perimetr >> square;
    perimetr /= 2;
    perimetr += 2;
    for  (int i = 3; perimetr - i >= i; ++i) 
        if ((i - 2) * (perimetr - i - 2) == square)
            return std::make_pair(perimetr - i, i);
    return std::make_pair(-1,-1);
        
}

int main() 
{
	auto res = func();
    std::cout << res.first << " " << res.second << std::flush;

	return 0;
}
