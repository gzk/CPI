#ifndef DEF_ARRAYNUMBER
#define DEF_ARRAYNUMBER
#include <iostream>
#include <list>

class ArrayNumber{

/*classe de base qui ne sera jamais instanciée mais qui permet de représenter les nombres en les stockant dans une liste*/

protected:

	char base_;//la base est représentée par un char (entier entre 1 et 255)
	std::list<char> digits_;//on stocke les chiffres un par un dans une liste de char (entre 0 et base-1)

public:

	//constructeurs:
	  ArrayNumber();
	  ArrayNumber(const ArrayNumber& a);
	  ArrayNumber(unsigned long int x, char base=10);

	//getters et setters
	  const std::list<char>& getDigits() const;
	  std::list<char>& setDigits();
	  char getBase() const;

};

std::ostream& operator << (std::ostream& os,const ArrayNumber &x);

#endif
