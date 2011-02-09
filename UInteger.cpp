

#include <ostream>

#include "ArrayNumber.h"
#include "UInteger.h"

#include <iterator>

#include <math.h>

//

//


using namespace std;
UInteger::UInteger():ArrayNumber(){}
//copie
UInteger::UInteger(UInteger const& x){
    digits_ = x.getDigits();
    base_ = x.getBase();
}
UInteger::UInteger(long x, int base):ArrayNumber((long)x, base){}
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
    if(retenue > 0) (*result).setDigits().push_back((retenue));
    return *result;
 }
UInteger UInteger::operator -(const UInteger &x)const{
    if(operator<(x)){
        return NULL;
    }
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

    //int retenue =0;
        //ajout de zero
    UInteger uia;//copie de this et x avec ajout de zero
    uia = x + *this;
    //if(x+)
    /*if((x.getDigits().size()) > getDigits().size()){
        uia=bourage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else{
        uib=x.bourage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    std::_List_iterator<char> itb = uia.setDigits().begin();
    for (std::_List_const_iterator<char> ita = uib.getDigits().begin();ita != uib.getDigits().end() || itb!= uia.getDigits().end();ita++) {
        *itb=((retenue+*itb+*ita)%base_);
        retenue=(retenue+*itb+*ita)/base_;
        cout << retenue << endl;
        itb++;
    }
    if(retenue > 0) uia.setDigits().push_back((retenue));*/
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
    UInteger uia,uib;//copie de this et x
    uia=UInteger(*this);
    uib=UInteger(x);
    //bourrage
    if((x.getDigits().size()) > getDigits().size()){
        uia=bourage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else{
        uib=x.bourage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    //
    std::list<char>::reverse_iterator ita = uia.setDigits().rbegin();
    for(std::list<char>::reverse_iterator itb = uib.setDigits().rbegin();itb != uib.setDigits().rend() && ita!= uia.setDigits().rend();ita++) {
        if(*ita<*itb){
            return true;
        }
         if(*ita>*itb){
            return false;
        }
        itb++;
    }
    return false;
}
 bool UInteger::operator <=(const UInteger &x)const{
    return (operator<(x) || operator==(x) );
 }
  bool UInteger::operator >(const UInteger &x)const{

    return (!operator<=(x));

}
 bool UInteger::operator >=(const UInteger &x)const{
    return (operator>(x) || operator==(x) );
 }
ostream& operator << (ostream& os,const UInteger &x){
        list<char>::const_reverse_iterator it;
        for(it = x.getDigits().rbegin();it != x.getDigits().rend(); it++){
            os << (int)*it;
        }
        return os;
  }
 UInteger& UInteger::operator ++(){
        *this += UInteger((long)1,getBase());
        return  *this;
 }
   UInteger& UInteger::operator ++(int i){
        *this += UInteger((long)i,getBase());
        return  *this;
 }
  UInteger& UInteger::operator --(){
        *this -= UInteger((long)1,getBase());
        return  *this;
 }
  UInteger& UInteger::operator --(int i){
        *this -= UInteger((long)i,getBase());
        return  *this;
 }
 UInteger UInteger::operator /(const UInteger &x)const{
    if(x>*this || x ==UInteger((long)0)){
        return UInteger((long)0,getBase());
    }
    UInteger result = UInteger((long)0,getBase());
    UInteger thisbis = *this;
    while(thisbis-x>UInteger((long)0,getBase())){
        thisbis-=x;
        ++result;
    }
    if(thisbis==x){
        ++result;
    }
    return result;
 }
  UInteger UInteger::operator *(const UInteger &x)const{
    UInteger result = UInteger((long)0,getBase());
    for(UInteger i = UInteger((long)0,getBase()); i<x;++i){
        result += *this;
    }
    return result;
 }

 UInteger& UInteger::operator /=(const UInteger &x){
    *this=*this / x;
    return *this;
 }
  UInteger& UInteger::operator *=(const UInteger &x){
    *this=*this * x;
    return *this;
 }
UInteger UInteger::operator %(const UInteger &x)const{
    if(x>*this || x ==UInteger((long)0)){
        return UInteger((long)0,getBase());
    }
    UInteger result = UInteger((long)0,getBase());
    UInteger thisbis = *this;

    while(thisbis-x>UInteger((long)0,getBase())){
        thisbis-=x;
        ++result;
    }
    if(thisbis==x){
        ++result;
    }

    return thisbis;
 }
  UInteger& UInteger::operator %=(const UInteger &x){
    *this=*this % x;
    return *this;
 }
UInteger UInteger::bourage(size_t nb)const{
    UInteger result = UInteger(*this);
    for(int i =0;i<nb;i++){
        result.setDigits().push_back(0);
    }
    return result;

}



