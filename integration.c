#include <stdio.h>
#include <math.h>
#include "tinyexpr.h"
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    char expression[256];
    double a, b, h, sum, integral;
    double x;
    int n;
    printf("Введите функцию f(x): ");
    fgets(expression, sizeof(expression), stdin);
    printf("Введите нижнюю границу интегрирования: ");
    scanf("%lf", &a);
    printf("Введите верхнюю границу интегрирования: ");
    scanf("%lf", &b);
    printf("Введите количество разбиений: ");
    scanf("%d", &n);
    if (n <= 0 || a >= b) {
        printf("Ошибка: неверные входные данные!\n");
        return 1;
    }
    // Переменная x для парсера
    te_variable vars[] = {
        {"x", &x}
    };
    int error;
    te_expr *expr = te_compile(expression, vars, 1, &error);
    if (expr == NULL) {
        printf("Ошибка в функции! Позиция ошибки: %d\n", error);
        return 1;
    }
    // Вычисление шага
    h = (b - a) / n;
    // Значения на границах
    x = a;
    sum = te_eval(expr) / 2.0;
    x = b;
    sum += te_eval(expr) / 2.0;
    // Сумма внутренних значений
    for (int i = 1; i < n; i++) {
        x = a + i * h;
        sum += te_eval(expr);
    }
    // Вычисление интеграла
    integral = h * sum;
    printf("\nРезультаты вычисления:\n");
    printf("Шаг разбиения: %.10lf\n", h);
    printf("Количество разбиений: %d\n", n);
    printf("Значение интеграла: %.10lf\n", integral);
    te_free(expr);
    return 0;
}