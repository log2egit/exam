#ifdef __linux__                //если линукс
#include <linux/limits.h>       //добавляем библиотеку, где объявлен макрос PATH_MAX
#define PATH_SIZE PATH_MAX      //объявляем макрос, хранящий максимально возможную длину пути к файлу
#else                           //иначе (если не линукс, а что-то другое, например, виндовс)
#include <stdlib.h>             //добавляем библиотеку, где объявлен макрос _MAX_PATH
#define PATH_SIZE _MAX_PATH     //объявляем макрос, хранящий максимально возможную длину пути к файлу
#endif                          //конец ifdef

#include <stdio.h>
#define START 1                     //чтобы выбрать, какие строки выводить, четные или нечетные, измените на 0 или 1 соответственно
int main() {
    char path[PATH_SIZE];           //создаем строку куда считаем путь к файлу (PATH_SIZE - максимальная длина пути файла)
    gets(path);                     //считываем строку с путём
    FILE *f_ptr = fopen(path, "r"); //открываем соответствующий файл на чтение ("r"), присваиваем его поток к переменной f_ptr (тип - указатель на FILE)

    char c;                         //сюда будем считывать символ
    int i = START;                  //значение i показывает, нужно ли ввыводить эту строку или нет
    while ((c = fgetc(f_ptr)) != EOF) {//пока не считаем конец файла
           if (i) putchar(c);       //если строку нужно выводить, выводим символ
           if (c=='\n') i=!i;       //если считали конец строки, изменяем i на противолопожное значение (0 на 1, 1 на 0)
    }
    fclose(f_ptr);                  //закрываем файл
}
