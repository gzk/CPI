#include <list>
#ifndef DEF_ARRAYNUMBER
#define DEF_ARRAYNUMBER

using namespace std;

class ArrayNumber{

	protected:

		char base_;

	public:
        std::list<char> digits_;
/*
        std::list<char> getList()const;
		ArrayNumber();
		ArrayNumber(int n, char N);
*/
	    ArrayNumber();
	    ArrayNumber(const ArrayNumber& a);
	    ArrayNumber(long x, char base=10);

	    const list<char>& getDigits() const ;
	    char getBase() const ;
};

#endif
