// 13. Пара букв

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string text;
    std::getline(std::cin, text);

    int cnt[26][26];
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			cnt[i][j] = 0;

    for (int i = 0; i < text.size() - 1; ++i) {
        if (text[i] != ' ' && text[i + 1] != ' ') {
            ++cnt[text[i] - 'A'][text[i + 1] - 'A'];
        }
    }
    int maxres = -1;
    int index1 = -1;

    int index2 = -1;

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
        	if (cnt[i][j] >= maxres) {
				maxres = cnt[i][j];
				index1 = i;
				index2 = j;
			}
		}
	}

    std::cout << static_cast<char>(index1 + 'A') << static_cast<char>(index2 + 'A');

	return 0;
}
