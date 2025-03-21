/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:16:44 by sniemela          #+#    #+#             */
/*   Updated: 2025/03/20 15:34:12 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cctype>
#include <stdexcept>

#define FIRSTNAME 0
#define LASTNAME 1
#define NICKNAME 2
#define NUMBER 3
#define SECRET 4

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void setInfo(std::string info, int type);
		std::string getInfo(int type);
};