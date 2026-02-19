template <typename T>
Array<T>::Array() : _arr(new T[0]()), _size(0) {}
//Array<T>::Array() : _arr(0), _size(0) {}
//
template <typename T>
Array<T>::Array(unsigned int size) : _arr(new T[size]()), _size(size)  {}

template <typename T>
Array<T>::Array(const Array& other) : _arr(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];

}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete [] _arr;
		_size = other._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < other._size; i++)
			_arr[i] = other._arr[i];
	}

	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _arr[index];
}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

/*
template <typename T>
void Array<T>::setValue(unsigned int index, const T value)
{
	_arr[index] = value;
}

template <typename T>
T Array<T>::getValue(unsigned int index) const 
{
	return _arr[index];
}
*/
template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}

template <typename T>
unsigned int Array<T>::size() const 
{
	return _size;
}
