
#include "ArrayNumber.h"

using namespace std;
/*
ArrayNumber::ArrayNumber():digits_(){

}

ArrayNumber::ArrayNumber(int n, char N): digits_(n,N)
{
	//base???
}*/
const list<char>& ArrayNumber::getDigits()const{
    return digits_;
}
char ArrayNumber::getBase()const{
    return base_;
}

ArrayNumber::ArrayNumber(){
      base_ = 10;
}

ArrayNumber::ArrayNumber(long n, char base){
        //si n vaut 0 on met 0 dans digits_
	base_ = base;
        if (n==0) digits_.push_front(0);
	else{
	    while(n > 0){
		  long stock = n % base_;
		  digits_.push_back(stock);
		  n /= base_;
		  //cout << "stock = " << stock << " n= " << n << endl;
	    }
	    //cout << "STOP!" << endl;
	}
}
ArrayNumber::ArrayNumber(ArrayNumber const& a):digits_(a.getDigits()),base_(a.getBase()){}

