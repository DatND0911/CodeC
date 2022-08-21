#ifndef HELPERS_H_
#define HELPERS_H_

#include <string>

namespace combini {

    class Helpers {
    public:
        static std::string readAllFromFile(const std::string& file);
        static bool removeFileIfExisted(const std::string& file);
        static int compareTime(std::string dateA, std::string dateB);
        static bool isValidDate(std::string date);
    };

}; // combini

#endif // HELPERS_H_