#include "VendingMachine.hpp"
#include <iostream>
#include <string>

int main() {
    VendingMachine machine;


    // initial state and balance
    std::cout << "Current state: IDLE" << std::endl;
    std::cout << "Current balance: 0" << std::endl;

    while (true) {
        //  for input
        std::cout << "Enter choice ('select', 'insert', 'dispense', 'cancel', or 'reset'): ";
        std::string choice;
        std::cin >> choice;
        std::cout<<"-----------------"<<std::endl;

        // user input
        if (choice == "select") {
            std::cout << "Enter item number: ";
            int itemNumber;
            std::cin >> itemNumber;
            machine.selectItem(itemNumber);
        } else if (choice == "insert") {
            std::cout << "Enter coin value: ";
            int coinValue;
            std::cin >> coinValue;
            machine.insertCoin(coinValue);
        } else if (choice == "dispense") {
            machine.dispenseItem();
        } else if (choice == "cancel") {
            machine.cancelTransaction();
        } else if (choice == "reset") {
            machine.reset();
        } else {
            std::cout << "Invalid choice." << std::endl;
            continue; // Skip state/balance display if invalid choice entered
        }
        std::cout<<"-----------------"<<std::endl;


        // updated state and balance
        std::cout << "Current state: ";
        switch (machine.getState()) {
            case VendingMachine::IDLE:
                std::cout << "IDLE";
                break;
            case VendingMachine::ITEM_SELECTED:
                std::cout << "ITEM_SELECTED";
                break;
            case VendingMachine::ITEM_DISPENSED:
                std::cout << "ITEM_DISPENSED";
                break;
            case VendingMachine::INSUFFICIENT_BALANCE:
                std::cout << "INSUFFICIENT_BALANCE";
                break;
        }
        // std::cout<<"-----------------"<<std::endl;
        std::cout << std::endl;
        std::cout << "Current balance: " << machine.getBalance() << std::endl;
        std::cout<<"-----------------"<<std::endl;
    }

    return 0;
}
