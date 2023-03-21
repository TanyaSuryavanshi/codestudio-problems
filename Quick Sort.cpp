#include <bits/stdc++.h> 

int partition(vector<int>& arr , int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quicks(vector<int>& arr,int s,int e){
    int p;
    if (s < e) {
    
    p = partition(arr, s, e);
    quicks(arr, s, p-1);
    quicks(arr, p + 1, e);
}
}
vector<int> quickSort(vector<int> arr)
{
    int n=arr.size();
    quicks(arr,0,n-1);
    return arr;
    
}
//sc=O(n)
//average time complexity of O(n log n).
//worst case time complexity of O(n^2)
