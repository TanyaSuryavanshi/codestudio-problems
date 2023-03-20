#include <bits/stdc++.h> 
bool checkPalindrome(long long N)
{
	vector<int> arr;
  	while (N > 0) {
    	if (N & 1) {
      		arr.push_back(1);
    	}
		else {
      		arr.push_back(0);
   	 	}
    	N = N >> 1;
  	}
  	int start = 0;
  	int end = arr.size() - 1;
	while (start <= end) {
	    if (arr[start] != arr[end]) {
	      return 0;
    	}
		else{
    	start++;
    	end--;
  		}
	}
	return 1;
	
}
