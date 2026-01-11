#include <stdio.h>
#include<locale.h>

// Объявление типа указателя на функцию
typedef double (*TFun)(double);

// Прототипы функций
int action(TFun prtf, double xmin, double xmax);
double test_function1(double x);
double test_function2(double x);
double test_function3(double x);

int main() {

    setlocale(LC_CTYPE, "RUS");
    
    double xmin = 1.0, xmax = 10.0;

    printf("Тест 1: Функция f(x) = x^2\n");
    if (action(test_function1, xmin, xmax)) {
        printf("Функция возрастает на интервале [%.2f, %.2f]\n", xmin, xmax);
    }
    else {
        printf("Функция НЕ возрастает на интервале [%.2f, %.2f]\n", xmin, xmax);
    }

    printf("\nТест 2: Функция f(x) = 2x + 1\n");
    if (action(test_function2, xmin, xmax)) {
        printf("Функция возрастает на интервале [%.2f, %.2f]\n", xmin, xmax);
    }
    else {
        printf("Функция НЕ возрастает на интервале [%.2f, %.2f]\n", xmin, xmax);
    }

    printf("\nТест 3: Функция f(x) = -x\n");
    if (action(test_function3, xmin, xmax)) {
        printf("Функция возрастает на интервале [%.2f, %.2f]\n", xmin, xmax);
    }
    else {
        printf("Функция НЕ возрастает на интервале [%.2f, %.2f]\n", xmin, xmax);
    }

    return 0;
}

// Реализация функции action
int action(TFun prtf, double xmin, double xmax) {
    if (xmin >= xmax) {
        printf("Ошибка: некорректный интервал\n");
        return 0;
    }

    const int N = 1000; // Количество проверочных точек
    double step = (xmax - xmin) / (N - 1);

    double prev_x = xmin;
    double prev_value = prtf(prev_x);

    for (int i = 1; i < N; i++) {
        double current_x = xmin + i * step;
        double current_value = prtf(current_x);

        // Если текущее значение меньше предыдущего - функция не возрастает
        if (current_value < prev_value) {
            return 0;
        }

        prev_value = current_value;
    }

    return 1; // Функция возрастает на всем интервале
}

// Тестовые функции
double test_function1(double x) {
    return x * x; // Не возрастает на отрицательных x, но возрастает на x > 0
}

double test_function2(double x) {
    return 2 * x + 1; // Строго возрастающая линейная функция
}

double test_function3(double x) {
    return -x; // Убывающая функция
}