//3. Супер мега марафон

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int parse_time(const std::string& line) {
    return (line[0] - '0') * 600 + (line[1] - '0') * 60 + (line[3] - '0') * 10 + (line[4] - '0');
}

bool check_avalible(int num, int div, int target) {
	int gcd = std::gcd(num, div);
	if (target % gcd == 0)
		return true;
	return false;
}

int meet_time(int s1, int s2, int l1, int l2) {
 	int delta = s2 - s1;

	int delta_ost = ((delta) % l1 + l1) % l1;;
	int l2_ost = l2 % l1;
	int target_ost = (l1 - delta_ost) % l1;
//	std::cout << s1 << " " << s2 << " " << l1 << " " << l2 << '\n';
//	std::cout << delta << " " << delta_ost << " " << l2_ost << " " << target_ost << std::endl;
	bool flag = check_avalible(l2_ost, l1, target_ost);
	if (flag == 0)
		return -1;
	int y = 0;
	while ((l2_ost * y + delta_ost) % l1)
		++y;
	return l2 * y + s2;
}

//x = (delta + l2 * y) / l1;

std::string convert(int time) {
	if (time == -1)
		return "Never";
 	std::vector<std::string> days = {"Saturday\n", "Sunday\n", "Monday\n", "Tuesday\n", "Wednesday\n", "Thursday\n", "Friday\n"};
	std::string res = "";
	int day_index = time / 1440;
	day_index %= 7;
	res += days[day_index];
	time %= 1440;
	int hr = time / 60;
	int min = time % 60;
	if (hr < 10)
		res += '0';
	res += std::to_string(hr);
	res += ':';
	if (min < 10)
		res += '0';
	res += std::to_string(min);
	return res;
}

int main() {
 	int s1, s2,l1,l2;
	std::string line;
	std::getline(std::cin, line);
	s1 = parse_time(line);
	std::getline(std::cin, line);
	s2 = parse_time(line);
	std::getline(std::cin, line);
	l1 = parse_time(line);
	std::getline(std::cin, line);
	l2 = parse_time(line);
	int time = meet_time(s1,s2,l1,l2);
	std::cout << convert(time);

}
