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
 * @param tabPays, le tableau des pays de parmi lesquels se trouve le pays
 * voulu
 * @return, l'objet json du pays voulu, ou NULL si le pays ne fait pas partie
 * du tableau passe en parametre
*/
json_t* countries_getCountry(const char * code, json_t* tabPays); 

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
const char * countries_getName(json_t * pays);

/*
 * Cette fonction retourne la capitale du pays passe en parametre
 *
 * @param pays, le pays dont on veut la capitale
 * @return, la chaine de caracteres representant la capitale
*/
const char * countries_getCapital(json_t * pays);

/*
 * Cette fonction ecrit les getObjectBorders d'un pays separees par 
 * une virgule dans une chaine de caracteres deja initialisee
 * dont le pointeur est passe en parametre.
 *
 * @param pays, le pays dont on veut les getObjectBorders
 * @param chaine, le pointeur vers la chaine ou on veut ecrire
 * les getObjectBorders
*/
void countries_writeBorders(json_t * pays, char *chaine);

/*
 * Cette fonction retourne le nombre de caracteres necessaires
 * pour qu'une chaine de caracteres puisse stocker toutes les
 * getObjectBorders separees par une virgule et un espacedu pays 
 * passe en parametre
 *
 * @param pays, le pays dont on veut connaitre la taille d'une 
 * chaine permettant de stocker ses getObjectBorders
 * @return, le nombre de caracteres, incluant le '\0'
*/
int countries_stringLengthBorders(json_t *pays);

/*
 * Cette fonction retourne le nombre de caracteres necessaires
 * pour qu'une chaine de caracteres puisse stocker toutes les 
 * getObjectLanguages separees par une virgule et un espace du pays passe 
 * en parametre
 *
 * @param pays, le pays dont on veut connaitre la taille d'une
 * chaine permettant de stocker ses getObjectLanguages
 * @return, le nombre de caracteres, incluant le '\0'
*/
int countries_stringLengthLanguages(json_t *pays);

/*
 * Cette fonction ecrit les getObjectLanguages d'un pays separees par 
 * une virgule et un espace dans une chaine de caracteres deja 
 * initialisee avec la bonne taille dont le pointeur est passe 
 * en parametre
 *
 * @pays, le pays dont on veut les getObjectLanguages
 * @chaine, le pointeur vers la chaine de caracteres ou ecrire
*/
void countries_writeLanguages(json_t *pays, char *chaine);

/*
 * Cette fonction retourne le nombre de langue d'un pays passe 
 * en parametre
 *
 * @pays, le pays dont on veut connaitre le nombre de getObjectLanguages
 * @return, le nombre de getObjectLanguages du pays
*/
int countries_numberOfLanguages(json_t * pays);

/*
 * Cette fonction retourne un object json contenant les getObjectLanguages
 * du pays passe en parametre
 *
 * @pays, le pays dont on veut l'objet json contenant les getObjectLanguages
 * @return, l'objet json contenant les getObjectLanguages du pays
 *
*/
json_t * countries_getObjectLanguages(json_t *pays); 

/*
 * Cette fonction retourne un objet json contenant les getObjectBorders
 * du pays passe en parametre
 *
 * @pays, le pays dont on veut l'objet json contenant les getObjectBorders
 * @return, l'objet json contenant les getObjectBorders du pays
*/
json_t *countries_getObjectBorders(json_t *pays);

/*
 * Cette fonction retourne un tableau json contenant les pays 
 * appartenant a la getRegion passee en parametre
 *
 * @tabPays, le tableau contenant tous les pays de la base de donnees
 * @getRegion, la getRegion a laquelle on veut que les pays dans le tableau
 * retourne appartiennent
 * @return, le tableau contenant les pays appartenant a la getRegion voulue
*/
json_t * countries_countriesInARegion(json_t *tabPays, char * getRegion);


/*
 * Cette fonction retourne une chaine de caracteres representant
 * la getRegion du pays passe en parametre
 *
 * @pays, le pays dont on veut la getRegion
 * @return, la chaine de caracteres representant la getRegion
*/
const char * countries_getRegion(json_t *pays);
