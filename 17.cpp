// 17. Кристаллы


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int med(int x, int y, int z) {
	if (x > y) {
     	if (x > z)
			return std::max(y,z);
		else
			return x;
	}
	else {
     	if (y > z)
			return std::max(x,z);
		else
			return y;
	}
}

std::string func() {
    std::string a,b,c;
    std::cin >> a >> b >> c;
    std::string templ_a, templ_b, templ_c;
    templ_a = templ_b = templ_c = "";
    templ_a += a[0];
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != templ_a.back())
            templ_a += a[i];
    }
    templ_b += b[0];
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] != templ_b.back())
            templ_b += b[i];
    }
    templ_c += c[0];
    for (int i = 1; i < c.size(); ++i) {
        if (c[i] != templ_c.back())
            templ_c += c[i];
    }
    if (templ_a != templ_b || templ_a != templ_c)
        return "IMPOSSIBLE";
    int n = templ_a.size();
    std::vector<int> vec_a(n);
    std::vector<int> vec_b(n);
    std::vector<int> vec_c(n);
    int j = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == templ_a[j])
            ++vec_a[j];
        else
            ++vec_a[++j];
    }
    j = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == templ_a[j])
            ++vec_b[j];
        else
            ++vec_b[++j];
    }
    j = 0;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == templ_a[j])
            ++vec_c[j];
        else
            ++vec_c[++j];
    }
    templ_a = "";
    for (int i = 0; i < n; ++i) {
        int avg = med(vec_a[i],vec_b[i], vec_c[i]);
        for (int j = 0; j < avg; ++j)
            templ_a += templ_b[i];
    }
    return templ_a;

}


int main()
{

    std::cout << func();


	return 0;
}
