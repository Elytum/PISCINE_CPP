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

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

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
	std::cout << "[20150406_153629]"
				<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
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
	std::cout << "[20150406_153629]"
				<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
	--Account::_nbAccounts;
}

void	Account::makeDeposit( int deposit ) {
	int		p_amount = this->_amount;

	++this->_nbDeposits;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
	std::cout << "[20150406_153629]"
				<< " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int		p_amount = this->_amount;

	if (this->_amount < withdrawal)
	{
		std::cout << "[20150406_153629]"
					<< " index:" << this->_accountIndex
					<< ";p_amount:" << p_amount
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	++this->_nbWithdrawals;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	std::cout << "[20150406_153629]"
				<< " index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (true);
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "[20150406_153629]"
				<< " accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

int		Account::checkAmount( void ) const {
	std::cout << "Launched checkammount" << std::endl << std::endl << std::endl;
	return (0);
}

void	Account::displayStatus( void ) const {
	std::cout << "[20150406_153629]"
				<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
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