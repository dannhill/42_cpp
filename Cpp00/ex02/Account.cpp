#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(0), _nbDeposits(0), _nbWithdrawals(0){
	if (initial_deposit < 0)
	{
		std::cerr << "Error: invalid amount. Input must be nonnegative." << std::endl;
		this->~Account();
	}
	_amount = initial_deposit;
	_accountIndex = getNbAccounts();
	_nbAccounts += 1;
	getTotalAmount();
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< checkAmount() << ";created" << std::endl;
	return;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< checkAmount() << ";closed" << std::endl;
	return;
}

int  Account::getNbAccounts(void){
	if (_nbAccounts < 0)
	{
		std::cerr << "Error: invalid accounts number. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	return _nbAccounts;
}

int Account::getTotalAmount(void){
	if (_totalAmount < 0)
	{
		std::cerr << "Error: invalid total amount number. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	return _totalAmount;
}

int Account::getNbDeposits(void){
	if (_totalNbDeposits < 0)
	{
		std::cerr << "Error: invalid total deposits number. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
	if (_totalNbWithdrawals < 0)
	{
		std::cerr << "Error: invalid total withdrawals number. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() <<
		";total:" << getTotalAmount() << ";deposits:" <<
		getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return;
}

void	Account::makeDeposit(int deposit){
	if (_amount < 0)
	{
		std::cerr << "Error: invalid amount value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" <<
		checkAmount() << ";deposit:";
	if (deposit < 0)
	{
		std::cout << "refused" << std::endl;
		return;
	}
	_amount += deposit;
	if (_totalAmount < 0)
	{
		std::cerr << "Error: invalid total amount value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_totalAmount += deposit;
	if (_totalNbDeposits < 0)
	{
		std::cerr << "Error: invalid total deposits value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_totalNbDeposits += 1;
	if (_nbDeposits < 0)
	{
		std::cerr << "Error: invalid deposits value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_nbDeposits += 1;
	std::cout << deposit << ";amount:" << checkAmount() <<
		";nb_deposits:" << _nbDeposits << std::endl;
	return;
}

bool	Account::makeWithdrawal(int withdrawal){
	if (_amount < 0)
	{
		std::cerr << "Error: invalid amount value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" <<
		checkAmount() << ";withdrawal:";
	if (withdrawal < 0 || _amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	if (_totalAmount < 0)
	{
		std::cerr << "Error: invalid total amount value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_totalAmount -= withdrawal;
	if (_totalNbWithdrawals < 0)
	{
		std::cerr << "Error: invalid total deposits value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_totalNbWithdrawals += 1;
	if (_nbWithdrawals < 0)
	{
		std::cerr << "Error: invalid deposits value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	_nbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << checkAmount() <<
		";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount(void) const{
	if (_amount < 0)
	{
		std::cerr << "Error: invalid amount value. Aborting." << std::endl;
		exit(EXIT_FAILURE);
	}
	return _amount;
}

void	Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
		";amount:" << checkAmount() << ";deposits:" <<
		_nbDeposits << ";withdrawals:" << _nbWithdrawals <<
		std::endl;
	return;
}

void	Account::_displayTimestamp(void){
	time_t		t_raw;
	struct tm	*tm;
	std::string	format;
	std::string	mon;
	
	t_raw = std::time(NULL);
	tm = localtime(&t_raw);
	format = asctime(tm);
	format = format.substr(4, format.length() - 5);
	std::cout << "[" << format.substr(16, 4);
	mon = format.substr(0, 3);
	if (mon.compare("Jan") == 0)
		std::cout << "01";
	else if (mon.compare("Feb") == 0)
		std::cout << "02";
	else if (mon.compare("Mar") == 0)
		std::cout << "03";
	else if (mon.compare("Apr") == 0)
		std::cout << "04";
	else if (mon.compare("May") == 0)
		std::cout << "05";
	else if (mon.compare("Jun") == 0)
		std::cout << "06";
	else if (mon.compare("Jul") == 0)
		std::cout << "07";
	else if (mon.compare("Aug") == 0)
		std::cout << "08";
	else if (mon.compare("Sep") == 0)
		std::cout << "09";
	else if (mon.compare("Oct") == 0)
		std::cout << "10";
	else if (mon.compare("Nov") == 0)
		std::cout << "11";
	else if (mon.compare("Dec") == 0)
		std::cout << "12";
	std::cout << format.substr(4, 2) << "_" <<
		format.substr(7, 2) << format.substr(10, 2) <<
		format.substr(13, 2) << "] ";

	return;
}
