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
	  /*UInteger a,b ;
	  cout<<base<<endl;
	  a=UInteger(l1,base);
	  cout<<a<<endl;
	  b=UInteger(l2,base);
	  if(a<b){
        cout << "1"<<endl;
	  }
	  else cout << "1"<<endl;
	 */
    Rational a(Integer(l1,base),Integer(l2,base));
    Rational b(Integer(l3,base),Integer(l4,base));
      cout <<l1 <<endl;
	  cout << "a=" << a << endl;
	  cout << "b=" << b << endl << endl;

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
/*
	  if(a>b){
      cout << a <<" > "<< b << " = " ;
	  }
	  else       cout << a <<" < "<< b << " = " ;
      if(a<b){
      cout << a <<" < "<< b << " = " ;
	  }
	  else       cout << a <<" > "<< b << " = " ;
	  //cout << a <<" ^ "<< b << " = " << (a^b) << endl;//ok
	 /* cout << a <<" %= "<< b << " = ";
	  a%=b;
	  cout <<a << endl*/

}


