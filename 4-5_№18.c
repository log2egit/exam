#include <stdlib.h>                 //если в stepik появляется ошибка со словом ‘_MAX_PATH’ undeclared, то замените в 12 и 15 строчке _MAX_PATH на допустим 1024
#include <stdio.h>
//введите путь к первому файлу и нажмите Enter, потом введите путь ко второму файлу и нажмите Enter. Если файл в одной папке с программой можно ввести просто название, например a1.txt

//существует два варианта программы 1)считываем по строке из каждого файла, сравниваем их, если равные считываем следующие, если не равные выводим их
//однако мы не знаем максимальный размер строки, так что нам придется считывать их посимвольно в динамический массив
//однако если считывать их посимвольно, тогда можно сравнивать сами символы, а не строки, поэтому я написал второй, сложный вариант
//2) Считываем по символу из каждого файла, сравниваем их, если они равны, считываем следующие, если нет, возвращаемся к началу строки и выводим её. Причем для этого вовсе не обязательно хранить саму строку. Она уже хранится в файле.
//чтобы возвратиться к началу строки, надо знать, сколько символов мы прочитали от начала строки, а затем сместить на это число указатель по файлу (указывает на один символ в файле, который и будет считан следующим.
//короче смотрите сами
int main() {
    char path_1[_MAX_PATH];                 //создаем строку куда считаем путь к файлу (_MAX_PATH - максимальная длина пути файла)
    gets(path_1);                           //считываем строку с путём
    FILE *file_1 = fopen(path_1, "rb");     //открываем соответствующий файл на чтение в бинарном режиме ("rb"), так как fseek (перемещение указателя по файлу), всё равно будет видеть /r/n (2 символа конца строки в виндовс)
    char path_2[_MAX_PATH];                 //то же самое для второго файла
    gets(path_2);
    FILE *file_2 = fopen(path_2, "rb");
    int c1, c2;                             //переменные, куда мы будет считывать символы (для 1 и 2 файла соответственно)
    int n1 = 0;                             //расстояние до начала текущей строки в 1 файле (чтобы можно было вернуться к началу строки)
    int n2 = 0;                             //расстояние до начала текущей строки во 2 файле
    while (n1++, n2++, (c1 = fgetc(file_1)) == (c2 = fgetc(file_2))) {  //когда мы считываем символ, нам в любом случае надо увеличить счетчик символов до начала текущей строки, поэтому мы сначала увеличиваем их, потом считываем символы, потом сравниваем их, оператор ',' возвращает последнее значение (но выполняются все выражения)
        if (c1 == '\n') {                                               //если оба символа - перевод строки (верхнее условие выполнилось - символы одинаковые, можно проверить лишь один), то расстояние до начала строки обнуляется
            n1 = 0;
            n2 = 0;
        }
        else if (c1 == EOF) {                                           //если оба символа - конец файла => файлы одинаковые. Выходим из цикла.
            break;
        }
    }
    if (c1 == EOF && c2 == EOF) puts("identical files");                //если мы вышли из цикла, и оба последних символа = EOF, то пишем, что файлы одинаковые
    else {                                                              //иначе (цикл не дошел до конца обоих файлов)
        if (c1 != EOF) {                                                //если не дошли до конца первого файла
        fseek(file_1, -n1, SEEK_CUR);                                   //возвращаемся к началу строки, где вылетел цикл (обнаружен несовпадающий символ)  fseek(указатель на файл, на сколько символов сместиться, от куда считать (SEEK_CUR = от текущего положения указателя)
        while ((c1 = fgetc(file_1)) != '\n') putchar(c1);               //пока не дошли до конца этой строки, выводим символы из нее.
        }
        putchar('\n');                                                  //в конце ставим перевод на новую строку. Если до этого была выведена строка, мы просто перейдем на новую строку в консоли, если строка не была выведена (c1 == EOF), то мы выведем пустую строку(отличающуюся от не пустой строки файла 2)
        if (c2 != EOF) {                                                //то же самое для файла 2
            fseek(file_2, -n2, SEEK_CUR);
            while ((c2 = fgetc(file_2)) != '\n') putchar(c2);
            }
        putchar('\n');
    }
    fclose(file_1);                                                     //закрываем файлы
    fclose(file_2);
    return 0;                                                           //конец
}
