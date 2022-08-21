#include <algorithm>
#include <iostream>

#include "user.h"
#include "helpers.h"

namespace combini {

    class Admin : public User {
    public:
        std::vector<Item> search(const std::vector<Item>& itemList, Attribute attribute, const std::string& value) override;
        
    };

    class Buyer : public User {
    public:
        std::vector<Item> search(const std::vector<Item>& itemList, Attribute attribute, const std::string& value) override;
    };

    // ==============================================================================================================

    std::vector<Item> Admin::search(const std::vector<Item>& itemList, Attribute attribute, const std::string& value) {

        std::vector<Item> newItemList;
        for (int i = 0; i < itemList.size(); i++)
        {
            switch (attribute)
            {
            case Attribute::kListCategory:
            {
                if (itemList[i].getCategory() == value) {
                    newItemList.push_back(itemList[i]);
                }
                break;
            }
                
            case Attribute::kListType:
            {
                if (itemList[i].getType() == value) {
                    newItemList.push_back(itemList[i]);
                }
                break;
            }

            case Attribute::kListExpiredDateBefore:
            {
                int res = Helpers::compareTime(itemList[i].getExpiredDate(), value);
                if (res == -1) {
                    newItemList.push_back(itemList[i]);
                }
                break;
            }
                    
            case Attribute::kListExpiredDateAfter:
            {
                int res = Helpers::compareTime(itemList[i].getExpiredDate(), value);
                if (res == 1) {
                    newItemList.push_back(itemList[i]);
                }
                break;
            }

            case Attribute::kCountRemainingAtDate:
            {

            }
                    
            default:
                break;
            }
        }

        return newItemList;  // TODO : Implement
    }

    ; std::vector<Item> Buyer::search(const std::vector<Item>& itemList, Attribute attribute, const std::string& value) {
        return {};  // TODO : Implement
    }

    User* UserFactory::generateUser(UserType) {
        return new Admin();  // TODO : Implement
    }

}; // combini
