#ifndef VENDINGMACHINE_HPP
#define VENDINGMACHINE_HPP

class VendingMachine {
public:
    enum State {
        IDLE=1,
        ITEM_SELECTED,
        ITEM_DISPENSED,
        INSUFFICIENT_BALANCE
    };

    void insertCoin(int coin);
    void selectItem(int itemNumber);
    void dispenseItem();
    void cancelTransaction();
    void reset();

    State getState() const;
    int getBalance() const;

private:
    int balance = 0;
    State state = IDLE;
    int selectedItem = -1;
};

#endif // VENDINGMACHINE_HPP
