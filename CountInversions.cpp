/*http://a2oj.com/Status.jsp?Username=20120062&ID=367*/
#include <bits/stdc++.h>
using namespace std;
/*
 long merge(long  *arr,long *arr2,long ,long ,long);

long mergeSort(long  *arr,long *arr2,long low,long high)
{
 long  mid,count=0;
 if(high<=low) return 0;

    mid = low + (high-low)/2;
    count += mergeSort(arr,arr2,low,mid);
    count += mergeSort(arr,arr2,mid+1,high);
    count += merge(arr,arr2,low,mid,high);

    return count;
}
long merge(long *a,long *b,long low,long mid,long high)
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
            count += (mid-i+1);
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

    return count;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        long num;
        cin >> num;
        long a[num];
        long b[num];
        for (long i = 0; i < num; i++) {
            cin >> a[i];
        }

        long count = mergeSort(a, b, 0, num - 1);

        cout << count << endl;
    }
    return 0;
}*/


long long merge(long arr[], long temp[], long left, long mid, long right);

long long mergeSort(long arr[], long temp[], long left, long right)
{
  long mid;
  long long count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    count  = mergeSort(arr, temp, left, mid);
    count += mergeSort(arr, temp, mid+1, right);
    count += merge(arr, temp, left, mid+1, right);
  }
  return count;
}

long long merge(long arr[], long temp[], long left, long mid, long right)
{
  long i, j, k;
  long long count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];


      count += (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return count;
}

int main()
{
    long long T;
    cin >> T;
    while(T--){
        int num;
        cin >> num;
        long a[num];
        long b[num];
        for (long i = 0; i < num; i++) {
            cin >> a[i];
        }

    long long count = mergeSort(a, b, 0, num - 1);

    cout << count << endl;
    }
    return 0;
}

