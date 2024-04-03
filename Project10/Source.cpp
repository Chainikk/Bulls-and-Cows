#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int randomnumber_check(string randnum)
{
	int r = 1;
	for (unsigned int i = 0; i < randnum.size(); i++) {
		for (unsigned int j = 0; j < randnum.size(); j++) {
			if (randnum[i] != randnum[j]) {
				r = 1;
			}
			if ((randnum[i] == randnum[j]) and (i == j)) {
				r = 1;
			}
			if ((randnum[i] == randnum[j]) and (i != j)) {
				r = 0; 
				break;
			}
		}
		if (r == 0) {
			break;
		}
	}
	return r;
}

int inputnumber_check(string number) 
{
	int n = 0;
	if (number.size() == 4) {
		for (unsigned int i = 0; i < number.size(); i++) {
			if (number[i] >= 48 and number[i] <= 57) {
				n = 1;
			}
			else {
				n = 0;
				break;
			}
		}
	}
	else {
		n = 0;
	}
	return n;
}

int countplus(string strrandnum, string number)
{
	int plus = 0;
	for (unsigned int i = 0; i < strrandnum.size(); i++) {
		for (unsigned int j = 0; j < number.size(); j++) {
			if ((strrandnum[i] == number[j]) and (i == j)) {
				plus += 1;
			}
		}
	}
	return plus;
}

int countminus(string strrandnum, string number)
{
	int minus = 0;
	for (unsigned int i = 0; i < strrandnum.size(); i++) {
		for (unsigned int j = 0; j < number.size(); j++) {
			if ((strrandnum[i] == number[j]) and (i != j)) {
				minus += 1;
			}
		}
	}
	return minus;
}
int main()
{
	setlocale(0, "");
	string strrandnum;
	string number;
	int randnum;	
	int randcheck = 0, numcheck = 0;
	int countp = 0, countm = 0;
	srand(int(time(NULL)));
	while (randcheck == 0) {
		randnum = 1000 + rand() % 8999;
		strrandnum = to_string(randnum);
		randcheck = randomnumber_check(strrandnum);
		if (randcheck == 1) {
			break;
		} 
	}
	//cout << strrandnum << endl;
	cout << "Игра начинается!" << endl;
	cout << "Введите четырехзначное число: ";
	while (true) {
		getline(cin, number);
		numcheck = 0;
		while (numcheck == 0) {
			numcheck = inputnumber_check(number);
			if (numcheck == 1) {
				break;
			}
			else {
				cout << "Вы ввели недопустимое число, попробуйте еще раз: ";
				getline(cin, number);
			}
		}
		countp = countplus(strrandnum, number);
		countm = countminus(strrandnum, number);
		if (countp == 4) {
			cout << endl;
			cout << "Поздравляем, вы угадали число!!!";   
			break;
		}
		else {
			cout << countp << "+" << " " << countm << "-" << endl;
			cout << "Введите новое число: ";
		}
	}	
	return 0;
}