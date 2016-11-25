/**   
* INF3135  
*  
* Travail pratique 2  
* Nom:			   Hallee
* Prenom:          Jean-Lou
* Code Permanent:  HALJ05129309
* Email:           jeanlou601@hotmail.com
* Nom:             Levasseur  
* Prenom:          Olivier  
* Code Permanent:  LEVO19109301  
* Email:           levasseuro.ol@gmail.com            
*/

#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "countries.h"
#include "graphviz.h"
#include "output.h"

// Implémentations
// ---------------

void producePng(char **rep, char *filename, json_t *root){
    const char *nameWithoutExtension;
    char *bashCommand = "neato -Goverlap=false -Tpng -o ";
    char *nameDot = (char*)malloc(sizeof(char)*strlen(filename)); 
    char *namePng = (char*)malloc(sizeof(char)*strlen(filename));
    char command[150];

    nameWithoutExtension = strtok(filename,".");
    strcpy(nameDot, nameWithoutExtension);
    strcat(nameDot, ".dot");
    strcpy(namePng, nameWithoutExtension);
    strcat(namePng, ".png");
    dotFile(rep, nameDot, root);
    sprintf(command,"%s%s %s\n", bashCommand, namePng, nameDot);
    system(command);
    system("rm -f *.dot");
}

void textFile(char **rep, char *filename, json_t *root){
    json_t *pays;
    json_t *values;
    bool onlyOneCountry = false;
    int i = 0;
    FILE *file = fopen(filename,"w");
    
    if(file == NULL){
        printf("File opening error.\n");
        exit(1);
    }
    
    if(rep[COUNTRY] != NULL){
        
        pays = countries_getCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    
    }else if(rep[REGION] != NULL){
        
        values = countries_countriesInARegion(root,rep[REGION + 1]);
    
    }else{
       
        values = root;
    }

    do  {
        
        if(!onlyOneCountry) pays = json_array_get(values,i);
        
        fprintf(file, "Name: %s\n",countries_getName(pays));
        fprintf(file, "Code: %s\n",countries_getCode(pays));
    
        if(rep[SHOW_CAPITAL] != NULL){
            fprintf(file, "Capital: %s\n",countries_getCapital(pays));
        }

        if(rep[SHOW_LANGUAGES] != NULL){

            char *getObjectLanguages = (char*)malloc(sizeof(char)*countries_stringLengthLanguages(pays));
            countries_writeLanguages(pays, getObjectLanguages);
            fprintf(file, "Languages: %s\n", getObjectLanguages);
            free(getObjectLanguages);
        }
    
        if(rep[SHOW_BORDERS] != NULL){
            char *getObjectBorders =(char*)malloc(sizeof(char)*countries_stringLengthBorders(pays));
            countries_writeBorders(pays, getObjectBorders);
            fprintf(file, "Borders: %s\n", getObjectBorders);
            free(getObjectBorders);
        }

        i++;

    }while(rep[COUNTRY] == NULL && i < json_array_size(values));
    
    fclose(file);
    
    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf(COUNTRY_REGION_CONFLICT_MSG);
}

void dotFile(char **rep, char *filename, json_t *root){
    json_t *pays;
    json_t *values;
    int getObjectLanguages;
    int capitale;
    int getObjectBorders;
    int flag;
    bool onlyOneCountry = false;
    
    if(rep[COUNTRY] != NULL){
       
        pays = countries_getCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    
    }else if(rep[REGION] != NULL){
        
        values = countries_countriesInARegion(root,rep[REGION + 1]);
    
    }else{
        
        values = root;
    }

    if(rep[SHOW_CAPITAL] != NULL){
        capitale = 1;
    }

    if(rep[SHOW_LANGUAGES] != NULL){
        getObjectLanguages = 1;
    }

    if(rep[SHOW_BORDERS] != NULL){
        getObjectBorders = 1;
    }

    if(rep[SHOW_FLAG] != NULL){
        flag = 1;
    }
        
    if(onlyOneCountry) graphviz_ecrireUnSeulPays(getObjectLanguages,capitale,getObjectBorders,flag,pays, filename);
    if(!onlyOneCountry) graphviz_ecrirePlusieursPays(getObjectLanguages,capitale,getObjectBorders,flag,values, filename);

    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf(COUNTRY_REGION_CONFLICT_MSG);
}

void stdoutDot(char **rep, json_t *root){
    int c;
    FILE *tempFile;
    dotFile(rep, "tempFile.txt", root);
    tempFile = fopen("tempFile.txt","r");
    
    if(tempFile){
        while((c = getc(tempFile)) != EOF){
            putchar(c);
        }
        fclose(tempFile);
        system("rm tempFile.txt");
    }   
}

void stdoutText(char **rep, json_t *root){
    json_t *pays;
    json_t *values;
    bool onlyOneCountry = false;
    int i = 0;
    
    if(rep[COUNTRY] != NULL){
        
        pays = countries_getCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    
    }else if(rep[REGION] != NULL){
        
        values = countries_countriesInARegion(root,rep[REGION + 1]);
    
    }else{
        
        values = root;
    }

    do  {
        
        if(!onlyOneCountry) pays = json_array_get(values,i);
        
        printf("Name: %s\n",countries_getName(pays));
        printf("Code: %s\n",countries_getCode(pays));
    
        if(rep[SHOW_CAPITAL] != NULL){
            
            printf("Capital: %s\n",countries_getCapital(pays));
        }
        
        if(rep[SHOW_LANGUAGES] != NULL){
            
            char *getObjectLanguages = (char*)malloc(sizeof(char)*countries_stringLengthLanguages(pays));
            countries_writeLanguages(pays, getObjectLanguages);
            printf("Languages: %s\n", getObjectLanguages);
            free(getObjectLanguages);
        }
    
        if(rep[SHOW_BORDERS] != NULL){
            
            char *getObjectBorders =(char*)malloc(sizeof(char)*countries_stringLengthBorders(pays));
            countries_writeBorders(pays, getObjectBorders);
            printf("Borders: %s\n", getObjectBorders);
            free(getObjectBorders);
        }
        i++;
    }while(rep[COUNTRY] == NULL && i < json_array_size(values));

    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf(COUNTRY_REGION_CONFLICT_MSG);
}

void help(){
    printf("%s", MSG_AIDE);
}
