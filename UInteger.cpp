#include "ArrayNumber.h"
#include "UInteger.h"

#include <ostream>
#include <iterator>
#include <math.h>

using namespace std;

//constructeurs

UInteger::UInteger():ArrayNumber() {} //constructeur vide

UInteger::UInteger(UInteger const& x) //constructeur de copie
{
    digits_ = x.getDigits();
    base_ = x.getBase();
}

UInteger::UInteger(unsigned long x, char base) //constructeur principal de la classe, qui appelle celui d'ArrayNumber pour initialiser la liste
{
    ArrayNumber a((unsigned long)x, base);
  //  cout << a <<endl;
    digits_= a.getDigits();
    base_ = a.getBase();
}

//opérateurs de calcul

UInteger UInteger::operator +(const UInteger &x)const //addition binaire
{
    /* UInteger uia,uib;
    	//ajout de zéros via la méthode bourrage
    	if((x.getDigits().size()) > getDigits().size()){
    		  uia=bourrage(x.getDigits().size()-getDigits().size());
    		  uib=x;
    	}
    	else{
    		  uib=x.bourrage(getDigits().size()-x.getDigits().size());
    		  uia=*this;
    	}
    	*/
    UInteger result =UInteger();//résultat nul
    int retenue =0;
    _List_const_iterator<char> ita = x.getDigits().begin();
    _List_const_iterator<char> itb ;
    for (itb= getDigits().begin(); itb != getDigits().end() && ita!= x.getDigits().end(); ita++)
    {
        result.setDigits().push_back((retenue+*itb+*ita)%base_);
        retenue=(retenue+*ita+*itb)/base_;
        itb++;
    }
    while((itb != getDigits().end()))
    {
        result.setDigits().push_back((retenue+*itb)%base_);
        retenue=(retenue+*itb)/base_;
        itb++;
    }
    while((ita != x.getDigits().end()))
    {
        result.setDigits().push_back((retenue+*ita)%base_);
        retenue=(retenue+*ita)/base_;
        ita++;
    }
    if(retenue > 0) result.setDigits().push_back((retenue));

    return result;
}

UInteger& UInteger::operator +=(const UInteger &x) //addition unaire
{
    UInteger uia;
    uia = x + *this;
    setDigits()=uia.getDigits();

    return *this;
}

UInteger UInteger::operator -(const UInteger &x)const //soustraction binaire
{
        UInteger result =*this;
        if(x.digits_.size() > result.digits_.size()){
            return  UInteger(0);
        }
        bool retenu = false;
        int base = (int)x.base_;
        list<char>::iterator it;
        list<char>::const_iterator ite;
        ite = x.digits_.begin();
        for(it = result.setDigits().begin(); ite != x.digits_.end() ; it++)
        {
            (*it) -= (*ite) ;
            if(retenu) {
                (*it)--;
            }
            retenu = false;
            while((*it) < 0){
                retenu = true;
                (*it) += base;
            }
            ite++;
        }

        for(; it != result.setDigits().end() ; it++){
             if(retenu){
                 (*it)--;
             }
             retenu = false;
             if((*it) < 0){
                 (*it) += base;
                 retenu = true;
             }
        }
   // cout << result << endl;
    list<char>::reverse_iterator itr = result.setDigits().rbegin();
    while(itr!=result.setDigits().rend()&&*(itr++)==0){
        result.setDigits().pop_back();
        //itr++;
    }
    //cout << result << endl;
        return result;
}

UInteger& UInteger::operator -=(const UInteger &x) //soustraction unaire
{
    UInteger uia;
    uia = (*this)-x;
    setDigits()=uia.getDigits();

    return *this;
}

UInteger UInteger::operator *(const UInteger &x)const //multiplication binaire
{
    UInteger result = UInteger((long)0,getBase());
    //on applique des additions successives
    for(UInteger i = UInteger((long)0,getBase()); i<x; ++i)
    {
        result += (*this);
    }

    return result;
}

UInteger& UInteger::operator *=(const UInteger &x) //multiplication unaire
{
    (*this) =(*this) * x;
    return *this;
}

UInteger UInteger::operator /(const UInteger &x)const //division binaire
{

    if(x==UInteger(1)){
    return *this;
    }
    if(x>*this || x ==UInteger((long)0))
    {
        return UInteger((long)0,getBase());
    }
    UInteger result = UInteger((long)0,getBase());
    UInteger thisbis = *this;
    while((thisbis-x)>UInteger((long)0,getBase()))
    {

        thisbis-=x;
      //  cout <<endl<< thisbis-x << " 1 " << x <<endl;
        ++result;
    }


    if(thisbis==x)
    {
        ++result;
    }

    return result;
}

UInteger& UInteger::operator /=(const UInteger &x) //division unaire
{
    *this = *this / x;
    return *this;
}

