#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "log_PATH.h"
#include "errors_PATH.h"


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

/*

int main(int argc, char *argv[]) {
    int option;
    char *log_path = NULL, *error_path = NULL;

    // Определение длинных аргументов
    static struct option long_options[] = {
        {"users", no_argument, NULL, 'u'},
        {"processes", no_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {"log", required_argument, NULL, 'l'},
        {"errors", required_argument, NULL, 'e'},
        {NULL, 0, NULL, 0} // Завершающий элемент
    };

    while (1) {
        // Используем getopt_long для обработки аргументов
        int option_index = 0;
        option = getopt_long(argc, argv, "uph l:e:", long_options, &option_index);

        // Проверяем, если все аргументы обработаны
        if (option == -1) {
            break;
        }

        switch (option) {
            case 'u':
                function_users();
                return 0;
            case 'p':
                function_processes();
                return 0;
            case 'h':
                function_help();
                return 0;
            case 'l':
                log_path = optarg;
                function_log(log_path);
                return 0;
            case 'e':
                error_path = optarg;
                function_errors(error_path);
                return 0;
            default:
                function_help();
                exit(1);
        }
    }

    // Если не были переданы аргументы
    if (optind == 1) {
        function_help();
    }

    return 0;
}
*/

