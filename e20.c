// С клавиатуры вводится последовательность вещественных чисел. В полученном списке определить числа с положительным значением. Если таких чисел нет - выдать соответствующее сообщение. Вычислить среднее арифметическое найденных чисел. вывести на печать полученный список, найденные числа и их среднее арифметическое. 

#include <stdio.h>

int main() {
    int n, count = 0;      // Количество чисел в списке и счетчик положительных чисел
    float numbers[100];    // Массив для хранения списка чисел (максимум 100 чисел)
    float positive_sum = 0.0; // Сумма положительных чисел

    // Ввод количества чисел
    printf("Введите количество чисел: ");
    scanf("%d", &n);

    // Проверка на корректность ввода
    if (n <= 0 || n > 100) {
        printf("Некорректное количество чисел. Введите значение от 1 до 100.\n");
        return 1;
    }

    // Ввод чисел
    printf("Введите %d вещественных числа:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &numbers[i]); // Считываем каждое число
    }

    // Вывод введенного списка чисел
    printf("\nВведенный список чисел:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    // Поиск положительных чисел и вычисление их суммы
    printf("\nПоложительные числа:\n");
    for (int i = 0; i < n; i++) {
        if (numbers[i] > 0) {
            printf("%.2f ", numbers[i]);
            positive_sum += numbers[i]; // Добавляем значение к сумме
            count++;                    // Увеличиваем счетчик положительных чисел
        }
    }

    // Проверка, были ли найдены положительные числа
    if (count == 0) {
        printf("\nПоложительные числа отсутствуют.\n");
    } else {
        // Вычисление среднего арифметического
        float average = positive_sum / count;
        printf("\nСреднее арифметическое положительных чисел: %.2f\n", average);
    }

    return 0;
}
