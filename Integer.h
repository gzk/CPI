#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>

#include "UInteger.h"



class Integer{

public:

	enum Sign {negative_ = -1, zero = 0, positive_ = 1};

	Integer();

	//copie
	Integer(Integer const& x);

	//autres
	Integer(Sign sign, UInteger ui);
	Integer(long x,char base );
	//opérateurs de calcul
	Integer operator +(const Integer &x)const;
	Integer operator -(const Integer &x)const;
	Integer operator *(const Integer &x)const;
	Integer operator /(const Integer &x)const;
	Integer& operator +=(const Integer &x);
	Integer& operator -=(const Integer &x);
	Integer& operator *= (const Integer &x);
	Integer& operator /= (const Integer &x);

	//opérateurs de comparaison
	bool operator ==(const Integer &x)const;
	bool operator !=(const Integer &x)const;
	bool operator <(const Integer &x)const;
	bool operator <=(const Integer &x)const;
	bool operator >(const Integer &x)const;
	bool operator >=(const Integer &x)const;

	const UInteger& getNb() const;
	const Sign getSign() const;

private:
	Integer bourrage(size_t nb)const;
	UInteger ui_;
	Sign sign_;


};

std::ostream& operator << (std::ostream &os, const Integer &output);


#endif /* INTEGER_H_ */
