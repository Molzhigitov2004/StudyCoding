#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> myVector = {42, 17, 93, 8, 65, 23, 81, 39, 12, 54};
    std::vector<int> Sorted(myVector.size());
    
    int MinVal = myVector[0];
    int MaxVal = myVector[0];
    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i] < MinVal) MinVal = myVector[i];
        if(myVector[i] > MaxVal) MaxVal = myVector[i];
    }
    std::vector<int> FrequencyArray((MaxVal - MinVal + 1), 0);
        
    for(int i = 0; i < myVector.size(); i++){
        FrequencyArray[myVector[i] - MinVal]++;
    }
    
    int carry = 0;
    for(int i = 0; i < FrequencyArray.size(); i++){
        carry = carry + FrequencyArray[i];
        FrequencyArray[i] = carry;
    }
    
    for(int i = myVector.size()-1; i >= 0; i--){
        Sorted[--FrequencyArray[myVector[i]-MinVal]] = myVector[i];
    }
    
    
    for(int i = 0; i < Sorted.size(); i++){
        std::cout<< Sorted[i] <<" ";
    }
}



//Time Complexety is O(N+K) Stable Sorting Algorithm
//Потому что в отличии от других алгоритмов сортировки этот не сравнивает элементы между собою
//Но он не заменил наш любимый QuickSort так-как:
//Он работает только с integer value или другими дискретными дататипами
//Ему становиться хуево когда Range большой
//Плюс мы выделяем доп место под все дело
//Алгоритм в целом прикольный
//Сначала мы создаем массив для сортиованных элементов
//Затем мы находим наибольшее и наименьшее значения 
//Создаем Frequency Array и заполняем его 
//Далее траверсимся с конца изначального массива
//И на вставляем значения в сортированный массив вот-так
//Сортированный массив[--Массив Частот[Оригинальный массив[i с конца]]]