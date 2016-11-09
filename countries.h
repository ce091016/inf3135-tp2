#include <jansson.h>

//PROTOTYPES
//

json_t* countries_getJsonObjectFromCountry(char * code, json_t* tabPays); 

const char * countries_getNomPays(json_t * pays);
 
const char * countries_getCapitale(json_t * pays);
 
const char * countries_getFrontieres(json_t * pays);
 
const char * countries_getLangues(json_t * pays);

int countries_nbLangues(json_t * pays);

json_t * countries_langues(json_t *pays); 

json_t ** countries_paysSelonRegion(json_t *tabPays, char * region);

const char * countries_region(json_t *pays);
