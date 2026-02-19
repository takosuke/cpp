#include <iostream>

template<typename T>
void printThing(T thing)
{
	std::cout << "Thing: " << thing << "!!!" << std::endl;
}

template <typename A, typename F>
void iter(A* arr, const int len, F fun)
{
	if (!arr || !fun)
		return;
	for (int i = 0; i < len; i++)
		fun(arr[i]);
}
