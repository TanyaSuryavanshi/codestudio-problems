#include <bits/stdc++.h> 
#include <vector>
void sort012(int *arr, int n)
{
int c0 = 0;

int c1 = 0;

int c2 = 0;

for(int i = 0; i < n; i++){

if(arr[i] == 0){

c0++;

}

if(arr[i] == 1){

c1++;

} else {

c2++;

}

}

for(int i = 0; i<n; i++){

if (c0) {

arr[i] = 0;

c0--;

} else if (c1) {

arr[i] = 1;

c1--;

} else {

arr[i] = 2;

c2--;

}

}


}
