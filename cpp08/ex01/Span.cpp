#include "Span.hpp"
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <ctime>
#include <iostream>

/*
static int randomInt()
{
	return rand() % 1000000;
}
*/

Span::Span(): _n(0), _v() {}

Span::Span(int n): _n(n), _v() {}

Span::Span(const Span& s): _n(s._n), _v(s._v){}

Span& Span::operator=(const Span& s)
{
	if (this != &s)
	{
		_v = s._v;
		_n = s._n;

	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v.size() == static_cast<std::vector<int>::size_type>(_n))
		// TODO is the Span:: prefix necessary?
		throw Span::ContainerFullException("Can't add more numbers to this container");
	_v.push_back(n);
}

int Span::shortestSpan()
{
	int tmp;
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min_span = std::numeric_limits<int>::max();
	std::vector<int>::iterator it = _v.begin();
	std::vector<int>::iterator next = it;
//	for (size_t i = 0; i < v.size(); i++)
	for (; it != _v.end() - 1; ++it)	
	{
		++next;
		tmp = abs(*it - *next);
		if (tmp < min_span)
			min_span = tmp;
	}
	return min_span;
}

int Span::longestSpan()
{
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return (v.back() - v.front());
}

void Span::randomFill()
{
	std::srand(std::time(NULL));
	std::back_insert_iterator<std::vector<int> > it = std::back_inserter(_v);
	for (unsigned int i = 0; i < _n; ++i)
		*it++ = std::rand() % _n;
}

void Span::printVector()
{
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); ++it)
		std::cout << *it << " - ";
	std::cout << "!!" << std::endl;
}

Span::ContainerFullException::ContainerFullException(const std::string& msg) : _msg(msg) {}
Span::ContainerFullException::~ContainerFullException() throw() {}
const char* Span::ContainerFullException::what() const throw() 
{
	return(_msg.c_str());
}
