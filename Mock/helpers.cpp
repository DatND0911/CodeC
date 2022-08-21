#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdio>
#include "helpers.h"

namespace combini {

    std::string Helpers::readAllFromFile(const std::string& file) {
        std::ifstream f(file);
        std::string str;
        if (f) {
            std::ostringstream ss;
            ss << f.rdbuf();
            str = ss.str();
        }

        return str;
    }

    bool Helpers::removeFileIfExisted(const std::string& file) {
        std::ifstream f(file);
        if (f) {
            if (remove(file.c_str())) {
                std::cout << "Failed to remove " << file << ". Cannot proceed\n";
                return false;
            }
        }

        return true;
    }

    int Helpers::compareTime(std::string dateA, std::string dateB) {
        if (dateA.empty() || dateB.empty()) throw std::exception("Not valid time");
        dateA = dateA.substr(6, 4) + dateA.substr(3, 2) + dateA.substr(0, 2);
        dateB = dateB.substr(6, 4) + dateB.substr(3, 2) + dateB.substr(0, 2);
        // dua date ve dang yyyymmdd

        return dateA.compare(dateB);
    }

    bool Helpers::isValidDate(std::string date) {
        if (date.empty()) {
            return false;
        }
        try {  // try catch xu ly exception
            int day, month, year;
            day = stoi(date.substr(0, 2));
            month = stoi(date.substr(3, 2));
            year = stoi(date.substr(6, 4));

            int x[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            if (!(year % 400) || (year % 4 == 0 && year % 100)) x[2]++;  // nam nhuan tang ngay thang 2 len 1
            if (month >= 1 && month <= 12 && day <= x[month] && day >= 0) return true;
            return false;
        }
        catch (const std::exception& ex) {
            return false;
        }
    }

}; // combini
