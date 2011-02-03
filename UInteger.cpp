
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
    digits_=x.getDigits();
    base_=x.base_;
}
//autres
UInteger::UInteger(unsigned long x,int base) :ArrayNumber(sizeof(unsigned long)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(unsigned short)+1;
    for (std::list<char>::iterator it = digits_.begin();it != getDigits().end();it++) {
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
    for (std::list<char>::iterator it = getDigits().begin();it != getDigits().end();it++) {
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
    for (std::list<char>::iterator it = getDigits().begin();it != getDigits().end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    getDigits().reverse();
}
UInteger::UInteger(int x,int base):ArrayNumber(sizeof(int)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(int)+1;
    for (std::list<char>::iterator it = getDigits().begin();it != getDigits().end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    getDigits().reverse();
}
UInteger::UInteger(unsigned short x,int base):ArrayNumber(sizeof(unsigned short)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(unsigned short)+1;
    for (std::list<char>::iterator it = getDigits().begin();it != getDigits().end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    getDigits().reverse();
}
UInteger::UInteger(short x,int base):ArrayNumber(sizeof(short)+1,0){
    base_=base;
    int j = 0;
    int tmp ;
    int taille = sizeof(short)+1;
    for (std::list<char>::iterator it = getDigits().begin();it != getDigits().end();it++) {
        tmp = (int) x/(pow(base_,taille-1-j++));
        *it = tmp ;
        x-=(tmp*(pow(base_,taille-j)));
    }
    getDigits().reverse();
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
    std::_List_const_iterator<char> ita = uia.getDigits().begin();
    for (std::_List_const_iterator<char> itb = uib.getDigits().begin();itb != uib.getDigits().end() || ita!= uia.getDigits().end();ita++) {
        (*result).setDigits().push_back((retenue+*itb+*ita)%base_);
        retenue=(retenue+*ita+*itb)/base_;
        itb++;
    }
    return *result;
 }
UInteger UInteger::operator -(const UInteger &x)const{
//ajout de zero
    UInteger uia,uib;
    if((x.getDigits().size()) > getDigits().size()){
        uia=bourage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else{
        uib=x.bourage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    int retenue =0;
    UInteger *result = new UInteger();
// calcul
    std::_List_const_iterator<char> itb = uia.getDigits().begin();
    for (std::_List_const_iterator<char> ita = uib.getDigits().begin();ita != uib.getDigits().end() || itb!= uia.getDigits().end();ita++) {
        if((*itb-*ita-retenue)%base_<0){
            (*result).setDigits().push_back( base_+(*itb-*ita-retenue));
            retenue=1;
        }
        else{
            (*result).setDigits().push_back((*itb-*ita-retenue));
            retenue=0;
        }
        itb++;
        }
    return *result;
 }
 UInteger& UInteger::operator -=(const UInteger &x){
    int retenue =0;
    //ajout de zero
    UInteger uia,uib;//copie de this et x avec ajout de zero
    if((x.getDigits().size()) > getDigits().size()){
        uia=bourage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else{
        uib=x.bourage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    std::_List_iterator<char> itb = uia.setDigits().begin();
    for (std::_List_const_iterator<char> ita = uib.getDigits().begin();ita != uib.getDigits().end() || itb!= uia.getDigits().end();ita++) {
        if((*itb-*ita-retenue)%base_<0){
            *itb = (int) base_+(*itb-*ita-retenue);
            retenue=1;
        }
        else {
          *itb=(*itb-*ita-retenue);
          retenue=0;
        }
            itb++;
    }
    setDigits()=uia.getDigits();
  return *this;
 }
 UInteger& UInteger::operator +=(const UInteger &x){
    int retenue =0;
        //ajout de zero
    UInteger uia,uib;//copie de this et x avec ajout de zero
    if((x.getDigits().size()) > getDigits().size()){
        uia=bourage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else{
        uib=x.bourage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    std::_List_iterator<char> itb = uia.setDigits().begin();
    for (std::_List_const_iterator<char> ita = uib.getDigits().begin();ita != uib.getDigits().end() || itb!= uia.getDigits().end();ita++) {
        *itb=((retenue+*ita+*itb)%base_);
        retenue=(retenue+*ita+*itb)/base_;
        itb++;
    }
    setDigits()=uia.getDigits();
    return *this;
 }
bool UInteger::operator ==(const UInteger &x)const{
    bool result = true;
    std::_List_const_iterator<char> ita = x.getDigits().begin();
    for (std::_List_const_iterator<char> itb = getDigits().begin();(itb != getDigits().end() || ita!= x.getDigits().end() )&& result;ita++) {
        if(*itb!=*ita){
            result = false;
        }
        itb++;
    }
    return result;
 }
 bool UInteger::operator !=(const UInteger &x)const{
    bool result = false;
    std::_List_const_iterator<char> ita = x.getDigits().begin();
    for (std::_List_const_iterator<char> itb = getDigits().begin();(itb != getDigits().end() || ita!= x.getDigits().end() )&& !result;ita++) {
        if(*itb!=*ita){
            result = true;
        }
        itb++;
    }
    return result;
 }
 bool UInteger::operator <(const UInteger &x)const{
    bool result = false;
    std::_List_const_iterator<char> ita = x.getDigits().end();
    for (std::_List_const_iterator<char> itb = getDigits().end();(itb != getDigits().begin() || ita!= x.getDigits().begin() )&& !result;ita--) {
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
        result.setDigits().push_back(0);
    }
    return result;

 }



