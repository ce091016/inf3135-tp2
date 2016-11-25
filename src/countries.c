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
#include <stdbool.h>

#include "countries.h"
#include "util.h"

// Implémentation
// --------------
    
json_t *countries_getCountry(const char *code, json_t *tabPays) {
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
    return NULL;
}

const char * countries_getCode(json_t *pays) {
    json_t * code = json_object_get(pays, "cca3");
    const char * codeRetour = json_string_value(code);
    return codeRetour;
}

const char * countries_getName(json_t *pays) {
    json_t * nom = (json_object_get(json_object_get(pays, "name"), "official"));
    const char * nomRetour = json_string_value(nom);
    if(nomRetour == NULL){
        printf("Invalid country code.\n");
        exit(0);
    }

    return nomRetour;
}

const char * countries_getCapital(json_t *pays) {
    json_t *capitale = (json_object_get(pays, "capital"));
    const char *capitaleRetour = json_string_value(capitale);
    return capitaleRetour;
}

int countries_stringLengthBorders(json_t *pays){
    json_t *getObjectBorders = countries_getObjectBorders(pays);
    if (json_is_array(getObjectBorders)) {
        if (json_array_size(getObjectBorders) == 0) {
            return 2;
        }
        int nbFrontieres = json_array_size(getObjectBorders);
        int nbCaracteres = (nbFrontieres * 3) + (nbFrontieres - 1)*2 + 1;
        return nbCaracteres;

    } else {
        return 2;
    }
}

void countries_writeBorders(json_t *pays, char *chaine) {
    json_t *getObjectBorders = countries_getObjectBorders(pays);
    int nbFrontieres = json_array_size(getObjectBorders);
    if (json_array_size(getObjectBorders) > 0){ 
        int i;
        sprintf(chaine,"%s", json_string_value(json_array_get(getObjectBorders,0)));
        for (i=1; i<nbFrontieres; i++) {
            sprintf(chaine + strlen(chaine), ", ");
            sprintf(chaine + strlen(chaine), "%s", json_string_value(json_array_get(getObjectBorders,i)));
        }
    } else {
        sprintf(chaine, " ");
    }
}

int countries_stringLengthLanguages(json_t *pays) {
    int nbCaracteres=0;
    json_t *getObjectLanguages = json_object_get(pays, "languages");
    void * iter = json_object_iter(getObjectLanguages);
    json_t *langueTemp = json_object_iter_value(iter);
    nbCaracteres += strlen(json_string_value(langueTemp));
    iter = json_object_iter_next(getObjectLanguages, iter);
    while (iter) {
        langueTemp = json_object_iter_value(iter);
        nbCaracteres += strlen(json_string_value(langueTemp));
        iter = json_object_iter_next(getObjectLanguages, iter);
    }
    nbCaracteres += 2*(countries_numberOfLanguages(pays)-1 );
    nbCaracteres += 1;
    return nbCaracteres;
}

void countries_writeLanguages(json_t *pays, char * chaine) {
    json_t *getObjectLanguages = json_object_get(pays, "languages");
    void *iter = json_object_iter(getObjectLanguages);
    json_t *langueTemp = json_object_iter_value(iter);
    sprintf(chaine, "%s", json_string_value(langueTemp));
    iter = json_object_iter_next(getObjectLanguages, iter);
    while (iter) {
        sprintf(chaine + strlen(chaine), ", ");
        langueTemp = json_object_iter_value(iter);
        sprintf(chaine + strlen(chaine), "%s", json_string_value(langueTemp));
        iter = json_object_iter_next(getObjectLanguages, iter);
    }
}

json_t * countries_getObjectLanguages(json_t *pays) {
    return json_object_get(pays, "languages");
}

json_t *countries_getObjectBorders(json_t *pays) {
    return json_object_get(pays, "borders");
}

int countries_numberOfLanguages(json_t *pays) {
    json_t *getObjectLanguages = json_object_get(pays, "languages");
    return json_object_size(getObjectLanguages);
}

const char * countries_getRegion(json_t *pays) {
    json_t *getRegion = json_object_get(pays, "getRegion");
    return json_string_value(getRegion);
}

json_t * countries_countriesInARegion(json_t *tabPays, char *getRegion) {
    json_t *tabPaysRegion = json_array(); 
    int i;
    bool empty = true;

    for (i=0; i<json_array_size(tabPays); i++) {
        json_t *paysTemp = json_array_get(tabPays, i);
        if (strcmp(countries_getRegion(paysTemp),getRegion) == 0) {
            json_array_append(tabPaysRegion, paysTemp);
            empty = false;
        }
    }
    if(empty){
        printf("Invalid getRegion.\n");
        exit(0);
    }else{
        return tabPaysRegion;
    }
}

