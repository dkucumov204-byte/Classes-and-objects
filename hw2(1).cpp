#include <iostream>
#include <string>
#include <clocale>

class Counter {
private:
    int value;

public:
    Counter() : value(1) {}

    Counter(int initialValue) : value(initialValue) {}

    void increment() {
        ++value;
    }

    void decrement() {
        --value;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::string answer;
    std::cin >> answer;

    Counter counter;

    if (answer == "да") {
        int initialValue;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
        counter = Counter(initialValue);
    }

    char command;
    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == '+') {
            counter.increment();
        } else if (command == '-') {
            counter.decrement();
        } else if (command == '=') {
            std::cout << counter.getValue() << std::endl;
        } else if (command == 'x') {
            std::cout << "До свидания!" << std::endl;
            break;
        } else {
            std::cout << "Неизвестная команда!" << std::endl;
        }
    }

    return 0;
}