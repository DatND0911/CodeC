#ifndef USER_H_
#define USER_H_

#include <vector>
#include "item.h"

namespace combini {

    enum class UserType {
        kAdmin,
        kBuyer
    };

    class User {
    public:
        User() {}
        virtual ~User() {}

        virtual std::vector<Item> search(const std::vector<Item>& itemList, Attribute attribute, const std::string& value) = 0;
    };

    class UserFactory {
    public:
        static User* generateUser(UserType);
    };

}; // combini

#endif // end of USER_H_