UInteger UInteger::modulo(const UInteger &x)const //modulo
{
    if((*this)>x)
    {
        return (*this)-(((*this)/x)*x);
    }
    else  return x-((x/(*this))*(*this));
}
UInteger UInteger::operator %(const UInteger &x)const //modulo binaire
{
    if(x>*this || x ==UInteger((long)0))
    {
        return UInteger((long)0,getBase());
    }
    UInteger result = UInteger((long)0,getBase());
    UInteger thisbis = *this;
    while(thisbis-x>UInteger((long)0,getBase()))
    {
        //cout << *this << endl;
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

UInteger& UInteger::operator %=(const UInteger &x) //modulo unaire
{
    *this=*this % x;

    return *this;
}


//opérateurs d'incrémentation

UInteger& UInteger::operator ++() //ajout de 1
{
    *this += UInteger((long)1,getBase());
    return  *this;
}

UInteger& UInteger::operator ++(int i) //ajout d'un entier donné
{
    *this += UInteger((long)i,getBase());
    return  *this;
}

UInteger& UInteger::operator --() //retrait de 1
{
    *this -= UInteger((long)1,getBase());
    return  *this;
}

UInteger& UInteger::operator --(int i) //retrait d'un entier donné
{
    *this -= UInteger((long)i,getBase());
    return  *this;
}

//opérateurs de comparaison

bool UInteger::operator ==(const UInteger &x)const //égalité
{
    bool result = true;
    _List_const_iterator<char> ita = x.getDigits().begin();
    for (_List_const_iterator<char> itb = getDigits().begin(); (itb != getDigits().end() || ita!= x.getDigits().end() )&& result; ita++)
    {
        if(*itb!=*ita)
        {
            result = false;
        }
        itb++;
    }
    return result;
}

bool UInteger::operator !=(const UInteger &x)const //différence
{
    bool result = false;
    _List_const_iterator<char> ita = x.getDigits().begin();
    for (_List_const_iterator<char> itb = getDigits().begin(); (itb != getDigits().end() || ita!= x.getDigits().end() )&& !result; ita++)
    {
        if(*itb!=*ita)
        {
            result = true;
        }
        itb++;
    }
    return result;
}

bool UInteger::operator <(const UInteger &x)const //strictement inférieur
{
    UInteger uia,uib;//copie de this et x
    uia=UInteger(*this);
    uib=UInteger(x);
    //ajout de zéros
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

    list<char>::reverse_iterator ita = uia.setDigits().rbegin();
    for(list<char>::reverse_iterator itb = uib.setDigits().rbegin(); itb != uib.setDigits().rend() && ita!= uia.setDigits().rend(); ita++)
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

bool UInteger::operator <=(const UInteger &x)const //inférieur ou égal
{
    return (operator<(x) || operator==(x) );
}

bool UInteger::operator >(const UInteger &x)const //strictement supérieur
{
    return (!operator<=(x));
}

bool UInteger::operator >=(const UInteger &x)const //supérieur ou égal
{
    return (operator>(x) || operator==(x) );
}


//opérateurs logiques

UInteger UInteger::operator &(const UInteger &n)const //ET logique
{
    UInteger x =toBase(2);
    UInteger y =n.toBase(2);
    y=y.bourrage(x.getDigits().size()-y.getDigits().size());
    x=x.bourrage(y.getDigits().size()-x.getDigits().size());

    UInteger result = UInteger();
    _List_const_iterator<char> itx = x.getDigits().begin();
    for (_List_const_iterator<char> ity = y.getDigits().begin(); ity != y.getDigits().end() || itx!= x.getDigits().end(); itx++)
    {
        if(*itx==1 && *ity==1)
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

UInteger UInteger::operator |(const UInteger &n)const //OU logique
{
    UInteger x =toBase(2);
    UInteger y =n.toBase(2);
    y=y.bourrage(x.getDigits().size()-y.getDigits().size());
    x=x;
    UInteger result = UInteger();
    _List_const_iterator<char> itx = x.getDigits().begin();
    for (_List_const_iterator<char> ity = y.getDigits().begin(); ity != y.getDigits().end() || itx!= x.getDigits().end(); itx++)
    {
        if(*itx==1 || *ity==1)
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

UInteger UInteger::operator ^(const UInteger &n)const //ou exclusif (xor)
{
    UInteger x =toBase(2);
    UInteger y =n.toBase(2);
    y=y.bourrage(x.getDigits().size()-y.getDigits().size());
    x=x;
    UInteger result = UInteger();
    _List_const_iterator<char> itx = x.getDigits().begin();
    for (_List_const_iterator<char> ity = y.getDigits().begin(); ity != y.getDigits().end() || itx!= x.getDigits().end(); itx++)
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


//opérateurs de flux (toujours sur des nombres en base 2)

UInteger UInteger::operator <<(int b) const //décalage à gauche
{
    UInteger result = (*this).toBase((char)2); //on convertit en base 2
    for(int i=0; i<b; i++)
    {
        result.setDigits().push_front((char)0); //on ajoute b zéros à la fin du nombre (donc au début de la liste!)
    }
    return result;
}

UInteger UInteger::operator >>(int b) const //décalage à droite
{
    UInteger result = (*this).toBase((char)2); //on convertit en base 2
    for(int i=0; i<b; i++)
    {
        result.setDigits().pop_front(); //on enlève les b bits de la fin du nombre (donc du début de la liste)
    }
    return result;
}


//méthodes "outils"

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
        cout << "base= " << base <<endl;
        UInteger reste;
        do
        {
            reste = tmp % base;
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
        for (_List_const_iterator<char> itx = getDigits().begin(); itx != getDigits().end() ; itx++)
        {
            cout <<"azerty " <<(long)pow(getBase(),i) <<endl;
            result+=*itx*((long)pow(getBase(),i));
            i++;
        }
    }
    return result;
}

/* méthode permettant de multiplier un UInteger par un long pour augmenter la vitesse d'exécution*/
UInteger UInteger::operator *(const long x)const
{
    UInteger result = UInteger((long)0,getBase());
    for(long i = 0; i<x; ++i)
    {
        result += *this;
    }
    return result;
}


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




