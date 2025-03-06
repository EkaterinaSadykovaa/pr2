//Для аргументов -l PATH и –log PATH замещает вывод на экран выводом в файл по заданному пути PATH
//Программа реализуется в отдельном файле в отдельной функции  

#include <stdio.h>
#include <stdlib.h>

void function_log(const char *path) {
   if (path == NULL) {
        perror("Ошибка расположения файла для вывода");
       return;
    }
    FILE *file = fopen(path, "w");
   if (file == NULL) {
        perror("Ошибка открытия файла для вывода");
       return;
    }
   stdout = file;
}



