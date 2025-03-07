#include <iostream>
#include <vector>
int Partition(std::vector<int>& array, int low, int high){
    int pivot = array[low];
    int i = low;
    int j = high;
    while(i < j){
        do{
            i++;
        }while(array[i] < pivot && i < high); // array[i] > pivot for Descending
        do{
            j--;
        }while(array[j] > pivot && j > low); // array[i] < pivot for Descending
        if(i < j){
        std::swap(array[i], array[j]);
        }
    }
    std::swap(array[low], array[j]);
    return j;
}

void QuickSort(std::vector<int>& array, int low, int high){
    if(low < high){ //base case restrictor
        int pivot = Partition(array, low, high);
        QuickSort(array, low, pivot);
        QuickSort(array, pivot+1, high);
    }
}



int main() {
    std::vector<int> myVector = {42, 17, 93, 8, 65, 23, 81, 39, 12, 54};
    
    QuickSort(myVector, 0, myVector.size());
    
    for(int i = 0; i < myVector.size(); i++){
        std::cout<< myVector[i] <<" ";
    }
}

//https://www.youtube.com/watch?v=7h1s2SojIRw&ab_channel=AbdulBari Тут обьяснение в видео
//Time Complexety is Theta(nlogn) and O(n^2)
//Простыми словами выбирая точку пивот мы стремимся отсортировать конкретно ее
//Это значит что все значения справа больше,  а слева меньше
//Для этого мы сначала выбираем пивот, в данном коде значение слева
//Затем i идет слева направо пока не найдет значение больше пивота
//j идет справа налево пока не найдет значение меньше пивота
//Затем они свапаются. В моменте когда i > j мы устанавливаем значения пивота на j
//Потому что j теперь показывает на место пивота в массиве
//Затем мы рекурсивно делаем то на части слева и справа от пивота
//Слева это low -> pivot
//Справа это pivot+1 -> high
//В конце получаем сортированный массив
//Плюсы этого алгоритма в том что он
//Не требует доп места(in place)
//В рандомных массивах быстрее чем MergeSort
//несмотря на то что ворст кейс тут хуже

