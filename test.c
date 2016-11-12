#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "countries.h"
#include "graphviz.h"

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

void stdoutOutput(char **rep, json_t *root);
void dotOutput(char **rep, char *filename, json_t *root);
void textOutput(char **rep, char *filename, json_t *root);
void producePng(char **rep, char *filename, json_t *root);
void help();

int main(int argc, char *argv[]){
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
           dotOutput(rep,filename,root);
       }else if(strcmp(rep[OUTPUT_FORMAT + 1], "text") == 0){
           stdoutOutput(rep,root);
           if(hasName) textOutput(rep,filename,root);
       }else if(strcmp(rep[OUTPUT_FORMAT + 1], "png") == 0){
            if(rep[OUTPUT_FILENAME + 1] != NULL){
                producePng(rep,filename,root);
            }else{
                printf("Filename required for 'png' format.\n");
                exit(1);
            }
       }else{
        printf("Invalid file format.\n");
        exit(1);
       }
    }else{
        stdoutOutput(rep,root);
    }
    free(rep);
    return 0;
}

void producePng(char **rep, char *filename, json_t *root){
    dotOutput(rep,filename,root);
    system("neato -Goverlap=false -Tpng -o canada.png graphviz.dot");
    system("rm -f *.dot");
}
void textOutput(char **rep, char *filename, json_t *root){
    json_t *test;
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
        test = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    }else if(rep[REGION] != NULL){
        values = countries_paysSelonRegion(root,rep[REGION + 1]);
    }else{
        values = root;
    }

    do  {
        if(!onlyOneCountry) test = json_array_get(values,i);
        
        fprintf(file, "Name : %s\n",countries_getNomPays(test));
        fprintf(file, "Code : %s\n",countries_getCode(test));
    
        if(rep[SHOW_CAPITAL] != NULL){
            fprintf(file, "Capital : %s\n",countries_getCapitale(test));
        }
        if(rep[SHOW_LANGUAGES] != NULL){
            fprintf(file, "Langues: ");
            countries_getLangues(test);
        }
    
        if(rep[SHOW_BORDERS] != NULL){
            char *langues = (char*)malloc(sizeof(char)*countries_nbCaracteresFrontieres(test));
            printf("Borders : %s\n",countries_frontieres2(test, langues));
            fprintf(file, "Borders : %s",countries_frontieres2(test, langues));
            free(langues);
        }
        i++;
    }while(rep[COUNTRY] == NULL && i < json_array_size(values));
    fclose(file);
    

    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf("Option '--country' activated; option '--region' ignored.\n");

}

void dotOutput(char **rep, char *filename, json_t *root){
    json_t *test;
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
        test = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
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
        
    if(onlyOneCountry) graphviz_ecrireUnSeulPays(langues,capitale,frontieres,flag,test, filename);
    if(!onlyOneCountry) graphviz_ecrirePlusieursPays(langues,capitale,frontieres,flag,values, filename);

    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf("Option '--country' activated; option '--region' ignored.\n");
}

void stdoutOutput(char **rep, json_t *root){
    json_t *test;
    json_t *values;
    bool onlyOneCountry = false;
    int i = 0;
    if(rep[HELP] != NULL){
        help();
        exit(0);
    } 
    
    if(rep[COUNTRY] != NULL){
        test = countries_getJsonObjectFromCountry(rep[COUNTRY + 1],root);
        onlyOneCountry = true;
    }else if(rep[REGION] != NULL){
        values = countries_paysSelonRegion(root,rep[REGION + 1]);
    }else{
        values = root;
    }

    do  {
        if(!onlyOneCountry) test = json_array_get(values,i);
        
        printf("Name : %s\n",countries_getNomPays(test));
        printf("Code : %s\n",countries_getCode(test));
    
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
        i++;
    }while(rep[COUNTRY] == NULL && i < json_array_size(values));

    

    if(rep[REGION] != NULL && rep[COUNTRY] != NULL) printf("Option '--country' activated; option '--region' ignored.\n");
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
    printf("                             The supported regions are \"africa\", \"americas\",\n");
    printf("                             \"asia\", \"europe\" and \"oceania\".\n");
}

