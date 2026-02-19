#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& c, int x)
{
	typename T::iterator it = std::find(c.begin(), c.end(), x);
	if (it != c.end())
		return it;
	else
		throw std::exception();
}

template <typename T>
typename T::const_iterator easyfind(const T& c, int x)
{
	typename T::const_iterator it = std::find(c.begin(), c.end(), x);
	if (it != c.end())
		return it;
	else
		//TODO don't throw exception here?Just return an end iterator and let
		//the caller handle it?
		throw std::out_of_range("Value not found");
}
