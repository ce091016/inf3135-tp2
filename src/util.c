#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "util.h"

void util_chaineEnMinuscules(const char * chaine, char * ptrChaine) {
    int i;
    for (i=0; i< strlen(chaine); i++) {
         ptrChaine[i] = tolower(chaine[i]); 
    }
    ptrChaine[strlen(chaine)] = '\0';
}

void util_chaineEnMajuscules(const char * chaine, char * ptrChaine) {
    int i;
    for (i=0; i< strlen(chaine); i++) {
        ptrChaine[i] = toupper(chaine[i]);
    }
    ptrChaine[strlen(chaine)] = '\0';
}
