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

    
json_t *countries_getJsonObjectFromCountry(char *code, json_t *tabPays) {
    json_t * returnObj;
    int i;
    for(i = 0; i < json_array_size(tabPays); i++) {
        json_t *data = json_array_get(tabPays, i);
        const char *codePays = countries_getCode(data);
        char codeParam[4];
        strcpy(codeParam, code);
        int longueurCode = strlen(codeParam);
        int j;
        for (j = 0; j<longueurCode; j++) {
            codeParam[j] = toupper(codeParam[j]);
        }
        if (strcmp(codeParam, codePays)==0) {
            returnObj = data;
            return returnObj;
        }
    }
    return NULL;
}

const char * countries_getCode(json_t *pays) {
    json_t * code = json_object_get(pays, "cca3");
    const char * codeRetour = json_string_value(code);
    return codeRetour;
}

const char * countries_getNomPays(json_t *pays) {
    json_t * nom = (json_object_get(json_object_get(pays, "name"), "official"));
    const char * nomRetour = json_string_value(nom);
    return nomRetour;
}

const char * countries_getCapitale(json_t *pays) {
    json_t *capitale = (json_object_get(pays, "capital"));
    const char *capitaleRetour = json_string_value(capitale);
    return capitaleRetour;
}

const char * countries_getFrontieres(json_t *pays) {
    json_t * frontieres = json_object_get(pays, "borders");
    int i;
    for (i=0; i<json_array_size(frontieres); i++) {
        const char * frontTemp = json_string_value(json_array_get(frontieres, i));
        printf("%s, ", frontTemp);
    }
    printf("\n");
}

int countries_nbCaracteresFrontieres(json_t *pays){
    json_t *frontieres = countries_frontieres(pays);
    int nbFrontieres = json_array_size(frontieres);
    int nbCaracteres = (nbFrontieres * 3) + (nbFrontieres - 1)*2 + 1;
    return nbCaracteres;
}

const char * countries_frontieres2(json_t *pays, char *chaine) {
    json_t *frontieres = countries_frontieres(pays);
    int nbFrontieres = json_array_size(frontieres);
    
    if (json_array_size(frontieres) == 0) {
        return "";
    } else {
        int i;
        sprintf(chaine,"%s", json_string_value(json_array_get(frontieres,0)));
        for (i=1; i<nbFrontieres; i++) {
            sprintf(chaine + strlen(chaine), ", ");
            sprintf(chaine + strlen(chaine), "%s", json_string_value(json_array_get(frontieres,i)));
        }
        sprintf(chaine + strlen(chaine),"\0");
        const char * retour = chaine;
        printf("frontieres : %s\n", retour);
        return retour;
    }
}

const char * countries_getLangues(json_t *pays) {
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

json_t *countries_frontieres(json_t *pays) {
    return json_object_get(pays, "borders");
}

int countries_nbLangues(json_t *pays) {
    json_t *langues = json_object_get(pays, "languages");
    return json_object_size(langues);
}

const char * countries_region(json_t *pays) {
    json_t *region = json_object_get(pays, "region");
    return json_string_value(region);
}

json_t * countries_paysSelonRegion(json_t *tabPays, char *region) {
    json_t *tabPaysRegion = json_array(); //je pense que l'allocation dynamique se fait toute seule
    int i;
    for (i=0; i<json_array_size(tabPays); i++) {
        json_t *paysTemp = json_array_get(tabPays, i);
        if (strcmp(countries_region(paysTemp),region) == 0) {
            json_array_append(tabPaysRegion, paysTemp);                
        }
    }
    return tabPaysRegion;
}

//a faire: changer les noms getLangues et getFrontieres pour printLangues...
//changer get Capitale et getNom pour countries_Capitale et countries_Nom

