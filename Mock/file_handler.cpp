#include "file_handler.h"
#include "item.h"

namespace combini {

	/**
	 * Make a CSV file with one or more rows of Item data
	 * @param fileName: the name of the file
	 * @param dataSet: represented as a vector of Item data
	 * @return: none
	 */
	void FileHandler::writeCsv(const std::string& fileName, const std::vector<Item>& dataSet) {
		// TODO : Implement
		//1. mo file
		std::ofstream outFile;
		outFile.open(fileName, std::ios::app);

		//2. duyet dataSet in ra -> dùng printfAsString
		if (outFile.is_open()) {
			/*for (auto i : dataSet) {
				outFile << i.printAsString() << std::endl;
			}*/
			for (int i = 0; i < dataSet.size(); i++)
			{
				if (i < dataSet.size() - 1) {
					outFile << dataSet[i].printAsString() << std::endl;
				}
				else {
					outFile << dataSet[i].printAsString();
				}
			}
		}
		//3. dong file
		outFile.close();
	}
	/**
	 * Read a CSV file
	 * @param fileName: the name of the file
	 * @return: a vector of Item data
	 */

	 // tach chuoi thanh vector "a,b,c,d" => vector
	std::vector<std::string> split(std::string str, char seperator) {
		int currIndex = 0, i = 0;
		int startIndex = 0, endIndex = 0;
		std::vector<std::string> res;
		while (i <= str.length()) {
			if (str[i] == seperator || i == str.length()) {
				endIndex = i;
				std::string subStr = "";
				subStr.append(str, startIndex, endIndex - startIndex);
				res.push_back(subStr);
				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
		return res;
	}

	// cat chuoi trong ben trai
	static inline void ltrim(std::string& s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
			return !std::isspace(ch);
			}));
	}

	// cat chuoi trong ben phai
	static inline void rtrim(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
			}).base(), s.end());
	}

	// cat chuoi trong 2 dau
	static inline void trim(std::string& s) {
		ltrim(s);
		rtrim(s);
	}

	std::vector<Item> FileHandler::readCsv(const std::string& fileName) {
		//1. mo file
		std::ifstream myFile;
		myFile.open(fileName);

		//2. xem cau truc file data de doc
		std::vector<Item> itemList;
		bool open = myFile.is_open();

		while (myFile.good()) {
			std::string line;
			getline(myFile, line, '\n');
			std::vector<std::string> row = split(line, ',');
			for (int i = 0; i < row.size(); i++) {
				trim(row[i]);
			}

			Item item(row[0], row[1], row[2], row[3], row[4], row[5], stoi(row[6]), row[7]);
			itemList.push_back(item);
		}

		//3. dong file
		myFile.close();

		return itemList;  // TODO : Implement
	}

}; // combini
