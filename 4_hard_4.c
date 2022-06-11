#include <stdlib.h>
#include <stdio.h>
                                                        //Первым числом послать кол-во элементов. После каждого числа ставить перевод на новую строку (Enter).
                                                        //После последнего числа ввод завершиться автоматически.
typedef struct ARR_STRUCT {                             //объявляем новый тип (структуру)
    int *a;                                             //здесь будет указатель на наш динамический массив
    int len;                                            //зсдесь будет его длинна (колличество элементов)
} ARR;                                                  //наш новый тип будет называться ARR

ARR *scan() {                                           //создаём функцию считывания, она будет возвращать указетель на наш тип (струтуру) ARR
    ARR *cur_arr = (ARR *)malloc(sizeof(ARR));          //выделяем динамическую память для струтуры ARR, присваеваем указатель на нее переменной cur_arr. Так будет называться экземпляр струтуры внутри нашей функции.
    scanf("%i", &cur_arr->len);                         //считываем длинну массива во второй элемент струтуры cur_arr->len
    cur_arr->a = (int *)malloc(cur_arr->len * sizeof(int));//создаём динамический массив длинной len, присваеваем его первому элементу струтуры a. Полный путь к массиву получается cur_arr->a
    int c;                                              //сюда будем считывать текущее введенное число
    for (int i = 0; i<cur_arr->len; i++) {              //пока коллиство элементов не достигло длинны массива
        scanf("%i", &c);                                //считываем число в переменную c
        cur_arr->a[i] = c;                              //вставляем на первое свободное место наш новый элемент
    }
    return cur_arr;                                     //возвращаем указатель на нашу структуру
}

int main() {
    ARR *arr_1 = scan();                                //создаём указатель на тип ARR, присваевам ему возвращаемое значение функции scan().

//    for(int n = 0; n<arr_1->len; n++) printf("%i ", arr_1->a[n]);//выводим наш массив.
                                                        //После ввода к массиву можно применьть любой алгоритм сортировки. arr_1->a хранит указатель на массив. arr_1->len хранит его длинну (кол-во элементов).
    return 0;
}