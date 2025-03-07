#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {42, 17, 93, 8, 65, 23, 81, 39, 12, 54};
    
    
    for(int i = 0; i < myVector.size(); i++){
        int j = i;
        while(j > 0 && myVector[j-1] > myVector[j]){
            int temp = myVector[j];
            myVector[j] = myVector[j-1];
            myVector[j-1] = temp;
            j--;
        }
    }
    
    for(int i = 0; i < myVector.size(); i++){
        std::cout<< myVector[i] <<" ";
    }
}

//Простыми словами
//Идем по массиву и если видим что данный элемент меньше предыдущего мы их 
//свапаем внутренним циклом до тех пор пока элемент не встанет на свое место.
//O(n^2)
//Работает лучше чем Selection Sort если массив частично сортирован
