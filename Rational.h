#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include "Integer.h"
#include "Rational.h"

class Rational
{
public:
    enum Sign {negative_ = -1, zero = 0, positive_ = 1};
    Rational();
    Rational(Rational const& x);
    Rational(Sign sign,UInteger const& num,UInteger const& den);
    Rational(Integer const& num,Integer const& den);
    Rational(long num,long den,char base);


    //opérateurs de calcul
    Rational operator +(const Rational &x)const;
    Rational operator -(const Rational &x)const;
    Rational operator *(const Rational &x)const;
    Rational operator /(const Rational &x)const;
    Rational& operator +=(const Rational &x);
    Rational& operator -=(const Rational &x);
    Rational& operator *= (const Rational &x);
    Rational& operator /= (const Rational &x);


    Rational& operator ++();
    Rational& operator ++(int i);
    Rational& operator --();
    Rational& operator --(int i);

    //opérateurs de comparaison
    bool operator ==(const Rational &x)const;
    bool operator !=(const Rational &x)const;
    bool operator <(const Rational &x)const;
    bool operator <=(const Rational &x)const;
    bool operator >(const Rational &x)const;
    bool operator >=(const Rational &x)const;

    UInteger pgcd(UInteger i, UInteger j);//methode qui retourne le pgcd
    Rational& reduire();
    const UInteger& getNum() const;
    const UInteger& getDen() const;
    const Sign getSign() const;

private:
    UInteger num_;
    UInteger den_;
    Sign sign_;
};

std::ostream& operator << (std::ostream &os, const Rational &output);


#endif // RATIONAL_H
