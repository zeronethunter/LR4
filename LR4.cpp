#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void randomVec(std::vector<int>& vec1, int n) {
    vec1.clear();  //создаем рандомный вектор длины n
    for (int i = 0; i < n; i++) {
        vec1.push_back(std::rand() % 201 - 100);
    }
}

void print(const std::vector<int>& vec1, const std::string s) {
    for (int i : vec1) {  //вывод вектора
        std::cout << i << ' ';
    }
    std::cout << s << std::endl;
}

void Merge(std::vector<int>& vec, int left, int right) {
    int first_half = left;  // начало левой половины
    int second_half = (left + right) / 2 + 1; // начало правой половины
    std::vector<int> add_vec;
    for (int i = 0; i <= right - left; ++i) { // кол-во итераций = кол-ву элементов в кусочке
        if (first_half == (left + right) / 2 + 1) { //если закончились левые, то до конца добавляем правые
            add_vec.push_back(vec[second_half]);
            ++second_half;
        } else if (second_half > right) {  //если же закончились правые, то до конца добавляем левые
            add_vec.push_back(vec[first_half]);
            ++first_half;
        } else {
            if (vec[first_half] < vec[second_half]) { //если еще есть, то сравниваем правый и левый по возрастанию
                add_vec.push_back(vec[first_half]);
                ++first_half;
            } else {
                add_vec.push_back(vec[second_half]);
                ++second_half;
            }
        }
    }
    for (int i = 0; i <= right - left; ++i) { // все, что получилось кидаем в вектор с позиции left
        vec[left + i] = add_vec[i];
    }
}

void MergeSort(std::vector<int>& vec, int left, int right) {
    if (right == left) { //если один элемент - ничего не делаем
        return;
    } else if (right - left == 1) {  //если два элемента, то сравниваем их по возрастанию
        if (vec[right] < vec[left]) {
            std::swap(vec[right], vec[left]);
        }
        return;
    }
    MergeSort(vec, left, (right + left) / 2);  //смотрим половину слева
    MergeSort(vec, (right + left) / 2 + 1, right);  //половина справа
    Merge(vec, left, right);  //сортируем две группы (слияние)
}

void oddEvenSort(std::vector<int>& vec1) {
    int n = vec1.size();
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {  //для четных мест
            for (int j = 0; j <= n - 2; j += 2) {
                if (vec1[j] < vec1[j + 1]) {
                    std::swap(vec1[j], vec1[j + 1]);
                }
            }
        } else {             //для нечетных мест
            for (int j = 1; j <= n - 2; j += 2) {
                if (vec1[j] < vec1[j + 1]) {
                    std::swap(vec1[j], vec1[j + 1]);
                }
            }
        }
    }
}

void BitonicMerge(std::vector<int>& vec, int left, int right, bool flag) {
    if (right == left) { //слияние 1-го элемента не имеет смысла
        return;
    }
    for (int i = 0; i <= (right - left) / 2; ++i) {  //само слияние
        if (flag) {
            if (vec[left + i] > vec[(right + left) / 2 + i + 1]) {
                std::swap(vec[left + i], vec[(right + left) / 2 + i + 1]);
            }
        }
        else {
            if (vec[left + i] < vec[(right + left) / 2 + i + 1]) {
                std::swap(vec[left + i], vec[(right + left) / 2 + i + 1]);
            }
        }
    }
    BitonicMerge(vec, left, (right + left) / 2, flag);  //рекурсивно повторяем, как в алгоритме, пока не будет слияние 2-х элементов
    BitonicMerge(vec, (right + left) / 2 + 1, right, flag);
}

void BitonicSort(std::vector<int>& vec, int left, int right, const bool flag) {
    if (right == left) {  //если элемент один, то выходим, чтобы рассмотреть 2 элемента
        return;
    }
    BitonicSort(vec, left, (left + right) / 2, true);  //половина слева
    BitonicSort(vec, (left + right) / 2 + 1, right, false);  //половина справа
    BitonicMerge(vec, left, right, flag);  //рекурсивное слияние
}

int main() {
    std::string sout = "This is your sorted vector";
    std::string sin = "This is your unsorted vector";
    std::cout << "LR4 - Func_Use" << std::endl;


    std::srand(std::time(nullptr));
    std::vector<int> vec1(30);


    randomVec(vec1, 30);
    print(vec1, sin);
    oddEvenSort(vec1);           //oddEvenSort - 1 task
    print(vec1, sout);


    randomVec(vec1, 30);
    print(vec1, sin);
    MergeSort(vec1, 0, 29);             //MergeSort - 2 task
    print(vec1, sout);

    randomVec(vec1, 16);
    print(vec1, sin);
    BitonicSort(vec1, 0, 15, 1);             //BitonicSort - 3 task
    print(vec1, sout);


    return 0;
}
