#include "ArrayNumber.h"

using namespace std;


//constructeurs:
	  ArrayNumber::ArrayNumber(){ //nombre nul, la base par défaut est de 10
			base_ = 10;
	  }

	  ArrayNumber::ArrayNumber(unsigned long int n, char base){//constructeur principal, il effectue la conversion vers la base voulue
			
			base_ = base;
			if (n==0) setDigits().push_front(0); //si n vaut 0 on met 0 dans digits_
			else{
				  while(n > 0){
						unsigned long stock = n % base_;
						setDigits().push_back(stock);
						n /= base_;
				  }
			}
	  }

	  ArrayNumber::ArrayNumber(ArrayNumber const& a):base_(a.getBase()),digits_(a.getDigits()){}//constructeur de copie

//getters et setters
	  const list<char>& ArrayNumber::getDigits()const{
			return digits_;
	  }

	  list<char>& ArrayNumber::setDigits(){
			return digits_;
	  }
	  char ArrayNumber::getBase()const{
			return base_;
	  }




