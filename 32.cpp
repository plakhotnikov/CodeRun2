// 32. Честный дележ


#pragma GCC optimize("O3")
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>


int count_pozitive(int array[]) {
    int k = 0;
    for (int i = 0; i < 26; ++i)
        if (array[i])
            ++k;
    return k;
}


bool chech_equal_array(int a[], int b[]) {
    for (int i = 0; i < 26; ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool check_substr(int len, const std::string& str) {
    int a[26];
    memset(a,0,sizeof(a));
    for (int i = 0; i < len; ++i)
        ++a[str[i] - 'a'];
    int b[26];
    for (int i = 1; i <= (str.size() / len - 1); ++i) {
        memset(b,0,sizeof(b));
        for (int j = 0; j < len; ++j)
            ++b[str[i * len + j] - 'a'];
        if (!chech_equal_array(a,b))
            return false;
    }
    return true;
}

int func(const std::string& str) {
    int array_letters_counter[26];
    memset(array_letters_counter, 0, sizeof(array_letters_counter));
    for (char c : str) {
        ++array_letters_counter[c - 'a'];
    }

    // нужно найти подстроку минимальной длины

    // 2. len(answer) % cnt_pos == 0
    //     следовательно, в тот же цикл можем добавить условие, при
    //     при котором будет просто continue;

    int cnt_pos = count_pozitive(array_letters_counter);

	int len = cnt_pos;
	while (len != str.size()) {
		if (str.size() % len == 0 && check_substr(len,str))
			return len;
		++len;
	}
    return str.size();
}




int main()
{
    std::string str;
    std::cin >> str;

    std::cout << str.size() / func(str);



	return 0;
}
