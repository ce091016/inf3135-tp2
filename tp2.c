#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "countries.h"

int main (int argc, char * argv[]) {
    json_error_t error;
    json_t *root;
    root = json_load_file("data/countries/countries.json", 0, &error);


    json_t * test;
    test = countries_getJsonObjectFromCountry("afg", root);
    printf("get nom : %s\n", countries_getNomPays(test));
    printf("get capitale : %s\n", countries_getCapitale(test));
    countries_getLangues(test);
    countries_getFrontieres(test);
    printf("nb de langues : %d\n", countries_nbLangues(test));
  
    //TEST de la fonction countries_langues
    json_t * langues = countries_langues(test);
    void * iter = json_object_iter(langues);
    json_t * value = json_object_iter_value(iter);
    const char * chaine = json_string_value(value);
    printf("%s\n", chaine);
    iter = json_object_iter_next(langues, iter);
    while (iter) {
        json_t * value = json_object_iter_value(iter);
        const char * chaine = json_string_value(value);
        printf("%s\n", chaine);
        iter = json_object_iter_next(langues, iter);
    }
}
