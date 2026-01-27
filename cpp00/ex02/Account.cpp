#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

int	Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount() {
	return _totalAmount;
}

int	Account::getNbDeposits() {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {
	std::cout << "test" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
		return false;
	_amount -= withdrawal;
	_nbWithdrawals--;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals--;
	return true;
}

int	Account::checkAmount() const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	std::cout << "[19920104_091532]"
		<< "index:" << _accountIndex
		<< ";amount:" << _amount 
		<< ";deposists:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}


