/*http://a2oj.com/Status.jsp?Username=20120062&ID=368*/
#include <bits/stdc++.h>
using namespace std;


long long count1 =0;
long long count2 =0;
long long count3 =0;


long long Partition(long long*a, long long l,long long r) {
		long long p=a[l];
		long long i =l+1;

		for(long long  j=l+1;j<=r;j++){
			if(a[j]<p){
				swap(a[j],a[i]);
				i++;
			}
		}
		swap(a[l], a[i-1]);
		return (i-1);
	}

void QuickSort(long long * a, long long l, long long r) {
		long long pivot;
		if(r>l){
		count1 += (r-l);
		pivot = Partition(a,l,r);

		QuickSort(a, l, pivot-1);
		QuickSort(a, pivot+1, r);
		}
}

/*
void QuickSort1(long long *arr,long long size){
    if(size <= 1)
        return;

    count1+=size-1;
    long long pivot = arr[0];
    long long low = 0;
    long long last = size-1;
    while(low < last){
        while(arr[low] < pivot){
            low++;
        }
        while(arr[last] > pivot){
            last--;
        }

        swap(arr[low] , arr[last]);
    }

    QuickSort1(arr,low);
    QuickSort1(&(arr[low + 1]), size - low - 1);
}

void QuickSort2(long long *arr,long long size){
    if(size <= 1)
        return;

    count2+=size-1;
    long long  pivot = arr[size-1];
    long long  low = 0;
    long long  last = size-1;
    while(low < last){
        while(arr[low] < pivot){
            low++;
        }
        while(arr[last] > pivot){
            last--;
        }

        swap(arr[low] , arr[last]);
    }

    QuickSort2(arr,low);
    QuickSort2(&(arr[low + 1]), size - low - 1);
}


void QuickSort3(long long *arr,long long size){
    if(size <= 1)
        return;
    count3+=size-1;
    long long median[3];
    median[0] = arr[0];
    median[1] = arr[(0+size-1)/2];
    median[2] = arr[size-1];
    sort(median,median+3);

    long long  pivot = median[1];
    long long  low = 0;
    long long  last = size-1;
    while(low < last){
        while(arr[low] < pivot){
            low++;
        }
        while(arr[last] > pivot){
            last--;
        }

        swap(arr[low] , arr[last]);
    }

    QuickSort3(arr,low);
    QuickSort3(&(arr[low + 1]), size - low - 1);
}*/

int main(){

/*    int arr[3] = {1,2,3};
    QuickSort1(arr,3);
    for(int i=0; i < 3; ++i)
        cout << arr[i]  << " ";
    cout << endl;
    cout << count1 << endl;
*/

    long long  T;
    cin >> T;
    while(T--){
        long long  n;
        cin >> n;
        long long  arr[n];
        for(long long  i=0; i < n; ++i){
            cin >> arr[i];
        }
        long long  arr1[n];
        for(long long  i=0; i < n; ++i){
            arr1[i] = arr[i];
        }
        long long  arr2[n];
        for(int i=0; i < n; ++i){
            arr2[i] = arr[i];
        }

        QuickSort(arr,0,n-1);
//        QuickSort2(arr1,n);
//      QuickSort3(arr2,n);
        /*for(int i=0 ;i < n; ++i){
            cout << arr1[i] << " ";
        }*/
        cout << count1 << " " << count2 << " " << count3 << endl;
        count1=0;
        count2=0;
        count3=0;

    }
    return 0;
}
