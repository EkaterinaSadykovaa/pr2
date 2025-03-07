#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log_PATH.h"
#include "errors_PATH.h"


int main(int argc, char *argv[]) {
    int option;
    int users_flag = 0, processes_flag = 0;

    struct option long_options[] = {
        {"users", no_argument, NULL, 'u'},
        {"processes", no_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {"log", required_argument, NULL, 'l'},
        {"errors", required_argument, NULL, 'e'},
        {NULL, 0, NULL, 0}
    };

    while ((option = getopt_long(argc, argv, "uph:l:e:", long_options, NULL)) != -1) {
        switch (option) {
            case 'u':
            	function_users();
                break;
            case 'p':
            	function_processes();
                break;
            case 'h':
            	function_help();
                return 0;
            case 'l':
                function_log(optarg);
               
                break;
            case 'e':
            	function_errors(optarg);
                break;
            default:
                function_help();
                return 1;
        }
    }


    return 0;
}
