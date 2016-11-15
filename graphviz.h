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
 * Cette fonction ecrit dans un fichier les informations voulues sur un pays en 
 * respectant le format graphviz.
 * 
 * @param langues, 1 si on veut afficher les langues, 0 sinon
 * @param capitale, 1 si on veut afficher la capitale, 0 sinon
 * @param frontieres, 1 si on veut afficher les frontieres, 0 sinon
 * @param flag, 1 si on veut afficher l'image du drapeau, 0 sinon
 * @param pays, le pays dont on veut afficher les informations
 * @param graphviz, un pointeur vers le fichier ouvert ou on veut ecrire
*/
void graphviz_ecrireUnPays(int langues, int capitale, int frontieres, int flag, json_t *pays, FILE * graphviz);

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

/**
 * Cette fonction ecrit dans un fichier les liens entre les pays qui ont 
 * des frontieres communes. Ces pays sont passes sous forme de tableau 
 * json en paramètre. Elle n'ecrit pas les frontieres entre des pays
 * qui ont des frontieres communes, mais qui ne font pas partie de la 
 * meme region. Elle evite egalement les repetitions, mais pour cela,
 * il faut que les pays dans le tableau soient en ordre alphabetique
 *
 * @param tabPays, le tableau des pays dont on veut avoir les liens
 * @param graphviz, un pointeur vers le fichier ou ecrire les liens 
*/
void graphviz_ecrirePaysVoisins(json_t *tabPays, FILE * graphviz); 



//il y aurait moyen d'elever les parametres langues, capitale, etc. das la fonction ecrire un seul pays et ecrireplusieurspays
