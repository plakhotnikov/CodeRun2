// 30. Табло

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>


struct Score {
    int first, second;
    std::string player_name;
};

void convert_info(const std::string& info, Score& score) {
    int colon_index = info.find(":");
    score.first = std::atoi(info.substr(0, colon_index).c_str());
    int name_index = info.find(" ") + 1;
    score.second = std::atoi(info.substr(colon_index + 1,
        name_index - colon_index - 2).c_str());
    score.player_name = info.substr(name_index, info.size() - name_index);
}

int main()
{
	int n;
    std::cin >> n;
    std::map<std::string, int> goals;
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::cin >> name;
        goals[name] = 0;
    }
    std::cin >> n;
    Score prev{0,0,""};
    Score cur;
    for (int i = 0; i <= n; ++i) {
        std::string info;
        std::getline(std::cin, info);
        convert_info(info, cur);
        int total = cur.first - prev.first + cur.second - prev.second;
        goals[cur.player_name] += total;
        prev = cur;
    }



    int max_player_score = -1;
    std::string name = "";
    for (auto& p : goals)
        if (p.second >= max_player_score) {
            max_player_score = p.second;
            name = p.first;
        }
    std::cout << name << " " << max_player_score << std::endl;

	return 0;
}
