/*
	10.1 求斐波那契数列的第 n 项  P74
*/

#include <iostream>
using namespace std;

// 方法一：迭代法
long long fibonacci(int n){
	if(n <= 1)
		return n;
	long long NMinusOne = 1;
	long long NMinusTwo = 0;
	long long N = 0;

	for(size_t i = 2; i <= n; ++i){
		N = NMinusOne + NMinusTwo;

		NMinusTwo = NMinusOne;
		NMinusOne = N;
	}
	return N;
}

int main()
{
	int x{ 2 };

	cout << fibonacci( x ) << endl;


	return 0;
}
