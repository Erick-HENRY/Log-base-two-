/**
 * @file
 * @author      Erick HENRY
 * @version     0.0
 * @date        25 juin 2018
 * @brief       Prototype pour mettre en place des fonctions mathématiques génériques : log base 2.
 *
 * @details     Fournit le log base 2 d'un entier 16 bits : retourne un entier 16 bits, log base 2 x 256.
 * 
 * @defgroup    GENERIC_MATH_GROUP Les fonctions mathématiques génériques
 * 
 * @brief       Définition des fonctions mathématiques génériques.
 * 
 * @{
 */


// This is a guard condition so that contents of this file are not included more than once.
#ifndef _GENERIC_MATH_H
#define _GENERIC_MATH_H


/*
  Section: Included Files
*/
#include <stdint.h>     /* Utilisation : Standard integer types per ISO/IEC 9899:1999 */


/*
  Section: Define
*/
/**
 * @brief       Division entre entier avec un arrondi au nombre supérieur
 * 
 * @details     Division de n par d, deux entiers signés ou non.
 *              Le résultat est arrondi à l'entier juste supérieur.
 * 
 * @param[in]   n         dividende
 * 
 * @param[in]   d         diviseur
 * 
 * @return le quotien
 *
 */
#define DIV_ROUND_UP( n , d )                                                   \
            ( ( (n) + (d) - 1 ) / (d) )


/*
  Section: Structure, Union, Enumeration
*/
// Empty


/*
 Section: typedef
*/
// Empty


/*
 Section: Macro Definitions
*/
// Empty


/*
  Section: Extern interface
*/
// Empty


/*
 Section: Local Variables
*/
// Empty


/*
  Section: Interface Routines
*/
/**
 * @brief   Calcul le log base 2 d'un entier 16 bits.
 * 
 * @details Fournit le log base 2 d'un entier 16 bits : retourne un entier 16 bits, log base 2 x 256.
 * 
 * @param[in]   data un uint16_t constant : la donnée à calculer
 * 
 * @return  un uint16_t : le log base 2 de data fois 256
 *          - partie entière dans l'octet haut
 *          - partie décimale dans l'octet bas
 *
 */
uint16_t log_base_2 ( const uint16_t data );

/** @} */

#endif // _GENERIC_MATH_H
    
/*
 End of File
*/