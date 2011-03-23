#include "UInteger.h"
#include "Integer.h"
#include "Rational.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

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
}


