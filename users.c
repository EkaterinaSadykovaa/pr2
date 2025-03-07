//для аргументов -u и --users выводит перечень пользователей и их домашних директорий на экран, отсортированных по алфавиту


#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>

void function_users() {
    struct passwd *pw;
    char *user_list[100];
    int count = 0;

    while ((pw = getpwent()) != NULL) {
        user_list[count] = strdup(pw->pw_name);
        count++;
    }
    endpwent();

    qsort(user_list, count, sizeof(char*), (int(*)(const void*, const void*)) strcmp);

    for (int i = 0; i < count; i++) {
        printf("Пользователь: %s, Домашняя директория: %s\n", user_list[i], getpwuid(getuid())->pw_dir);
        free(user_list[i]);
    }
}
