#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit) : _nbDeposits(initial_deposit)
{
    _accountIndex = getNbAccounts();
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
        << "amount:" << getTotalAmount() << ";"
        << "created" << std::endl;
    _nbAccounts++;
    
}

Account::~Account(void)
{
}

void    Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (_amount - withdrawal > 0)
    {
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        return true;
    }
    else
        return false;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::_displayTimestamp(void)
{
    std::time_t  now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    char time[20];

    std::strftime(time, sizeof(time), "[%Y%m%d_%H%M%S]", ltm);

    std::cout << time << std::endl;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout <<  " index:" << _accountIndex << ";"
        << "amout:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << ";";
}

int Account::getNbAccounts(void)
{
    return  _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return  _totalAmount;
}

int Account::getNbDeposits(void)
{
    return  _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return  _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void)
{
    std::cout << "accounts:" << getNbAccounts() << ";"
        << "amount:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals" << getNbWithdrawals() << ";" << std::endl;
}
