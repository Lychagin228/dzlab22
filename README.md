# Домашнее задание к работе 22
## Условие задачи

Реализовать функцию action (TFun prtf, double xmin, double xmax), которая по
заданной указателем prtf функции и интервал определения от xmin до xmax

Проверяющую является ли функция возрастающей на заданном
интервале.

## 1. Алгоритм
### Алгоритм
1. Проверка корректности интервала:

Если xmin >= xmax, выводится сообщение об ошибке и возвращается 0

2. Инициализация параметров:

Задается количество проверочных точек N (1000 точек)

Вычисляется шаг между точками: step = (xmax - xmin) / (N - 1)

3. Вычисление первого значения:

Вычисляется значение функции в начальной точке xmin с помощью переданного указателя prtf

4. Циклическая проверка:

В цикле от 1 до N-1 вычисляются текущие координаты current_x

Вычисляется значение функции в текущей точке

Сравнивается с предыдущим значением:

Если current_value < prev_value, функция возвращает 0 (функция не возрастает)

Иначе обновляется prev_value для следующей итерации

5. Завершение:

Если все проверки пройдены успешно, функция возвращает 1 (функция возрастает на интервале)

## 2. Реализация программы

#include <stdio.h>

#include <locale.h>

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

## 3. Результаты работы программы

Тест 1: Функция f(x) = x^2

Функция возрастает на интервале [1.00, 10.00]


Тест 2: Функция f(x) = 2x + 1

Функция возрастает на интервале [1.00, 10.00]


Тест 3: Функция f(x) = -x

Функция НЕ возрастает на интервале [1.00, 10.00]


## 4. Информация о разработчике
Лычагин Антон бИЦ-252
