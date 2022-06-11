#include <stdlib.h>
#include <stdio.h>
//читайте здесь, там и другие функции для односвязного списка https://t4s.tech/realizatsiya-odnosvyaznogo-lineynogo-spiska-v-si/?
//чтобы развернуть односвязный список, его сначала надо создать. Созданим 5 функций: создать новый список, добавить элемент в начало, в конец, развернуть список и вывести список

typedef struct node_struct {    //объявляем новый тип (структуру), элементы нашего односвязного списка будут представлять собой экземпляры этой структуры
    int value;                  //в первом поле структуры будет храниться значение текущего элемента (число, которое храниться в этой клетке списка)
    struct node_struct *next;   //во втором поле структуры будет хранится указаетель на следующий элемент списка.
} node;                         //наш новый тип будет называться node - узел списка

node *create(int head_value) {                  //создадим первоначальный (head) узел нашего списка. Функция принимает значение для него и возвращает указетель на него
    node *head = (node *)malloc(sizeof(node));  //создаём переменную head, представляющую собой указаетель на элемент списка. Память выделяем динамически
    head->value = head_value;                   //в поле value записываем нужно значение
    head->next = NULL;                          //пока это единственный элемент списка. После него других нет. В поле next пишем пустой указатель NULL.
    return head;                                //возвращаем указатель на созданных элемент
};

node *add_to_start(node *head, int new_value) {//добавить элемент в начало списка. Соответственно первый элемент списка поменяется. Функция принимает старый первый элемент и значение для нового
    node *new_node = (node *)malloc(sizeof(node));  //создаём новый элемент
    new_node->value = new_value;                    //заполняем нужным значением его соответствующее поле
    new_node->next = head;                          //так как этот элемент вставляется в начало, то старый первый элемент будет стоять за ним.
    return new_node;                                //возвращаем указатель на новый первый элемент списка
}

void add_to_end(node *head, int new_value) {    //добавить элемент в конец списка
    node *last_node = head;                     //создаём указатель на элемент списка. Пока он смотрит на первый элемент
    while (last_node->next != NULL) {           //пока мы не дошли до последнего элемента (у которого указатель на следующий равен NULL)
        last_node = last_node->next;            //переходим к следующему элементу
    }                                           //в конце last_node хранит указатель на последний элемент
    last_node->next = (node *)malloc(sizeof(node));//у последнего элемента в поле next присваиваем указатель на новую динамически выделенную память под новый элемент
    last_node = last_node->next;                //переходим к только что созданному элементу. Теперь он последний.
    last_node->value = new_value;               //заполняем нужным значением его соответствующее поле
    last_node->next = NULL;                     //после него других элементов нет. В поле next пишем пустой указатель NULL.
}

node *reverse(node *head) {                     //разворот списка
    node *prev = NULL;                          //здесь будем хранить указатель на предыдущий элемент. Так как начальный элемент станет последним, после него будет NULL
    node *cur;                                  //буфер для хранения указателя на элемент с которым сейчас работаем
    node *next = head;                          //указатель на следующий элемент. Когда цикл запустится, он сразу приствоится в cur
    while (next != NULL) {                      //пока не дошли до конца списка (следующий элемент NULL)
        cur = next;                             //переходим к рассмотрению элемент, который раньше шел за тем, который мы рассмотрели на предыдущей интерации цикла
        next = cur->next;                       //сохраняем указаетель на элемент, который идет за ним
        cur->next = prev;                       //теперь за ним идет элемент, который раньше шел перед ним
        prev = cur;                             //сохраняем указатель на только что рассмотренный элемент (для следующий интерации цикла)
    }
    return cur;                                 //возвращаем элемент, на котором вылетел цикл (он раньше он был последним (ссылался на NULL)), теперь он будет первым
}

void print(node *head) {                //напечатать список
    node *cur_node = head;              //мы не можем использовать для прохода по списку переменную head, так как тогда мы потеряем (окончательно) его начало. Создадим новую переменную
    while (cur_node != NULL) {          //пока мы не дошли до конца списка (указатель на текущий элемент стал NULL (мы зашли за конец спика))
        printf("%i ", cur_node->value); //вывести значение текущего элемента
        cur_node = cur_node->next;      //перейти к следующему элементу
    }
    putchar('\n');                      //перейти на новую строку
}

int main() {                                                    //чтобы развернуть список, его надо сначало создать
    node *list_1 = create(100);                                 //допустим значение первого элемента 100
    for (int i = 0; i<10; i++) add_to_end(list_1, i);           //добавим в цикле в конец списка несколько элементов
    for (int i = -10; i>-20; i--) list_1 = add_to_start(list_1, i);//добавим в цикле в начало списка несколько элементов. Так как начальный элемент изменяется, каждый раз присваиваем значение list_1
    print(list_1);                                              //напечатаем список
    list_1 = reverse(list_1);                                   //реверс списка. Так как начальный элемент изменяется (им становиться последний элемент), присваиваем значение list_1
    print(list_1);                                              //напечатаем список
}
