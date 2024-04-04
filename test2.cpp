#include <iostream>
#include "omp.h"
#include <thread>

using namespace std;

int main()
{
	
	int sum_0 = 0;
	int array[1000];
	for (int i = 0; i < 1000; i++) {
		array[i] = rand();
		//cout << array[i] << " ";
		sum_0 += array[i];
	}
	const int processor_count = std::thread::hardware_concurrency();  // 4 потока
	cout << processor_count << endl;

	int sum = 0;
#pragma omp parallel reduction(+:sum) num_threads(processor_count)
	{
#pragma omp for
		for (int i = 0; i < 1000; i++) {
			sum += array[i];
		}
	}
	cout << "Sum_1 = " << sum_0 << endl;
	cout << "Sum_2 = " << sum << endl;

	return 0;
}