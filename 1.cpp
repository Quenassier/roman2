#include <iostream>
#include <map>
#include <cmath>

std::string intToRoman(int num) {
    std::map<int, std::string, std::greater<int>> romanMap = {
       {1000, "M"},
       {500, "D"},
       {100, "C"},
       {50, "L"},
       {10, "X"},
       {5, "V"},
       {1, "I"}
    };
    
    // MCMXCIV
    std::string result = "";
    int num1 = num;
    int i = 0;
    for (; num1; num1/=10) i++;
    std::cout << i;
    int n = i - 1;
    for (const auto& entry : romanMap) {
        while (num >= entry.first) {
            if (num > entry.first && num > 4 * pow(10, n) && i - 1 != n) {
                result += romanMap[(pow(10, n - 1))];
                result += romanMap[(pow(10, n))];
                num -= 4 * entry.first;
            } else {
              result += entry.second;
                num -= entry.first;
            }
        }
        if (i % 2 == 0) n--;
        i--;
    }

    return result;
    }

        int main() {
        int intValue;

        std::cout << "Enter an integer: ";
        std::cin >> intValue;

        std::string romanNumeral = intToRoman(intValue);

        std::cout << "The Roman numeral for " << intValue << " is: " << romanNumeral << std::endl;

        return 0;
    }
