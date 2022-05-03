#ifndef __COMMAND_PATTERN_H__
#define __COMMAND_PATTERN_H__
#include <iostream>
#include <vector>

class BankAccount {
public:
    bool deposit(int amount) {
        m_balance += amount;
        std::cout << " Amount : " << amount
                  << " deposited, Balance : " << m_balance << "\n";
        return true;
    }

    bool withdraw(int amount) {
        if (m_balance - amount >= m_overdraftLimit) {
            m_balance -= amount;
            std::cout << " Amount : " << amount
                      << " withdrew, Balance : " << m_balance << "\n";
            return true;
        }
        return false;
    }

private:
    int m_balance{0};
    int m_overdraftLimit{-500};
};

class Command {
public:
    virtual void call() = 0;
    virtual void undo() = 0;
    bool         m_success{false};
};

class BankAccountCommand : public Command {
public:
    enum class Action { deposit, withdraw };
    BankAccountCommand(BankAccount& account, const Action action, int amount)
        : m_account(account), m_action(action), m_amount(amount) {}

    void call() override;
    void undo() override;

private:
    BankAccount& m_account;
    const Action m_action;
    int          m_amount;
};

void BankAccountCommand::call() {
    switch (m_action) {
        case Action::deposit:
            m_success = m_account.deposit(m_amount);
            break;

        case Action::withdraw:
            m_success = m_account.withdraw(m_amount);
            break;

        default:
            break;
    }
}

void BankAccountCommand::undo() {
    switch (m_action) {
        case Action::withdraw:
            if (m_success) {
                m_account.deposit(m_amount);
            }
            break;

        case Action::deposit:
            if (m_success) {
                m_account.withdraw(m_amount);
            }
            break;

        default:
            break;
    }
}

// COMPOSITE COMMAND
class CompositeBankAccountCommand : std::vector<BankAccountCommand>, Command {
public:
    CompositeBankAccountCommand(const std::initializer_list<value_type>& items)
        : std::vector<BankAccountCommand>(items) {}

    void call() override {
        bool ok = true;
        for (auto& cmd : *this) {
            if (ok) {
                cmd.call();
                ok = cmd.m_success;
            }
        }
    }

    void undo() override {
        for (auto it = rbegin(); it != rend(); ++it) {
            it->undo();
        }
    }
};

class MoneyTransferCommand : public CompositeBankAccountCommand {
public:
    MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount)
        : CompositeBankAccountCommand{
              BankAccountCommand(from, BankAccountCommand::Action::withdraw,
                                 amount),
              BankAccountCommand(to, BankAccountCommand::Action::deposit,
                                 amount)} {}
};
#endif
