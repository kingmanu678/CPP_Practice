#include <string>

class Invoice {
public:
    Invoice(std::string partNumber, std::string partDescription, int quantity, int price);
    void setPartNumber(std::string number);
    std::string getPartNumber() const;
    void setPartDescription(std::string description);
    std::string getPartDescription() const;
    void setQuantity(int count);
    int getQuantity() const;
    void setPricePerItem(int price);
    int getPricePerItem() const;
    int getInvoiceAmount() const;

private:
    std::string partNumber;
    std::string partDescription;
    int quantity;
    int pricePerItem;
};