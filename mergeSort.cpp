#include <bits/stdc++.h>
using namespace std;

void marge(int *arr,int *arr2,int low,int mid,int hight);

void mergeSort(int *arr,int *arr2,int low,int hight){
    int mid;
    if( low < hight){
        mid = (low + high) / 2;
        mergeSort(arr,arr2,low,mid);
        mergeSort(arr,arr2,mid+1,hight);
        marge(arr,arr2,low,mid,hight);
    }
}

void merge(int *a,int *b,int low,int mid,int high)
{
     long h,i,j,k,count=0;
     h=low;
     i=low;
     j=mid+1;

     while((h<=mid)&&(j<=high))
     {
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
     }

    if(h>mid){
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }else{
        for(k=h;k<=mid;k++){
            b[i]=a[k];
            i++;
        }
     }
     for(k=low;k<=high;k++) a[k]=b[k];

}
int main(){
    int num;
    cout << "How many numbers do you want to sort: ";
    cin >> num;
    int a[num];
    int b[num];
    for (int i = 0; i < num; i++) {
        cout << (i + 1) << ": ";
        cin >> a[i];
    }

  // Start merge sort
  mergeSort(a, b, 0, num - 1);

    // Print the sorted array
    cout << endl;
    for (int i = 0; i < num; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
