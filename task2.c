#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char k1[3], k2[3];
    int x1, y1, x2, y2;
    int dx, dy;
    int choice;
    int can[5];
    printf("Первая клетка (например, a1): ");
    scanf("%2s", k1);
    printf("Вторая клетка (например, h8): ");
    scanf("%2s", k2);
    if (strlen(k1) != 2 || strlen(k2) != 2 ||
        k1[0] < 'a' || k1[0] > 'h' ||
        k2[0] < 'a' || k2[0] > 'h' ||
        k1[1] < '1' || k1[1] > '8' ||
        k2[1] < '1' || k2[1] > '8') {
        printf("Некорректные координаты!\n");
        return 1;
    }
    x1 = k1[0] - 'a' + 1;
    y1 = k1[1] - '0';
    x2 = k2[0] - 'a' + 1;
    y2 = k2[1] - '0';
    if (x1 == x2 && y1 == y2) {
        printf("Клетки должны быть различными!\n");
        return 1;
    }
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    printf("\nФигура:\n");
    printf("1 - Король\n");
    printf("2 - Ферзь\n");
    printf("3 - Ладья\n");
    printf("4 - Слон\n");
    printf("5 - Конь\n");
    scanf("%d", &choice);
    can[0] = (dx <= 1 && dy <= 1);
    can[1] = (dx == 0 || dy == 0 || dx == dy);
    can[2] = (dx == 0 || dy == 0);
    can[3] = (dx == dy);
    can[4] = (dx == 1 && dy == 2) ||
             (dx == 2 && dy == 1);
    if (choice < 1 || choice > 5) {
        printf("Неверный выбор!\n");
        return 1;
    }
    char *names[] = {
        "Король", "Ферзь", "Ладья", "Слон", "Конь"
    };
    if (can[choice - 1]) {
        printf("%s может перейти за один ход.\n",
               names[choice - 1]);
    } else {
        printf("%s не может перейти за один ход.\n",
               names[choice - 1]);

        printf("Другие фигуры, которые могут перейти:\n");
        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (i != choice - 1 && can[i]) {
                printf("%s\n", names[i]);
                found = 1;
            }
        }
        if (!found)
            printf("Таких фигур нет.\n");
    }
    return 0;
}