#include <stdio.h>

int main() {
    int num = 0; //сюда будем считывать число
    scanf("%d", &num); //считываем число
    if (num%3==0) { //если делится на 3
        printf("Fizz");
    }
    if (num%5==0) { //если делится на 5
        printf("Buzz");
    }
    if (num%3!=0 && num%5!=0) { //если ни на 3, ни на 5
        printf("%d", num); //выводим само число
    }
    return 0;
}
