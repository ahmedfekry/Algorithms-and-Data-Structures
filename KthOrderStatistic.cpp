/*http://a2oj.com/Status.jsp?Username=20120062&ID=369*/
#include <bits/stdc++.h>
using namespace std;

long long m_w=0 ,m_z=0 ,T=0 ,K ,N;
int get_random()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 1000000000;
}

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

long long quick_sort(long long arr[],long long l, long long r, long long k)
{

    if (k > 0 && k <= r - l + 1)
    {

        long long pivot = Partition(arr, l, r);

        if (pivot-l == k-1)
            return arr[pivot];
        if (pivot-l > k-1)
            return quick_sort(arr, l, pivot-1, k);

        return quick_sort(arr, pivot+1, r, k-pivot+l-1);
    }
}


int main()
{
    cin>>T;
    while(T--){
        cin>>N>> K>> m_w>> m_z;
        long long *arr = new long long [N];
        for(long long j=0; j<N; j++){
            arr[j]=get_random();
        }
        long long left=0, right=N-1;
        cout<<quick_sort(arr,left, right,K)<<endl;

    }




}
