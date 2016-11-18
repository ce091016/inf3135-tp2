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
 * Cette fonction permet de g�rer les entr�es de l'utilisateur.
 * Tout ce qui succ�de 'bin/tp2' lors de l'ex�cution du programme
 * est trait�. Cette fonction est grandement inspir� du fichier
 * 'long_opt.c' montr� dans le cours de INF3135 s�ance 7.
 * @param argc, la taille de argv.
 * @param argv, un "tableau" de cha�nes de caract�res contenant
 * les options entr�es par l'utilisateur (pas encore trait� par getopt).
 * @param rep, un "tableau" o� chaque position correspond � un flag diff�rent.
 *
 */
void input(int argc, char *argv[], char* rep[]);
