///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	void print() { cout << num << "/" << denom << endl; };
	Fraction add(Fraction, int); //overloaded addition operator
	Fraction add(int, Fraction);
	friend bool operator>(Fraction LHS, Fraction RHS);
};

bool operator>(Fraction LHS, Fraction RHS)
{
	if ((LHS.num*RHS.denom) > (RHS.num*LHS.denom)) return 1;
	else return 0;
}

Fraction Fraction::add(Fraction arg1, int arg2)
{
	Fraction result(0,1);
	result.num = arg1.num + arg2*arg1.denom;
	result.denom = arg1.denom;
	return result;
}

Fraction Fraction::add(int arg1, Fraction arg2)
{
	Fraction result(0, 1);
	result.num = arg2.num + arg1*arg2.denom;
	result.denom = arg2.denom;
	return result;
}

int main()
{
	Fraction testFraction1(2, 3);
	Fraction testFraction2(2, 3);
	int testint1 = 3;

	testFraction1 = testFraction1.add(testFraction1, testint1);
	testFraction1.print();

	testFraction2 = testFraction2.add(testint1, testFraction2);
	testFraction2.print();

}