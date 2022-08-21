#include <string>
#include <cstdio>

#include "item.h"
namespace combini {

    const std::string& Item::getCategory() const {
        return mCategory;
    }

    void Item::setCategory(const std::string& category) {
        mCategory = category;
    }

    const std::string& Item::getId() const {
        return mID;
    }

    void Item::setId(const std::string& id) {
        mID = id;
    }

    const std::string& Item::getType() const {
        return mType;
    }

    void Item::setType(const std::string& type) {
        mType = type;
    }

    const std::string& Item::getDescription() const {
        return mDescription;
    }

    void Item::setDescription(const std::string& des) {
        mDescription = des;
    }

    const std::string& Item::getTransferDate() const {
        return mTransferDate;
    }

    void Item::setTransferDate(const std::string& date) {
        mTransferDate = date;
    }

    const std::string& Item::getExpiredDate() const {
        return mExpiredDate;
    }

    void Item::setExpiredDate(const std::string& date) {
        mExpiredDate = date;
    }

    int Item::getQuantity() const {
        return mQuantity;
    }

    void Item::setQuantity(int quantity) {
        mQuantity = quantity;
    }

    const std::string& Item::getUnit() const {
        return mUnit;
    }

    void Item::setUnit(const std::string& unit) {
        mUnit = unit;
    }

    std::string Item::printAsString() const {
        std::string str = 
              mCategory + "," + mID + "," + mType + ","
            + mDescription + "," + mTransferDate + "," + mExpiredDate + ","
            + std::to_string(mQuantity) + "," + mUnit;
        return str;
    }

}; // combini
