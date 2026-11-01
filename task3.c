#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int mode, number, guess, attempts = 0;
    int low = 1, high = 1000;
    char answer;
    srand(time(NULL));
    printf("1 - Компьютер загадывает\n2 - Пользователь загадывает\n");
    scanf("%d", &mode);
    if (mode == 1) {
        number = rand() % 1000 + 1;
        do {
            printf("Ваш вариант: ");
            scanf("%d", &guess);
            attempts++;
            if (guess < number)
                printf("Больше\n");
            else if (guess > number)
                printf("Меньше\n");
            else
                printf("Угадали! Попыток: %d\n", attempts);
        } while (guess != number);
    }
    else if (mode == 2) {
        while (low <= high) {
            guess = (low + high) / 2;
            attempts++;
            printf("Моё число: %d. Ваш ответ: ", guess);
            scanf(" %c", &answer);
            if (answer == '>')
                low = guess + 1;
            else if (answer == '<')
                high = guess - 1;
            else if (answer == '=') {
                printf("Угадал! Попыток: %d\n", attempts);
                break;
            }
            else {
                printf("Введите >, < или =\n");
                attempts--;
            }
        }
        if (low > high)
            printf("Ответы противоречивы.\n");
    }
    else {
        printf("Неверный режим.\n");
    }
    return 0;
}