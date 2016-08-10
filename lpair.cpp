#include <bits/stdc++.h>
using namespace std;
struct point{
	long m;
	long f;
};

bool cmp(point &a,point &b){
	return a.m < b.m;
}
point p[(long)1e5+1];
long *a;
long  _mergeSort(long arr[], long temp[], long left, long right);
long merge(long arr[], long temp[], long left, long mid, long right);

long mergeSort(long arr[], long array_size){
    long *temp = (long *)malloc(sizeof(long)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
long _mergeSort(long arr[], long temp[], long left, long right){
  long mid, inv_count = 0;
  if (right > left){
    mid = (right + left)/2;
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

long merge(long arr[], long temp[], long left, long mid, long right){
  long i, j, k;
  long inv_count = 0;
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))  {
    if (arr[i] <= arr[j])  {
      temp[k++] = arr[i++];
    }
    else{
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
   while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  return inv_count;
}

int main(){
	long n;
	cin>>n;
	long m,f;
	for(long i=0;i<n;i++){
		cin>>m>>f;
		p[i].m=m;
		p[i].f=f;
	}
	sort(p,p+n,cmp);
  a=new long[n];
	for(long i=0;i<n;i++)
		a[i]=p[i].f;
	cout<<mergeSort(a,n)<<endl;
}
