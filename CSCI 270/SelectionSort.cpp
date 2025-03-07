#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {42, 17, 93, 8, 65, 23, 81, 39, 12, 54};
    
    for(int i = 0; i < myVector.size(); i++){
        int Minimum = i;
        int j = i;
        while(j < myVector.size()){
            if(myVector[j] < myVector[Minimum]) Minimum = j;
            j++;
        }
        int temp = myVector[i];
        myVector[i] = myVector[Minimum];
        myVector[Minimum] = temp;
    }
    
    for(int i = 0; i < myVector.size(); i++){
        std::cout<< myVector[i] <<" ";
    }
}

//Это наитупейший алгоритм для сортировки
//Простыми словами есть сортированная часть и несортированная часть
//Разделяет их основной цикл своим индексом i
//Каждый раз мы ищем минимальное значение в неосортированной части и ебашим
//К концу сортированной простой заменой чисел
//O(n^2) также как и инсершни сорт
//Работает лучше если массив нихуя не сортирован