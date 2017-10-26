#include <iostream>
using namespace std;
#include "polynomial.cpp"

int main() {
	polynomial p;
	p.setCoeff(0, 3);
	p.setCoeff(2, 5);
	p.setCoeff(1, 5);

	cout << p.evaluate(3) << endl;
	p.print();
	cout << p.getCoeff(1) << endl;
	cout << p.degree() << endl;

	polynomial p2;
	//p.setCoeff(1, 3);
	//p.add(p2);

}
