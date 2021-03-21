//#include <boost/filesystem.hpp>
//#include <filesystem>
#include <fstream>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"
#include "../../../source/repos/5.4/json.hpp"

namespace fs = std::experimental::filesystem;
using nlohmann::json;


struct Human {
    std::string name;
    unsigned int age;
    std::string address;
    double weight;

    friend std::istream& operator>> (std::istream& in, Human& human);
};

std::istream& operator>> (std::istream& in, Human& human)
{
    in >> human.name;
    in >> human.address;
    in >> human.age;
    in >> human.weight;

    return in;
}

int main(int argc, char** argv)
{

    std::vector<Human> h(3);

    for (size_t i = 0; i < h.size(); i++) {
        std::cout << "Enter human #" << i + 1 << ": ";
        std::cin >> h[i];
    }

    json j;


    std::string outFile;

    for (size_t i = 0; i < h.size(); i++) {
        outFile = "out" + std::to_string(i + 1) + ".dat";
        std::ofstream out_1(outFile);

        if (!out_1.is_open()) {
            std::cerr << "Can not open: " << outFile << std::endl;
            return EXIT_FAILURE;
        }

        j["name"] = h[i].name;
        j["address"] = h[i].address;
        j["age"] = h[i].age;
        j["weight"] = h[i].weight;

        for (auto iterator = j.begin(); iterator != j.end(); ++iterator) {
            out_1 << iterator.key() << ": " << iterator.value() << "\n";
        }

        out_1.close();
    }

    return EXIT_SUCCESS;
}