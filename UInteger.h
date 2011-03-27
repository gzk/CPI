#ifndef DEF_UINTEGER
#define DEF_UINTEGER
#include "ArrayNumber.h"
#include <iostream>
#include <ostream>

class UInteger : public ArrayNumber
{
/*! \class UInteger
* \brief classe representant un entier non signé,
*elle hérite de ArrayNumber, elle reprend ses attributs (la base et la liste de nombres)
* et ses méthodes notamment les accesseurs
*/

public:

    //constructeurs (ils prennent en chargent tous les types d'entiers primitifs mais appellent au final tous le constructeur de base d'ArrayNumber
    /*!
        * \brief Constructeur vide de la classe UInteger
        */
    UInteger();

    /*!
    * \brief Constructeur de copie de la classe UInteger
    * \param x :  un UInteger
    */
    UInteger(UInteger const& x);
    /*!
    * \brief
    * Constructeur de la classe UInteger
    * \param x :  le nombre à représenter
    * \param base : la base dans laquelle est représenté le nombre defaut 10
    */
    UInteger(unsigned long x,char base_=10);
    //opérateurs de calcul
    /*!
    * \brief addition :
    * addition de deux UInteger sans modification des données
    * \param x :  le nombre à ajouter
    *\return le resultat de l'operation
    */
    UInteger operator +(const UInteger &x)const;
    /*!
    * \brief addition :
    * addition de deux UInteger avec modification de l'UInteger appelant
    * \param x :  le nombre à ajouter
    */
    UInteger& operator +=(const UInteger &x);
    /*!
    * \brief soustraction :
    * soustraction de deux UInteger sans modification de l'UInteger appelant
    * \param x :  le nombre à soustraire
    */
    UInteger operator -(const UInteger &x)const;
    /*!
    * \brief soustraction :
    * soustraction de deux UInteger avec modification de l'UInteger appelant
    * \param x :  le nombre à soustraire
    *\return le resultat de l'operation
    */
    UInteger& operator -=(const UInteger &x);
    /*!
    * \brief multiplication :
    * multiplication de deux UInteger sans modification de l'UInteger appelant
    * \param x :  le nombre à multiplier
    *\return le resultat de l'operation
    */
    UInteger operator *(const UInteger &x)const;
    /*!
    * \brief multiplication :
    * multiplication de deux UInteger avec modification de l'UInteger appelant
    * \param x :  le nombre à multiplier
    */
    UInteger& operator *=(const UInteger &x);
    /*!
    * \brief multiplication :
    * multiplication de deux UInteger avec modification de l'UInteger appelant
    *pour pouvoir multiplier un UInteger par un long
    * \param x :  le nombre à multiplier
    *\return le resultat de l'operation
    */
    UInteger operator *(const long x)const;
    /*!
    * \brief division :
    * divisions de deux UInteger sans modification de l'UInteger appelant
    * \param x :  le nombre à diviser
    */
    UInteger operator /(const UInteger &x)const;
    /*!
    * \brief division :
    * divisions de deux UInteger avec modification de l'UInteger appelant
    * \param x :  le nombre à diviser
    *\return le resultat de l'operation
    */
    UInteger& operator /=(const UInteger &x);

    //opérateurs d'incrémentation
    /*!
    * \brief incrementation :
    */
    UInteger& operator ++();
    /*!
    * \brief incrementation par un nombre
    *\param le nombre à ajouter
    */
    UInteger& operator ++(int i);
    /*!
    * \brief decrementation
    */
    UInteger& operator --();
    /*!
    * \brief decrementation par un nombre
    *\param le nombre à ajouter
    */
    UInteger& operator --(int i);

    //opérateurs de comparaison
        /*!
    * \brief operateur d'égalité
    * \param x :  le nombre à comparer
    */
    bool operator ==(const UInteger &x)const;
    /*!
    * \brief operateur d'inegalité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator !=(const UInteger &x)const;
    /*!
    * \brief operateur d'inferiorité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator <(const UInteger &x)const;
    /*!
    * \brief operateur inferieur ou égal
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator <=(const UInteger &x)const;
    /*!
    * \brief operateur de supériorité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator >(const UInteger &x)const;
    /*!
    * \brief operateur supérieur ou égal
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator >=(const UInteger &x)const;

    //opérateurs de flux
    UInteger operator <<(int b)const;
    UInteger operator >>(int b)const;

    //opérateurs logiques
    /*!
    * \brief modulo binaire
    * \param x :  le nombre à diviser
    *\return le reste
    */
    UInteger operator %(const UInteger &x)const;
    /*!
    * \brief modulo binaire
    *
    * \param x :  le nombre à diviser
    *
    */
    UInteger& operator %=(const UInteger &x);
    /*!
    * \brief ou exclusif (xor)
    *
    * \param x :  le nombre à comparer
    *
    */
    UInteger operator ^(const UInteger &x)const;
    /*!
    * \brief AND
    *
    * \param x :  le nombre à comparer
    *\return le resultat
    */
    UInteger operator &(const UInteger &x)const;
    /*!
    * \brief OR
    *
    * \param x :  le nombre à comparer
    *\return le resultat
    */
    UInteger operator |(const UInteger &x)const;

private:
    /*!
    * \brief convertisseur
    *\param la base dans laquelle le nombre doit etre représenté
    *\return le nombre dans la base demandé
    */
    UInteger toBase(char base)const;//méthodes "outils utilisés dans les autres méthodes"
    /*!
    * \brief pour remplir de zéros la liste de chiffres afin de faciliter les calculs (envisager de la supprimer!)
    *\param nb : le nombre de zero à rajouter
    *\return le nombre avec les zero rajouté
    */
    UInteger bourrage(size_t nb) const;//
};

//opérateur d'affichage
std::ostream& operator << (std::ostream& os,const UInteger &x);

#endif
