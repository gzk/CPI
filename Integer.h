#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>

#include "UInteger.h"



class Integer{

	/*la classe qui permet de représenter un entier signé, elle encapsule un UInteger et représente son signe grâce à un type énuméré,
	et surcharge les mêmes opérateurs*/
	
public:

	enum Sign {negative_ = -1, zero = 0, positive_ = 1};

	//constructeurs
	Integer();
	Integer(Integer const& x);
	Integer(Sign sign, UInteger ui);
	Integer(long x,char base );
	
	//opérateurs de calcul
	Integer operator +(const Integer &x)const;
	Integer& operator +=(const Integer &x);
	Integer operator -(const Integer &x)const;
	Integer& operator -=(const Integer &x);
	Integer operator *(const Integer &x)const;
	Integer& operator *= (const Integer &x);
	Integer operator /(const Integer &x)const;
	Integer& operator /= (const Integer &x);
	Integer operator %(const Integer &x)const;
	Integer& operator %=(const Integer &x);
	
	//opérateurs d'incrémentation
	Integer& operator ++();
	Integer& operator ++(int i);
	Integer& operator --();
	Integer& operator --(int i);

	//opérateurs de comparaison
	bool operator ==(const Integer &x)const;
	bool operator !=(const Integer &x)const;
	bool operator <(const Integer &x)const;
	bool operator <=(const Integer &x)const;
	bool operator >(const Integer &x)const;
	bool operator >=(const Integer &x)const;
	
	//opérateurs de flux
	Integer operator <<(int b)const;
	Integer operator >>(int b)const;
	
	//opérateurs logiques
	Integer operator &(const Integer &x)const;
	Integer operator |(const Integer &x)const;
	Integer operator ^(const UInteger &x)const;

	//accesseurs
	const UInteger& getNb() const;
	const Sign getSign() const;

private:

	UInteger ui_;
	Sign sign_;

	Integer bourrage(size_t nb)const;
};

//opérateur d'affichage
std::ostream& operator << (std::ostream &os, const Integer &output);


#endif
