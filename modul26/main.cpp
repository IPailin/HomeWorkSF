#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <thread>


class MultiThread {

public:

	MultiThread(const unsigned int& size_array, const unsigned int& number_part) : size_array_m(size_array), number_part_m(number_part) {};

	int result_summa() {

		//проверяем корректность введенных значений
		if (number_part_m > (size_array_m / 2)) {
			std::cout << "Error interval" << std::endl;
			return -1;
		}

		//создаем требуемый массив и заполняем его
		int *array{ new int[size_array_m] };
		fill_array(array);

		
		std::vector <int*> array_subarray; //создаем вектор подмассивов на которые требуется разбить основной
		int number_element = size_array_m / number_part_m; // колличество элементов в подмоссиве
		int size_last_array = size_array_m - (number_element * (number_part_m - 1)); // вычисляем размер последнего подмассива

		// выполняем разбивку массива на подмоссивы
		for (int i = 0; i < number_part_m - 1; ++i) {
			int* arr{ new int[number_element] };

			for (int j = number_element * i, k = 0; k < number_element; ++j, ++k) {

				arr[k] = array[j];
			}
			array_subarray.push_back(arr);
		}

		//заполняем последний подмассив
		int* arr{ new int[size_last_array] };
		for (int j = number_element * (number_part_m -1), k = 0; j < size_array_m; ++j, ++k) {

			arr[k] = array[j];

		}
		array_subarray.push_back(arr);

		//выводим полученные подмассивы
		for (int i = 0; i < array_subarray.size(); ++i) {

			if (i == (array_subarray.size() - 1)) {
				for (int j = 0; j < size_last_array; ++j) {
					std::cout << array_subarray[i][j] << " ";
				}
				std::cout << std::endl;
			}
			else {
				for (int j = 0; j < number_element; ++j) {
					std::cout << array_subarray[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}

		//Создаем вектор потоков и инициализируем их функцие подсчета значения
		std::vector<std::thread> vec_th; 
		for (int i = 0; i < number_part_m; ++i) {

			if (i == (array_subarray.size() - 1)) {
				std::thread th(&MultiThread::calculate_summa, this, array_subarray.at(i), size_last_array);
				vec_th.push_back(std::move(th));
			}
			else {
				std::thread th(&MultiThread::calculate_summa, this, array_subarray.at(i), number_element);
				vec_th.push_back(std::move(th));
			}
			
		}

		for (std::thread& th : vec_th) {
			if (th.joinable()) {
				th.join();
			}
		}

		std::cout << "summa = " << summa << std::endl;

		return summa;
	}

private:
	unsigned int size_array_m{ 0 };
	unsigned int number_part_m{ 0 };
	double summa{ 0.0 };


	void fill_array(int* array) {

		srand(time(0));

		for (int i = 0; i < size_array_m; ++i) {

			array[i] = rand() % 5;
		}

		std::cout << "Start array\n";
		for (int i = 0; i < size_array_m; ++i) {
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}

	void calculate_summa(int* sub_arr, int size_arr) {

		int result{ 0 };

		for (int i = 0; i < size_arr; ++i) {
			result += sub_arr[i];
		}

		summa += result;
		std::cout << "result = " << result << std::endl;
	}
};



int main() {

	MultiThread mt(13, 3);
	mt.result_summa();

	std::cout << std::endl;

	MultiThread mt1(145, 40);
	mt1.result_summa();

	std::cout << std::endl;

	MultiThread mt2(10, 2);
	mt2.result_summa();

	std::cout << std::endl;

	MultiThread mt3(1024, 5);
	mt3.result_summa();

	std::cout << std::endl;

	MultiThread mt4(13, 9);
	mt4.result_summa();
	return 0;
}