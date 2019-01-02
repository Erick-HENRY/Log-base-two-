/**
 * @file
 * @author      Erick HENRY
 * @version     0.0
 * @date        25 juin 2018
 * @brief       Définition des fonctions mathématiques génériques : log base 2.
 *
 * @details     Fournit le log base 2 d'un entier 16 bits : retourne un entier 16 bits, log base 2 x 256.
 * 
 * @addtogroup    GENERIC_MATH_GROUP Les fonctions mathématiques génériques
 * 
 * @{
 */


/*
  Section: Included Files
*/
#include "generic_math.h"


/*
  Section: Define
*/
// Empty


/*
  Section: Structure, Union, Enumeration
*/
// Empty


/*
 Section: Macro Definitions
*/
// Empty


/*
 Section: Local Functions
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
  Section: Driver Interface
*/
/*
 * @brief   Calcul le log base 2 d'un entier 16 bits.
 * 
 * @details Fournit le log base 2 d'un entier 16 bits : retourne un entier 16 bits, log base 2 x 256.\n
 *          Détails dans le document interne : 000_000_00Y
 * 
 * @param[in]   data un uint16_t constant : la donnée à calculer
 * 
 * @return un uint16_t : le log base 2 de data fois 256
 *          - partie entière dans l'octet haut
 *          - partie décimale dans l'octet bas
 *
 */
uint16_t log_base_2 ( const uint16_t data )
    {
    /** 
     * @brief   temp : Variable pour avoir une copie modifiable de la donnée 
     */
    uint16_t temp;
    
    /**
     * @brief   Log_Int : Variable pour stocker la partie entière du résultat
     * @details La partie entière est le nombre de bit du nombre data
     */
    uint8_t Log_Int=0;
    
    /**
     * @brief   Log_Dec : Variable pour stocker la partie décimale du résultat
     */
    uint8_t Log_Dec=0;
    
    /**
     * @brief   i : Variable pour la boucle for
     */        
    uint8_t i; 

    /** Calcul de la partie entière du log base 2 */
    temp = data;
    while ( temp >>= 1 )
        Log_Int++;
    
    /** Calcul le nombre "reste" telle que :
            data = 2 puissance Log_Int * reste et
            cale ce nombre sur 8 bits de poid faible telle que 2 = 256 */
    if ( Log_Int > 7 )
        temp = ( data>>(Log_Int-7) );
    else if ( Log_Int < 7 )
        temp = ( data<<(7-Log_Int) );    
    else        
        temp = data;    
    
    /** Calcul la partie décimale du log */
    for ( i=8 ; i ; i-- )
        {
        Log_Dec<<=1;
        temp *= temp;
        if ( temp > (1<<15) )
            {
            Log_Dec++;
            temp>>=8;
            }
        else
            {
            temp>>=7;
            }
        }
 
    return ((Log_Int<<8)+Log_Dec);
    }
/** @} */

/*
 End of File
*/
