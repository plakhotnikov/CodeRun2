// 24. Счастливый номер

#pragma GCC optimize("O3")

#include <iostream>
#include <string>
#include <vector>

struct Number {
	std::vector<int> f;
	std::vector<int> s;
	int len;
	int sum1, sum2;
	Number(const std::string& str): len(str.size() / 2) {
		sum1 = sum2 = 0;
		f.reserve(len);
		s.reserve(len);
		for (int i = 0; i < len; ++i) {
			f.push_back(str[len - 1 - i] - '0');
			sum1 += str[len - 1 - i] - '0';
		}
		for (int i = 0; i < len; ++i) {
			s.push_back(str[2 * len - 1 - i] - '0');
			sum2 += str[2 * len - 1 - i] - '0';
		}
		add_one_to_s();
		bool none = true;
		for (int i = 0; i < len; ++i)
			if (s[i] != 0 || f[i] != 0) {
				none = false;
				break;
			}
		if (none)
			add_one_to_s();

/*		std::cout << "num + 1 = ";
		print();
		std::cout << "sum1 = " << sum1 << "; sum2 = " << sum2 << std::endl;**/
	}


	void add_one_to_f() {
		for (int i = 0; i < len; ++i) {
			++f[i];
			f[i] %= 10;
			if (f[i]) {
				sum1 += 1;
				break;
			}
			else {
				sum1 -= 9;
			}
		}
	}

	void add_one_to_s() {
		bool one = false;
		for (int i = 0; i < len; ++i) {
			++s[i];
			s[i] %= 10;
			if (s[i]) {
				sum2 += 1;
				one = true;
				break;
			}
			else {
				sum2 -= 9;
			}
		}
		if (!one)
			add_one_to_f();
	}



	void add_to_s(int x) {
		for (int i = 0; i < len; ++i) {
			if (x > 9) {
				s[i] = 9;
				x-=9;
			}
			else if (x > 0){
				s[i] = x;
				x = 0;
			}
			else
				break;
		}
		sum2 += x;
	}



	void increase() {
//		std::cout << "increase() called" << std::endl;
		for (int i = 0; i < len; ++i) {
         	sum2 += 9 - s[i];
			s[i] = 9;
			if (sum1 <= sum2) {
				s[i] -= sum2 - sum1;
				sum2 -= sum2 - sum1;
				return;
			}
		}
	}

    void decrease() {
//		std::cout << "derease() called" << std::endl;
		for (int i = 1; i < len; ++i) {
			while (s[i-1] == 0 && i < len) {
				++i;
			}
			if (i == len)
				break;
			sum2 -= s[i-1];
			++sum2;
			++s[i];
			s[i - 1] = 0;
			while (i < len && s[i] == 10) {
				++i;
				if (i < len)
					++s[i];
				s[i - 1] = 0;
				sum2 -= 9;
			}
			if (i >= len)
				break;
			if (sum1 >= sum2) {
				add_to_s(sum1 - sum2);
				return;
			}
		}
		s[s.size() - 1] = 0;
		sum2 = 0;
		add_one_to_f();
		increase();
	}


	void make_lucky() {
 		if (sum1 > sum2)
			increase();
		else if (sum1 < sum2)
			decrease();
	}

	void print() {
		for (int i = 0; i < len; ++i) {
			std::cout << f[len - 1 - i];
		}
        for (int i = 0; i < len; ++i) {
			std::cout << s[len - 1 - i];
		}
		std::cout << std::endl;
	}
	int to_int() {
		int x = 0;
        for (int i = 0; i < len; ++i) {
			x *= 10;
			x += f[len - 1 - i];
		}
        for (int i = 0; i < len; ++i) {
			x *= 10;
			x += s[len - 1 - i];
		}
		return x;
	}
};

int main()
{

 	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str;
	std::cin >> str;
	Number n(str);
	n.make_lucky();
 	n.print();
}

