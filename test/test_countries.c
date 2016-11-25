#include <stdio.h>
#include <jansson.h>
#include <stdbool.h>

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include "../src/countries.h"
#include "../src/util.h"

bool dotFileTest(){
    
    bool passOrFail = false;
    system("bin/tp2 --country can --output-format dot --output-filename test.dot");
    FILE *file = fopen("test.dot","r");
    if(file != NULL){
        printf("Test 'dot' file réussi.\n");
        passOrFail = true;
        system("rm test.dot");
    }else{
        printf("Test 'dot' file échoué.\n");
    }
    return passOrFail;
}

bool textFileTest(){

    bool passOrFail = false;
    system("bin/tp2 --country can --output-format text --output-filename test.txt");
    FILE *file = fopen("test.txt","r");
    if(file != NULL){
        printf("Test 'text' file réussi.\n");
        passOrFail = true;
        system("rm test.txt");
    }else{
        printf("Test 'text' file échoué.\n");
    }
    return passOrFail;
}

void test_jansson(void) {
    json_error_t error;
    json_t *root = json_load_file("data/countries/countries.json",0,&error);
    json_t *pays = countries_getCountry("can", root);

    CU_ASSERT_STRING_EQUAL_FATAL(countries_getName(pays),"Canada")
    CU_ASSERT_STRING_EQUAL_FATAL(countries_getCapital(pays), "Ottawa")
    CU_ASSERT_STRING_EQUAL_FATAL(countries_getCode(pays), "CAN")
    CU_ASSERT_STRING_EQUAL_FATAL(countries_getRegion(pays), "Americas")

}

void test_afg(void) {
    json_error_t error;
    json_t *root = json_load_file("data/countries/countries.json",0,&error);
    json_t *pays = countries_getCountry("afg", root);

    CU_ASSERT_STRING_EQUAL_FATAL(countries_getName(pays), "Islamic Republic of Afghanistan")
    CU_ASSERT_STRING_EQUAL_FATAL(countries_getCapital(pays), "Kabul")
    CU_ASSERT_STRING_EQUAL_FATAL(countries_getCode(pays), "AFG")

}

int main() {
    printf("\nTests d'existence de fichiers.\n\n");
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

    printf("%d tests réussis, %d échoués.\n\n\n", pass, fail); 

    CU_pSuite pSuite = NULL;
    // Initialisation
    if (CU_initialize_registry() != CUE_SUCCESS )
        return CU_get_error();

    // Ajout d'une suite
    pSuite = CU_add_suite("Testing des pays", NULL, NULL);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Ajout de tests a la suite
    if (CU_add_test(pSuite, "Test Canada",     test_jansson)  == NULL ||
        CU_add_test(pSuite, "Test Afghanistan", test_afg) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Ajout de tests a la suite
    if (CU_add_test(pSuite, "Test chargement du fichier", test_jansson)  == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Lancement des tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
