#include <iostream>
#include <vector>

std::vector<int> Merge(std::vector<int>& a, std::vector<int>& b){ // Это функция сортирует и обьединяет 2 массива
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    
    while(i < a.size()){
        result.push_back(a[i]);
        i++;
    }
    
    while(j < b.size()){
        result.push_back(b[j]);
        j++;
    }
    
    return result;
}

void mergeSort(std::vector<int>& toSort){ // эта функция делит массив на две части по талого и потом вызывает на нее сортиовщик
    if(toSort.size() == 1) return;
    int mid = toSort.size()/2;
    std::vector<int> left(toSort.begin(), toSort.begin() + mid);
    std::vector<int> right(toSort.begin() + mid, toSort.end());
    
    mergeSort(left);
    mergeSort(right);
    
    toSort = Merge(left, right);
}

int main(){
    std::vector<int> myVector = {42, 17, 93, 8, 65, 23, 81, 39, 12, 54};
    mergeSort(myVector);
    for(int i = 0; i < myVector.size(); i++){
        std::cout << myVector[i] <<" ";
    }

}
//Простыми словам мы сначала делим большой массив на половину до талого пока можем делить
//Затем мы в функции Merge для каждой из пар каждого размера производим сортировку и конкатенацию
//Таким образом на выходе мы получаем отсортированный массив говна
//Выглядит дерьмово но быстрее чем Insert sort так-как этот алгос дает нам O(nLog(n)) time complexety