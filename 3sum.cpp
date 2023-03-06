/*Explanation:

step 1: sort the array.

 

step 2: start with i = 0 and for every value of i, keep track of two indices left and right.

 

step 3: check if sum == K or sum < K or sum > K and increment or decrement your left and right indices accordingly.

 

step 4: After finding the triplet in step 3, make sure no two adjacent elements are equal i.e arr[left] == arr[left + 1] and arr[right] == arr[right -1].
*/

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;

	sort(arr.begin(), arr.end());

	for(int i = 0; i < n - 2; i++)
	{
		/* This condition checks whether previous element which i was at is equal 
		 to the current element where i is now */
		
		if(i > 0 && arr[i] == arr[i - 1])
		   continue;
        
		// setting up left and right 
		int left = i + 1;
		int right = n - 1;

		// Traversing the array using left and right
		while(left < right)
		{
			int sum = arr[i] + arr[left] + arr[right];

			if(sum == K)
			{
                          ans.push_back({arr[i], arr[left], arr[right]});

                          /* These below two while loops check that for a
                          particular value of  i  no two adjacent values of left
                          and right are equal. we prevent the repeating triplets
                          because of these loops and the initial condition of
                          continue when i>0 and arr[i] == arr[i+1]*/

                          while (left < right && arr[left] == arr[left + 1]) {
                            left++;
				}

				while(left < right && arr[right] == arr[right - 1])
				{
					right--;
				}

				left++;
				right--;
			}
			else if(sum < K)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return ans;
}
