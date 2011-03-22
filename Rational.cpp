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
    sign_ =sign_;
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
    // cout<<den_<<endl;
    // cout<<num_<<endl;
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
        result=Rational((Integer(getNum())*getSign())+(Integer(x.getNum())*x.getSign()),getDen());
    }
    else
    {
        result=Rational(((Integer(getNum())*getSign())*x.getDen())+((Integer(x.getNum())*x.getSign())*getDen()),getDen()*x.getDen());
    }
    // cout << ((Integer(getNum())*getSign())*x.getDen())+((Integer(x.getNum())*x.getSign())*getDen()) <<endl;

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
        result=Rational((Integer(getNum())*getSign())-(Integer(x.getNum())*x.getSign()),getDen());
    }
    else
    {
        result=Rational(((Integer(getNum())*getSign())*x.getDen())-((Integer(x.getNum())*x.getSign())*getDen()),getDen()*x.getDen());
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
            return (getNum() > x.getNum()) && (getDen() <=x.getDen());
        }
        else return (getNum() < x.getNum()) && (getDen() >=x.getDen());
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
            return (getNum() < x.getNum()) && (getDen() >=x.getDen());
        }
        else return (getNum() > x.getNum()) && (getDen() <=x.getDen());
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
    // if(i==j) return i;
    /*  if (i<j) swap(i,j);
      if(j == UInteger(0))
          return i;
      else
          return pgcd(j, i%j);

     /*
    while(j>UInteger(0))
    {
        cout<<i<<endl;
        if (i<j)
        {

            swap(i,j);
        }
        i=j;
        j= i% j;
    }
    return i;*/
    /*while(j!=UInteger(0))
    {
        if(i<j)
        {
            swap(i,j);
        }
        i=i-j;
    }
    cout<<i<<endl;
    cout<<j<<endl;

    return i;*/
/*    do{

    if(i>j){
    i=i-j;}
    else j=j-i;
    }while(i!=j && i!=UInteger(0));
    return j;
*/
while(i!=j){
    if(i>j){
        i-=j;
    }
    else j-=i;
    }
    return i;
}
Rational& Rational::reduire()
{
   /* cout << den_ <<" =den "<<endl;
     cout << num_ <<" =num "<<endl;
*/
    UInteger pgcd = (*this).pgcd(den_,num_);
    //cout <<pgcd <<" =pgcd ";
      num_/=pgcd;
      den_/=pgcd;
    /* cout << den_ <<" =den "<<endl;
      cout << num_ <<" =num "<<endl;
      */
    return (*this);
}
//opérateurs logiques
/*
	Rational Rational::operator &(const Rational &x)const;
	Rational Rational::operator |(const Rational &x)const;
	Rational Rational::operator ^(const UInteger &x)const;*/

//opérateur d'affichage

ostream& operator << (ostream &os, const Rational &output)
{
    if(output.getSign() == Rational::negative_) os << '-';
    os << output.getNum() <<"/"<< output.getDen();
    return os;
}

