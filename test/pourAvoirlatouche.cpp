#include <stdio.h>
#include <conio.h>

int main() {
    int nombre = 0;
    while(nombre !=5 ){
        char ch = getch();
        printf("Received Input: %c\n", ch);
    }
    return 0;
}