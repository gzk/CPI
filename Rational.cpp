#include "Rational.h"
#include <stdlib.h>
using namespace std;
//constructeurs
Rational::Rational()
{
    sign_ = zero;
    num_ = UInteger();
    den_ = UInteger();
}
Rational::Rational(Sign sign,UInteger const& num,UInteger const& den)
{
    sign_ =sign;
    num_ = num;
    if (den == UInteger(0))
    {
        exit(1);
    }
    den_ = den;
    reduire();
}
Rational::Rational(Integer const& numerateur,Integer const& denominateur)
{
    if( numerateur.getSign()!=denominateur.getSign())
    {
        sign_ = negative_;
    }
    else sign_ = positive_;
    den_ = denominateur.getNb();
    num_ = numerateur.getNb();
    reduire();
}

Rational::Rational(long numerateur,long denominateur,char base)
{

    if((numerateur < 0 && denominateur >0 )|| (numerateur > 0 && denominateur < 0))
    {
        sign_ = negative_;
    }
    else sign_ = positive_;
    num_ = UInteger(numerateur,base);
    den_ = UInteger(denominateur,base);
    reduire();
}

//copie
Rational::Rational(Rational const& x)
{
    den_ = x.den_;
    num_ = x.num_;
    sign_ = x.getSign();
}
//accesseurs
const UInteger& Rational::getNum() const
{
    return num_;
}
const UInteger& Rational::getDen() const
{
    return den_;
}
const Rational::Sign Rational::getSign() const
{
    return sign_;
}
//opérateurs de calcul
Rational Rational::operator +(const Rational &x) const
{
    Rational result;
    if(getDen()==x.getDen())
    {
        result=Rational((Integer((Integer::Sign)getSign(),getNum()))+(Integer((Integer::Sign) x.getSign(),x.getNum())),getDen());
    }
    else
    {
        result=Rational(((Integer((Integer::Sign)getSign(),getNum()))*x.getDen())+((Integer((Integer::Sign) x.getSign(),x.getNum()))*getDen()),getDen()*x.getDen());
    }
    result.reduire();
    return result;
}

Rational& Rational::operator +=(const Rational &x)
{
    return *this = (*this) + x;
}

Rational Rational::operator -(const Rational &x) const
{
    Rational result;
    if(getDen()==x.getDen())
    {
        result=Rational((Integer((Integer::Sign)getSign(),getNum()))-(Integer((Integer::Sign) x.getSign(),x.getNum())),getDen());
    }
    else
    {
        result=Rational(((Integer((Integer::Sign)getSign(),getNum()))*x.getDen())-((Integer((Integer::Sign) x.getSign(),x.getNum()))*getDen()),getDen()*x.getDen());
    }
    result.reduire();
    return result;
}

Rational& Rational::operator -=(const Rational &x)
{
    return *this = (*this) - x;
}

Rational Rational::operator *(const Rational &x) const
{
    Rational result;
    Sign sign = negative_;
    if(getSign()==x.getSign())
    {
        sign=positive_;
    }
    result=Rational(sign,getNum()*x.getNum(),getDen()*x.getDen());
    result.reduire();

    return result;
}
Rational& Rational::operator *=(const Rational &x)
{
    return *this = (*this) * x;
}

Rational Rational::operator /(const Rational &x) const
{
    Rational result;
    Sign sign = negative_;
    if(getSign()==x.getSign())
    {
        sign=positive_;
    }
    result=Rational(sign,getNum()*x.getDen(),getDen()*x.getNum());
    result.reduire();
    return (result);
}

Rational& Rational::operator /=(const Rational &x)
{
    return *this = (*this) / x;
}


//opérateurs de comparaison

bool Rational::operator ==(const Rational &x)const
{
    return getSign()==x.getSign() && getNum()==x.getNum() && getDen()==x.getDen();
}

bool Rational::operator !=(const Rational &x)const
{
    return !(x==*this);
}

bool Rational::operator <(const Rational &x)const //strictement inférieur
{
    if(getSign()==x.getSign())
    {
        if(getSign()==negative_)
        {
            return (getNum()*x.getDen()>x.getNum()*getDen());
        }
        else return (getNum()*x.getDen()<x.getNum()*getDen());
    }
    return getSign()==negative_;
}

bool Rational::operator <=(const Rational &x)const //inférieur ou égal
{
    return ((*this) < x) || ((*this) == x);
}

bool Rational::operator >(const Rational &x)const
{
    if(getSign()==x.getSign())
    {
        if(getSign()==negative_)
        {
            return getNum()*x.getDen()<x.getNum()*getDen();
        }
        else return (getNum()*x.getDen()>x.getNum()*getDen());
    }
    return getSign()==positive_;
}

bool Rational::operator >=(const Rational &x)const
{
    return ((*this) > x) || ((*this) == x);
}


//opérateurs d'incrémentation

Rational& Rational::operator ++()
{
    return *this = *this + Rational(getSign(),UInteger((long)1),(*this).getDen());
}
Rational& Rational::operator ++(int i)
{
    return *this = *this + Rational(getSign(),UInteger((long)i),(*this).getDen());
}
Rational& Rational::operator --()
{
    return *this = *this + Rational(getSign(),UInteger((long)-1),(*this).getDen());
}
Rational& Rational::operator --(int i)
{
    return *this = *this + Rational(getSign(),UInteger((long)-i),(*this).getDen());
}
UInteger Rational::pgcd(UInteger i, UInteger j)//methode qui retourne le pgcd
{
    while(i!=j )
    {
        if(i>j)
        {
            i-=j;
        }
        else j-=i;
        if(j==UInteger(0))
        {
            return i;
        }
    }
    return i;
}
Rational& Rational::reduire()
{
    UInteger pgcd = (*this).pgcd(den_,num_);
    num_/=pgcd;
    den_/=pgcd;
    return (*this);
}

//opérateur d'affichage

ostream& operator << (ostream &os, const Rational &output)
{
    if(output.getSign() == Rational::negative_) os << '-';
    os << output.getNum() <<"/"<< output.getDen();
    return os;
}

