#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "graphviz.h"
#include "input.h"
#include "output.h"
#include "countries.h"

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

int main (int argc, char * argv[]) {
    json_error_t error;
    json_t *root = json_load_file("data/countries/countries.json",0,&error);
    char *filename;
    bool hasName = false;
    char **rep = (char**)calloc(TAILLE_MAX + 1, sizeof(char*)); 
    input(argc, argv, rep);

    if(rep[OUTPUT_FORMAT] != NULL){

        if(rep[OUTPUT_FILENAME + 1] != NULL){
            
            filename = rep[OUTPUT_FILENAME + 1];
            hasName = true;
        }
        if(strcmp(rep[OUTPUT_FORMAT + 1], "dot") == 0){
           
           if(!hasName) stdoutDot(rep, root); 
           if(hasName) dotFile(rep, filename, root);

       }else if(strcmp(rep[OUTPUT_FORMAT + 1], "text") == 0){
           
           if(!hasName) stdoutText(rep, root);
           if(hasName) textFile(rep, filename, root);

       }else if(strcmp(rep[OUTPUT_FORMAT + 1], "png") == 0){
            
           if(rep[OUTPUT_FILENAME + 1] != NULL){
                
               producePng(rep, filename, root);
            
           }else{
               printf("Filename required for 'png' format.\n");
               exit(1);
            }
       }else{
            printf("Invalid file format.\n");
            exit(1);
       }
    }else{
        stdoutText(rep, root);
    }
    free(rep);
    return 0;
}
