#include<jansson.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"input.h"
#include"countries.h"

#define TAILLE_MAX 12
#define HELP 0
#define OUTPUT_FORMAT 1
#define OUTPUT_FILENAME 3
#define SHOW_LANGUAGES 5
#define SHOW_CAPITAL 6
#define SHOW_BORDERS 7
#define SHOW_FLAG 8
#define COUNTRY 9
#define REGION 11


int main(int argc, char *argv[]){
    json_error_t error;
    json_t *root;
    root = json_load_file("data/countries/countries.json",0,&error);
    json_t *test;
    json_t *value;
    json_t *langues;
    const char *chaine;
    void *iter;
    char *string;
    char **rep = (char**)calloc(TAILLE_MAX + 1, sizeof(char*));
    
    input(argc, argv, rep);
    
    if(rep[COUNTRY] != NULL){
        test = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
        printf("Name : %s\n",countries_getNomPays(test));
        printf("Code : \n");
    }
    if(rep[SHOW_CAPITAL] != NULL){
        printf("Capital : %s\n",countries_getCapitale(test));
    }
    if(rep[SHOW_LANGUAGES] != NULL){
        printf("Langues: ");
        countries_getLangues(test);
    }
    
    if(rep[SHOW_BORDERS] != NULL){
        printf("Borders : ");
        countries_getFrontieres(test); 
    }
    if(rep[SHOW_FLAG] != NULL){
    
    }


    free(rep);


    return 0;
}
