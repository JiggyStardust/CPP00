/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:05:07 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/20 15:13:21 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>
// #include <cctype>

// int	getNbAccounts( void );
// int	getTotalAmount( void );
// int	getNbDeposits( void );
// int	getNbWithdrawals( void );

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
	";created" << std::endl;
}

Account::~Account( void )
{
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
	";closed" << std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t timestamp;
	char output[18];
	struct tm * datetime;

	time(&timestamp);
	datetime = localtime(&timestamp);
	strftime(output, 18, "[%G%m%d_%H%M%S]", datetime);
	std::cout << output << " ";
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
	";deposit:" << deposit << ";amount:" << _amount + deposit << std::endl;
	_amount += deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	balance = _amount - withdrawal;
	_displayTimestamp();
	if (balance < 0)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
		";withdrawal:refused" << std::endl;
	}
	else
	{ 
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << \
		";withdrawal:" << withdrawal << ";amount:" << balance << \
		";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
		_amount = balance;
		_nbWithdrawals++;
	}
	return (true);
}

int		Account::checkAmount( void ) const
{
	std::cout << "checkAmount" << std::endl;
	return (1);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << \
	";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << \
	";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;

}