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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "countries.h"
#include "util.h"

// Implémentation
// --------------
    
json_t *countries_getJsonObjectFromCountry(const char *code, json_t *tabPays) {
    json_t * returnObj;
    int i;
    char codeParam[4];
    util_chaineEnMajuscules(code, codeParam);

    for(i = 0; i < json_array_size(tabPays); i++) {
        json_t *data = json_array_get(tabPays, i);
        const char *codePays = countries_getCode(data);
        if (strcmp(codeParam, codePays)==0) {
            returnObj = data;
            return returnObj;
        }
    }
    printf("Code pays inexistant.\n");
    exit(0);
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

int countries_nbCaracteresFrontieres(json_t *pays){
    json_t *frontieres = countries_frontieres(pays);
    if (json_is_array(frontieres)) {
        if (json_array_size(frontieres) == 0) {
            return 2;
        }
        int nbFrontieres = json_array_size(frontieres);
        int nbCaracteres = (nbFrontieres * 3) + (nbFrontieres - 1)*2 + 1;
        return nbCaracteres;

    } else {
        return 2;
    }
}

void countries_frontieres2(json_t *pays, char *chaine) {
    json_t *frontieres = countries_frontieres(pays);
    int nbFrontieres = json_array_size(frontieres);
    if (json_array_size(frontieres) > 0){ 
        int i;
        sprintf(chaine,"%s", json_string_value(json_array_get(frontieres,0)));
        for (i=1; i<nbFrontieres; i++) {
            sprintf(chaine + strlen(chaine), ", ");
            sprintf(chaine + strlen(chaine), "%s", json_string_value(json_array_get(frontieres,i)));
        }
    } else {
        sprintf(chaine, " ");
    }
}

int countries_nbCaracteresLangues(json_t *pays) {
    int nbCaracteres=0;
    json_t *langues = json_object_get(pays, "languages");
    void * iter = json_object_iter(langues);
    json_t *langueTemp = json_object_iter_value(iter);
    nbCaracteres += strlen(json_string_value(langueTemp));
    iter = json_object_iter_next(langues, iter);
    while (iter) {
        langueTemp = json_object_iter_value(iter);
        nbCaracteres += strlen(json_string_value(langueTemp));
        iter = json_object_iter_next(langues, iter);
    }
    nbCaracteres += 2*(countries_nbLangues(pays)-1 );
    nbCaracteres += 1;
    return nbCaracteres;
}

void countries_langues2(json_t *pays, char * chaine) {
    json_t *langues = json_object_get(pays, "languages");
    void *iter = json_object_iter(langues);
    json_t *langueTemp = json_object_iter_value(iter);
    sprintf(chaine, "%s", json_string_value(langueTemp));
    iter = json_object_iter_next(langues, iter);
    while (iter) {
        sprintf(chaine + strlen(chaine), ", ");
        langueTemp = json_object_iter_value(iter);
        sprintf(chaine + strlen(chaine), "%s", json_string_value(langueTemp));
        iter = json_object_iter_next(langues, iter);
    }
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
    json_t *tabPaysRegion = json_array(); 
    int i;
    for (i=0; i<json_array_size(tabPays); i++) {
        json_t *paysTemp = json_array_get(tabPays, i);
        if (strcmp(countries_region(paysTemp),region) == 0) {
            json_array_append(tabPaysRegion, paysTemp);                
        }
    }
    return tabPaysRegion;
}

//a faire:
//changer get Capitale et getNom pour countries_Capitale et countries_Nom
//gérer le cas où les fonctions getters ne trouvent pas d'objet voulu

//on devrait pas rajouter une fonction qui load le fichier json?

//pourquoi les fonctions qui écrivent dans des strings ne créent-elles 
//pas elles-mêmes la string? pcq elles se trouvent dans un fichier différent 
//de l'endroit ou elles sont appelées, ce qui fait que la string peut etre 
//effacée ou modifiée
