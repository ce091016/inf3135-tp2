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

// Constantes
// ----------

#define DEBUTGRAPH "graph {\n"
#define FINGRAPH "}\n"
#define DEBUTPAYS "    " 
#define DEBUTPAYS2 " [\n"
#define FINPAYS "    ];\n"
#define SHAPE "        shape = none\n"
#define LABEL "        label = <<table border=\"0\" cellspacing=\"0\">\n"
#define LABELFIN "        </table>>\n"
#define TRTDIMAGE "            <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\">"
#define TRTDIMAGE2 "<img src=\"data/countries/data/"
#define TRTDIMAGE3 ".png\" scale=\"true\"/>"
#define TRTDIMAGE4 "</td></tr>\n"
#define TRTDNAME "            <tr><td align=\"left\" border=\"1\"><b>Name</b>: "
#define TRTDCODE "            <tr><td align=\"left\" border=\"1\"><b>Code</b>: "
#define TRTDCAPITAL "            <tr><td align=\"left\" border=\"1\"><b>Capital</b>: "
#define TRTDLANGUAGE "            <tr><td align=\"left\" border=\"1\"><b>Language</b>: "
#define TRTDBORDERS "            <tr><td align=\"left\" border=\"1\"><b>Borders</b>: " 
#define FINTRTD "</td></tr>\n"

// Prototypes  
// ---------- 


/** 
 * Cette fonction ouvre un fichier pour plus tard ecrire a l'interieur
 * en appelant la fonction graphviz_ecrireUnPays une seule fois. 
 * 
 * @param getObjectLanguages, 1 si on veut afficher les getObjectLanguages, 0 sinon
 * @param capitale, 1 si on veut afficher la capitale, 0 sinon
 * @param getObjectBorders, 1 si on veut afficher les getObjectBorders, 0 sinon
 * @param flag, 1 si on veut afficher l'image du drapeau, 0 sinon
 * @param pays, le pays dont on veut afficher les informations
 * @param nomfichier, le nom du fichier ou l'on veut ecrire les informations 
*/
void graphviz_ecrireUnSeulPays(int getObjectLanguages, int capitale, int getObjectBorders, int flag, json_t *pays, const char * nomFichier);

/**
 * Cette fonction ecrit dans un fichier les informations voulues sur tous 
 * les pays d'un tableau passe en parametres. De plus, il definit les 
 * liens entre les pays qui ont des getObjectBorders communes pour que ces 
 * pays soient relies dans graphviz en appelant la fonction 
 * graphviz_ecrirePlusieursPays
 *
 * @param getObjectLanguages, 1 si on veut afficher les getObjectLanguages, 0 sinon
 * @param capitale, 1 si on veut afficher la capitale, 0 sinon
 * @param getObjectBorders, 1 si on veut afficher les getObjectBorders, 0 sinon
 * @param flag, 1 si on veut afficher l'image du drapeau, 0 sinon
 * @param pays, le pays dont on veut afficher les informations
 * @param graphviz, un pointeur vers le fichier ouvert ou on veut ecrire
*/
void graphviz_ecrirePlusieursPays(int getObjectLanguages, int capitale, int getObjectBorders, int flag, json_t *tabPays, const char * nomFichier);


//il y aurait moyen d'elever les parametres getObjectLanguages, capitale, etc. das la fonction ecrire un seul pays et ecrireplusieurspays
//je crois qu'il serait bien de ne pas montrer la fonction ecrireUnPays, car c'est une fonction qui est appelée par les fonctions ecrireUnSeulPays et ecrirePlusieursPays et c'Est donc une fonction privée que l'utilisateur n'a pas besoin de connaître
//meme chose pour ecrirePaysVoisins
