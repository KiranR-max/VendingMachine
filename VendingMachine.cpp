#include "VendingMachine.hpp"
#include <iostream>

void VendingMachine::insertCoin(int coin) {
    switch (state) {
        case IDLE:
            std::cout << "select an item first." << std::endl;
            break;
        case ITEM_SELECTED:
            balance += coin;
            if (balance >= selectedItem) {
                dispenseItem();
            } 
            else {
                state = INSUFFICIENT_BALANCE;
                std::cout << "Insufficient balance." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation for current state." << std::endl;
            break;
    }
}

void VendingMachine::selectItem(int itemNumber) {
    switch (state) {
        case IDLE:
            selectedItem = itemNumber;
            state = ITEM_SELECTED;
            std::cout << " insert coins totaling " << selectedItem << std::endl;
            break;
        case ITEM_SELECTED:
            std::cout << "You have already selected an item. Please insert coins totaling " << selectedItem  << std::endl;
            break;
        default:
            std::cout << "Invalid operation for current state." << std::endl;
            break;
    }
}

void VendingMachine::dispenseItem() {
    state = ITEM_DISPENSED;
    balance -= selectedItem;
    std::cout << "Item dispensed." << std::endl;
}

void VendingMachine::cancelTransaction() {
    if (state == ITEM_SELECTED || state == INSUFFICIENT_BALANCE) {
        state = IDLE;
        selectedItem = -1;
        balance = 0;
        std::cout << "Transaction canceled." << std::endl;
    } else {
        std::cout << "Invalid operation for current state." << std::endl;
    }
}

void VendingMachine::reset() {
    state = IDLE;
    selectedItem = -1;
    balance = 0;
    std::cout << "Vending machine is reset." << std::endl;
}

VendingMachine::State VendingMachine::getState() const {
    return state;
}

int VendingMachine::getBalance() const { //does not modify the object's state
    return balance;
}
