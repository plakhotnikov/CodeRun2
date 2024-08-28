// 26. Наибольший квадрат

#include <iostream>
#include <string>
#include <vector>

int n, m;
int max_ver(int i, int j, std::vector<std::vector<int>>& result) {
	++i;
    int cnt = 1;
    while (i != n && result[i][j] != 0) {
        ++cnt;
        ++i;
    }
    return cnt;
}

int max_hor(int i, int j, std::vector<std::vector<int>>& result) {
    int cnt = 1;
	++j;
    while (j != m && result[i][j] != 0) {
        ++cnt;
        ++j;
    }
    return cnt;
}



int main()
{
    std::cin >> n >> m;
    std::vector<std::vector<int>> vec(n);
    for (int i = 0; i < n; ++i) {
        std::vector<int> v(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> v[i];
        }
        vec[i] = v;
    }
    std::vector<std::vector<int>> result(n);
    int max_res = 0;
    int index_x = n - 1;
    int index_y = m - 1;
    for (int i = 0; i < n; ++i) {
        result[i].resize(m);
    }

    for (int i = 0; i < n; ++i) {
        result[i][m - 1] = vec[i][m - 1];
        if (result[i][m - 1] > max_res) {
            max_res = result[i][m - 1];
            index_x = i;
            index_y = m - 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        result[n - 1][i] = vec[n - 1][i];
        if (result[n - 1][i] > max_res) {
            max_res = result[n - 1][i];
            index_x = n - 1;
            index_y = i;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
			if (vec[i][j]) {
    	        result[i][j] = std::min(result[i + 1][j + 1], std::min(
        	        result[i][j + 1], result[i + 1][j]
	            )) + 1;
	            if (result[i][j] > max_res) {
    	            max_res = result[i][j];
        	        index_x = i;
	                index_y = j;
    	        }
			}
        }
    }
/*	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			std::cout << result[i][j] << " ";
		std::cout << std::endl;
	}*/
	++index_x;
	++index_y;
    std::cout << max_res << '\n' << index_x << " " << index_y;


	return 0;
}
