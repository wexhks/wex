#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double h, w, d;
    double rho_dvp, rho_dsp, rho_wood;
    double m1, m2, m3, m4, m5, total;
    int n;
    printf("Высота (180-220 см): ");
    scanf("%lf", &h);
    printf("Ширина (80-120 см): ");
    scanf("%lf", &w);
    printf("Глубина (50-90 см): ");
    scanf("%lf", &d);
    printf("Плотность ДВП (кг/м3): ");
    scanf("%lf", &rho_dvp);
    printf("Плотность ДСП (кг/м3): ");
    scanf("%lf", &rho_dsp);
    printf("Плотность дерева (кг/м3): ");
    scanf("%lf", &rho_wood);
    if (h < 180 || h > 220 ||
        w < 80 || w > 120 ||
        d < 50 || d > 90) {
        printf("Ошибка!\n");
        return 1;
    }
    h /= 100;
    w /= 100;
    d /= 100;
    n = (int)(h / 0.4) - 1;
    if (n < 0) n = 0;
    m1 = h * w * 0.005 * rho_dvp;
    m2 = 2 * h * d * 0.015 * rho_dsp;
    m3 = 2 * w * d * 0.015 * rho_dsp;
    m4 = h * w * 0.01 * rho_wood;
    m5 = n * w * d * 0.015 * rho_dsp;
    total = m1 + m2 + m3 + m4 + m5;
    printf("\nКоличество полок: %d\n", n);
    printf("Масса шкафа: %.2f кг\n", total);
    return 0;
}