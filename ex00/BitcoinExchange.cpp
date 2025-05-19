/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:05:48 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/19 17:16:25 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_exchangeRates = src._exchangeRates;
	return *this;
}

void BitcoinExchange::loadExchangeRates(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data.csv" << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line); // Skip the header line
	while (std::getline(file, line))
	{
		if (line.find(',') != std::string::npos)
			line.replace(line.find(','), 1, " ");
		std::istringstream iss(line);
		std::string date;
		float rate;
		if (iss >> date >> rate)
			_exchangeRates[date] = rate;
		else
			std::cerr << "Error: invalid exchange rate format" << std::endl;
	}
	file.close();
}

void BitcoinExchange::parseInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line); // Skip the header line
	
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		char delimiter;
		float value;
		if (iss >> date >> delimiter >> value)
		{
			if (value < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			if (delimiter != '|')
			{
				std::cerr << "Error: invalid delimiter." << std::endl;
				continue;
			}
			if (date.length() != 10 || date[4] != '-' || date[7] != '-')
			{
				std::cerr << "Error: invalid date format." << std::endl;
				continue;
			}
			if (date < "2010-08-14")
			{
				std::cerr << "Error: date out of range." << std::endl;
				continue;
			}
			if (!isValidDate(date))
			{
				std::cerr << "Error: invalid date." << std::endl;
				continue;
			}
			calculateExchangeRate(date, value);
		}
		else
			std::cerr << "Error: invalid input format => " << line << std::endl;
	}
	file.close();
}

void BitcoinExchange::calculateExchangeRate(const std::string &date, const float &value)
{
	std::map<std::string, float>::iterator it = _exchangeRates.end();
	do
		it--;
	while (it->first > date && it != _exchangeRates.begin());
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;

}

int isValidDate(const std::string &date)
{
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return 0;
	if (day < 1 || day > 31)
		return 0;
	if (month == 2)
	{
		if (day > 29)
			return 0;
		if (day == 29 && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return 0;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return 0;
	return 1;
}
