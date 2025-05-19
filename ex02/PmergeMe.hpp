/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:52:31 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/19 21:14:42 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		//Member functions
		void mergeSort(std::vector<int> &vec, int left, int right);
		void mergeSort(std::deque<int> &deque, int left, int right);
		void merge(std::vector<int> &vec, int left, int mid, int right);
		void merge(std::deque<int> &deque, int left, int mid, int right);

		//constructors
		PmergeMe();

	public:
		//Constructors and destructor
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		//Assignment operator
		PmergeMe &operator=(const PmergeMe &other);

		//Member functions
		void sort();
};
