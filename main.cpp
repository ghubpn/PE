/* Standard Includes */
#include <iostream>
#include <cmath>
#include <deque>



/* Question Function Declarations */
int q1();  // O(1)
int q2();  // O(log(n))
int q3();  // O()
int q4();  // O()
int q5();  // O()
int q6();  // O()
int q7();  // O()
int q8();  // O()
int q9();  // O()
int q10(); // O()
int q11(); // O()



/* Utility Function Declarations */
int  SumOfMultiples( int base, int max ); // O(1)
int  Fib( int n );                        // O(log(n))
int  FibIndexBeforeX( int x );            // O(log(n))
int  sumEvenFibsToN( int n );             // O(log(n))
int  largestPrimeFactor( long long x );
bool isPalindrome( int x );
bool isPrime( int x );



/* Main Function */
using namespace std;
int main() {
	cout << endl;
	cout << "a1  = " << q1() << endl;
	cout << "a2  = " << q2() << endl;
	cout << "a3  = " << q3() << endl;
	cout << "a4  = " << q4() << endl;
	cout << "a5  = " << q5() << endl;
	cout << "a6  = " << q6() << endl;
	cout << "a7  = " << q7() << endl;
	cout << "a8  = " << q8() << endl;
	cout << "a9  = " << q9() << endl;
	cout << "a10 = " << q10() << endl;
	cout << "a11 = " << q11() << endl;
	cout << endl;
	return 0;
}



/* Question Functions */

int q1() {
	int sum = SumOfMultiples(3,999) + SumOfMultiples(5,999) - SumOfMultiples(15,999);
	return sum;
}

int q2() {
	int limit     = 4000000;
	int lastIndex = FibIndexBeforeX( limit );
	int sum       = sumEvenFibsToN( lastIndex );
	return sum;
}

int q3() {
	long long n = 600851475143;
	return largestPrimeFactor( n );
}

int q4() {
	int pal = 0;
	int pi  = 0;
	int pj  = 0;
	for ( int i = 999; i > 99; --i ) {
		for ( int j = 999; j > 99; --j ) {
			if ( isPalindrome( i * j )) {
				if ( i * j > pal )
					pal = i * j;
				if ( i < pi && j < pj )
					return pal;
				pi = i;
				pj = j;
			}
		}
	}
	return pal;
}

int q5() {
	int max = 5;
	int product = 1;
	int factor;
	for ( int i = 2; i <= max; ++i ) {
		if ( isPrime(i) ) {
			if ( i*i <= max )
				factor = i*i;
			else if ( max % i == 0 )
				factor = max;
			else
				factor = i;
			cout << factor << endl;
			product *= factor;
		}
	}
	return product;
}

int q6() {
	return 0;
}

int q7() {
	return 0;
}

int q8() {
	return 0;
}

int q9() {
	return 0;
}

int q10() {
	return 0;
}

int q11() {
	return 0;
}



/* Utility Functions */

int SumOfMultiples( int base, int max ) {
	// compute largest number less than max when divided by base
	int maxMult = max / base;
	// return base multiplied by sum from 1 to maxMult
	return base * maxMult * (++maxMult) / 2;
}

int Fib( int n ) {
	double alpha =  (sqrt(5)+1) / 2;
	double beta  = -(sqrt(5)-1) / 2;
	double Fn    =  (pow(alpha,n) - pow(beta,n)) / sqrt(5);
	return (int)floor(Fn);
}

int FibIndexBeforeX( int x ) {
	double alpha =  (sqrt(5)+1) / 2;
	double F = log(x * sqrt(5) + 0.5) / log(alpha);
	return (int)floor(F);
}

int sumEvenFibsToN( int n ) {
	int x = n/3;
	return (Fib(3*x + 2) - 1) / 2;
}

int largestPrimeFactor( long long x ) {
	long long remainder = x;
	long largestFactor = 0;
	int  iter = 2;
	while ( iter * iter <= remainder ) {
		if ( remainder % iter == 0 ) {
			remainder /= iter;
			largestFactor = iter;
		} else
			++iter;
	}
	if ( remainder > largestFactor)
		largestFactor = remainder;
	return largestFactor;
}

bool isPalindrome( int x ) {
	deque<int> digits;
	int left;
	int right;
	while ( x >= 1 ) {
		digits.push_front(x%10);
		x /= 10;
	}
	while ( digits.size() > 1 ) {
		left  = digits.front();
		right = digits.back();
		if ( left != right )
			return false;
		digits.pop_front();
		digits.pop_back();
	}
	return true;
}

bool isPrime( int x ) {
	for ( int i = 2; i <= sqrt(x); ++i ) {
		if ( x % i == 0 )
			return false;
	}
	return true;
}