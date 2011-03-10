#include "Rational.h"
#include <stdlib.h>
using namespace std;

	Rational::Rational(){
		sign_ = zero;
		num_ = UInteger();
		den_ = UInteger();
	}
	Rational::Rational(Sign sign,UInteger const& num,UInteger const& den){
			sign_ =sign_;
			num_ = num;
			if (den == UInteger(0)){
                exit(1);
			}
            den_ = den;
	}
	Rational::Rational(Integer const& numerateur,Integer const& denominateur){
		if( numerateur.getSign()!=denominateur.getSign()){
			sign_ = negative_;
        }else sign_ = positive_;
        den_ = denominateur.getNb();
        num_ = numerateur.getNb();

	}

	Rational::Rational(long numerateur,long denominateur,char base){

			if(numerateur < 0 && denominateur >0 || numerateur > 0 && denominateur < 0){
				sign_ = negative_;
			}else if(x > 0){
				sign_ = positive_;
				ui_ = UInteger(x,base);
			}else{
				sign_ = zero;
				ui_ = UInteger((long)0,base);
			}
	}

	//copie
	Integer::Integer(Integer const& x){
		ui_ = x.getNb();
		sign_ = x.getSign();
	}
    const UInteger& Integer::getNb() const{
        return ui_;
    }
    const Integer::Sign Integer::getSign() const{
        return sign_;
    }
