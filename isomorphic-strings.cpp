/*
Two strings str1 and str2 are called isomorphic if there is a one-to-one mapping possible 
for every character of str1 to every character of str2. 
And all occurrences of every character in ‘str1’ map to the same character in ‘str2’.

Input:  str1 = “aab”, str2 = “xxy”
Output: True
Explanation: ‘a’ is mapped to ‘x’ and ‘b’ is mapped to ‘y’.

Input:  str1 = “aab”, str2 = “xyz”
Output: False
Explanation: One occurrence of ‘a’ in str1 has ‘x’ in str2 and other occurrence of ‘a’ has ‘y’.
*/

// C++ program to check if two strings are isomorphic
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// This function returns true if str1 and str2 are
// isomorphic
bool areIsomorphic(string str1, string str2)
{

	int m = str1.length(), n = str2.length();

	// Length of both strings must be same for one to one
	// correspondence
	if (m != n)
		return false;

	// To mark visited characters in str2
	bool marked[MAX_CHARS] = { false };

	// To store mapping of every character from str1 to
	// that of str2. Initialize all entries of map as -1.
	int map[MAX_CHARS];
	memset(map, -1, sizeof(map));

	// Process all characters one by one
	for (int i = 0; i < n; i++) {
		// If current character of str1 is seen first
		// time in it.
		if (map[str1[i]] == -1) {
			// If current character of str2 is already
			// seen, one to one mapping not possible
			if (marked[str2[i]] == true)
				return false;

			// Mark current character of str2 as visited
			marked[str2[i]] = true;

			// Store mapping of current characters
			map[str1[i]] = str2[i];
		}

		// If this is not first appearance of current
		// character in str1, then check if previous
		// appearance mapped to same character of str2
		else if (map[str1[i]] != str2[i])
			return false;
	}

	return true;
}

// Driver program
int main()
{
	cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
		<< endl;
	return 0;
}
