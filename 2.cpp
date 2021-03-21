#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::fstream fin;
    fin.open("../test.txt", std::ios::in);
    std::string s;
    std::getline(fin, s);
    int k = s.length();
    std::cout << k << std::endl;
    std::cout << fin.tellg() << std::endl;
    std::cout << "Enter a string number: ";
    int str;
    std::cin >> str;
    fin.seekg((k + 1) * str);
    if (!std::getline(fin, s).eof())
        std::cout << s << std::endl;
    else
        std::cout << "EoF reached" << std::endl;
    fin.close();
    return 0;
}