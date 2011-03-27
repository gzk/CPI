#include "UInteger.h"
#include "Integer.h"
#include "Rational.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/**
* \fn int main (void)
* \brief Calcul des factorielles de 1 jusqu'au nombre saisie .
*
* \return EXIT_SUCCESS - Arrêt normal du programme.
*/
int main() {

    unsigned long l1,l2,l3,l4;
	long base;
	cout << "Saisir nb 1: ";
    cin >> l1;
	cout << "Saisir nb 2: ";
    cin >> l2;
    cout << "Saisir nb 1: ";
    cin >> l3;
	cout << "Saisir nb 2: ";
    cin >> l4;
	cout << "Saisir base: ";
    cin >> base;
	cout << endl;
	/*
    UInteger a(l1,10);
    UInteger b = UInteger(l2,10);
    */
    Rational a(Integer(l1,base),Integer(l2,base));
    Rational b(Integer(l3,base),Integer(l4,base));
      cout <<l1 <<endl;
	  cout << "a=" << a << endl;
	  cout << "b=" << b << endl << endl;
	  cout << a <<" += "<< b << " = " ;
	  a+=b;
	  cout << a << endl;
	  cout << a <<" -= "<< b << " = ";
      a-=b;
	  cout << a << endl;
	  cout << a <<" *= "<< b << " = ";
	  a*=b;
	  cout << a << endl;
	  cout << a <<" /= "<< b << " = ";
	  a/=b;
	  cout << a << endl;
/*calcul de factoriel
    long l1;
    cin >> l1;

    UInteger  j((long)1,10);
    // test factorial using operator*=(UInteger const&)
    for (long i =1; i<l1; ++i)
    {
        j = j * i;
        std::cout << i << "! =" << j << "\n";
    }
    j = j * l1;
    std::cout << l1<< "! =" << j << "\n";*/
    return EXIT_SUCCESS;
}


