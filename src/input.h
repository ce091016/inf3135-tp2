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

#define HELP_MSG "Try using 'bin/tp2 --help' for more information.\n"

// Prototypes
// ----------

/*
 * Cette fonction permet de gérer les entrées de l'utilisateur.
 * Tout ce qui succède 'bin/tp2' lors de l'exécution du programme
 * est traité. Cette fonction est grandement inspiré du fichier
 * 'long_opt.c' montré dans le cours de INF3135 séance 7.
 * @param argc, la taille de argv.
 * @param argv, un "tableau" de chaînes de caractères contenant
 * les options entrées par l'utilisateur (pas encore traité par getopt).
 * @param rep, un "tableau" où chaque position correspond à un flag différent.
 *
 */
void input(int argc, char *argv[], char* rep[]);
