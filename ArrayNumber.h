
#ifndef DEF_ARRAYNUMBER
#define DEF_ARRAYNUMBER
#include <list>

class ArrayNumber{

	protected:

		char base_;

	public:
	    std::list<char> digits_;
	    ArrayNumber();
	    ArrayNumber(const ArrayNumber& a);
	    ArrayNumber(long x, char base=10);
	    const std::list<char>& getDigits() const ;
	    std::list<char>& setDigits();
	    char getBase() const ;
};

#endif
