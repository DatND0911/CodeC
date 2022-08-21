#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include <string>
#include <fstream>
#include <vector>
#include <memory>

#include "item.h"

namespace combini {

    class FileHandler {
    public:
        // Make a CSV file with one or more rows of Item data
        void writeCsv(const std::string& fileName, const std::vector<Item>& dataSet);
        // Read and return a vector of Item data read from file.
        std::vector<Item> readCsv(const std::string& fileName);
    };

    
}; // combini

#endif // end of FILE_HANDLER_H_
