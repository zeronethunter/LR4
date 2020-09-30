#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
std::vector<int> randomVec(std::vector<int>& vec1, int n){
    for(int i = 0; i <= n-1; i++){
        vec1[i] = (std::rand()%201 - 100);
    }
    return vec1;
}
void print(std::vector<int>& vec1, std::string s){
    for(int i: vec1){
        std::cout << i << ' ';
    }
    std::cout << s << std::endl;
}
void swapWithIf(std::vector<int>& vec1, int i, int j, int dir)
{
    if (dir==(vec1[i]>vec1[j]))
        std::swap(vec1[i],vec1[j]);
}
void bitonicMerge(std::vector<int>& vec1, int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        for (int i=low; i<low+k; i++)
            swapWithIf(vec1, i, i+k, dir);
        bitonicMerge(vec1, low, k, dir);
        bitonicMerge(vec1, low+k, k, dir);
    }
}
void bitonicSort(std::vector<int>& vec1,int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;

        bitonicSort(vec1, low, k, 1);
        bitonicSort(vec1, low+k, k, 0);
        bitonicMerge(vec1,low, cnt, dir);
    }
}
std::vector<int> oddEvenSort(std::vector<int>& vec1, int n){
    bool isSort = false;
    while(isSort!=true){
        isSort = true;
        for(int i=1; i <= n-2; i+=2){
            if(vec1[i] > vec1[i+1]){
                std::swap(vec1[i], vec1[i+1]);
                isSort = false;
            }
        for(int i =0; i<= n-2; i+=2){
            if(vec1[i] > vec1[i+1]){
                std::swap(vec1[i], vec1[i+1]);
                isSort = false;
            }
        }
        }
    }
  return vec1;
}
std::vector<int> MergeIt(std::vector<int>& vec1, int l, int m,  int r){
    int i, j ,k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    for(i = 0; i < nl; i++)
        larr[i] = vec1[l+i];
    for(j = 0; j < nr; j++)
        rarr[j] = vec1[m+1+j];
    i = 0; j = 0; k = l;
    while((i < nl) && (j < nr)) {
        if(larr[i] <= rarr[j]) {
            vec1[k] = larr[i];
            i++;
        }else{
            vec1[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        vec1[k] = larr[i];
        i++;
        k++;
    }
    while(j<nr) {
        vec1[k] = rarr[j];
        j++;
        k++;
    }
    return vec1;
}
void MergeSort(std::vector<int>& vec1, int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;
        MergeSort(vec1, l, m);
        MergeSort(vec1, m+1, r);
        MergeIt(vec1, l, m, r);
    }
}
int main(){
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
    randomVec(vec1, 32);
    print(vec1, sin);
    bitonicSort(vec1,0, 32, 1);  //bitonicSort - 3 task
    print(vec1, sout);
    return 0;
}
