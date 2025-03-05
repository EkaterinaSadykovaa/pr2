//для аргументов -p и --processes выводит перечень запущенных процессов, отсортированных по их идентификатору

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>


void function_processes() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    
    if (dp == NULL) {
        perror("opendir");
       
    }

    printf("%-6s %s\n", "PID", "Command");

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Проверяем, что это числовая директория(в каталоге /proc в Linux каждое имя подкаталога соответствует PID (идентификатору процесса), который всегда начинается с цифры. )
            int pid = atoi(entry->d_name);
            char cmdline[256];
            snprintf(cmdline, sizeof(cmdline), "/proc/%d/cmdline", pid);
            
            FILE *fp = fopen(cmdline, "r");
            if (fp) {
                fgets(cmdline, sizeof(cmdline), fp);
                printf("%-6d %s\n", pid, cmdline);
                fclose(fp);
            }
        }
    }
    
    closedir(dp);
}

