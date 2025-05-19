/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:52:40 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/19 21:32:28 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num < 0)
			throw std::invalid_argument("Negative numbers are not allowed.");
		_vector.push_back(num);
		_deque.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

void PmergeMe::sort()
{
	int deque_time = 0;
	std::cout << "Before sorting:";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << " " << _vector[i];
	
	clock_t vector_time = clock();
	mergeSort(_vector, 0, _vector.size() - 1);
	vector_time = clock() - vector_time;

	deque_time = clock();
	mergeSort(_deque, 0, _deque.size() - 1);
	deque_time = clock() - deque_time;
	
	std::cout << "\nAfter sorting:";
	for (size_t i = 0; i < _deque.size(); ++i)
		std::cout << " " << _deque[i];
	std::cout << "\nTime taken for vector: " << vector_time << " microseconds";
	std::cout << "\nTime taken for deque: " << deque_time << " microseconds" << std::endl;
}

void PmergeMe::mergeSort(std::vector<int> &vec, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

void PmergeMe::mergeSort(std::deque<int> &deque, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(deque, left, mid);
		mergeSort(deque, mid + 1, right);
		merge(deque, left, mid, right);
	}
}

void PmergeMe::merge(std::vector<int> &vec, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	std::vector<int> temp(right - left + 1);
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			temp[k++] = vec[i++];
		else
			temp[k++] = vec[j++];
	}

	while (i <= mid)
		temp[k++] = vec[i++];

	while (j <= right)
		temp[k++] = vec[j++];

	for (int m = 0; m < k; ++m)
		vec[left + m] = temp[m];
}

void PmergeMe::merge(std::deque<int> &deque, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	std::deque<int> temp(right - left + 1);
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (deque[i] <= deque[j])
			temp[k++] = deque[i++];
		else
			temp[k++] = deque[j++];
	}

	while (i <= mid)
		temp[k++] = deque[i++];

	while (j <= right)
		temp[k++] = deque[j++];

	for (int m = 0; m < k; ++m)
		deque[left + m] = temp[m];
}
