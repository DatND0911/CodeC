#include <iostream>
#include <string>
#include "file_handler.h"
#include "user.h"
#include "helpers.h"

using combini::FileHandler;
using combini::UserFactory;
using combini::Item;
using combini::User;
using combini::Helpers;
using combini::UserType;
using combini::Attribute;

struct TestData {
    UserType userType;
    Attribute attribute;
    std::string query;
    std::string result;
};

std::vector<TestData> testList{
    {
        UserType::kAdmin,
        Attribute::kListCategory,
        "Utensil",
        "Utensil,U0002,Import,Top Oven,15/05/2022,15/05/2030,10,set\n"
        "Utensil,U0001,Import,Big Glass,15/05/2022,15/06/2025,100,set\n"
        "Utensil,U0003,Import,Silver Spoon,15/05/2022,15/05/2025,200,set\n"
        "Utensil,U0002,Export,Top Oven,16/05/2022,15/05/2030,10,set"
    },
    {
        UserType::kAdmin,
        Attribute::kListCategory,
        "Drink",
        "Drink,D0003,Import,Oolong Tea,15/05/2022,15/09/2022,100,litres\n"
        "Drink,D0001,Import,Wine,15/05/2022,15/07/2025,200,litres\n"
        "Drink,D0002,Import,Beer,15/05/2022,15/05/2023,100,litres"
    },
    {
        UserType::kAdmin,
        Attribute::kListCategory,
        "Food",
        "Food,F0001,Import,Fresh Meat,15/05/2022,31/05/2022,10,kg\n"
        "Food,F0003,Import,Goat Meat,15/05/2022,31/05/2022,100,kg\n"
        "Food,F0002,Import,Spinach,15/05/2022,15/06/2022,200,kg\n"
        "Food,F0002,Export,Spinach,16/05/2022,15/06/2022,100,kg\n"
        "Food,F0002,Import,Spinach,01/06/2022,01/07/2022,50,kg"
    },
    {
        UserType::kAdmin,
        Attribute::kListType,
        "Import",
        "Food,F0001,Import,Fresh Meat,15/05/2022,31/05/2022,10,kg\n"
        "Drink,D0003,Import,Oolong Tea,15/05/2022,15/09/2022,100,litres\n"
        "Food,F0003,Import,Goat Meat,15/05/2022,31/05/2022,100,kg\n"
        "Drink,D0001,Import,Wine,15/05/2022,15/07/2025,200,litres\n"
        "Utensil,U0002,Import,Top Oven,15/05/2022,15/05/2030,10,set\n"
        "Food,F0002,Import,Spinach,15/05/2022,15/06/2022,200,kg\n"
        "Drink,D0002,Import,Beer,15/05/2022,15/05/2023,100,litres\n"
        "Utensil,U0001,Import,Big Glass,15/05/2022,15/06/2025,100,set\n"
        "Utensil,U0003,Import,Silver Spoon,15/05/2022,15/05/2025,200,set\n"
        "Food,F0002,Import,Spinach,01/06/2022,01/07/2022,50,kg"
    },
    {
        UserType::kAdmin,
        Attribute::kListType,
        "Export",
        "Food,F0002,Export,Spinach,16/05/2022,15/06/2022,100,kg\n"
        "Utensil,U0002,Export,Top Oven,16/05/2022,15/05/2030,10,set"
    },
    {
        UserType::kAdmin,
        Attribute::kListExpiredDateBefore,
        "16/05/2023",
        "Food,F0001,Import,Fresh Meat,15/05/2022,31/05/2022,10,kg\n"
        "Drink,D0003,Import,Oolong Tea,15/05/2022,15/09/2022,100,litres\n"
        "Food,F0003,Import,Goat Meat,15/05/2022,31/05/2022,100,kg\n"
        "Food,F0002,Import,Spinach,15/05/2022,15/06/2022,200,kg\n"
        "Drink,D0002,Import,Beer,15/05/2022,15/05/2023,100,litres\n"
        "Food,F0002,Export,Spinach,16/05/2022,15/06/2022,100,kg\n"
        "Food,F0002,Import,Spinach,01/06/2022,01/07/2022,50,kg"
    },
    {
        UserType::kAdmin,
        Attribute::kListExpiredDateAfter,
        "16/05/2023",
        "Drink,D0001,Import,Wine,15/05/2022,15/07/2025,200,litres\n"
        "Utensil,U0002,Import,Top Oven,15/05/2022,15/05/2030,10,set\n"
        "Utensil,U0001,Import,Big Glass,15/05/2022,15/06/2025,100,set\n"
        "Utensil,U0003,Import,Silver Spoon,15/05/2022,15/05/2025,200,set\n"
        "Utensil,U0002,Export,Top Oven,16/05/2022,15/05/2030,10,set"
    },
    {
        UserType::kAdmin,
        Attribute::kCountRemainingAtDate,
        "17/05/2022",
        "Food,F0001,Count,Fresh Meat,17/05/2022,31/05/2022,10,kg\n"
        "Drink,D0003,Count,Oolong Tea,17/05/2022,15/09/2022,100,litres\n"
        "Food,F0003,Count,Goat Meat,17/05/2022,31/05/2022,100,kg\n"
        "Drink,D0001,Count,Wine,17/05/2022,15/07/2025,200,litres\n"
        "Utensil,U0002,Count,Top Oven,17/05/2022,15/05/2030,0,set\n"
        "Food,F0002,Count,Spinach,17/05/2022,15/06/2022,100,kg\n"
        "Drink,D0002,Count,Beer,17/05/2022,15/05/2023,100,litres\n"
        "Utensil,U0001,Count,Big Glass,17/05/2022,15/06/2025,100,set\n"
        "Utensil,U0003,Count,Silver Spoon,17/05/2022,15/05/2025,200,set"
    },
    {
        UserType::kBuyer,
        Attribute::kCountRemainingAtDate,
        "17/05/2022",
        "Food,F0001,Count,Fresh Meat,17/05/2022,31/05/2022,10,kg\n"
        "Drink,D0003,Count,Oolong Tea,17/05/2022,15/09/2022,100,litres\n"
        "Food,F0003,Count,Goat Meat,17/05/2022,31/05/2022,100,kg\n"
        "Drink,D0001,Count,Wine,17/05/2022,15/07/2025,200,litres\n"
        "Food,F0002,Count,Spinach,17/05/2022,15/06/2022,100,kg\n"
        "Drink,D0002,Count,Beer,17/05/2022,15/05/2023,100,litres\n"
        "Utensil,U0001,Count,Big Glass,17/05/2022,15/06/2025,100,set\n"
        "Utensil,U0003,Count,Silver Spoon,17/05/2022,15/05/2025,200,set"
    }
};

