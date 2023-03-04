#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{/* correct but not optimized
	vector<int> inter;
	for(int i=0;i<n;i++){
		int element=arr1[i];
		for(int j=0;j<m;j++){
			if(element < arr2[j])
				break;
            if (element == arr2[j]) {
                inter.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
	}
	return inter;
	//for same value in both to avoid considering same 
value arr2 value is marked as min.
*/

	int i=0,j=0;
	vector<int> inter;
	while(i<n && j<m){
		if(arr1[i]==arr2[j]){
			inter.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j])
		{
			i++;
        } 
		else{
            j++;
        }
    }
	return inter;
}
