

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
        *itb=((retenue+*itb+*ita)%base_);
        retenue=(retenue+*itb+*ita)/base_;
        cout << retenue << endl;
        itb++;
    }
    if(retenue > 0) uia.setDigits().push_back((retenue));
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
    UInteger uia,uib;//copie de this et x
    uia=UInteger(*this);
    uib=UInteger(x);
    std::list<char>::reverse_iterator ita = uia.setDigits().rbegin();
    for (std::list<char>::reverse_iterator itb = uib.setDigits().rbegin();(itb != uib.setDigits().rend() && ita!= uia.setDigits().rend() )&& !result;ita++) {
        if(*ita>*itb){
            result = true;
        }
        itb++;
    }
    if(ita!= uia.setDigits().rend()){
        return true;
    }
    return result;
}
 bool UInteger::operator <=(const UInteger &x)const{
    return (operator<(x) || operator==(x) );
 }
  bool UInteger::operator >(const UInteger &x)const{
    bool result = false;
    UInteger uia,uib;//copie de this et x
    uia=UInteger(*this);
    uib=UInteger(x);
    std::list<char>::reverse_iterator ita = uib.setDigits().rbegin();
    for (std::list<char>::reverse_iterator itb = uia.setDigits().rbegin();(itb != uia.setDigits().rend() && ita!= uib.setDigits().rend() )&& !result;ita++) {
        if(*ita>*itb){
            result = true;
        }
        itb++;
    }
    if(ita!= uia.setDigits().rend()){
        return true;
    }
    return result;
}
 bool UInteger::operator >=(const UInteger &x)const{
    return (operator>(x) || operator==(x) );
 }
ostream& UInteger::operator << (ostream& os,UInteger &x)const{
        list<char>::const_reverse_iterator it;
        //for(it = setDigits().rbegin(); it != setDigits().rend() ; it++){
         //   os << (int)*it;
        //}
        it = setDigits().rbegin();
        os << *it;
        return os;
  }
 UInteger& UInteger::operator ++(){
        *this += UInteger((long)1);
        return  *this;
 }
 UInteger UInteger::operator /(const UInteger &x)const{
    if(x >= *this)return NULL;
    for(UInteger i = UInteger((long)0); i<x;++i){
        //*this -=
    }
 }
  UInteger UInteger::operator *(const UInteger &x)const{
    UInteger result = UInteger((long)0);
    for(UInteger i = UInteger((long)1); i<x;++i){
        cout << "cgsqfc" << ends;
        result += x;
    }
    return result;
 }
UInteger UInteger::bourage(size_t nb)const{
    UInteger result = UInteger(*this);
    for(int i =0;i<nb;i++){
        result.setDigits().push_back(0);
    }
    return result;

}



