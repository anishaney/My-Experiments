#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	int first[] = {1, 5, 3, 10, 9};
	int second[] = {4, 2, 9, 13, 5};

	std::vector<int> v(10);
	std::vector<int>::iterator it;

	std::sort(first, first+5);
	std::sort(second, second+5);

	it = std::set_intersection(first, first+5, second, second+5, v.begin());

	v.resize(it - v.begin());

	std::cout << "The intersection has: " << (v.size()) << " elements." << std::endl;
	for (it = v.begin(); it != v.end(); it++)
	{
		std::cout << ' ' << *it;
	}
	
	return 0;
}
