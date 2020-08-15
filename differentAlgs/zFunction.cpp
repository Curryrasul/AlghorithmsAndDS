/*
    Данный алгоритм позволяет находить z-функцию за O(n). 
    z функция нужна для нахождения подстрок в строке за линейное время.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Принимаем строку - возваращем z-функцию строки
vector<int> findZFunc(const string& s) {
    // Длина строки
    int n = s.size();
    
    // Возвращаемый вектор
    vector<int> zFunc(n, 0);
    // Два указателя на z-блок
    int l = 0;
    int r = 0;

    // Начинаем с единицы , т.к zFunc[0] по определению равен 0
    for (int i = 1; i < n; i++) {
        // Если наш индекс входит в z блок
        // (Z блок - это суффикс , который совпадает с префиксом),
        // то выбираем минимум из zFunc[i - l] (это уже посчитанной zFunc и при этом
        // s[i - l] == s[i]). Но может быть такое, что z функция в индексе i будет уже идти дальше
        // границы z блока, поэтому просто в таком случае дадим ей максимально возможное значение
        // А наивным алгоритмом далее увеличим до нужного значения.
        if (r >= i) {
            zFunc[i] = min(zFunc[i - l], r - i + 1);
        }
        // Наивным методом увеличиваем zFunc[i]
        while (zFunc[i] + i < n && s[zFunc[i]] == s[zFunc[i] + i]) {
            zFunc[i]++;
        }
        // Расширяем границы, если текущий zFunc[i] != 0, или же мы уже и так не в конце
        if (i + zFunc[i] - 1 > r) {
            l = i;
            r = i + zFunc[i] - 1;
        }
    }

    return zFunc;
}

int main() {
    string s;
    cin >> s;
    for (int i : findZFunc(s)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}