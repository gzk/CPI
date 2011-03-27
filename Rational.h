#ifndef RATIONAL_H
#define RATIONAL_H


#include <iostream>
#include "Integer.h"
#include "Rational.h"

class Rational
{
    /*! \class Rational
    * \brief classe representant un Rationnel, elle contient un UInteger représentant le numerateur, un autre UInteger représentant le dénominateur et un signe
    */
public:
    /*!
    * \brief Type énuméré Sign qui représente le signe de l'entier
    *
    */
    enum Sign {negative_ = -1, zero = 0, positive_ = 1};
    //constructeurs
    /*!
    * \brief Constructeur vide de la classe Rational
    */
    Rational();
    /*!
    * \brief Constructeur de copie de la classe Rational
    * \param x : un Integer
    */
    Rational(Rational const& x);
    /*!
    * \brief Constructeur de la classe Rational à partir de deux UInteger ( un numérateur et un dénominateur) et son signe
    * \param num : un UInteger representant le numérateur
    * \param den : un UInteger representant le dénominateur
    * \param sign : le signe
    */
    Rational(Sign sign,UInteger const& num,UInteger const& den);
    /*!
    * \brief Constructeur de la classe Rational à partir de deux Integer ( un numérateur et un dénominateur)
    * \param num : un Integer representant le numérateur
    * \param den : un Integer representant le dénominateur
    */
    Rational(Integer const& num,Integer const& den);
    /*!
    * \brief Constructeur de la classe Rational à partir de deux long ( un numérateur et un dénominateur) et une base
    * \param num : un long representant le numérateur
    * \param den : un long representant le dénominateur
    * \param base : la base
    */
    Rational(long num,long den,char base);


 //opérateurs de calcul
 /*!
    * \brief addition :
    * addition de deux Rational sans modification des données
    * \param x :  le nombre à ajouter
    *\return le resultat de l'operation
    */
    Rational operator +(const Rational &x)const;
    /*!
    * \brief addition :
    * addition de deux Rational avec modification de l'Rational appelant
    * \param x :  le nombre à ajouter
    */
    Rational& operator +=(const Rational &x);
    /*!
    * \brief soustraction :
    * soustraction de deux Rational sans modification de l'Rational appelant
    * \param x :  le nombre à soustraire
    */
    Rational operator -(const Rational &x)const;
    /*!
    * \brief soustraction :
    * soustraction de deux Rational avec modification de l'Rational appelant
    * \param x :  le nombre à soustraire
    *\return le resultat de l'operation
    */
    Rational& operator -=(const Rational &x);
    /*!
    * \brief multiplication :
    * multiplication de deux Rational sans modification de l'Rational appelant
    * \param x :  le nombre à multiplier
    *\return le resultat de l'operation
    */
    Rational operator *(const Rational &x)const;
    /*!
    * \brief multiplication :
    * multiplication de deux Rational avec modification de l'Rational appelant
    * \param x :  le nombre à multiplier
    */
    Rational& operator *=(const Rational &x);
    /*!
    * \brief multiplication :
    * multiplication de deux Rational avec modification de l'Rational appelant
    *pour pouvoir multiplier un Rational par un long
    * \param x :  le nombre à multiplier
    *\return le resultat de l'operation
    */
    Rational operator *(const long x)const;
    /*!
    * \brief division :
    * divisions de deux Rational sans modification de l'Rational appelant
    * \param x :  le nombre à diviser
    */
    Rational operator /(const Rational &x)const;
    /*!
    * \brief division :
    * divisions de deux Rational avec modification de l'Rational appelant
    * \param x :  le nombre à diviser
    *\return le resultat de l'operation
    */
    Rational& operator /=(const Rational &x);

    //opérateurs d'incrémentation
    /*!
    * \brief incrementation :
    */
    Rational& operator ++();
    /*!
    * \brief incrementation par un nombre
    *\param le nombre à ajouter
    */
    Rational& operator ++(int i);
    /*!
    * \brief decrementation
    */
    Rational& operator --();
    /*!
    * \brief decrementation par un nombre
    *\param le nombre à ajouter
    */
    Rational& operator --(int i);

    //opérateurs de comparaison
        /*!
    * \brief operateur d'égalité
    * \param x :  le nombre à comparer
    */
    bool operator ==(const Rational &x)const;
    /*!
    * \brief operateur d'inegalité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator !=(const Rational &x)const;
    /*!
    * \brief operateur d'inferiorité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator <(const Rational &x)const;
    /*!
    * \brief operateur inferieur ou égal
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator <=(const Rational &x)const;
    /*!
    * \brief operateur de supériorité
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator >(const Rational &x)const;
    /*!
    * \brief operateur supérieur ou égal
    * \param x :  le nombre à comparer
    *\return un booleen
    */
    bool operator >=(const Rational &x)const;
    /*!
    * \brief Getter du numérateur
    *\return le numérateur
    */
    const UInteger& getNum() const;
    /*!
    * \brief Getter du dénominateur
    *\return le dénominateur
    */
    const UInteger& getDen() const;
    /*!
    * \brief Getter du signe
    *\return le signe
    */
    const Sign getSign() const;

private:
    /*!
    * \brief pgcd de deux UInteger
    * \param i :  le premier nombre
    * \param j :  le deuxieme nombre
    *\return le pgcd
    */
    UInteger pgcd(UInteger i, UInteger j);//methode qui retourne le pgcd
    /*!
    * \brief methode qui rend ireductible un Rational
    */
    Rational& reduire();
    UInteger num_;/*!< Un UInteger représentant le numérateur*/
    UInteger den_;/*!< Un UInteger représentant le dénominateur*/
    Sign sign_;/*!< le signe*/
};

std::ostream& operator << (std::ostream &os, const Rational &output);


#endif // RATIONAL_H