void testExecutor(const TestData& td, const std::string& inputFile) {
    static int testCount = 1;
    User* user = nullptr;
    FileHandler fileHandler;
    std::vector<Item> itemList;
    std::vector<Item> resultList;
    std::string resultFile = "resultFile" + std::to_string(testCount) + ".txt";

    std::cout << "[Test #" << testCount++ << "]";

    if (!Helpers::removeFileIfExisted(resultFile)) {
        exit(-1);
    }

    // Get all items from file
    itemList = fileHandler.readCsv(inputFile);

    // Create user.
    user = UserFactory::generateUser(td.userType);
    resultList = user->search(itemList, td.attribute, td.query);

    fileHandler.writeCsv(resultFile, resultList);

    /*std::string result = td.result;
    std::string result1 = Helpers::readAllFromFile(resultFile);
    std::cout << result1;*/

    if (td.result == Helpers::readAllFromFile(resultFile)) {
        std::cout << "PASSED!!!\n\n";
    }
    else {
        std::cout << "FAILED. Expected result:\n" << td.result << "\n\n";
    }

    delete user;
}

int main(int argc, char* argv[]) {
    // Running through all the test cases
    for (auto td : testList) {
        testExecutor(td, "goods.csv");
    }

    /*FileHandler* fileHandler = new FileHandler();
    std::vector<Item> itemList = fileHandler->readCsv("good.csv");
    fileHandler->writeCsv("outFile.csv", itemList);*/

    //std::string str;
    //fflush(stdin);
    //getline(std::cin, str);
    ////str = str.substr(0, 2) + str.substr(3, 2) + str.substr(6, 4);
    //int test = Helpers::compareTime("28/01/2000", "27/01/2000");

    return 0;
}