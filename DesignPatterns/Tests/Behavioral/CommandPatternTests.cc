#include "CommandPattern.h"
#include "gtest/gtest.h"

TEST(Command, Simple) {
    BankAccount        account;
    BankAccountCommand cmd{account, BankAccountCommand::Action::deposit, 100};
    cmd.call();
    cmd.undo();

    EXPECT_TRUE(true);
}

TEST(Command, Composite) {
    BankAccount        from, to;
    BankAccountCommand cmd{from, BankAccountCommand::Action::deposit, 100};
    cmd.call();

    MoneyTransferCommand moneyTransferCmd(from, to, 100);
    moneyTransferCmd.call();

    EXPECT_TRUE(true);
}
