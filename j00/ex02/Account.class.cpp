// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Mon Jun 15 19:17:57 2015                      //
//                Last update : Mon Jun 15 19:42:21 2015                      //
//                Made by : Arthur Chazal <achazal@student.42.fr>             //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include "Account.class.hpp"
#include <iostream>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];

    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);
    std::cout << buf;
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
}

Account::Account( void ) {
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";closed" << std::endl;
	--Account::_nbAccounts;
}

void	Account::makeDeposit( int deposit ) {
	int		p_amount = this->_amount;

	++this->_nbDeposits;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int		p_amount = this->_amount;

	if (checkAmount() < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex
					<< ";p_amount:" << p_amount
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	++this->_nbWithdrawals;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (true);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //