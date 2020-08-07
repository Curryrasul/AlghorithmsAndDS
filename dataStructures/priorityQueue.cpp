// Очередь с приоритетом (реализация с числами)

// Структура данных, в которой данные упорядоченны (представлены в виде бинарной кучи)
// (например, приоритет в данном случае - это значение числа). То есть данная структура позволяет 
// доставать максимальный элемент за O(1). Добавление и удаление элемента выполняется за O(log(N))
// Очередь с приоритетом часто реализуют на основе бинарной кучи (смотреть sortAlgs/heapSort.cpp)
// Если какие - то методы не описаны, то смотрите на реализации прошлых структур.

#include <iostream>

// Функция так же взята из sortAlgs/heapSort.cpp
void heapify(int *arr, int i, int n) {
    while(1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int j = i;

        if (l < n && arr[i] < arr[l]) {
            i = l;
        }
        if (r < n && arr[i] < arr[r]) {
            i = r;
        }
        if (i == j) {
            break;
        }
        std::swap(arr[i], arr[j]);
    }
}

class PriorityQueue {
public:
    // Инициализируем
    PriorityQueue(const int len = 0) {
        this->cap = len;
        this->count = 0;
        this->heap = new int[len];
    }

    // Проверка на пустоту
    bool isEmpty() const{
        return this->count == 0;
    }

    void insert(int elem) {
        // Если полон, то расширяем
        if (isFull()) {
            int tempArr[this->count];
            
            for (int i = 0; i < this->count; i++) {
                tempArr[i] = this->heap[i];
            }
            
            this->cap += 10;
            
            delete[] this->heap;
            this->heap = new int[this->cap];
            
            for (int i = 0; i < this->count; i++) {
                this->heap[i] = tempArr[i];
            }
        }
        int i = this->count++;
        // Сначала добавляем элемент в конец
        this->heap[i] = elem;
        // Затем поднимаем его вверх , если он превосходит своих родителей.
        while(i > 0 && this->heap[(i - 1) / 2] < this->heap[i]) {
            std::swap(this->heap[(i - 1) / 2], this->heap[i]);
            i = (i - 1) / 2;
        }
    }

    // Удаление максимального элемента ( сложность O(lg(n)), т.к надо вызывать heapify())
    int extractMax() {
        if (isEmpty()) {
            return 0;
        }
        // Элемент на позиции 0 - максимальный , его значение вернем в конце функции
        int temp = this->heap[0];
        this->count--;
        if (this->count > 0) {
            // Ставим последний элемент на первое место
            this->heap[0] = this->heap[this->count];
            // Затем вызываем для него heapify()
            heapify(this->heap, 0, this->count);
        }
        return temp;
    }

    ~PriorityQueue() {
        delete[] this->heap;
    }

private:
    int *heap;
    int cap, count;

    bool isFull() const {
        return this->count == this->cap;
    }
};

// Демонстрация работы
int main() {
    PriorityQueue p;
    p.insert(1);
    p.insert(-5);
    p.insert(16);
    p.insert(34);
    p.insert(27);
    p.insert(100);
    while (!(p.isEmpty())) {
        std::cout << p.extractMax() << "\n";
    }
    return 0;
}