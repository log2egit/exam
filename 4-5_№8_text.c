#include <stdlib.h>
#include <stdio.h>
//после ввода перейти на новую строку и послать EOF (у меня Ctrl+C)

int main() {                                                        //функция main
    int len = 1;                                                    //длинна динамического массива (будет расширяться)
    char *arr = (char *)malloc(len * sizeof(char));                 //динамический массив для хранения строки
    if (arr == NULL) return(1);                                     //если память не выделилась - завершаем с ошибкой
    int i = 0;                                                      //текущее положение в динамическом массиве
    int empty_flag = 1;                                             //флаг для пустой строки (если встречались только пробелы, чтобы потом удалить строку)
    int c;                                                          //текущий (только что считанный) символ
    int prev = '\n';                                                //предыдущий (считанный на предыдущем шаге) символ, присваемаем \n чтобы начать с новой строки
    while ((c = getchar()) != EOF) {                                //считываем символ и сохраняем в переменную с, пока не считаем конец файла
        if (c=='\n') {                                              //если новая строка
            if (prev=='\n') continue;                               //если предыдущий символ = перенос строки (пустая строка) просто переходим к следующей букве
            if (empty_flag==1){i--; continue;}                      //закомент есл стр из пробел не счит пустой. если стр из пробел => переход на 1 клетк в массиве назад (новую стр пишем поверх ед сохр пробела)
            empty_flag=1;                                           //если это просто новая строка, тогда пока ставим флаг пустой строки в 1
        }
        if (c=='\t') c = ' ';                                       //если считали таб, заменяем его на пробел
        if (c==' ' && prev==' ') continue;                          //если предыдущий символ был пробелом, а новый тоже пробел (или таб), пропускаем его
        if (c!=' ' && c!='\n') empty_flag=0;                        //если символ не пробел (не таб) и не новая строка, тогда строка не пустая, флаг в 0
        if (i+2 > len) arr = realloc(arr, (len*=2)*sizeof(char));   //если новый символ не влезает в массив (i+2 из-за индексации с 0 и символа '/0'), расширяем его в 2 раза
        if (arr == NULL) return(1);                                 //если память не выделилась - завершаем с ошибкой
        arr[i] = c;                                                 //вставляем новый символ в массив
        i++;                                                        //увеличиваем счетчик по массиву
        prev = c;                                                   //предыдущий символ равен текущему
    }                                                               //вставляем конец строки на место последнего переноса
    if (i>0) {arr[--i] = '\0'; puts(arr);}                          //если строка не пустая, вставляем конец строки на место последнего переноса и выводим её
    return 0;
}
