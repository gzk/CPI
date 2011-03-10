#include "UInteger.h"
#include "Integer.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

    long l1,l2;
	char base;
	cout << "Saisir nb 1: ";
    cin >> l1;
	cout << "Saisir nb 2: ";
    cin >> l2;
	cout << "Saisir base: ";
    cin >> base;
	cout << endl;
	/*
    UInteger a(l1,10);
    UInteger b = UInteger(l2,10);

	  cout << "a=" << a.getBase() <<"x"<< a << endl;
	  cout << "b=" << b.getBase() <<"x"<< b << endl << endl;

	  cout << a <<" += "<< b << " = " ;
	  a+=b;
	  cout << a << endl;
	  cout << a <<" -= "<< b << " = ";
	  a-=b;
	  cout << a << endl;
	  cout << a <<" *= "<< b << " = ";
	  a*=b;
	  cout << a << endl;//pas ok
	  cout << a <<" /= "<< b << " = ";
	  a/=b;
	  cout << a << endl;
	  //cout << a <<" ^ "<< b << " = " << (a^b) << endl;//ok
	  cout << a <<" %= "<< b << " = ";
	  a%=b;
	  cout <<a << endl;*/

	Integer a(l1,10);
    Integer b = Integer(l2,10);

	  cout << "a=" << a.getNb().getBase() <<"x"<< a << endl;
	  cout << "b=" << b.getNb().getBase() <<"x"<< b << endl << endl;

	  cout << a <<" += "<< b << " = " ;
	  a+=b;
	  cout << a << endl;
	  cout << a <<" -= "<< b << " = ";//pas ok
	  a-=b;
	  cout << a << endl;
	  cout << a <<" *= "<< b << " = ";//pas ok on ne garde pas le signe
	  a*=b;
	  cout << a << endl;//pas ok
	  cout << a <<" /= "<< b << " = ";
	  a/=b;
	  cout << a << endl;
	  //cout << a <<" ^ "<< b << " = " << (a^b) << endl;//ok
	 /* cout << a <<" %= "<< b << " = ";
	  a%=b;
	  cout <<a << endl*/

}


