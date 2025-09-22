#include "Invoice.h"

Invoice::Invoice(std::string partNumber, std::string partDescription, int quantity, int price) {
    setPartNumber(partNumber);
    setPartDescription(partDescription);
    setQuantity(quantity);
    setPricePerItem(price);
}

void Invoice::setPartNumber(std::string number) {
    partNumber = number;
}

std::string Invoice::getPartNumber() const {
    return partNumber;
}

void Invoice::setPartDescription(std::string description) {
    partDescription = description;
}

std::string Invoice::getPartDescription() const {
    return partDescription;
}

void Invoice::setQuantity(int count) {
    if (count > 0) {
        quantity = count;
    } else {
        quantity = 0;
    }
}

int Invoice::getQuantity() const {
    return quantity;
}

void Invoice::setPricePerItem(int price) {
    if (price > 0) {
        pricePerItem = price;
    } else {
        pricePerItem = 0;
    }
}

int Invoice::getPricePerItem() const {
    return pricePerItem;
}

int Invoice::getInvoiceAmount() const {
    return getQuantity() * getPricePerItem();
}