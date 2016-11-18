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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include "input.h"

static int option_flag;

// Implémentation
// --------------

void input(int argc, char *argv[],char *rep[]){
    int c;

    while(true){
    
        static struct option long_options[] =
            {
                {"help", no_argument, &option_flag, 1},
                {"output-format", required_argument, &option_flag,    2},
                {"output-filename", required_argument, &option_flag,    3},
                {"show-languages", no_argument, &option_flag,    4},
                {"show-capital", no_argument, &option_flag,    5},
                {"show-borders", no_argument, &option_flag,    6},
                {"show-flag", no_argument, &option_flag,    7},
                {"country", required_argument, &option_flag,    8},
                {"region", required_argument, &option_flag,    9},
                {0, 0, 0, 0}
            };
        int option_index = 0;
        c = getopt_long(argc, argv, "", long_options, &option_index);
        
        if(c == '?') option_flag = '?';
        if(c == -1) break;

        switch(option_flag){
            case 0:
                if(long_options[option_index].flag != 0)
                    break;
                printf("option %s", long_options[option_index].name);
                if(optarg)
                    printf(" with arg %s", optarg);
                printf("\n");
                break;

            case 1:
                rep[0] = "help";
                break;
            
            case 2:
                rep[1] = "output-format";
                rep[2] = optarg;
                break;
            
            case 3:
                rep[3] = "output-filename";
                rep[4] = optarg;
                break;

            case 4:
                rep[5] = "show-languages";
                break;

            case 5:
                rep[6] = "show-capital";
                break;

            case 6:
                rep[7] = "show-borders";
               break;

            case 7:
                rep[8] = "show-flag";
               break;

            case 8:
                rep[9] = "country";
                rep[10] = optarg;
                break;

            case 9:
                rep[11] = "region";
                rep[12] = optarg;
                break;

            case '?':
                printf(HELP_MSG);
                exit(1);

            default:
                abort();
        }
    }

    if(optind < argc){
        printf("Invalid option.\n");
        while(optind < argc){
            printf("%s ", argv[optind++]);
            putchar('\n');
            printf(HELP_MSG);
        }

        exit(0);
    }
}
