#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

int powFoo(int a, int x);
int sumFoo(int a, int b);
bool topFoo(int num);
int PerfectFoo(int begin, int end);
void displayCard(std::string card);
void happyNumFoo(int num);
double argFoo(int arr[], int length);
void argFoo(int arr[], int16_t length);
bool isLeapYear(int year);
int qDaysInYear(int dd1, int mm1, int yyyy1, int dd2, int mm2, int yyyy2);


int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	
	std::cout << "Тема : Многомерные массивы" << std::endl << std::endl;
	std::cout << "Задание 1:" << std::endl;
	/*
		Напишите программу, которая создает двухмерный массив и заполняет его по следующему
	принципу: пользователь вводит число (например, 3) первый элемент массива принимает 
	значение этого числа, последующий элемент массива принимает значение этого числа
	умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива предыдущий элемен,т
	умноженный на 2 (т.е. 6*2=12 для нашего примера). Созданный массив вывести на экран
	*/

	int num;
	std::cout << "Введите начальное число: ";
	std::cin >> num;
	const int ROSE = 5;
	const int COLS = 5;
	int arr[ROSE][COLS];
	for (int i = 0; i < ROSE; ++i) {
		for (int j = 0; j < COLS; ++j, (num *= 2)) {
			arr[i][j] = num;
			std::cout << arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Задание 2:" << std::endl;
	/*
		Напишите программу, которая создает двухмерный массив и заполняет его по следующему
	принципу: пользователь вводит число (например, 3) первый элемент массива принимает 
	значение этого числа, последующий элемент массива принимает значение этого числа+ 1 (т.е. 4 
	для нашего примера), третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего 
	примера). Созданный массив вывести на экран
	*/

	int num1;
	std::cout << "Введите начальное число: ";
	std::cin >> num1;
	const int ROSE1 = 5;
	const int COLS1 = 5;
	int arr1[ROSE1][COLS1];
	for (int i = 0; i < ROSE1; ++i) {
		for (int j = 0; j < COLS1; ++j, num1++) {
			arr1[i][j] = num1;
			std::cout << arr1[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Задание 3:" << std::endl;
	/*
		Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. 
	Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз).
	Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический. 
	*/

	const int ROWS3 = 5;
	const int COLS3 = 5;
	int arr3[ROWS3][COLS3];
	std::cout << "Массив случайных чисел: " << std::endl;
	for (int i = 0; i < ROWS3; ++i) {
		for (int j = 0; j < COLS3; ++j) {
			arr3[i][j] = rand() % 50;
			std::cout << arr3[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	int razryad = 0;
	char ch;
	std::cout << "Введите количество разрядов на которые необходимо сдвинуть значения строк и в какую строну('r' or 'l'): ";
	std::cin >> razryad >> ch;

	int temp[COLS3];

	if (ch == 'r') {
		for (int i = 0; i < ROWS3; ++i) {
			for (int j = 0; j < COLS3; ++j) {
				temp[(j + razryad) % COLS3] = arr3[i][j];
			}
			for (int j = 0; j < COLS3; ++j) {
				arr3[i][j] = temp[j];
			}
		}
	}
	else if (ch == 'l') {
		for (int i = 0; i < ROWS3; ++i) {
			for (int j = 0; j < COLS3; ++j) {
				temp[(j - razryad + COLS3) % COLS3] = arr3[i][j];
			}
			for (int j = 0; j < COLS3; ++j) {
				arr3[i][j] = temp[j];
			}
		}
	}
	else {
		std::cout << "Некорректное направление сдвига!" << std::endl;
	}

	std::cout << "\nПолученный массив после сдвига: " << std::endl;
	for (int i = 0; i < ROWS3; ++i) {
		for (int j = 0; j < COLS3; ++j) {
			std::cout << arr3[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Задание 4:" << std::endl;
	/*
		В двумерном массиве целых числе посчитать:
	Сумму всех элементов массива
	Среднее арифметическое всехэлементов массива
	Минимальный элемент
	Максимальный элемен
	*/

	const int ROWS4 = 5;
	const int COLS4 = 5;
	int arr4[ROWS4][COLS4];
	int sum = 0;
	double argv;
	int min = 0, max = 0;
	for (int i = 0; i < ROWS4; ++i) {
		for (int j = 0; j < COLS4; ++j) {
			arr4[i][j] = rand() % 50;
			std::cout << arr4[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	min = max = arr4[0][0];
	for (int i = 0; i < ROWS4; ++i) {
		for (int j = 0; j < COLS4; ++j) {
			sum += arr4[i][j];
			if (max < arr4[i][j]) max = arr4[i][j];
			if (min > arr4[i][j]) min = arr4[i][j];
		}
	}
	std::cout << "Сумма элементов массива равна: " << sum << std::endl;
	std::cout << "Среднее арифметическое элементов массива равна: " << static_cast<double> (sum) / (ROWS4 * COLS4) << std::endl;
	std::cout << "Минимальное значение элементов массива равно: " << min << std::endl;
	std::cout << "Максимальное значение элементов массива равно: " << max << std::endl;

	std::cout << "Задание 5:" << std::endl;
	/*
		В двумерном массиве целых чисел посчитать сумму элементов: в каждой строке; в каждом
	столбце; одновременно по всем строкам и всем столбцам.
	*/

	const int ROWS5 = 3;
	const int COLS5 = 5;
	int arr5[ROWS5][COLS5];


	for (int i = 0; i < ROWS5; ++i)
	{
		for (int j = 0; j < COLS5; ++j)
		{
			arr5[i][j] = rand() % 50;
		}
	}

	for (int i = 0; i < ROWS5; ++i)
	{
		int sum5 = 0;
		for (int j = 0; j < COLS5; ++j)
		{
			std::cout << arr5[i][j] << '\t';
			sum5 += arr5[i][j];
		}
		std::cout << " | " << sum5;
		std::cout << std::endl;
	}

	for (int i = 0; i < COLS5; ++i)
	{
		std::cout << "--- " << '\t';
	}
	std::cout << std::endl;

	for (int j = 0; j < COLS5; ++j)
	{
		int sum5 = 0;
		for (int i = 0; i < ROWS5; ++i)
		{
			sum5 += arr5[i][j];
		}
		std::cout << sum5 << '\t';
	}
	int Total_sum5 = 0;
	for (int i = 0; i < ROWS5; ++i)
	{
		for (int j = 0; j < COLS5; ++j)
		{
			Total_sum5 += arr5[i][j];

		}
	}
	std::cout << " | " << Total_sum5;
	
	std::cout << "\nЗадание 6:" << std::endl;
	/*
		Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.
	Первый массив заполняется случайными числами, в диапазоне от 0 до 50. Второй массив 
	заполняется по следующему принципу: первый элемент второго массива равен сумме первого и
	второго элемента первого массива, второй элемент второго массива равен сумму третьего и
	четвертого элемента первого массива
	*/

	const int ROWS6_1 = 5;
	const int COLS6_1 = 10;
	int arr6_1[ROWS6_1][COLS6_1];

	const int ROWS6_2 = 5;
	const int COLS6_2 = 5;
	int arr6_2[ROWS6_2][COLS6_2];

	for (int i = 0; i < ROWS6_1; ++i)
	{
		for (int j = 0; j < COLS6_1; ++j)
		{
			arr6_1[i][j] = rand() % 50;
			std::cout << arr6_1[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Второй массив размером 5х5: " << std::endl;
	for (int i = 0; i < ROWS6_1; ++i)
	{
		for (int j = 0; j < COLS6_2; ++j)
		{
			arr6_2[i][j] = arr6_1[i][j*2] + arr6_1[i][j*2 + 1];
			std::cout << arr6_2[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Тема : Функции" << std::endl << std::endl;

	std::cout << "\nЗадание 1:" << std::endl;
	/*
		Написать функцию, которая принимает два параметра: основание степени и показатель
	степени, и вычисляет степень числа на основе полученных данных
	*/

	int a, b;//Значения основания и степени
	std::cout << "Введите основание степени: ";
	std::cin >> a;
	std::cout << "Введите показатель степени: ";
	std::cin >> b;
	std::cout << powFoo(a, b) << std::endl << std::endl;

	std::cout << "\nЗадание 2:" << std::endl;
	/*
		Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму
	чисел из диапазона между ними
	*/
	int NUM1 = 0, NUM2 = 0;
	std::cout << "Введите два числа: ";
	std::cin >> NUM1 >> NUM2;
	if (NUM1 < NUM2)
	{
		std::cout << "Сумма чисел равна: " << sumFoo(NUM1, NUM2) << std::endl;
	}
	else {
		std::cout << "Сумма чисел равна: " << sumFoo(NUM1, NUM2) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\nЗадание 3:" << std::endl;
	/*
		Число называется совершенным, если сумма всех его делителей равна ему самому. Напишите 
	функцию поиска таких чисел во введенном интервале
	*/
	int intervalMin, intervalMax;
Label1:
	std::cout << "\nВведите значение интервала: ";
	std::cin >> intervalMin >> intervalMax;
	if (intervalMin < intervalMax)
	{
		std::cout << PerfectFoo(intervalMin, intervalMax) << std::endl;
	}
	else if (intervalMin > intervalMax)
	{
		std::cout << PerfectFoo(intervalMax, intervalMin) << std::endl;
	}
	else {
		std::cout << "Введите значения диапазона заново!";
		goto Label1;
	}
	std::cout << std::endl;

	std::cout << "\nЗадание 4:" << std::endl;
	/*
		Написать функцию, выводящую на экран переданную ей игральную карту
	*/
	std::string card = "10♠";
	displayCard(card);

	std::cout << "\nЗадание 5:" << std::endl;
	/*
		Написать функцию, которая определяет, является ли «счастливым» шестизначное число
	*/
	int aa = 0;
	std::cout << "Введите шестизначное число: ";
Label2:
	std::cin >> aa;
	if (aa < 100000 || aa > 999999)
	{
		std::cout << aa << " не входит в указанный диапазон!!! Введите заново!!!";
		goto Label2;
	}
	happyNumFoo(aa);

	std::cout << "\nЗадание 6:" << std::endl;
	/*
		Написать функцию, которая принимает две даты (т.е. функция принимает шесть параметров) и
вычисляет разность в днях между этими датами. Для решения этой задачи необходимо также 
написать функцию, которая определяет, является ли год високосным.
	*/
	int day1, month1, year1, day2, month2, year2;

	std::cout << "Введите первую дату (день, месяц, год): ";
	std::cin >> day1 >> month1 >> year1;

	std::cout << "Введите вторую дату (день, месяц, год): ";
	std::cin >> day2 >> month2 >> year2;

	int difference = qDaysInYear(day1, month1, year1, day2, month2, year2);

	std::cout << "Разность в днях между двумя датами: " << difference << std::endl;

	std::cout << "\nЗадание 7:" << std::endl;
	/*
		Написать функцию, определяющую среднее арифметическое элементов передаевамого ей
	массива.
	*/
	const int size = 10;
	int ARR[size];
	for (int i = 0; i < size; ++i)
	{
		ARR[i] = rand() % 10;
		std::cout << ARR[i] << '\t';
	}
	std::cout << std::endl;


	std::cout << "Среднее арифметическое элементов массива: " << argFoo(ARR, size) << std::endl;


	std::cout << "\nЗадание 8:" << std::endl;
	/*
		Написать функцию, определяющую количество положительных, отрицательных и нулевых 
	элементов передаваемого ей массива
	*/
	const int16_t size2 = 10;
	int ARR2[size2];
	for (int i = 0; i < size2; ++i)
	{
		ARR2[i] = rand() % 10;
		std::cout << ARR2[i] << '\t';
	}
	std::cout << std::endl;

	argFoo(ARR2, size2);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
int powFoo(int a, int x)
{
	return pow(a, x);
}
//////////////////////////////////////////////////////////////////////////////////////////
int sumFoo(int a, int b)
{
	int sum = 0;
	for (int i = a; i < b - 1; i++)
	{
		sum += i + 1;
	}
	return sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

bool topFoo(int num)
{
	int sum = 1;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
			if (num / i != i)
			{
				sum += num / i;
			}
		}
	}
	return(sum == num);
}
////////////////////////////////////////////////////////////////////////////////////////////
int PerfectFoo(int begin, int end)
{
	int perfectNum = 0;
	for (int i = begin; i <= end; i++)
	{
		if (topFoo(i))
		{
			perfectNum += i;
		}
	}
	return perfectNum;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void displayCard(std::string card) {
	std::cout << "┌─────────┐" << std::endl;
	std::cout << "│         │" << std::endl;
	std::cout << "│    " << card << "  │" << std::endl;
	std::cout << "│         │" << std::endl;
	std::cout << "│         │" << std::endl;
	std::cout << "└─────────┘" << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void happyNumFoo(int num)
{
	int a = num / 1000;
	int firstSum = (a % 10 + (a % 100 - a % 10) / 10 + a / 100);
	int b = num % 1000;
	int secondSum = (b % 10 + (b % 100 - b % 10) / 10 + b / 100);
	(firstSum == secondSum) ? (std::cout << "Число счастливое" << std::endl) :
		(std::cout << "Число не счастливое" << std::endl);
}
///////////////////////////////////////////////////////////////////////////////////////////////
double argFoo(int arr[], int length)
{
	double sum = 0;
	for (int i = 0; i < length; ++i)
	{
		sum += arr[i];
	}
	return sum / length;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void argFoo(int arr[], int16_t length)
{
	int count_pisitive = 0, count_negative = 0, count_zerro = 0;
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] == 0)
		{
			count_zerro++;
		}
		if (arr[i] > 0)
		{
			count_pisitive++;
		}
		if (arr[i] < 0)
		{
			count_negative++;
		}
	}
	std::cout << "Количество положительных элементов: " << count_pisitive << std::endl;
	std::cout << "Количество отрицательных элементов: " << count_negative << std::endl;
	std::cout << "Количество нулевых элементов: " << count_zerro << std::endl;
}

	//////////////////////////////////////////////////////////////////////////////////////////////
	bool isLeapYear(int year) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			return true;
		}
		return false;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////
	int qDaysInYear(int dd1, int mm1, int yyyy1, int dd2, int mm2, int yyyy2)
	{
		int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int totalYear1 = 0;
		int totalMonth1 = 0;
		int totalDays1 = 0;
		totalYear1 = yyyy1 * 364;
		for (int i = 1; i <= mm1; ++i)
			totalMonth1 += daysInMonth[i];

		totalDays1 = dd1 + totalMonth1 + totalYear1;
		if (isLeapYear(yyyy1))
		{
			++totalDays1;
		}

		int totalYear2 = 0;
		int totalMonth2 = 0;
		int totalDays2 = 0;
		totalYear2 = yyyy2 * 364;
		for (int i = 1; i <= mm2; ++i)
			totalMonth2 += daysInMonth[i];

		totalDays2 = dd2 + totalMonth2 + totalYear2;
		if (isLeapYear(yyyy2))
		{
			++totalDays2;
		}

		if (totalDays1 > totalDays2) {
			return totalDays1 - totalDays2;
		}
		else if (totalDays1 < totalDays2) {
			return totalDays2 - totalDays1;
		}
		else {
			return 0;
		}
	}



