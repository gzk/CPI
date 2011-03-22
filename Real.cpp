#include "Real.h"
unsigned int Real::precision_=50;
using namespace std;

//constructeurs
	Real::Real(){
		num_ = Integer();
		comma_=0;
	}

/*	Real::Real(UInteger comma, Integer x){
        num_=x;
        comma_=comma;
	}
*/
//opérateurs de calcul
	/*Real Real::operator +(const Real &x) const{
		Real result =Real();

		UInteger a = getNb();
		UInteger b = x.getNb();

		if(getSign() == x.getSign()){
			result = Real(x.getSign(), b+a);
		}else{
			if(getSign() == -1 && a > b){ // !!! implémenter comparaison
				result = Real(negative_,a - b);
			}else if(getSign() > -1 && a > b){
				result = Real(positive_,a - b);
			}else if(getSign() == -1 && a < b){
				result = Real(positive_, b - a);
			}else/*(this.getSign() > -1 && a  < b )*//*{
				result = Real(negative_, b - a);
			}
		}

		return result;
	}

	Real& Real::operator +=(const Real &x){
		return *this = (*this) + x;
	}

	Real Real::operator -(const Real &x) const{
		Real result =Real();

		UInteger a = getNb();
		UInteger b = x.getNb();

		if(getSign() == x.getSign()){
			if(a<b){
				result = Real(x.getSign(), b-a);
			}else{
				result = Real(x.getSign(), a-b);
			}
		}else{
			if(getSign() == -1 && a > b){
				result = Real(negative_,a - b);
			}else if(getSign() > -1 && a > b){
				result = Real(positive_,a - b);
			}else if(getSign() == -1 && a < b){
				result = Real(positive_, b - a);
			}else/*(this.getSign() > -1 && a  < b )*//*{
				result = Real(negative_, b - a);
			}
		}

		return result;
	}

	Real& Real::operator -=(const Real &x){
		return *this = (*this) - x;
	}

	Real Real::operator *(const Real &x) const{
        Sign sign = negative_;
        if(getSign()==x.getSign()){
            sign=positive_;
        }
        return (Real(sign,getNb()*x.getNb()));
	}
	Real Real::operator *(long x) const{
        Sign sign = negative_;
        if((getSign()==1 && x>0 )|| (getSign()==negative_ && x<0 ) ){
            sign=positive_;
        }
        return (Real(sign,getNb()*x));
	}

	Real& Real::operator *=(const Real &x){
		return *this = (*this) * x;
	}

    Real Real::operator /(const Real &x) const{
        Sign sign = negative_;
        if(getSign()==x.getSign()){
            sign=positive_;
        }
        return (Real(sign,getNb()/x.getNb()));
	}

	Real& Real::operator /=(const Real &x){
		return *this = (*this) / x;
	}

	Real Real::operator %(const Real &x)const{
		return Real(getSign(),getNb()%x.getNb());
	}

	Real& Real::operator %=(const Real &x){
		return *this = (*this) % x;
	}



//opérateurs de comparaison

	bool Real::operator ==(const Real &x)const{
		return getSign()==x.getSign() && getNb()==x.getNb();
	}

	bool Real::operator !=(const Real &x)const{
		return getSign()!=x.getSign() || getNb()!=x.getNb();
	}

    bool Real::operator <(const Real &x)const{//strictement inférieur
         if(getSign()==x.getSign()){
            if(getSign()==negative_){
                return getNb() > x.getNb();
            }
            else return getNb() < x.getNb();
        }
        return getSign()==negative_;
    }

	bool Real::operator <=(const Real &x)const{//inférieur ou égal
        return ((*this) < x) || ((*this) == x);
	}

	bool Real::operator >(const Real &x)const{
		if(getSign()==x.getSign()){
            if(getSign()==negative_){
                return getNb() < x.getNb();
            }
            else return getNb() > x.getNb();
        }
        return getSign()==positive_;
	}

	bool Real::operator >=(const Real &x)const{
		return ((*this) > x) || ((*this) == x);
	}


//opérateurs d'incrémentation

	Real& Real::operator ++(){
		return *this = *this + Real((long)1,(*this).getNb().getBase());
	}
	Real& Real::operator ++(int i){
		return *this = *this + Real((long)i,(*this).getNb().getBase());
	}
	Real& Real::operator --(){
		return *this = *this + Real((long)-1,(*this).getNb().getBase());
	}
	Real& Real::operator --(int i){
		return *this = *this + Real((long)-i,(*this).getNb().getBase());
	}

//opérateurs logiques
/*
	Real Real::operator &(const Real &x)const;
	Real Real::operator |(const Real &x)const;
	Real Real::operator ^(const UInteger &x)const;*/

//opérateur d'affichage
/*
	  ostream& operator << (ostream &os, const Real &output){
			if(output.getSign() == Real::negative_) os << '-';
			os << output.getNb();
			return os;
	  }
*/
