#include <iterator>
#include <math.h>
#include <iostream>

#include "UInteger.h"
#include "Integer.h"

using namespace std;

Integer::Integer()
{
    sign_ = zero;
    ui_ = UInteger();
}

Integer::Integer(Sign sign, UInteger x)
{
    sign_ = zero;
    ui_ = UInteger((long)0);

}

Integer::Integer(long x, char base)
{
    if(x < 0)
    {
        sign_ = negative_;
        ui_ = UInteger(-x,base);
    }
    else if(x > 0)
    {
        sign_ = positive_;
        ui_ = UInteger(x,base);
    }
    else
    {
        sign_ = zero;
        ui_ = UInteger((long)0,base);
    }
}

//copie
Integer::Integer(Integer const& x)
{
    ui_ = x.getNb();
    sign_ = x.getSign();
}
const UInteger& Integer::getNb() const
{
    return ui_;
}
const Integer::Sign Integer::getSign() const
{
    return sign_;
}
//opérateurs de calcul
Integer Integer::operator +(const Integer &x) const
{
    Integer* result = new Integer();

    UInteger a = getNb();
    UInteger b = x.getNb();

    if(getSign() == x.getSign())
    {
        *result = Integer(x.getSign(), b+a);
    }
    else
    {
        if(getSign() == -1 && a > b)  // !!! implémenter comparaison
        {
            *result = Integer(negative_,a - b);
        }
        else if(getSign() > -1 && a > b)
        {
            *result = Integer(positive_,a - b);
        }
        else if(getSign() == -1 && a < b)
        {
            *result = Integer(positive_, b - a);
        }
        else/*(this.getSign() > -1 && a  < b )*/
        {
            *result = Integer(negative_, b - a);
        }
    }

    return *result;
}

Integer& Integer::operator +=(const Integer &x)
{
    return *this = (*this) + x;
}

Integer Integer::operator -(const Integer &x) const
{
    Integer* result = new Integer();

    UInteger a = getNb();
    UInteger b = x.getNb();

    if(getSign() == x.getSign())
    {
        if(a<b)
        {
            *result = Integer(x.getSign(), b-a);
        }
        else
        {
            *result = Integer(x.getSign(), a-b);
        }
    }
    else
    {
        if(getSign() == -1 && a > b)
        {
            *result = Integer(negative_,a - b);
        }
        else if(getSign() > -1 && a > b)
        {
            *result = Integer(positive_,a - b);
        }
        else if(getSign() == -1 && a < b)
        {
            *result = Integer(positive_, b - a);
        }
        else/*(this.getSign() > -1 && a  < b )*/
        {
            *result = Integer(negative_, b - a);
        }
    }

    return *result;
}

Integer& Integer::operator -=(const Integer &x)
{
    return *this = (*this) - x;
}

Integer Integer::operator *(const Integer &x) const
{
    Sign sign = negative_;
    if(getSign()==x.getSign())
    {
        sign=positive_;
    }
    return (Integer(sign,getNb()*x.getNb()));
}
Integer& Integer::operator *=(const Integer &x)
{
    return *this = (*this) * x;
}
Integer Integer::operator /(const Integer &x) const
{
    Sign sign = negative_;
    if(getSign()==x.getSign())
    {
        sign=positive_;
    }
    return (Integer(sign,getNb()/x.getNb()));
}
Integer& Integer::operator /=(const Integer &x)
{
    return *this = (*this) / x;
}

bool Integer::operator <(const Integer &x)const
{
    if(getSign()==x.getSign())
    {
        if(getSign()==negative_)
        {
            return getNb() > x.getNb();
        }
        else return getNb() < x.getNb();
    }
    return getSign()==negative_;
}
bool Integer::operator <=(const Integer &x)const
{
    return (*this) < x;
}
ostream& operator << (ostream &os, const Integer &output)
{
    if(output.getSign()==-1)
    {
        os  << "-" << output.getNb() <<  ends;
    }
    else os << output.getNb() <<  ends;
    return os;
}
