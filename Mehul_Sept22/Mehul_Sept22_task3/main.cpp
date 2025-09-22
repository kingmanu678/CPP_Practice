#include <iostream>
#include "Invoice.h"

int main() {
    Invoice invoice("12345", "Hammer", 10, 15);

    std::cout << "Part Number: " << invoice.getPartNumber() << std::endl;
    std::cout << "Part Description: " << invoice.getPartDescription() << std::endl;
    std::cout << "Quantity: " << invoice.getQuantity() << std::endl;
    std::cout << "Price Per Item: " << invoice.getPricePerItem() << std::endl;
    std::cout << "Invoice Amount: " << invoice.getInvoiceAmount() << std::endl;

    return 0;
}