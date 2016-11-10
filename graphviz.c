#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "countries.h"


#define DEBUTGRAPH "graph {\n"
#define FINGRAPH "}\n"
#define DEBUTPAYS "    " 
#define DEBUTPAYS2 " [\n"
#define FINPAYS "    ];\n"
#define SHAPE "        shape = none\n"
#define LABEL "        label = <<table border=\"0\" cellspacing=\"0\">\n"
#define LABELFIN "        </table>>\n"
#define TRTDIMAGE "            <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\">\n"
#define TRTDIMAGE2 "              <img src=\""
#define TRTDIMAGE3 ".png\" scale=\"true\"/>\n"
#define TRTDIMAGE4 "            </td></tr>\n"
#define TRTDNAME "            <tr><td align=\"left\" border=\"1\"><b>Name</b>: "
#define TRTDCODE "            <tr><td align=\"left\" border=\"1\"><b>Code</b>: "
#define TRTDCAPITAL "            <tr><td align=\"left\" border=\"1\"><b>Capital</b>: "
#define TRTDLANGUAGE "            <tr><td align=\"left\" border=\"1\"><b>Language</b>: "
#define TRTDBORDERS "            <tr><td align=\"left\" border=\"1\"><b>Borders</b>: " 
#define FINTRTD "</td></tr>\n"


//int main(int argc, char * argv[]) {
//        
//}

void graphviz_ecrireUnPays(int langues, int capitale, int frontieres, int flag, json_t *pays, FILE * graphviz) {
    
    const char * codePays = countries_getCode(pays); 
    fprintf(graphviz, "%s%s%s", DEBUTPAYS, codePays, DEBUTPAYS2);
    fprintf(graphviz, "%s%s", SHAPE, LABEL);
    if (flag == 1) {
        fprintf(graphviz, "%s%s%s%s%s", TRTDIMAGE, TRTDIMAGE2, codePays, TRTDIMAGE3, TRTDIMAGE4);
    }
    fprintf(graphviz, "%s%s%s", TRTDNAME, countries_getNomPays(pays), FINTRTD);
    fprintf(graphviz, "%s%s%s", TRTDCODE, countries_getCode(pays), FINTRTD);
    if (langues == 1) {
        json_t * langues = countries_langues(pays);
        fprintf(graphviz, "%s", TRTDLANGUAGE);
        void * iter = json_object_iter(langues);
        json_t *langueTemp = json_object_iter_value(iter);
        fprintf(graphviz, "%s", json_string_value(langueTemp));
        iter = json_object_iter_next(langues, iter);
        while (iter) {
            langueTemp = json_object_iter_value(iter);
            fprintf(graphviz, ", %s", json_string_value(langueTemp));
            iter = json_object_iter_next(langues, iter);
        }
        fprintf(graphviz, "%s", FINTRTD);
    }
    if (frontieres == 1) {
        fprintf(graphviz, "%s", TRTDBORDERS);
        json_t *frontieres = countries_frontieres(pays);
        if (json_array_size(frontieres) > 0) {
            fprintf(graphviz, "%s", json_string_value(json_array_get(frontieres,0)));
        }
        int i=1;
        while (i<json_array_size(frontieres)) {
            fprintf(graphviz, ", %s", json_string_value(json_array_get(frontieres,i)));
            i++;
        }
        fprintf(graphviz, "%s", FINTRTD);

    }
    fprintf(graphviz, "%s%s", LABELFIN, FINPAYS);
}

void graphviz_ecrireUnSeulPays(int langues, int capitale, int frontieres, int flag, json_t *pays) {
    FILE * graphviz = fopen("graphviz.dot", "w");
    fprintf(graphviz, "%s", DEBUTGRAPH);
    graphviz_ecrireUnPays(langues, capitale, frontieres, flag, pays, graphviz);    
    fprintf(graphviz, "%s", FINGRAPH);
    fclose(graphviz);
}

void graphviz_ecrirePlusieursPays(int langues, int capitale, int frontieres, int flag, json_t *tabPays) {
    FILE * graphviz = fopen("graphviz.dot", "w");
    fprintf(graphviz, "%s", DEBUTGRAPH);
    int i;
    for (i=0; i< json_array_size(tabPays); i++) {
        graphviz_ecrireUnPays(langues, capitale, frontieres, flag, json_array_get(tabPays, i), graphviz);
    }
    fprintf(graphviz, "%s", FINGRAPH);
    fclose(graphviz);
}

//pourquoi ne pas seulement passer le pays en paramètres?
//
//A FAIRE: 
//--prendre le code de ecrireUnPays et le séparer en sous-fonctions
//--rajouter à la fin de ecrirePlusieursPays les liens entre les pays qui ont des frontières communes
//--mettre les noms de code en lettre minuscules
//
