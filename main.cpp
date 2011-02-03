
#include "UInteger.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;


int main() {
    /*UInteger ut((long)121,88);
    int i =0;
    for (std::list<char>::iterator it = ut.digits_.begin();it != ut.digits_.end();it++) {
        cout << (int)*it << endl;
        /*i++;
        if (i==2) return 1;
    }*/
    long l1,l2;
    cin >> l2;
    cin >> l1;
    UInteger ut1(l1,10);
    for (std::list<char>::iterator it = (ut1).digits_.begin();it != (ut1).digits_.end();it++) {
        cout << (int)*it << ends;
        /*i++;
        if (i==2) return 1;*/
    }
     cout << " " << endl;
    UInteger ut2(l2,10);
    for (std::list<char>::iterator it = (ut2).digits_.begin();it != (ut2).digits_.end();it++) {
        cout << (int)*it << ends;
        /*i++;
        if (i==2) return 1;*/
    }
      cout << " " << endl;
    UInteger *ut = new UInteger();
    ut2 -= ut1;
    int i =0;
    for (std::list<char>::iterator it = (ut2).digits_.begin();it != (ut2).digits_.end();it++) {
        cout << (int)*it << ends;
        /*i++;
        if (i==2) return 1;*/
   // }*/
    //if(ut1<ut2) cout << "cool" << ends;


    }

}


