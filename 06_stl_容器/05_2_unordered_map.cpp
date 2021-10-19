#include <iostream>
#include <unordered_map>

using namespace std;
void print_map(std::unordered_map<string, string> &mymap)
{
    std::string str_temp;
    for (std::unordered_map<std::string, std::string>::iterator it = mymap.begin(); it != mymap.end(); ++it)
    {
        // printf("%s => %s\n", it->first.data(), it->second.data());
        // printf("typeid(it->first): %s\n", typeid(it->first).name());//NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
        str_temp = str_temp + it->first + " : " + it->second + "\t";
    }
    // cout << str_temp << endl;
    printf("%s\n", str_temp.data());
}
int main(int argc, char *argv[])
{
    unordered_map<string, string> hash =
        {{"a", to_string(12)},
         {"b", to_string(1.5)},
         {"c", "cccc"}};
    print_map(hash);

    cout << "------------------1.插入/更新---------------------" << endl;
    hash["a"] = "aaaa"; //更新
    hash["d"] = "dddd"; //插入
    print_map(hash);

    cout << "------------------2.查找---------------------" << endl;
    cout << "hash.count(a): " << hash.count("a") << endl; //1
    cout << "hash.count(z): " << hash.count("z") << endl; //0

    return -1;
}