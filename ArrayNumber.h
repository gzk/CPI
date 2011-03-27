#ifndef DEF_ARRAYNUMBER
#define DEF_ARRAYNUMBER
#include <iostream>
#include <list>

class ArrayNumber
{
/*! \class ArrayNumber
* \brief classe representant un nombre sous forme de liste de chiffres
*
* La classe gere differentes bases
*/
protected:

    char base_; /*!< la base est représentée par un char (entier entre 1 et 255)*/
    std::list<char> digits_;/*!<on stocke les chiffres un par un dans une liste de char (entre 0 et base-1)*/

public:
    /*!
    * \brief Constructeur vide
    *
    * Constructeur de la classe ArrayNumber
    */
    ArrayNumber();
    /*!
    * \brief Constructeur de copie
    *Constructeur de la classe ArrayNumber
    * \param array :  un ArrayNumber
    */

    ArrayNumber(const ArrayNumber& array);
    /*!
    * \brief Constructeur
    *Constructeur de la classe ArrayNumber
    * \param x :  le nombre à stocker
    * \param base : la base dans laquelle stocker le nombre defaut 10
    */
    ArrayNumber(unsigned long int x, char base=10);

    //getters et setters
    /*!
    * \brief Getter de la liste de chiffres
    * \return la liste de chiffres non modifiable
    */
    const std::list<char>& getDigits() const;
    /*!
    * \brief Setter de la liste de chiffres
    * \return la liste de chiffres modifiable
    */
    std::list<char>& setDigits();
    /*!
    * \brief Getter de la base
    *\return  la base
    */
    char getBase() const;

};

std::ostream& operator << (std::ostream& os,const ArrayNumber &x);

#endif
