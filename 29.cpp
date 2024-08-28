//29. Крестики-нолики

#include <iostream>
#include <string>
#include <vector>
int n,m;
std::vector<std::string> field;

bool check_border(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool check_vertical() {
	if (n < 5)
		return false;
 	for (int j = 0; j < m; ++j) {
     	char sym = ' ';
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
         	if (field[i][j] == sym)
				++cnt;
			else {
				if (cnt >= 5 && sym != '.')
					return true;
				cnt = 1;
				sym = field[i][j];
			}
		}
		if (cnt >= 5 && sym != '.')
			return true;
	}
	return false;
}

bool check_horizontal() {
	if (m < 5)
		return false;
 	for (int i = 0; i < n; ++i) {
     	char sym = ' ';
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
         	if (field[i][j] == sym)
				++cnt;
			else {
				if (cnt >= 5 && sym != '.')
					return true;
				cnt = 1;
				sym = field[i][j];
			}
		}
		if (cnt >= 5 && sym != '.')
			return true;
	}
	return false;
}


int check_diagonal_to_right(int i, int j);
int check_diagonal_to_left(int i, int j);

bool check_diagonal() {
 	if (n < 5 || m < 5)
		return false;
	for (int i = 0; i < n; ++i)
		if (check_diagonal_to_right(i, 0) >= 5 || check_diagonal_to_left(i, m - 1) >= 5)
			return true;
	for (int j = 0; j < m; ++j)
		if (check_diagonal_to_right(0, j) >= 5 || check_diagonal_to_left(0, j) >= 5)
			return true;
	return false;
}

int check_diagonal_to_right(int i, int j) {
   	char sym = ' ';
	int cnt = 0;
	int max_cnt = 0;
	while (check_border(i,j)) {
		if (field[i][j] == sym)
			++cnt;
		else {
			if (max_cnt < cnt && sym != '.')
				max_cnt = cnt;
			sym = field[i][j];
			cnt = 1;
		}
		++i;
		++j;
	}
    if (max_cnt < cnt && sym != '.')
		max_cnt = cnt;
	return max_cnt;
}

int check_diagonal_to_left(int i, int j) {
   	char sym = ' ';
	int cnt = 0;
	int max_cnt = 0;
	while (check_border(i,j)) {
		if (field[i][j] == sym)
			++cnt;
		else {
			if (max_cnt < cnt && sym != '.')
				max_cnt = cnt;
			sym = field[i][j];
			cnt = 1;
		}
		++i;
		--j;
	}
    if (max_cnt < cnt && sym != '.')
		max_cnt = cnt;
	return max_cnt;
}
int main() {
	std::cin >> n >> m;
	field.resize(n);
	for (int i = 0; i < n; ++i)
		std::cin >> field[i];
	if (check_vertical() || check_horizontal() || check_diagonal())
		std::cout << "Yes";
	else
		std::cout << "No";


}
