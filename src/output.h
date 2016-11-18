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
#define MSG_AIDE "Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]\n [--show-languages] [--show-capital] [--show-borders] [--show-flag]\n [--country COUNTRY] [--region REGION]\n\nDisplays information about countries.\n\nOptional arguments:\n  --help                     Show this help message and exit.\n  --output-format FORMAT     Selects the ouput format (either \"text\", \"dot\" or \"png\").\n                             The \"dot\" format is the one recognized by Graphviz.\n                             The default format is \"text\".\n  --output-filename FILENAME The name of the output filename. This argument is\n                             mandatory for the \"png\" format. For the \"text\" and \"dot\"\n                             format, the result is printed on stdout if no output\n                             filename is given.\n  --show-languages           The official languages of each country are displayed.\n  --show-capital             The capital of each country is displayed.\n  --show-flag                The flag of each country is displayed\n                             (only for \"dot\" and \"png\" format).\n  --country COUNTRY          The country code (e.g. \"can\", \"usa\") to be displayed.\n  --region REGION            The region of the countries to be displayed.\n                             The supported regions are \"Africa\", \"Americas\",\n                             \"Asia\", \"Europe\" and \"Oceania\".\n"
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


