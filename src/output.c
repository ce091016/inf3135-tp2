#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "countries.h"
#include "graphviz.h"

#define COUNTRY_REGION_CONFLICT_MSG "Option '--country' activated; option '--region' ignored.\n"
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

void stdoutText(char **rep, json_t *root);
void stdoutDot(char **rep, json_t *root);
void dotFile(char **rep, char *filename, json_t *root);
void textFile(char **rep, char *filename, json_t *root);
void producePng(char **rep, char *filename, json_t *root);
void help();

/*
void producePng2(char **rep, char *filename, json_t *root){
    const char *bashCommand = "neato -Goverlap=false -Tpng -O ";
}
*/
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
    
    if(rep[HELP] != NULL){
        help();
        exit(0);
    } 
    
    if(rep[COUNTRY] != NULL){
        
        pays = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    
    }else if(rep[REGION] != NULL){
        
        values = countries_paysSelonRegion(root,rep[REGION + 1]);
    
    }else{
       
        values = root;
    }

    do  {
        
        if(!onlyOneCountry) pays = json_array_get(values,i);
        
        fprintf(file, "Name: %s\n",countries_getNomPays(pays));
        fprintf(file, "Code: %s\n",countries_getCode(pays));
    
        if(rep[SHOW_CAPITAL] != NULL){
            fprintf(file, "Capital: %s\n",countries_getCapitale(pays));
        }

        if(rep[SHOW_LANGUAGES] != NULL){

            char *langues = (char*)malloc(sizeof(char)*countries_nbCaracteresLangues(pays));
            countries_langues2(pays, langues);
            fprintf(file, "Languages: %s\n", langues);
            free(langues);
        }
    
        if(rep[SHOW_BORDERS] != NULL){
            char *frontieres =(char*)malloc(sizeof(char)*countries_nbCaracteresFrontieres(pays));
            countries_frontieres2(pays, frontieres);
            fprintf(file, "Borders: %s\n", frontieres);
            free(frontieres);
        }

        i++;

    }while(rep[COUNTRY] == NULL && i < json_array_size(values));
    
    fclose(file);
    
    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf(COUNTRY_REGION_CONFLICT_MSG);
}

void dotFile(char **rep, char *filename, json_t *root){
    json_t *pays;
    json_t *values;
    int langues;
    int capitale;
    int frontieres;
    int flag;
    bool onlyOneCountry = false;
    
    if(rep[HELP] != NULL){
        help();
        exit(0);
    } 
    
    if(rep[COUNTRY] != NULL){
       
        pays = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    
    }else if(rep[REGION] != NULL){
        
        values = countries_paysSelonRegion(root,rep[REGION + 1]);
    
    }else{
        
        values = root;
    }

    if(rep[SHOW_CAPITAL] != NULL){
        capitale = 1;
    }

    if(rep[SHOW_LANGUAGES] != NULL){
        langues = 1;
    }

    if(rep[SHOW_BORDERS] != NULL){
        frontieres = 1;
    }

    if(rep[SHOW_FLAG] != NULL){
        flag = 1;
    }
        
    if(onlyOneCountry) graphviz_ecrireUnSeulPays(langues,capitale,frontieres,flag,pays, filename);
    if(!onlyOneCountry) graphviz_ecrirePlusieursPays(langues,capitale,frontieres,flag,values, filename);

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
    
    if(rep[HELP] != NULL){
        help();
        exit(0);
    } 
    
    if(rep[COUNTRY] != NULL){
        
        pays = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    
    }else if(rep[REGION] != NULL){
        
        values = countries_paysSelonRegion(root,rep[REGION + 1]);
    
    }else{
        
        values = root;
    }

    do  {
        
        if(!onlyOneCountry) pays = json_array_get(values,i);
        
        printf("Name: %s\n",countries_getNomPays(pays));
        printf("Code: %s\n",countries_getCode(pays));
    
        if(rep[SHOW_CAPITAL] != NULL){
            
            printf("Capital: %s\n",countries_getCapitale(pays));
        }
        
        if(rep[SHOW_LANGUAGES] != NULL){
            
            char *langues = (char*)malloc(sizeof(char)*countries_nbCaracteresLangues(pays));
            countries_langues2(pays, langues);
            printf("Languages: %s\n", langues);
            free(langues);
        }
    
        if(rep[SHOW_BORDERS] != NULL){
            
            char *frontieres =(char*)malloc(sizeof(char)*countries_nbCaracteresFrontieres(pays));
            countries_frontieres2(pays, frontieres);
            printf("Borders: %s\n", frontieres);
            free(frontieres);
        }
        
        i++;
    
    }while(rep[COUNTRY] == NULL && i < json_array_size(values));

    

    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf(COUNTRY_REGION_CONFLICT_MSG);
}

void help(){
    printf("Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]\n");
	printf(" [--show-languages] [--show-capital] [--show-borders] [--show-flag]\n");
 	printf(" [--country COUNTRY] [--region REGION]\n\n");

	printf("Displays information about countries.\n\n");

	printf("Optional arguments:\n");
  	printf("  --help                     Show this help message and exit.\n");
  	printf("  --output-format FORMAT     Selects the ouput format (either \"text\", \"dot\" or \"png\").\n");
    printf("                             The \"dot\" format is the one recognized by Graphviz.\n");
    printf("                             The default format is \"text\".\n");
  	printf("  --output-filename FILENAME The name of the output filename. This argument is\n");
    printf("                             mandatory for the \"png\" format. For the \"text\" and \"dot\"\n");
    printf("                             format, the result is printed on stdout if no output\n");
    printf("                             filename is given.\n");
  	printf("  --show-languages           The official languages of each country are displayed.\n");
  	printf("  --show-capital             The capital of each country is displayed.\n");
    printf("  --show-borders             The borders of each country is displayed.\n");
  	printf("  --show-flag                The flag of each country is displayed\n");
    printf("                             (only for \"dot\" and \"png\" format).\n");
  	printf("  --country COUNTRY          The country code (e.g. \"can\", \"usa\") to be displayed.\n");
  	printf("  --region REGION            The region of the countries to be displayed.\n");
    printf("                             The supported regions are \"Africa\", \"Americas\",\n");
    printf("                             \"Asia\", \"Europe\" and \"Oceania\".\n");
}

