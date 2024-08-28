// 28. У кого больше королев?
#include <iostream>
#include <string>
#include <vector>

int func() {
    std::vector<int> vec(4);
	for (int& a : vec)
		std::cin >> a;
	int sum = vec[0] + vec[1] + vec[2] + vec[3];
    if (sum >= 2 && sum <= 4)
        return 0;
	for (int i = 0; i < 4; ++i) 
		if (sum - vec[i] <= 4)
			return 1;
	for (int i = 0; i < 3; ++i) 
		for (int j = i + 1; j < 4; ++j) 
			if (vec[i] + vec[j] <= 4)
				return 2;
	for (int i = 0; i < 4; ++i) 
		if (vec[i] <= 4)
			return 3;
	return 4;
}


int main() 
{
	

	std::cout << func();
        
    

	return 0;
}
