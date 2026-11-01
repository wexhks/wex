#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");
    wchar_t c;
    int words = 0;
    int numbers = 0;
    int in_word = 0;
    int in_number = 0;
    printf("Введите строку:\n");
    while ((c = getwchar()) != L'\n' && c != WEOF) {
        if (iswalpha(c)) {
            if (!in_word) {
                words++;
            }
            in_word = 1;
            in_number = 0;
        } else if (iswdigit(c)) {
            if (!in_number) {
                numbers++;
            }
            in_number = 1;
            in_word = 0;
        } else {
            in_word = 0;
            in_number = 0;
        }
    }
    printf("Количество слов: %d\n", words);
    printf("Количество чисел: %d\n", numbers);
    return 0;
}