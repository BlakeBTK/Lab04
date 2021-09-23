/*****************************************
* CSE 278 Lab 04
* Author: Blake Kuechler
* Date: 9/23/2021
* Description: This program contains multiple functions that work with input files as well
* as unordered maps whislt using argv to select which function to run
******************************************/
#include <iostream>
#include <fstream>
#include <unordered_map>

// Question 1: Tester for the use of argv
void Q1() {
    std::cout << "This is the code for the first question";
}

// Takes the input from a file that has grades, and finds the average of the grades
int Q2() {
    std::ifstream input("input.txt");
    std::string in;
    int sum = 0;
    int amount = 0;
    // Loop that adds all the grades in the file together as well as counts the 
    // amount of individual grades there are
    while(std::getline(input, in)) {
        int check = std::stoi(in);
        sum += check;
        amount++;
    }
    // Calculates the average of the grades
    int avg = sum / amount;
    input.close();
    return avg;
}

// Question 3: Creates an unordered map using names of students and grades in two
// seperate input files
void Q3() {
    std::ifstream name("NameFile.txt");
    std::ifstream num("input.txt");
    
    using strIntMap = std::unordered_map<std::string, int>;
    strIntMap map;
    std::string thisName;
    std::string thisNum;
    // Loop that stores the names and grades in the unordered map
    while(std::getline(name, thisName) && std::getline(num, thisNum)) {
        int addInt = std::stoi(thisNum);
        map.insert(std::pair<std::string, int> {thisName, addInt});
    }
    std::string check;
    std::cout << "Enter the name of the student: ";
    std::cin >> check;
    // Checks to see if the name inputted is in the unordered map, states it doesn't
    // exist if not found
    if(map.find(check) == map.end()) {
        std::cout << "Not exists";
    } else {
        std::cout << map[check];
    }
    
}

int main(int argc, char *argv[]) {
    // Function that checks to see which function in the program to run, and outputs
    // error message if there isn't a valid argument given
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
