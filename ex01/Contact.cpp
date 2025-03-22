/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:24:57 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/22 13:42:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int		isStringSpace(std::string str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if (!std::isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

std::string Contact::getInfo(int type)
{
	if (type == FIRSTNAME)
		return firstName;
	else if (type == LASTNAME)
		return lastName;
	else if (type == NICKNAME)
		return nickName;
	else if (type == NUMBER)
		return phoneNumber;
	else
		return darkestSecret;
}

void	Contact::setInfo(std::string info, int type)
{
	if (info.empty() || isStringSpace(info))
		throw std::runtime_error("No field in a contact should be left empty.");
	if (type == FIRSTNAME)
		firstName = info;
	else if (type == LASTNAME)
		lastName = info;
	else if (type == NICKNAME)
		nickName = info;
	else if (type == NUMBER)
	{
		for (size_t i = 0; i < info.length(); i++)
		{
			if (!std::isdigit(info[i]))
				throw std::runtime_error("Phone number should only hold digits.");
		}
		phoneNumber = info;
	}
	else if (type == SECRET)
		darkestSecret = info;
}