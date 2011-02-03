
#include "UInteger.h"

#include <iterator>

#include <math.h>
#include <sstream>
//
#include <iostream>
//


using namespace std;
UInteger::UInteger():ArrayNumber(){}

//copie
UInteger::UInteger(UInteger const& x){
    digits_ = x.getDigits();
    base_ = x.getBase();
}

//autres
//UInteger::UInteger(unsigned long x,char base) :ArrayNumber((long)x, base){}

UInteger::UInteger(long x, int base):ArrayNumber((long)x, base){}

/*UInteger::UInteger(unsigned int x, char base):ArrayNumber((long) x, base){}

UInteger::UInteger(int x, char base):ArrayNumber((long) x, base){}

UInteger::UInteger(unsigned short x ,char base):ArrayNumber((long) x, base){}

UInteger::UInteger(short x, char base):ArrayNumber((long) x, base){}

UInteger::UInteger(char x, char base) :ArrayNumber((long) x, base){}



UInteger::UInteger():ArrayNumber(0,0){

}
//copie
UInteger::UInteger(UInteger const& x):ArrayNumber(sizeof(unsigned long)+1,0){
    digits_=x.digits_;
    base_=x.base_;
}
//autres
UInteger::UInteger(unsigned long x,int base) :ArrayNumber(sizeof(unsigned long)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(unsigned short)+1;
    for (std::list<char>::iterator it = digits_.begin();it != digits_.end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    digits_.reverse();

}
UInteger::UInteger(long x,int base):ArrayNumber(sizeof(long)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(long)+1;
    for (std::list<char>::iterator it = digits_.begin();it != digits_.end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    digits_.reverse();
}
UInteger::UInteger(unsigned int x,int base):ArrayNumber(sizeof(unsigned int)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(unsigned int)+1;
    for (std::list<char>::iterator it = digits_.begin();it != digits_.end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    digits_.reverse();
}
UInteger::UInteger(int x,int base):ArrayNumber(sizeof(int)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(int)+1;
    for (std::list<char>::iterator it = digits_.begin();it != digits_.end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    digits_.reverse();
}
UInteger::UInteger(unsigned short x,int base):ArrayNumber(sizeof(unsigned short)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(unsigned short)+1;
    for (std::list<char>::iterator it = digits_.begin();it != digits_.end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    digits_.reverse();
}
UInteger::UInteger(short x,int base):ArrayNumber(sizeof(short)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(short)+1;
    for (std::list<char>::iterator it = digits_.begin();it != digits_.end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    digits_.reverse();
}
UInteger::UInteger(char x,int base) :ArrayNumber(sizeof(char)+1,0){
    base_=base;
}
*/
UInteger UInteger::operator +(const UInteger &x)const{
    UInteger uia,uib;
    if((x.getDigits().size()) > getDigits().size()){
        uia=bourage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else{
        uib=x.bourage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    UInteger *result = new UInteger();
    int retenue =0;

    //std::list<char>::iterator itr = (*result).digits_.begin();
    std::_List_const_iterator<char> ita = uia.digits_.begin();
    for (std::_List_const_iterator<char> itb = uib.digits_.begin();itb != uib.digits_.end() || ita!= uia.digits_.end();ita++) {
        (*result).digits_.push_back((retenue+*itb+*ita)%base_);
        retenue=(retenue+*ita+*itb)/base_;
        itb++;
    }
    /*if(ita != digits_.end()){
        ita++;
        (*result).digits_.push_back((retenue+*ita)%base_);
        retenue=(retenue+*ita)/base_;
    }*/
    return *result;
 }
UInteger UInteger::operator -(const UInteger &x)const{
    int retenue =0;
    UInteger *result = new UInteger();
    std::list<char>::iterator itr = (*result).digits_.begin();
    std::_List_const_iterator<char> ita = x.digits_.begin();
    for (std::_List_const_iterator<char> itb = digits_.begin();itb != digits_.end() || ita!= x.digits_.end();ita++) {
        if((*itb-*ita-retenue)%base_<0){
            (*result).digits_.push_back( base_+(*itb-*ita-retenue));
            retenue=1;
        }
        else{
            (*result).digits_.push_back((*itb-*ita-retenue));
            retenue=0;
        }
        itb++;
        }
    return *result;
 }
 UInteger& UInteger::operator -=(const UInteger &x){
    UInteger *result;
    int retenue =0;
    std::_List_const_iterator<char> ita = x.digits_.begin();
    for (std::_List_iterator<char> itb = digits_.begin();itb != digits_.end() || ita!= x.digits_.end();ita++) {
        if((*itb-*ita-retenue)%base_<0){
        //if(retenue >0 ){
            *itb = (int) base_+(*itb-*ita-retenue);
            retenue=1;
        //}
        //else *itb = (int) 0;
        }
        else {
          *itb=(*itb-*ita-retenue);
          retenue=0;
        }
            itb++;
    }
    result=this;



  return *this;
 }
 UInteger& UInteger::operator +=(const UInteger &x){
    int retenue =0;
    std::_List_const_iterator<char> ita = x.digits_.begin();
    for (std::_List_iterator<char> itb = digits_.begin();itb != digits_.end() || ita!= x.digits_.end();ita++) {
        *itb=((retenue+*ita+*itb)%base_);
        retenue=(retenue+*ita+*itb)/base_;
        itb++;
    }

    return *this;
 }
bool UInteger::operator ==(const UInteger &x)const{
    bool result = true;
    std::_List_const_iterator<char> ita = x.digits_.begin();
    for (std::_List_const_iterator<char> itb = digits_.begin();(itb != digits_.end() || ita!= x.digits_.end() )&& result;ita++) {
        if(*itb!=*ita){
            result = false;
        }
        itb++;
    }
    return result;
 }
 bool UInteger::operator !=(const UInteger &x)const{
    bool result = false;
    std::_List_const_iterator<char> ita = x.digits_.begin();
    for (std::_List_const_iterator<char> itb = digits_.begin();(itb != digits_.end() || ita!= x.digits_.end() )&& !result;ita++) {
        if(*itb!=*ita){
            result = true;
        }
        itb++;
    }
    return result;
 }
 bool UInteger::operator <(const UInteger &x)const{
    bool result = false;
    std::_List_const_iterator<char> ita = x.digits_.end();
    for (std::_List_const_iterator<char> itb = digits_.end();(itb != digits_.begin() || ita!= x.digits_.begin() )&& !result;ita--) {
        if(*ita>*itb){
            result = true;
        }
        itb--;
    }
    return result;
 }
 UInteger UInteger::bourage(size_t nb)const{
    UInteger result = UInteger(*this);
    for(unsigned int i =0;i<nb;i++){
        result.digits_.push_back(0);
    }
    return result;

 }



