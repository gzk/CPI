#ifndef DEF_UINTEGER
#define DEF_UINTEGER

#include "ArrayNumber.h"

#include <iostream>
#include <ostream>

class UInteger : public ArrayNumber{

/*la classe qui permet de représenter un entier non signé, elle hérite de ArrayNumber, elle reprend ses attributs (la base et la liste de nombres)
et ses méthodes notamment les accesseurs*/

public:

	  //constructeurs (ils prennent en chargent tous les types d'entiers primitifs mais appellent au final tous le constructeur de base d'ArrayNumber
	  UInteger();
	  UInteger(UInteger const& x);
	  UInteger(unsigned long x,char base_=10);
	  /*UInteger(long x,int base_=10);
	  UInteger(unsigned int x,int base_=10);
	  UInteger(int x,int base_=10);
	  UInteger(unsigned short x,int base_=10);
	  UInteger(short x,int base_=10);
	  UInteger(char x,int base_=10);*/

	  //opérateurs de calcul
	  UInteger operator +(const UInteger &x)const;
	  UInteger& operator +=(const UInteger &x);
	  UInteger operator -(const UInteger &x)const;
	  UInteger& operator -=(const UInteger &x);
	  UInteger operator *(const UInteger &x)const;
	  UInteger& operator *=(const UInteger &x);
	  UInteger operator /(const UInteger &x)const;
	  UInteger& operator /=(const UInteger &x);
      UInteger modulo(const UInteger &x)const;
	  UInteger operator %(const UInteger &x)const;
	  UInteger& operator %=(const UInteger &x);
	  UInteger operator ^(const UInteger &x)const;


	  //opérateurs d'incrémentation
	  UInteger& operator ++();
	  UInteger& operator ++(int i);
	  UInteger& operator --();
	  UInteger& operator --(int i);

	  //opérateurs de comparaison
	  bool operator ==(const UInteger &x)const;
	  bool operator !=(const UInteger &x)const;
	  bool operator <(const UInteger &x)const;
	  bool operator <=(const UInteger &x)const;
	  bool operator >(const UInteger &x)const;
	  bool operator >=(const UInteger &x)const;

	  //opérateurs de flux
	  UInteger operator <<(int b)const;
	  UInteger operator >>(int b)const;

	  //opérateurs logiques
	  UInteger operator &(const UInteger &x)const;
	  UInteger operator |(const UInteger &x)const;
	  UInteger operator *(const long x)const;// pour pouvoir multiplier un UInteger par un long pour augmenter la vitesse d'exécution
	   UInteger toBase(char base)const;//convertisseur

private:

	  //méthodes "outils utilisés dans les autres méthodes"

	  UInteger bourrage(size_t nb) const;//pour remplir de zéros la liste de chiffres afin de faciliter les calculs (envisager de la supprimer!)
};

//opérateur d'affichage
std::ostream& operator << (std::ostream& os,const UInteger &x);

#endif
