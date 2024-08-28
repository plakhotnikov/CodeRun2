// задача 1. шары и корзины



#include <iostream>
#include <vector>

int func(int x) {
	int d = 1;
	while (d < x)
		d *= 2;
	return d;
}

void update_tree(std::vector<int>& tree, int left, int right) {
 	while (left != right) {
     	left /= 2;
		right /= 2;
		for (int i = left; i <= right; ++i) {
         	tree[i] = ((long long )tree[i * 2] * tree[i * 2 + 1]) % (int)(1e9+7);
		}
	}
	left /= 2;
	while (left != 0) {
     	tree[left] = ((long long)tree[left * 2] * tree[left * 2 + 1]) % (int)(1e9+7);
		left /= 2;
	}
}

int get_mul(const std::vector<int>& tree, int left, int right) {
	if (left == right)
		return tree[left];
	long long ret = 1;
 	while (left <= right) {
     	if (left % 2 == 1) {
			ret = ((long long) ret *  tree[left++]) % (int)(1e9 + 7);
		}
		if (right % 2 == 0) {
			ret = ((long long) ret *  tree[right--]) % (int)(1e9 + 7);
		}
		left /= 2;
		right /= 2;
	}
	return ret;
}


int main() {
	 	int n;
		std::cin >> n;
		int sz = func(n);
		std::vector<int> tree(2 * sz, 1);
		for (int i = sz; i < sz + n; ++i)
			std::cin >> tree[i];
		int offset = sz - 1;
		update_tree(tree, offset + 1, offset + n);
		int q;
		std::cin >> q;
		while (q--) {
    	 	int t,l,r;
			std::cin >> t >> l >> r;
			if (t) {
				std::cout << get_mul(tree, offset + l, offset + r) << std::endl;
			}
			else {
        	 	for (int i = l; i <= r; ++i) {
            	 	++tree[offset + i];
				}
				update_tree(tree, offset + l, offset + r);
			}
		}
}
