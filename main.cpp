
#include "UInteger.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main() {
    long l1,l2;
    cin >> l2;
    cin >> l1;
    UInteger ut1(l1,10);
    for (std::list<char>::iterator it = (ut1).digits_.begin();it != (ut1).digits_.end();it++) {
        cout << (int)*it << ends;
    }
     cout << " " << endl;
    UInteger ut2 = UInteger(l2,10);

    for (std::list<char>::iterator it = (ut2).digits_.begin();it != (ut2).digits_.end();it++) {
        cout << (int)*it << ends;
    }
      cout << " " << endl;

    ut2 += ut1;
    for (std::list<char>::iterator it = (ut2).digits_.begin();it != (ut2).digits_.end();it++) {
        cout << (int)*it << ends;
    }
    if(ut1>=ut2) cout << "cool" << ends;




}


