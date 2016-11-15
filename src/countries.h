/**   
* INF3135  
*  
* Travail pratique 2  
*  
* Nom:             Levasseur  
* Prenom:          Olivier  
* Code Permanent:  LEVO19109301  
* Email:           levasseuro.ol@gmail.com  
* Nom:			   Hallee
* Prenom:          Jean-Lou
* Code Permanent:  HALJ05129309
* Email:           
*/

#include <jansson.h>

// Prototypes
// ----------


/*
 * Cette fonction retourne un objet json qui represente un pays dont le code
 * correspond au code passe en parametre
 *
 * @param code, le code du pays qu'on veut que la fonction retourne
 * @param tabPays, le tableau des pays de la base de données
 * @return, l'objet json du pays voulu
*/
json_t* countries_getJsonObjectFromCountry(const char * code, json_t* tabPays); 

/*
 * Cette fonction retourne le code du pays passe en parametre
 *
 * @param pays, le pays dont on veut le code
 * @return, la chaine de caracteres representant le code
*/
const char * countries_getCode(json_t *pays);


/*
 * Cette fonction retourne le nom du pays passe en parametre
 *
 * @pays, le pays dont on veut le nom
 * @return, la chaine de caracteres representant le nom
*/
const char * countries_getNomPays(json_t * pays);

/*
 * Cette fonction retourne la capitale du pays passe en parametre
 *
 * @param pays, le nom dont on veut la capitale
 * @return, la chaine de caracteres representant la capitale
*/
const char * countries_getCapitale(json_t * pays);

/*
 * Cette fonction ecrit les frontieres d'un pays separees par 
 * une virgule dans une chaine de caracteres deja initialisee
 * dont le pointeur est passe en parametre.
 *
 * @param pays, le pays dont on veut les frontieres
 * @param chaine, le pointeur vers la chaine ou on veut ecrire
 * les frontieres
*/
void countries_frontieres2(json_t * pays, char *chaine);

/*
 * Cette fonction retourne le nombre de caracteres necessaires
 * pour qu'une chaine de caracteres puisse stocker toutes les
 * frontieres separees par une virgule du pays passe en parametre
 *
 * @param pays, le pays dont on veut connaitre la taille d'une 
 * chaine permettant de stocker ses frontieres
 * @return, le nombre de caracteres, incluant le '\0'
*/
int countries_nbCaracteresFrontieres(json_t *pays);

/*
 * Cette fonction retourne le nombre de caracteres necessaires
 * pour qu'une chaine de caracteres puisse stocker toutes les 
 * langues separees par une virgule du pays passe en parametre
 *
 * @param pays, le pays dont on veut connaitre la taille d'une
 * chaine permettant de stocker ses langues
 * @return, le nombre de caracteres, incluant le '\0'
*/
int countries_nbCaracteresLangues(json_t *pays);

/*
 * Cette fonction ecrit les langues d'un pays separees par 
 * une virgule dans une chaine de caracteres deja initialisee
 * avec la bonne taille dont le pointeur est passe en parametre
 *
 * @pays, le pays dont on veut les langues
 * @chaine, le pointeur vers la chaine de caracteres ou ecrire
*/
void countries_langues2(json_t *pays, char *chaine);

/*
 * 
*/
int countries_nbLangues(json_t * pays);

json_t * countries_langues(json_t *pays); 

json_t *countries_frontieres(json_t *pays);

json_t * countries_paysSelonRegion(json_t *tabPays, char * region);

const char * countries_region(json_t *pays);
