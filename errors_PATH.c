//Для аргументов -e PATH и –errors PATH замещает вывод ошибок из потока stderr в файл по заданному пути PATH
//Программа реализуеься в отдельном файле в отдельной функции 


#include <stdio.h>
#include <stdlib.h>

void function_errors(const char *path) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
       perror("Ошибка открытия файла для ошибок");
      return;
    }
    if (path == NULL) {
       perror("Не указан файл для ошибок");
      return;
    }
    stderr = file;
}

