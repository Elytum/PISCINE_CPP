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

static int	Account::getNbAccounts( void ) {
	return (this->_nbAccounts);
}

static int	Account::getTotalAmount( void ) {
	return (this->_totalAmount);
}

static int	Account::getNbDeposits( void ) {
	return (this->_totalNbDeposits);
}

static int	Account::getNbWithdrawals( void ) {
	return (this->_totalNbWithdrawals);
}

Account::Account( int initial_deposit ) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 1;
	this->_nbWithdrawals = 0;
}

Account::Account( void ) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void ) {
	--this->_nbAccounts;
}

void	Account::makeDeposit( int deposit ) {
	++this->_nbDeposits;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (this->_amount < withdrawal)
		return (false);
	++this->_nbWithdrawals;
	this->_amount -= withdrawal;
	return (true);
}

static void	Account::displayAccountsInfos( void ) {
	std::count << "Launched displayAccountsInfos" :: std::endl;
}

int		Account::checkAmount( void ) const {
	std::count << "Launched checkammount" :: std::endl;
}

void	Account::displayStatus( void ) const {
	std::count << "Launched displaystatus" :: std::endl;
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //