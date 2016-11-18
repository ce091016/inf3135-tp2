/**   
* INF3135  
*  
* Travail pratique 2  
* Nom:			   Hallee
* Prenom:          Jean-Lou
* Code Permanent:  HALJ05129309
* Email:           jeanlou601@hotmail.com
* Nom:             Levasseur  
* Prenom:          Olivier  
* Code Permanent:  LEVO19109301  
* Email:           levasseuro.ol@gmail.com            
*/
// Constantes
// ----------

#define COUNTRY_REGION_CONFLICT_MSG "Option '--country' activated; option '--region' ignored.\n"
#define TAILLE_MAX 12
#define HELP 0
#define OUTPUT_FORMAT 1
#define OUTPUT_FILENAME 3
#define SHOW_LANGUAGES 5
#define SHOW_CAPITAL 6
#define SHOW_BORDERS 7
#define SHOW_FLAG 8
#define COUNTRY 9
#define REGION 11

// Prototypes
// ----------

/**
 *
 *
 *
 *
 */
void stdoutText(char **rep, json_t *root);

/**
 *
 *
 *
 */
void stdoutDot(char **rep, json_t *root);

/**
 *
 *
 *
 */
void dotFile(char **rep, char *filename, json_t *root);

/*
 *
 *
 *
 */
void textFile(char **rep, char *filename, json_t *root);

/**
 * Cette fonction permet de créer une image au 
 * format 'PNG'.(en créant un fichier temporaire au format 
 * 'dot').
 *
 */
void producePng(char **rep, char *filename, json_t *root);


/**
 * Cette fonction permet d'afficher le message d'aide lorsque
 * l'utilisateur entre la commande 'bin/tp2 --help'
 */
void help();


