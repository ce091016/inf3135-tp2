#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>


static int option_flag;

int main(int argc, char *argv[]){
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
                printf("option -a\n");
                break;
            
            case 2:
                printf("option -b\n");
                break;
            
            case 3:
                printf("option -c\n");
                break;

            case 4:
                printf("option -d\n");
                break;

            case 5:

            case 6:

            case 7:

            case 8:

            case 9:

            case '?':
                break;

            default:
                abort();
        }
    }

    if(option_flag == 4)
        puts("option_flag is set.\n");

    if(optind < argc){
        printf("non-option ARGV-elements: ");
        while(optind < argc){
            printf("%s ", argv[optind++]);
            putchar('\n');
        }

        exit(0);


    }
    
}
