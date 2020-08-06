// Реализация стека целых чисел

// В C++ уже есть реализации данной структуры, и не стоит использовать данный код
// для реализаций чего-либо.

#include <iostream>
#include <cstdlib>

class MyStack {

// Стек работает по принципу LIFO (Last In First Out)

public:
    // Конструктор, по умолчанию вместимость стека нулевая.
    MyStack(const int len = 0) {
        this->cap = len;
        this->data = new int[len];
        this->top = 0;
    }

    // Проверка на пустоту
    bool isEmpty() const{
        return this->top == 0;
    }

    // Если места не хватает создаем новый массив и в него копируем содержимое старого
    void push(const int elem) {
        if (isFull()) {
            int tempArr[this->top];
            
            for (int i = 0; i < this->top; i++) {
                tempArr[i] = this->data[i];
            }
            
            this->cap += 10;
            
            delete[] this->data;
            this->data = new int[this->cap];
            
            for (int i = 0; i < this->top; i++) {
                this->data[i] = tempArr[i];
            }
        }

        this->data[this->top] = elem;
        this->top++;
    }

    // Вытащить последний элемент
    int pop() {
        if (!isEmpty()) {
            this->top--;
            return this->data[this->top];
        }
        return 0;
    }

    // Удаляем выделенный массив
    ~MyStack() {
        delete[] this->data;
    }

private:
    // Целочисленный массив
    int *data;
    // cap - вместимость, top индекс указывающий на следующий элемент.
    int cap, top;

    // Проверка на полноту
    bool isFull() const {
        return this->top == this->cap;
    }
};

// Демонстрация
int main() {
    MyStack stack;
    stack.push(10);
    stack.push(15);
    stack.push(30);
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << "\n";
    }
    return 0;
}