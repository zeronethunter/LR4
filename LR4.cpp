#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
void randomVec(std::vector<int>& vec1, int n) {
    vec1.clear();  //создаем рандомный вектор длины n
    vec1.resize(n);
    for (int i = 0; i < n; i++) {
        vec1[i] = (std::rand() % 201 - 100);
    }
}
void print(const std::vector<int>& vec1, const std::string s) {
    for (int i : vec1) {  //вывод вектора
        std::cout << i << ' ';
    }
    std::cout << s << std::endl;
}

void Merge(std::vector<int>& vec, int left, int right) {
    std::vector<int> new_vec(vec.begin() + left, vec.begin() + right + 1);
    for (int i = left; i <= right; i++)  //само слияние с сортировкой
    {
        vec[i] = *std::min_element(new_vec.begin(), new_vec.end());
        new_vec.erase(std::min_element(new_vec.begin(), new_vec.end()));
    }
}

void MergeSort(std::vector<int>& vec, int left, int right) {
    if (right - left < 1) {
        return;
    }
    MergeSort(vec, left, (right + left) / 2);  //смотрим половину слева
    MergeSort(vec, (right + left) / 2 + 1, right);  //половина справа
    Merge(vec, left, right);  //сортируем две группы (слияние)
}
void oddEvenSort(std::vector<int>& vec1, int n) {
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {  //для четных мест
            for (int j = 0; j <= n - 2; j += 2) {
                if (vec1[j] < vec1[j + 1]) {
                    std::swap(vec1[j], vec1[j + 1]);
                }
            }
        }
        else {  //для нечетных мест
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

void BitonicSort(std::vector<int>& vec, int left, int right, const bool flag, int true_right) {
    if (right == left) {  //если элемент один, то выходим, чтобы рассмотреть 2 элемента
        return;
    }
    BitonicSort(vec, left, (left + right) / 2, true, true_right);  //половина слева
    BitonicSort(vec, (left + right) / 2 + 1, right, false, true_right);  //половина справа
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
    oddEvenSort(vec1, 30);           //oddEvenSort - 1 task
    print(vec1, sout);


    randomVec(vec1, 30);
    print(vec1, sin);
    MergeSort(vec1, 0, 29);             //MergeSort - 2 task
    print(vec1, sout);

    randomVec(vec1, 16);
    print(vec1, sin);
    BitonicSort(vec1, 0, 15, 1, 15);             //BitonicSort - 3 task
    print(vec1, sout);


    return 0;
}
