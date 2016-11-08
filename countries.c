#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "countries.h"

/*int main (int argc, char *argv[]) {
    
    json_error_t error;
    json_t *root;
    root = json_load_file("data/countries/countries.json", 0, &error);

    int i;
    int j=0; //increment du nombre de pays parcourus
    //Parcourir tous les pays et afficher leur nom
    for(i = 0; i < json_array_size(root); i++) {
        json_t *data = json_array_get(root, i);
        json_t *name = json_object_get(json_object_get(data, "name"), "official");
        const char * nameOfficial = json_string_value(name);
        printf("name : %s\n", nameOfficial);
        j++;
    }
    printf("nombre de pays : %d\n", j);
    json_t * test;
    //trouver un pays par son code
    test = countries_getJsonObjectFromCountry("afg", root);
    //test fonctions get
    printf("get nom : %s\n", countries_getNomPays(test));
    printf("get capitale : %s\n", countries_getCapitale(test));
    countries_getLangues(test);
    countries_getFrontieres(test);
    printf("nbLangues : %d\n", countries_nbLangues(test));
}*/

    
json_t* countries_getJsonObjectFromCountry(char * code, json_t* tabPays) {
    json_t * returnObj;
    int i;
    for(i = 0; i < json_array_size(tabPays); i++) {
        json_t *data = json_array_get(tabPays, i);
        json_t *codePays = json_object_get(data, "cca3");
        char codeParam[4];
        strcpy(codeParam, code);
        int longueurCode = strlen(codeParam);
        int j;
        for (j = 0; j<longueurCode; j++) {
            codeParam[j] = toupper(codeParam[j]);
        }
        if (strcmp(codeParam, json_string_value(codePays))==0) {
            returnObj = data;
            break;
        }
    }
    return returnObj;
}

const char * countries_getNomPays(json_t * pays) {
    json_t * nom = (json_object_get(json_object_get(pays, "name"), "official"));
    const char * nomRetour = json_string_value(nom);
    return nomRetour;
}

const char * countries_getCapitale(json_t * pays) {
    json_t *capitale = (json_object_get(pays, "capital"));
    const char *capitaleRetour = json_string_value(capitale);
    return capitaleRetour;
}

const char * countries_getFrontieres(json_t * pays) {
    json_t * frontieres = json_object_get(pays, "borders");
    int i;
    for (i=0; i<json_array_size(frontieres); i++) {
        const char * frontTemp = json_string_value(json_array_get(frontieres, i));
        printf("%s\n", frontTemp);
    }
}

const char * countries_getLangues(json_t * pays) {
    json_t * langues = json_object_get(pays,"languages");
    void * iter = json_object_iter(langues);
    json_t * langueTemp = json_object_iter_value(iter);
    const char * langueTempChaine = json_string_value(langueTemp);
    char languesRetour[1024];
//    strcpy(languesRetour, langueTempChaine);

    iter = json_object_iter_next(langues, iter);
    printf("%s", langueTempChaine);
    while (iter) {
        langueTemp = json_object_iter_value(iter);
        langueTempChaine = json_string_value(langueTemp);
//        strcat(languesRetour, langueTempChaine); 
        printf(", %s", langueTempChaine);
        iter = json_object_iter_next(langues, iter);
    }
    printf("\n");
//    char * finChaineLangue = "\0";
//    strcat(languesRetour, finChaineLangue);
//    return languesRetour;
}

json_t * countries_langues(json_t *pays) {
    return json_object_get(pays, "languages");
}

int countries_nbLangues(json_t * pays) {
    json_t * langues = json_object_get(pays, "languages");
    return json_object_size(langues);
}

//a faire: changer les noms getLangues et getFrontieres pour printLangues...
//changer get Capitale et getNom pour countries_Capitale et countries_Nom

//ma strategie presentement est d'aller chercher les objets dont je veux connaitre
//certaines informations et appeler des methodes retournant les informations sur
//ces objets. 
//Une strategie alternative serait de parcourir le tableau de tous les objets, et 
//d'afficher les informations voulues sur les pays au fur et à mesure. il faudrait
//cependant pour cela que je puisse indiquer a la fonction quelles informations
//je veux afficher.

/*pourrait faire un tableau de pays pour --region. Je parcours le tableau
 * de tous les pays, et chaque fois qu'un pays est dans la region voulue
 * j'ajoute l'indice du tableau soit dans une string, soit dans un tableau.
 * Je peux aussi me faire une variable nbPaysRegion qui compte le nombre de pays 
 * dans une region. Ensuite, je crée un tableau qui contient des objets json 
 * de taille nbPaysRegion et j'y mets les pays correspondant aux indices trouves
*/
