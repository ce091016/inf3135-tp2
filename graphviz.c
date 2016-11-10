#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "countries.h"


#define DEBUTGRAPH "graph {\n"
#define DEBUTPAYS "    " 
#define DEBUTPAYS2 " [\n"
#define SHAPE "        shape = none\n"
#define LABEL "        label = <<table border=\"0\" cellspacing=\"0\">\n"
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

void graphviz_ecrireUnPays(int langues, int capitale, int frontieres, int flag, char * codePays, json_t *tabPays) {
    
    json_t * pays = countries_getJsonObjectFromCountry(codePays, tabPays);
    FILE * graphviz = fopen("graphviz.dot", "w");
    fputs(DEBUTGRAPH, graphviz); 
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


    fclose(graphviz);
}

//pourquoi ne pas seulement passer le pays en paramètres?
