#ifndef REAL_H
#define REAL_H
#include "Integer.h"


class Real
{
public:
    Real();
    static unsigned int precision_;
    Real(Real const& x);
    Real(UInteger const& x);

    //opérateurs de calcul
    Real operator +(const Real &x)const;
    Real& operator +=(const Real &x);
    Real operator -(const Real &x)const;
    Real& operator -=(const Real &x);
    Real operator *(const Real &x)const;
    Real operator *(long x)const;
    Real& operator *= (const Real &x);
    Real operator /(const Real &x)const;
    Real& operator /= (const Real &x);
    Real operator %(const Real &x)const;
    Real& operator %=(const Real &x);

    //opérateurs d'incrémentation
    Real& operator ++();
    Real& operator ++(int i);
    Real& operator --();
    Real& operator --(int i);

    //opérateurs de comparaison
    bool operator ==(const Real &x)const;
    bool operator !=(const Real &x)const;
    bool operator <(const Real &x)const;
    bool operator <=(const Real &x)const;
    bool operator >(const Real &x)const;
    bool operator >=(const Real &x)const;

    //opérateurs de flux
    Real operator <<(int b)const;
    Real operator >>(int b)const;

    //opérateurs logiques
    Real operator &(const Real &x)const;
    Real operator |(const Real &x)const;
    Real operator ^(const Real &x)const;

    //accesseurs
    const UInteger& getNb() const;
    const Integer::Sign getSign() const;


private:
    Integer num_;
    UInteger comma_;
};

#endif // REAL_H
