#include <iostream>
using namespace std;

template <typename tmplt>  void InsertionSort(tmplt *arr,int n){

    for(int i=2; i < n; ++i){
        tmplt key = arr[i];
        int j = i-1;
        while( j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
            arr[j+1] = key;
    }
}

int main(){

    char arr[] = {'a','b','f','c','g','h','d','e','j','i'};

    InsertionSort(arr,10);
    for(int i=0; i < 10; ++i){
        cout << arr[i] << " " ;
    }
    cout << endl;
    int arr1[] = {9,2,1,4,6,5,7,8,3,0};

    InsertionSort(arr1,10);
    for(int i=0; i < 10; ++i){
        cout << arr1[i] << " " ;
    }

    return 0;
}
/*
    run time = log(n^2)
    efficient in small data than merge sort
*/
