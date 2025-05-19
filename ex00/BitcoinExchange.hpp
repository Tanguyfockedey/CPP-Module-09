/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:05:36 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/19 17:08:43 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>


class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRates;

	public:
		// Constructors and destructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &src);

		// Member functions
		void loadExchangeRates(const std::string &filename);
		void parseInput(const std::string &filename);
		void calculateExchangeRate(const std::string &date, const float &value);
};

int isValidDate(const std::string &date);