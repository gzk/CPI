#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>

#include "UInteger.h"



class Integer
{
    /*! \class Integer
    * \brief classe representant un entier signé, elle encapsule un UInteger et représente son signe grâce à un type énuméré,
    	et surcharge les mêmes opérateurs
    */

public:
    /*!
    * \brief Type énuméré Sign qui représente le signe de l'entier
    *
    */
    enum Sign {negative_ = -1, zero = 0, positive_ = 1};

    //constructeurs
    /*!
    * \brief Constructeur vide de la classe Integer
    */
    Integer();
    /*!
    * \brief Constructeur de copie de la classe Integer
    * \param x : un Integer
    */
    Integer(Integer const& x);
    /*!
    * \brief Constructeur de la classe Integer à partir d'un UInteger
    * \param x : un UInteger
    */
    Integer(UInteger const& x);
    /*!
    * \brief Constructeur de la classe Integer à partir d'un UInteger
    * \param x : un UInteger
    * \param sign : le signe de l'entier
    */
    Integer(Sign sign, UInteger ui);
    /*!
    * \brief
    * Constructeur de la classe Integer
    * \param x :  le nombre à représenter
    * \param base : la base dans laquelle est représenté le nombre
    */
    Integer(long x,char base );

    //opérateurs de calcul
  /*!
    * \brief addition :
    * addition de deux Integer sans modification des données
    * \param x :  le nombre à ajouter
    *\return le resultat de l'operation
    */
    Integer operator +(const Integer &x)const;
    /*!
    * \brief addition :
    * addition de deux Integer avec modification de l'Integer appelant
    * \param x :  le nombre à ajouter
    */
    Integer& operator +=(const Integer &x);
    /*!
    * \brief soustraction :
    * soustraction de deux Integer sans modification de l'Integer appelant
    * \param x :  le nombre à soustraire
    */
    Integer operator -(const Integer &x)const;
    /*!
    * \brief soustraction :
    * soustraction de deux Integer avec modification de l'Integer appelant
    * \param x :  le nombre à soustraire
    *\return le resultat de l'operation
    */
    Integer& operator -=(const Integer &x);
    /*!
    * \brief multiplication :
    * multiplication de deux Integer sans modification de l'Integer appelant
    * \param x :  le nombre à multiplier
    *\return le resultat de l'operation
    */
    Integer operator *(const Integer &x)const;
    /*!
    * \brief multiplication :
    * multiplication de deux Integer avec modification de l'Integer appelant
    * \param x :  le nombre à multiplier
    */
    Integer& operator *=(const Integer &x);
    /*!
    * \brief multiplication :
    * multiplication de deux Integer avec modification de l'Integer appelant
    *pour pouvoir multiplier un Integer par un long
    * \param x :  le nombre à multiplier
    *\return le resultat de l'operation
    */
    Integer operator *(const long x)const;
    /*!
    * \brief division :
    * divisions de deux Integer sans modification de l'Integer appelant
    * \param x :  le nombre à diviser
    */
    Integer operator /(const Integer &x)const;
    /*!
    * \brief division :
    * divisions de deux Integer avec modification de l'Integer appelant
    * \param x :  le nombre à diviser
    *\return le resultat de l'operation
    */
    Integer& operator /=(const Integer &x);

    //opérateurs d'incrémentation
    /*!
    * \brief incrementation :
    */
    Integer& operator ++();
    /*!
    * \brief incrementation par un nombre
    *\param le nombre à ajouter
    */
    Integer& operator ++(int i);
    /*!
    * \brief decrementation
    */
    Integer& operator --();
    /*!
    * \brief decrementation par un nombre
    *\param le nombre à ajouter
    */
    Integer& operator --(int i);

    //opérateurs de comparaison
        /*!
    * \brief operateur d'égalité
    * \param x :  le nombre à comparer
    */
    bool operator ==(const Integer &x)const;
    /*!
    * \brief operateur d'inegalité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator !=(const Integer &x)const;
    /*!
    * \brief operateur d'inferiorité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator <(const Integer &x)const;
    /*!
    * \brief operateur inferieur ou égal
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator <=(const Integer &x)const;
    /*!
    * \brief operateur de supériorité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator >(const Integer &x)const;
    /*!
    * \brief operateur supérieur ou égal
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator >=(const Integer &x)const;

    //opérateurs de flux
    Integer operator <<(int b)const;
    Integer operator >>(int b)const;

    //opérateurs logiques
    /*!
    * \brief modulo binaire
    * \param x :  le nombre à diviser
    *\return le reste
    */
    Integer operator %(const Integer &x)const;
    /*!
    * \brief modulo binaire :
    *
    * \param x :  le nombre à diviser
    *
    */
    Integer& operator %=(const Integer &x);
    //accesseurs
    /*!
    * \brief Getter de l'UInteger encapsulé
    *\return Un UInteger
    */
    const UInteger& getNb() const;
    /*!
    * \brief Getter du signe
    *\return le signe
    */
    const Sign getSign() const;

private:

    UInteger ui_;/*!< Un UInteger représentant le nombre*/
    Sign sign_;/*!<son signe */
};

//opérateur d'affichage
std::ostream& operator << (std::ostream &os, const Integer &output);


#endif
