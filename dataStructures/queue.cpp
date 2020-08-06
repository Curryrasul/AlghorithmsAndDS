// Очередь целых чисел

// Реализация почти такая же как стек, но некоторые методы различаются, т.к очередь работает по
// принципу FIFO (First in First Out)

#include <iostream>
#include <cstdlib>

class MyQueue {

public:
    // Конструктор, по умолчанию вместимость стека нулевая.
    MyQueue(const int len = 0) {
        this->cap = len;
        this->data = new int[len];
        this->tail = 0;
        this->head = 0;
        this->count = 0;
    }

    // Проверка на пустоту
    bool isEmpty() const{
        return this->count == 0;
    }

    // Если места не хватает создаем новый массив и в него копируем содержимое старого
    void enqueue(const int elem) {
        if (isFull()) {
            int tempArr[this->count];
            
            for (int i = 0; i < this->count; i++) {
                tempArr[i] = this->data[i];
            }
            
            this->cap += 10;
            
            delete[] this->data;
            this->data = new int[this->cap];
            
            for (int i = 0; i < this->count; i++) {
                this->data[i] = tempArr[i];
            }
        }

        this->data[this->tail] = elem;
        this->tail++;
        this->count++;
    }

    // Вытащить последний элемент
    int dequeue() {
        if (!isEmpty()) {
            this->count--;
            return this->data[this->head++];
        }
        return 0;
    }

    // Удаляем выделенный массив
    ~MyQueue() {
        delete[] this->data;
    }

private:
    // Целочисленный массив
    int *data;
    // cap - вместимость, top индекс указывающий куда класть элемент, head откуда его удалять.
    // count - количество элементов
    int cap, tail, head, count;

    // Проверка на полноту
    bool isFull() const {
        return this->count == this->cap;
    }
};

// Демонстрация
int main() {
    MyQueue queue;
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(30);
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << "\n";
    }
    return 0;
}