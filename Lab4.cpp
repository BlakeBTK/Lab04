#include <iostream>
#include <fstream>
#include <unordered_map>

void Q1() {
    std::cout << "This is the code for the first question";
}

int Q2() {
    std::ifstream input("input.txt");
    std::string in;
    int sum = 0;
    int amount = 0;
    while(std::getline(input, in)) {
        int check = std::stoi(in);
        sum += check;
        amount++;
    }
    int avg = sum / amount;
    input.close();
    return avg;
}

void Q3() {
    std::ifstream name("NameFile.txt");
    std::ifstream num("input.txt");
    
    using strIntMap = std::unordered_map<std::string, int>;
    strIntMap map;
    std::string thisName;
    std::string thisNum;
    while(std::getline(name, thisName) && std::getline(num, thisNum)) {
        int addInt = std::stoi(thisNum);
        map.insert(std::pair<std::string, int> {thisName, addInt});
    }
    std::string check;
    std::cout << "Enter the name of the student: ";
    std::cin >> check;
    if(map.find(check) == map.end()) {
        std::cout << "Not exists";
    } else {
        std::cout << map[check];
    }
    
}

int main(int argc, char *argv[]) {
    if(argc == 2) {
        char check = argv[1][1];
        switch(check) {
            case '1':
                Q1();
                break;
            case '2':
                std::cout << Q2();
                break;
            case '3':
                Q3();
                break;
        }
    } else {
        std::cout << "Not valid arguments";
    }
    

    return 0;
}
