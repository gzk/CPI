
#include <ostream>

#include "ArrayNumber.h"
#include "UInteger.h"

#include <iterator>

#include <math.h>



using namespace std;
UInteger::UInteger():ArrayNumber() {}
//copie
UInteger::UInteger(UInteger const& x)
{
    digits_ = x.getDigits();
    base_ = x.getBase();
}
UInteger::UInteger(long x, int base):ArrayNumber((long)x, base) {}
UInteger UInteger::operator +(const UInteger &x)const
{
    UInteger uia,uib;
    if((x.getDigits().size()) > getDigits().size())
    {
        uia=bourrage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else
    {
        uib=x.bourrage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    UInteger result =UInteger();
    int retenue =0;
    std::_List_const_iterator<char> ita = uia.getDigits().begin();
    for (std::_List_const_iterator<char> itb = uib.getDigits().begin(); itb != uib.getDigits().end() || ita!= uia.getDigits().end(); ita++)
    {
        result.setDigits().push_back((retenue+*itb+*ita)%base_);
        retenue=(retenue+*ita+*itb)/base_;
        itb++;
    }
    if(retenue > 0) result.setDigits().push_back((retenue));
    return result;
}
UInteger UInteger::operator -(const UInteger &x)const
{
    if(operator<(x))
    {
        return NULL;
    }
//ajout de zero
    UInteger uia,uib;
    if((x.getDigits().size()) > getDigits().size())
    {
        uia=bourrage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else
    {
        uib=x.bourrage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    int retenue =0;
    UInteger result =UInteger();
// calcul
    std::_List_const_iterator<char> itb = uia.getDigits().begin();
    for (std::_List_const_iterator<char> ita = uib.getDigits().begin(); ita != uib.getDigits().end() || itb!= uia.getDigits().end(); ita++)
    {
        if((*itb-*ita-retenue)%base_<0)
        {
            result.setDigits().push_back( base_+(*itb-*ita-retenue));
            retenue=1;
        }
        else
        {
            result.setDigits().push_back((*itb-*ita-retenue));
            retenue=0;
        }
        itb++;
    }

    return result;
}
UInteger& UInteger::operator -=(const UInteger &x)
{
    int retenue =0;
    //ajout de zero
    UInteger uia,uib;//copie de this et x avec ajout de zero
    if((x.getDigits().size()) > getDigits().size())
    {
        uia=bourrage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else
    {
        uib=x.bourrage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    std::_List_iterator<char> itb = uia.setDigits().begin();
    for (std::_List_const_iterator<char> ita = uib.getDigits().begin(); ita != uib.getDigits().end() || itb!= uia.getDigits().end(); ita++)
    {
        if((*itb-*ita-retenue)%base_<0)
        {
            *itb = (int) base_+(*itb-*ita-retenue);
            retenue=1;
        }
        else
        {
            *itb=(*itb-*ita-retenue);
            retenue=0;
        }
        itb++;
    }
    setDigits()=uia.getDigits();
    return *this;
}
UInteger& UInteger::operator +=(const UInteger &x)
{
    UInteger uia;
    uia = x + *this;
    setDigits()=uia.getDigits();
    return *this;
}
bool UInteger::operator ==(const UInteger &x)const
{
    bool result = true;
    std::_List_const_iterator<char> ita = x.getDigits().begin();
    for (std::_List_const_iterator<char> itb = getDigits().begin(); (itb != getDigits().end() || ita!= x.getDigits().end() )&& result; ita++)
    {
        if(*itb!=*ita)
        {
            result = false;
        }
        itb++;
    }
    return result;
}
bool UInteger::operator !=(const UInteger &x)const
{
    bool result = false;
    std::_List_const_iterator<char> ita = x.getDigits().begin();
    for (std::_List_const_iterator<char> itb = getDigits().begin(); (itb != getDigits().end() || ita!= x.getDigits().end() )&& !result; ita++)
    {
        if(*itb!=*ita)
        {
            result = true;
        }
        itb++;
    }
    return result;
}
bool UInteger::operator <(const UInteger &x)const
{
    UInteger uia,uib;//copie de this et x
    uia=UInteger(*this);
    uib=UInteger(x);
    //bourrage
    if((x.getDigits().size()) > getDigits().size())
    {
        uia=bourrage(x.getDigits().size()-getDigits().size());
        uib=x;
    }
    else
    {
        uib=x.bourrage(getDigits().size()-x.getDigits().size());
        uia=*this;
    }
    //
    std::list<char>::reverse_iterator ita = uia.setDigits().rbegin();
    for(std::list<char>::reverse_iterator itb = uib.setDigits().rbegin(); itb != uib.setDigits().rend() && ita!= uia.setDigits().rend(); ita++)
    {
        if(*ita<*itb)
        {
            return true;
        }
        if(*ita>*itb)
        {
            return false;
        }
        itb++;
    }
    return false;
}
bool UInteger::operator <=(const UInteger &x)const
{
    return (operator<(x) || operator==(x) );
}
bool UInteger::operator >(const UInteger &x)const
{

    return (!operator<=(x));

}
bool UInteger::operator >=(const UInteger &x)const
{
    return (operator>(x) || operator==(x) );
}
/*ostream& operator << (ostream& os,const UInteger &x){
        list<char>::const_reverse_iterator it;
        for(it = x.getDigits().rbegin();it != x.getDigits().rend(); it++){
            os << (int)*it;
        }
        return os;
  }*/
UInteger& UInteger::operator ++()
{
    *this += UInteger((long)1,getBase());
    return  *this;
}
UInteger& UInteger::operator ++(int i)
{
    *this += UInteger((long)i,getBase());
    return  *this;
}
UInteger& UInteger::operator --()
{
    *this -= UInteger((long)1,getBase());
    return  *this;
}
UInteger& UInteger::operator --(int i)
{
    *this -= UInteger((long)i,getBase());
    return  *this;
}
UInteger UInteger::operator /(const UInteger &x)const
{
    if(x>*this || x ==UInteger((long)0))
    {
        return UInteger((long)0,getBase());
    }
    UInteger result = UInteger((long)0,getBase());
    UInteger thisbis = *this;
    while(thisbis-x>UInteger((long)0,getBase()))
    {
        thisbis-=x;
        ++result;
    }
    if(thisbis==x)
    {
        ++result;
    }
    return result;
}

UInteger UInteger::operator *(const UInteger &x)const{
  /*  int fd[2];
    pipe(fd);
    int pid=fork();
*/
    UInteger result ((long)0,getBase());
    if(x<*this)
    {
        for(UInteger i = UInteger((long)0,getBase()); i<x; ++i)
        {
            result += *this;
        }
    }
    else
    {
        for(UInteger i = UInteger((long)0,getBase()); i<*this; ++i)
        {
            result += x;
        }
    }
    return result;
}

UInteger& UInteger::operator /=(const UInteger &x)
{
    *this=*this / x;
    return *this;
}
UInteger& UInteger::operator *=(const UInteger &x)
{
    *this=*this * x;
    return *this;
}
UInteger UInteger::operator %(const UInteger &x)const
{
    if(x>*this || x ==UInteger((long)0))
    {
        return UInteger((long)0,getBase());
    }
    UInteger result = UInteger((long)0,getBase());
    UInteger thisbis = *this;
    while(thisbis-x>UInteger((long)0,getBase()))
    {
        cout << *this << endl;
        thisbis-=x;
        ++result;
    }
    if(thisbis==x)
    {
        thisbis-=x;
        ++result;
    }

    return thisbis;
}
/*
UInteger UInteger::operator ^(const UInteger &x)const{
   UInteger result =*this;
    for(UInteger i = UInteger((long)1);i<x;++i){
       result *= result;
    }
    return result;
}
*/
UInteger& UInteger::operator %=(const UInteger &x)
{
    *this=*this % x;
    return *this;
}
UInteger UInteger::operator &(const UInteger &n)const
{
    UInteger x =toBase(2);
    UInteger y =n.toBase(2);
    //if((x.getDigits().size()) > y.getDigits().size()){
    y=y.bourrage(x.getDigits().size()-y.getDigits().size());
    x=x;
    /*}
    else{
        x=x.bourrage(y.getDigits().size()-x.getDigits().size());
    }*/
    UInteger result = UInteger();
    std::_List_const_iterator<char> itx = x.getDigits().begin();
    for (std::_List_const_iterator<char> ity = y.getDigits().begin(); ity != y.getDigits().end() || itx!= x.getDigits().end(); itx++)
    {
        if(*itx==1 &*ity==1)
        {
            result.setDigits().push_back(1);
        }
        else result.setDigits().push_back(0);
        ity++;
    }
    result.base_=2;
    result= result.toBase(getBase());
    result.base_=getBase();
    return result;
}
UInteger UInteger::operator |(const UInteger &n)const
{
    UInteger x =toBase(2);
    UInteger y =n.toBase(2);
    y=y.bourrage(x.getDigits().size()-y.getDigits().size());
    x=x;
    UInteger result = UInteger();
    std::_List_const_iterator<char> itx = x.getDigits().begin();
    for (std::_List_const_iterator<char> ity = y.getDigits().begin(); ity != y.getDigits().end() || itx!= x.getDigits().end(); itx++)
    {
        if(*itx==1 |*ity==1)
        {
            result.setDigits().push_back(1);
        }
        else result.setDigits().push_back(0);
        ity++;
    }
    result.base_=2;
    result= result.toBase(getBase());
    result.base_=getBase();
    return result;
}
UInteger UInteger::operator ^(const UInteger &n)const
{
    UInteger x =toBase(2);
    UInteger y =n.toBase(2);
    y=y.bourrage(x.getDigits().size()-y.getDigits().size());
    x=x;
    UInteger result = UInteger();
    std::_List_const_iterator<char> itx = x.getDigits().begin();
    for (std::_List_const_iterator<char> ity = y.getDigits().begin(); ity != y.getDigits().end() || itx!= x.getDigits().end(); itx++)
    {
        if(*itx!=*ity)
        {
            result.setDigits().push_back(1);
        }
        else result.setDigits().push_back(0);
        ity++;
    }
    result.base_=2;
    result= result.toBase(getBase());
    result.base_=getBase();
    return result;
}



UInteger UInteger::operator <<(int b) const
{
    UInteger result = (*this).toBase((char)2); //on convertit en base 2
    for(int i=0; i<b; i++)
    {
        result.setDigits().push_front((char)0); //on ajoute b zéros à la fin du nombre (donc au début de la liste!)
    }
    return result;
}

UInteger UInteger::operator >>(int b) const
{
    UInteger result = (*this).toBase((char)2); //on convertit en base 2
    for(int i=0; i<b; i++)
    {
        result.setDigits().pop_front(); //on enlève les b bits de la fin du nombre (donc du début de la liste)
    }
    return result;
}

/*Cette fonction permet de remplier avec des zéros la liste de chiffres afin que lors d'une opération sur deux nombres, leurs listes aient la même longueur*/
UInteger UInteger::bourrage(size_t nb)const
{
    UInteger result = UInteger(*this);
    for(int i =0; i<(int)nb; i++)
    {
        result.setDigits().push_back(0);
    }
    return result;

}
/*Convertisseur vers une base donnée*/
UInteger UInteger::toBase(char b)const
{
    UInteger result =UInteger();
    result.base_=b;

    if (*this==UInteger((long)0))result.setDigits()=getDigits();//si le nombre vaut 0, il vaut 0 dans toutes les bases

    else if(getBase()>b)
    {

        UInteger tmp = *this;
        UInteger base = UInteger((long)b,getBase());
        int cpt = 0;
        cout<< "base= " << base <<endl;
        do
        {
            UInteger reste(tmp);
            reste %= base;
            cout <<"reste = "<< (int)reste.getDigits().front() << endl;
            result.setDigits().push_back(reste.getDigits().front());
            if(tmp >= base)
            {
                tmp /= base;
            }
        }
        while(tmp >= base);
        cout <<"tmp = " << tmp << endl;
        result.setDigits().push_back(tmp.getDigits().front());
    }
    else
    {
        cout << "hhvh " << *this << endl;
        int i = 0;
        for (std::_List_const_iterator<char> itx = getDigits().begin(); itx != getDigits().end() ; itx++)
        {
            cout <<"azerty " <<(long)pow(getBase(),i) <<endl;
            result+=*itx*((long)pow(getBase(),i));
            i++;
        }
    }
    return result;




}
// pour pouvoir multiplier un UInteger par un long pour augmenter la vitesse d'exetution
UInteger UInteger::operator *(const long x)const{
    UInteger result = UInteger((long)0,getBase());
    for(long i = 0; i<x; ++i){
        result += *this;
    }
    return result;
}
/*UInteger multiplierKaratsuba(UInteger nombre1, UInteger nombre2)
{
    UInteger resultat, nombre1_1, nombre1_2, nombre2_1, nombre2_2;
    UInteger X, Y, Z, sommeX, sommeY;
    std::_List_const_iterator<char> ptrNb1 = nombre1.getDigits().begin(), ptrNb2 = nombre2.getDigits().end();
    int i = 0, taille = (max(nombre1->taille, nombre2->taille)) / 2;

    //Si la taille des nombre est inférieure à 100 on fait la multiplication
    // classique
    if (nombre1->taille <= 100 && nombre2->taille <= 100)
    {
        resultat = nombre1 * nombre2;
    }

    //Sinon on découpé les nombres en deux sous parties
    else
    {
        nombre1_1 = UInteger();
        nombre1_2 = UInteger();
        nombre2_1 = UInteger();
        nombre2_2 = UInteger();

        //Sous parties de droites des nombres (on prend les chiffres depuis la fin
        //jusqu'à taille, qui est le max de la taille des deux nombres d'entrés
        for (i = 0; i < taille; i++)
        {
            if (ptrNb1 != NULL)
            {
                ajouterDebut(&nombre1_2, ptrNb1->chiffre);
                ptrNb1 = ptrNb1->precedent;
            }

            if (ptrNb2 != NULL)
            {
                ajouterDebut(&nombre2_2, ptrNb2->chiffre);
                ptrNb2 = ptrNb2->precedent;
            }
        }

        //Puis la sous partie de droite
        while (ptrNb1 != NULL)
        {
            ajouterDebut(&nombre1_1, ptrNb1->chiffre);
            ptrNb1 = ptrNb1->precedent;
        }

        if (nombre1_1->debut == NULL)
        {
            ajouterDebut(&nombre1_1, 0);
        }

        while (ptrNb2 != NULL)
        {
            ajouterDebut(&nombre2_1, ptrNb2->chiffre);
            ptrNb2 = ptrNb2->precedent;
        }

        if (nombre2_1->debut == NULL)
        {
            ajouterDebut(&nombre2_1, 0);
        }

        //Et finalement on fait les calculs avec les appels récursifs de la fonction
        sommeX = nombre1_1 + nombre1_2;
        sommeY = nombre2_1+ nombre2_2;
        X = multiplierKaratsuba(nombre1_1, nombre2_1);
        Y = multiplierKaratsuba(nombre1_2, nombre2_2);
        Z = multiplierKaratsuba(sommeX, sommeY);
        Z = differenceNombre(Z, X);
        Z = differenceNombre(Z, Y);

        multiplier10(&X, 2*taille);
        multiplier10(&Z, taille);

        resultat = ajouterNombre(X, Y);
        resultat = ajouterNombre(resultat, Z);
    }

    return resultat;
}*/
//opérateur d'affichage
ostream& operator << (ostream &os, const UInteger &output)
{

    list<char>::const_reverse_iterator it;

    for(it = output.getDigits().rbegin(); it != output.getDigits().rend() ; it++)
    {
        os << (int)*it;
    }
    return os;
}




