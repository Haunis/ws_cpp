#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	std::map<std::string, std::string> mymap =
		{
			{"mom", to_string(12)},
			{"dad", to_string(1.5)},
			{"bro", "bro_value"}};

	std::string str_temp;
	for (std::map<std::string, std::string>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		//		std::cout << it->first << " => " << it->second << '\n';
		//		printf("%s => %s\n", it->first.data(), it->second.data());
		str_temp = str_temp + it->first + "=" + it->second + "\n";

	//	str_temp = "=>";
	cout << str_temp << endl;
	printf("%s", str_temp.data());
	return 0;
}
