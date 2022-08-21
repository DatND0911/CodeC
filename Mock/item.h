#ifndef ITEM_H_
#define ITEM_H_

#include <string>

namespace combini {

    enum class Attribute {
        kListCategory,
        kListType,
        kListExpiredDateBefore,
        kListExpiredDateAfter,
        kCountRemainingAtDate,
    };

    class Item {
    public:
        Item(const std::string& category, const std::string& id, const std::string& type, const std::string& description,
            const std::string& transferDate, const std::string& expiredDate, const int quantity, const std::string& unit) {
            mCategory = category;
            mID = id;
            mType = type;
            mDescription = description;
            mTransferDate = transferDate;
            mExpiredDate = expiredDate;
            mQuantity = quantity;
            mUnit = unit;
        }

        ~Item() {}

        const std::string& getCategory() const;
        void setCategory(const std::string& category);

        const std::string& getId() const;
        void setId(const std::string& id);

        const std::string& getType() const;
        void setType(const std::string& type);

        const std::string& getDescription() const;
        void setDescription(const std::string& des);

        const std::string& getTransferDate() const;
        void setTransferDate(const std::string& date);

        const std::string& getExpiredDate() const;
        void setExpiredDate(const std::string& date);

        int getQuantity() const;
        void setQuantity(int quantity);

        const std::string& getUnit() const;
        void setUnit(const std::string& unit);

        std::string printAsString() const;

    private:
        std::string mCategory{ "" };
        std::string mID{ "" };
        std::string mType{ "" };
        std::string mDescription{ "" };
        // date in dd/MM/yyyy
        std::string mTransferDate{ "" };
        // date in dd/MM/yyyy
        std::string mExpiredDate{ "" };
        int mQuantity{ 0 };
        std::string mUnit{ "" };
    }; // end of Item

}; // combini

#endif // end of ITEM_H_
