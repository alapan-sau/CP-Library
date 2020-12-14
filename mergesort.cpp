#include<bits/stdc++.h>

using namespace std;



void merge(int arr[], int l, int m, int r){

    int l1 = m-l+1;
    int l2 = r-m;

    int L[l1];
    int R[l2];

    for(int i=l;i<=r;i++){
        if(i<=m){
            L[i-l] = arr[i];
        }
        else{
            R[i-m-1] = arr[i];
        }
    }

    int i=0, j=0,k=l;
    while(i<l1 && j<l2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<l1){
        arr[k] = L[i];
        i++;k++;
    }
    while(j<l2){
        arr[k] = R[j];
        j++;k++;
    }
}


int mergesort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);

        merge(arr, l, mid, r);
    }
    return 0;
}

int  main(){
    int arr[] = {1,2,5,3,8,4,7,8,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++) cout << arr[i] << " "; cout << endl;
    return 0;
}