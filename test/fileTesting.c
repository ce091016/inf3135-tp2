/**
 * Ces tests servent à vérifier l'existence des fichier 
 * 'text' et 'dot' lorsqu'ils doivent être créés.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dotFileTest(){
    
    bool passOrFail = false;
    system("cd ..; bin/tp2 --country can --output-format dot --output-filename test.dot");
    FILE *file = fopen("../test.dot","r");
    if(file != NULL){
        printf("Test 'dot' file réussi.\n");
        passOrFail = true;
        system("rm ../test.dot");
    }else{
        printf("Test 'dot' file échoué.\n");
    }
    return passOrFail;
}

bool textFileTest(){

    bool passOrFail = false;
    system("cd ..; bin/tp2 --country can --output-format text --output-filename test.txt");
    FILE *file = fopen("../test.txt","r");
    if(file != NULL){
        printf("Test 'text' file réussi.\n");
        passOrFail = true;
        system("rm ../test.txt");
    }else{
        printf("Test 'text' file échoué.\n");
    }
    return passOrFail;
}
/**
int pass = 0;
    int fail = 0;
    if(dotFileTest()){
        pass++;
    }else{
        fail++;
    }

    if(textFileTest()){
        pass++;
    }else{
        fail++;
    }

    printf("%d tests réussis, %d échoués.\n", pass, fail); 
*/
