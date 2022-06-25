#include <stdlib.h>

#ifdef __linux__                //если линукс
#include <linux/limits.h>       //добавляем библиотеку, где объявлен макрос PATH_MAX
#define PATH_SIZE PATH_MAX      //объявляем макрос, хранящий максимально возможную длину пути к файлу
#else                           //иначе (если не линукс, а что-то другое, например, виндовс)
#define PATH_SIZE _MAX_PATH     //объявляем макрос, хранящий максимально возможную длину пути к файлу
#endif                          //конец ifdef

#include <stdio.h>
                                    //числа должны быть записаны в текстовый файл, каждое с новой строки. Последняя строка должна быть пустой (у меня автоматически добавляется при сохранении).
                                    //1
                                    //введите путь к файлу и нажмите Enter. Если файл в одной папке с программой можно ввести просто название, например a2.txt
int main() {
    char path[PATH_SIZE];           //создаем строку куда считаем путь к файлу (PATH_SIZE - максимальная длина пути файла)
    gets(path);                     //считываем строку с путём
    FILE *f_ptr = fopen(path, "r"); //открываем соответствующий файл на чтение ("r"), присваиваем его поток к переменной f_ptr (тип - указатель на FILE)
    if (f_ptr == NULL) return(1);                         //если файл не открылся, завершаем с ошибкой
    int len = 1;                                        //начальная длинна. Потом в этой переменной будем хранить текущую длинну динамического массива.
    int *a = (int *)malloc(len * sizeof(int));          //создаём динамический массив, присваеваем его указателю a

    int i = 0;                                          //счетчик по массиву. Одновременно показывает первое свободное место и колличество элементов массива.
    int c;                                              //сюда будем считывать текущее число из файла
    while(fscanf(f_ptr, "%i", &c) != EOF) {             //считываем число из файла (поток f_ptr) в переменную c, пока fscanf не вернула EOF (конец файла)
        if (i+1 > len) {                                //проверяем, что номер нового элемента не превосходит размер нашего массива (i+1 так как индексация с 0)
            a = (int *)realloc(a, (len*=2)*sizeof(int));//если превосходит, расширяем массив в 2 раза (и увеличваем len).
        }
        a[i] = c;                                       //вставляем на первое свободное место наш новый элемент
        i++;                                            //увеличиваем счетчик колличества элементов
    }
    fclose(f_ptr);                                      //закрываем файл

//    for(int n = 0; n<i; n++) printf("%i ", a[n]);       //выводим наш массив.
                                                        //После ввода к массиву можно применьть любой алгоритм сортировки. a хранит указатель на массив. i хранит его длинну (кол-во элементов).
    return 0;
}
