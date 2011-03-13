#include <iterator>
#include <math.h>
#include <iostream>

#include "UInteger.h"
#include "Integer.h"

using namespace std;

//constructeurs
	Integer::Integer(){
		sign_ = zero;
		ui_ = UInteger();
	}

	Integer::Integer(Sign sign, UInteger x){
		if(x < UInteger((long)0)){
			sign_ = negative_;
			ui_ = UInteger(x);
		}else if(x > UInteger((long)0)){
			sign_ = positive_;
			ui_ = UInteger(x);
		}else{
			sign_ = zero;
			ui_ = UInteger((long)0);
		}
	}

	Integer::Integer(long x, char base){
			if(x < 0){
				sign_ = negative_;
				ui_ = UInteger(-x,base);
			}else if(x > 0){
				sign_ = positive_;
				ui_ = UInteger(x,base);
			}else{
				sign_ = zero;
				ui_ = UInteger((long)0,base);
			}
	}
	Integer::Integer(UInteger const& x){//copie
		ui_ = x;
		sign_ = positive_;
	}
	Integer::Integer(Integer const& x){//copie
		ui_ = x.getNb();
		sign_ = x.getSign();
	}

//accesseurs
    const UInteger& Integer::getNb() const{
        return ui_;
    }
    const Integer::Sign Integer::getSign() const{
        return sign_;
    }

//opérateurs de calcul
	Integer Integer::operator +(const Integer &x) const{
		Integer result =Integer();

		UInteger a = getNb();
		UInteger b = x.getNb();

		if(getSign() == x.getSign()){
			result = Integer(x.getSign(), b+a);
		}else{
			if(getSign() == -1 && a > b){ // !!! implémenter comparaison
				result = Integer(negative_,a - b);
			}else if(getSign() > -1 && a > b){
				result = Integer(positive_,a - b);
			}else if(getSign() == -1 && a < b){
				result = Integer(positive_, b - a);
			}else/*(this.getSign() > -1 && a  < b )*/{
				result = Integer(negative_, b - a);
			}
		}

		return result;
	}

	Integer& Integer::operator +=(const Integer &x){
		return *this = (*this) + x;
	}

	Integer Integer::operator -(const Integer &x) const{
		Integer result =Integer();

		UInteger a = getNb();
		UInteger b = x.getNb();

		if(getSign() == x.getSign()){
			if(a<b){
				result = Integer(x.getSign(), b-a);
			}else{
				result = Integer(x.getSign(), a-b);
			}
		}else{
			if(getSign() == -1 && a > b){
				result = Integer(negative_,a - b);
			}else if(getSign() > -1 && a > b){
				result = Integer(positive_,a - b);
			}else if(getSign() == -1 && a < b){
				result = Integer(positive_, b - a);
			}else/*(this.getSign() > -1 && a  < b )*/{
				result = Integer(negative_, b - a);
			}
		}

		return result;
	}

	Integer& Integer::operator -=(const Integer &x){
		return *this = (*this) - x;
	}

	Integer Integer::operator *(const Integer &x) const{
        Sign sign = negative_;
        if(getSign()==x.getSign()){
            sign=positive_;
        }
        return (Integer(sign,getNb()*x.getNb()));
	}
	Integer Integer::operator *(long x) const{
        Sign sign = negative_;
        if((getSign()==1 && x>0 )|| (getSign()==negative_ && x<0 ) ){
            sign=positive_;
        }
        return (Integer(sign,getNb()*x));
	}

	Integer& Integer::operator *=(const Integer &x){
		return *this = (*this) * x;
	}

    Integer Integer::operator /(const Integer &x) const{
        Sign sign = negative_;
        if(getSign()==x.getSign()){
            sign=positive_;
        }
        return (Integer(sign,getNb()/x.getNb()));
	}

	Integer& Integer::operator /=(const Integer &x){
		return *this = (*this) / x;
	}

	Integer Integer::operator %(const Integer &x)const{
		return Integer(getSign(),getNb()%x.getNb());
	}

	Integer& Integer::operator %=(const Integer &x){
		return *this = (*this) % x;
	}



//opérateurs de comparaison

	bool Integer::operator ==(const Integer &x)const{
		return getSign()==x.getSign() && getNb()==x.getNb();
	}

	bool Integer::operator !=(const Integer &x)const{
		return getSign()!=x.getSign() || getNb()!=x.getNb();
	}

    bool Integer::operator <(const Integer &x)const{//strictement inférieur
         if(getSign()==x.getSign()){
            if(getSign()==negative_){
                return getNb() > x.getNb();
            }
            else return getNb() < x.getNb();
        }
        return getSign()==negative_;
    }

	bool Integer::operator <=(const Integer &x)const{//inférieur ou égal
        return ((*this) < x) || ((*this) == x);
	}

	bool Integer::operator >(const Integer &x)const{
		if(getSign()==x.getSign()){
            if(getSign()==negative_){
                return getNb() < x.getNb();
            }
            else return getNb() > x.getNb();
        }
        return getSign()==positive_;
	}

	bool Integer::operator >=(const Integer &x)const{
		return ((*this) > x) || ((*this) == x);
	}


//opérateurs d'incrémentation

	Integer& Integer::operator ++(){
		return *this = *this + Integer((long)1,(*this).getNb().getBase());
	}
	Integer& Integer::operator ++(int i){
		return *this = *this + Integer((long)i,(*this).getNb().getBase());
	}
	Integer& Integer::operator --(){
		return *this = *this + Integer((long)-1,(*this).getNb().getBase());
	}
	Integer& Integer::operator --(int i){
		return *this = *this + Integer((long)-i,(*this).getNb().getBase());
	}

//opérateurs logiques
/*
	Integer Integer::operator &(const Integer &x)const;
	Integer Integer::operator |(const Integer &x)const;
	Integer Integer::operator ^(const UInteger &x)const;*/

//opérateur d'affichage

	  ostream& operator << (ostream &os, const Integer &output){
			if(output.getSign() == Integer::negative_) os << '-';
			os << output.getNb();
			return os;
	  }
