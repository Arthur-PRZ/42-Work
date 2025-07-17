#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
    _accountIndex = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    _totalAmount += _amount;
    _accountIndex = getNbAccounts();
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "created" << std::endl;
    _nbAccounts++;
    
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "closed" << std::endl;    
}

void    Account::makeDeposit(int deposit)
{
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";"
        << "p_amount:" << _amount << ";"
        << "deposits:" << deposit << ";";
    _amount += deposit;
    std::cout << "amount:" << _amount << ";"
        << "nb_deposits:" << _nbDeposits << std::endl;

}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount - withdrawal > 0)
    {   
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << " index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:" << withdrawal << ";";
        _amount -= withdrawal;
        std::cout << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
    else
    {
        std::cout << " index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "withdrawal:refused" << std::endl;        
        return false;
    }
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

    std::cout << time;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout <<  " index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "deposits:" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals << std::endl;
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
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() << std::endl;
}
