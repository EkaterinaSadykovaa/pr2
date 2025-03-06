#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log_PATH.h"
#include "errors_PATH.h"

/*
int main(int argc, char *argv[]) {
    int option;
    char *log_path = NULL, *error_path = NULL;

    while ((option = getopt(argc, argv, "u:p:hl:e:")) != -1) {
    //while ((option = getopt(argc, argv, "uphl:e:")) != -1) {
        switch (option) {
            case 'u':
                function_users();
                //break;
                return 0;
            case 'p':
                function_processes();
                //break;
                return 0;;
            case 'h':
                function_help();
                exit(0);
            case 'l':
                log_path = optarg;
                function_log(log_path);
                //break;
                return 0;;
            case 'e':
                error_path = optarg;
                function_errors(error_path);
                //break;
                return 0;;
            default:
                function_help();
                exit(1);
        }
    }
    
    if (optind == 1) {
        function_help();
    }

    return 0;
}
*/



static int flag[4];

static char *short_option = "uph:l:e:";

static struct option long_options[] = {
    {"users",     no_argument,       &flag[0],  'u' },
    {"processes",  required_argument, &flag[1], 'p' },
    {"help",  no_argument, &flag[2], 'h'},
    {"log",  required_argument, &flag[2], 'l'},
    {"errors",  required_argument, &flag[2], 'e'},    
    {0,         0,                 0,         0 }
};

int main(int argc, char **argv) {
    int opt, i;
    char *log_path = NULL, *error_path = NULL;

    while (1) {
        int option_index = 0;

        opt = getopt_long(argc, argv, short_option,
                          long_options, &option_index);
        if (opt == -1)
            break;

        switch (opt) {
        case 0: /* for long option */
            printf("option %s", long_options[option_index].name);
            if (optarg)
                printf(" with arg '%s'", optarg);
            printf("\n");
            break;
	case 'u':
            function_users();
            break;
               
        case 'p':
            function_processes();
            break;
                
        case 'h':
            function_help();
                exit(0);
            case 'l':
                log_path = optarg;
                function_log(log_path);
                break;
            case 'e':
                error_path = optarg;
                function_errors(error_path);
                break;
            default:
                function_help();
                exit(1);	
        }
    }

    while (optind < argc) {
        printf("\tanother argument:%s\n", argv[optind++]);
    }

    for (i=0; i<5; i++) {
        printf("flag[%d] = %d\n", i, flag[i]);
    }

    return 0;
}
