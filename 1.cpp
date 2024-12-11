#include <iostream>
#include <string>
using namespace std;

struct Transaction {
private:
    string Number;
    int amount;
    string currency;

public:

Transaction(const string& number, int amt, const string& curr)
    : Number(number), amount(amt), currency(curr) {}

string getNumber() const {
    return Number;
}

int getAmount() const {
    return amount;
}

string getCurrency() const {
    return currency;
}

void setNumber(const string& newNumber) {
    Number = newNumber;
}

void setAmount(int newAmount) {
    if (newAmount >= 0) {
        amount = newAmount;
    }
}

void setCurrency(const string& newCurrency) {
    currency = newCurrency;
}

bool validateNumber() const {
    if (Number.length() != 20) return false;
    for (char c : Number) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void addTimestampTonNumber() {
    if (validateNumber()) {
        string timestamp = "20231204_123456";
        Number += "_" + timestamp;
} else {
    cout << "Номер транзакції недійсний" << endl;
    }
}

void displayInfo() const {
cout << "Номер транзакції " << Number << ", Рахунок " << amount << ", Валюта " << currency << endl;
    }
};

int main() {

Transaction transaction("40817810900000012345", 159, "UAH");
transaction.displayInfo();
transaction.addTimestampTonNumber();
transaction.displayInfo();

}
