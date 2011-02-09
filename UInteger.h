#ifndef DEF_UINTEGER
#define DEF_UINTEGER




#include "ArrayNumber.h"
#include <iostream>
#include <ostream>
class UInteger : public ArrayNumber{

	public:


		UInteger();
		//copie
		UInteger(UInteger const& x);
		//autres
		UInteger(unsigned long x,char base_=10);
		UInteger(long x,int base_=10);
		UInteger(unsigned int x,int base_=10);
		UInteger(int x,int base_=10);
		UInteger(unsigned short x,int base_=10);
		UInteger(short x,int base_=10);
		UInteger(char x,int base_=10);

		UInteger operator +(const UInteger &x)const;
        UInteger operator -(const UInteger &x)const;
		UInteger& operator +=(const UInteger &x);
        UInteger& operator -=(const UInteger &x);
        UInteger& operator ++();
        UInteger& operator ++(int i);
        UInteger& operator --();
        UInteger& operator --(int i);
        bool operator ==(const UInteger &x)const;
        bool operator !=(const UInteger &x)const;
        bool operator <(const UInteger &x)const;
        bool operator <=(const UInteger &x)const;
        bool operator >(const UInteger &x)const;
        bool operator >=(const UInteger &x)const;
        UInteger operator /(const UInteger &x)const;
        UInteger operator %(const UInteger &x)const;
        UInteger operator *(const UInteger &x)const;
        UInteger& operator /=(const UInteger &x);
        UInteger& operator *=(const UInteger &x);
        UInteger& operator %=(const UInteger &x);
    private:
        UInteger bourage(size_t nb) const;
};
        std::ostream& operator << (std::ostream& os,const UInteger &x);
#endif


