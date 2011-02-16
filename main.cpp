
#include "UInteger.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main() {
    long l1,l2;
    cin >> l1;
    cin >> l2;
    UInteger ut1(l1);
    UInteger ut2 = UInteger(l2);
    //operator o ;
    //cin >> o;
    cout << ut1 <<" / "<<ut2 << endl;

    ut1  = ut1/ut2;
   // ut1  = ut1.toBase(13);
    cout << "resultat : "<< ut1 << ends;

   // if(ut1<ut2){
      // cout << "cool" << ends;
    //}



}


