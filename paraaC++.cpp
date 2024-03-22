#include <stdio.h>
#include <iostream>
using namespace std;

class BankAc {
private: 
    int accountNumber;
    double balance;
    double interestRate;
public:

    BankAc createAccount(int accNumber, double initialBalance) {
        BankAc account;
        account.accountNumber = accNumber;
        account.balance = initialBalance;
        account.interestRate = 0.0;
        return account;
    }

    void deposit(BankAc* account, double amount) {
        account->balance += amount;
    }

    void withdraw(BankAc* account, double amount) {
        if (amount <= account->balance) {
            account->balance -= amount;
        }
        else {
            printf("Ошибка: Недостаточно средств на счете.\n");
        }
    }

    double getBalance(BankAc* account) {
        return account->balance;
    }

    double getInterest(BankAc* account) {
        return account->balance * account->interestRate * (1.0 / 12);
    }

    int getAccountNumber(BankAc* account) {
        return account->accountNumber;
    }

    void setInterestRate(BankAc* account, double newRate) {
        account->interestRate = newRate;
    }

    bool transfer(BankAc* from, BankAc* to, double amount) {
        if (from->balance >= amount) {
            from->balance -= amount;
            to->balance += amount;
            return true;
        }
        else {
            printf("Ошибка: Недостаточно средств для перевода.\n");
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "Создайте первый счёт\n";
    int nomerscheta;
    cout << "Введите номер счёта\n";
    cin >> nomerscheta;
    double balance;
    cout << "Введите баланс счёта\n";
    cin >> balance;
    cout << "Создайте второй счёт\n";
    int nomerscheta2;
    cout << "Введите номер счёта\n";
    cin >> nomerscheta2;
    double balance2;
    cout << "Введите баланс счёта\n";
    cin >> balance2;
    BankAc bank;
    BankAc account1 = bank.createAccount(nomerscheta, balance);
    BankAc account2 = bank.createAccount(nomerscheta2, balance2);
    double money;
    int nomer;
    bool otvet = false;
    while (true)
    {
        cout << "--------------Банк--------------\n";
        cout << "1. Пополнить баланс\n2. Снять средства\n3. Вывести баланс\n4. Заработанная сумма\n5. Обновить проценты\n6. Номер счёта\n7. Перевод\n8. Выход\n";
        int vibor;
        cin >> vibor;
        double money1;
        double money2;
        switch (vibor)
        {
        case 1:
            cout << "Введите сумму для пополнения: ";
            while (otvet != true)
            {
                try
                {
                    otvet = true;
                    cin >> money;
                }
                catch (const std::exception&)
                {
                    otvet = false;
                    cout << "Это не число!!!!";
                }
            }
            bank.deposit(&account1, money);
            cout << "Операция успешно выполнена\n";
            break;
        case 2:
            cout << "Введите сумму для снятия: ";
            while (otvet != true)
            {
                try
                {
                    otvet = true;
                    cin >> money;
                }
                catch (const std::exception&)
                {
                    otvet = false;
                    cout << "Это не число!!!!";
                }
            }
            bank.withdraw(&account1, money);
            cout << "Операция успешно выполнена\n";
            break;
        case 3:
            money = bank.getBalance(&account1);
            cout << "Ваш баланс: " << money << endl;
            break;
        case 4: 
            money = bank.getInterest(&account1);
            cout << "Вы заработали: " << money << endl;
            break;
        case 5:
            cout << "Введите процент: ";
            while (otvet != true)
            {
                try
                {
                    otvet = true;
                    cin >> money;
                }
                catch (const std::exception&)
                {
                    otvet = false;
                    cout << "Это не число!!!!";
                }
            }
            bank.setInterestRate(&account1, money);
            break;
        case 6:
            nomer = bank.getAccountNumber(&account1);
            cout << "Номер вашего счёта: " << nomer << endl;
            break;
        case 7:
            cout << "Введите сумму перевода: ";
            while (otvet != true)
            {
                try
                {
                    otvet = true;
                    cin >> money;
                }
                catch (const std::exception&)
                {
                    otvet = false;
                    cout << "Это не число!!!!";
                }
            }
            bank.transfer(&account1, &account2, money);
            money1 = bank.getBalance(&account1);
            money2 = bank.getBalance(&account2);
            printf("Перевод выполнен успешно. Баланс account1: %.2f, Баланс account2: %.2f\n", money1, money2);
            break;
        default:
            exit(0);
            break;
        }
    }
}