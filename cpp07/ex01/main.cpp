#include "iter.hpp"

int main()
{
	int arr[] = {3, 4, 1, 5, 7, 9};

	iter(arr, 6, printThing<const int>);
}


