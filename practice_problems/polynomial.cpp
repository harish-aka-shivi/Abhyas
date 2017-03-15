#include <iostream>
#include "EArray.cpp"
using namespace std;
class polynomial {
	EArray<int> coeffs;
	public:
	void setCoeff(int power, int coeff) {
		for (int i = coeffs.size(); i < power; i++) {
			coeffs.set(i, 0);
		}
		coeffs.set(power, coeff);
  }

  void print() {
    for(int i = 0; i < coeffs.size();i++) {
      std::cout << coeffs.get(i)<< "x^"<<i<< " + ";
    }
    std::cout << std::endl;
  }

  int evaluate(int input) {
    int sum = 0;
    for(int i = 0; i <coeffs.size() ; i++ ) {
      int coefficient = coeffs.get(i);
      int multi = 1;
      for(int j = i; j >0; j-- ) {
          multi = multi*input;
      }
      sum = sum + multi*coefficient;
      }
      return sum;
  }

  int getCoeff(int i) {
    if(i > coeffs.size()-1) {
      return 0;
    } else  {
      return coeffs.get(i);
    }
  }

  int degree() {
    for(int i = coeffs.size()-1; i >= 0 ; i--) {
      if(k)
    }
  }

};

//
// int main() {
//
//   EArray<int> earray;
//   int demo[100];
//   int a = 100;
//   earray.add(5);
//   std::cout << "earray" << "<- this is earray"<< demo << std::endl;
//   while(!earray.isEmpty()) {
//     std::cout << earray.removeLast() << std::endl;
//   }
//   return 0;
//
// }
