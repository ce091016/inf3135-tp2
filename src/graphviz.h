/**   
* INF3135  
*  
* Travail pratique 2  
*  
* Nom:             Levasseur  
* Prenom:          Olivier  
* Code Permanent:  LEVO 1910 9301  
* Email:           levasseuro.ol@gmail.com  
* Nom:			   Hallee
* Prenom:          Jean-Lou
* Code Permanent:  HALJ05129309
* Email:           
*/

// Prototypes  
// ---------- 


/** 
 * Cette fonction ouvre un fichier pour plus tard ecrire a l'interieur
 * en appelant la fonction graphviz_ecrireUnPays une seule fois. 
 * 
 * @param langues, 1 si on veut afficher les langues, 0 sinon
 * @param capitale, 1 si on veut afficher la capitale, 0 sinon
 * @param frontieres, 1 si on veut afficher les frontieres, 0 sinon
 * @param flag, 1 si on veut afficher l'image du drapeau, 0 sinon
 * @param pays, le pays dont on veut afficher les informations
 * @param nomfichier, le nom du fichier ou l'on veut ecrire les informations 
*/
void graphviz_ecrireUnSeulPays(int langues, int capitale, int frontieres, int flag, json_t *pays, const char * nomFichier);

/**
 * Cette fonction ecrit dans un fichier les informations voulues sur tous 
 * les pays d'un tableau passe en parametres. De plus, il definit les 
 * liens entre les pays qui ont des frontieres communes pour que ces 
 * pays soient relies dans graphviz en appelant la fonction 
 * graphviz_ecrirePlusieursPays
 *
 * @param langues, 1 si on veut afficher les langues, 0 sinon
 * @param capitale, 1 si on veut afficher la capitale, 0 sinon
 * @param frontieres, 1 si on veut afficher les frontieres, 0 sinon
 * @param flag, 1 si on veut afficher l'image du drapeau, 0 sinon
 * @param pays, le pays dont on veut afficher les informations
 * @param graphviz, un pointeur vers le fichier ouvert ou on veut ecrire
*/
void graphviz_ecrirePlusieursPays(int langues, int capitale, int frontieres, int flag, json_t *tabPays, const char * nomFichier);


//il y aurait moyen d'elever les parametres langues, capitale, etc. das la fonction ecrire un seul pays et ecrireplusieurspays
//je crois qu'il serait bien de ne pas montrer la fonction ecrireUnPays, car c'est une fonction qui est appelée par les fonctions ecrireUnSeulPays et ecrirePlusieursPays et c'Est donc une fonction privée que l'utilisateur n'a pas besoin de connaître
//meme chose pour ecrirePaysVoisins
