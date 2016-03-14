/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>

char KthIndexFromEnd(char *str, int K) {
	if (str == NULL || K < 0)	//invalid inputs
		return '\0';
	int ind, pos;
	for (ind = 0; str[ind + 1] != '\0'&&ind < K; ind++){	//first moving K positions
		continue;
	}
	if (ind == K){					//checking K greater than the length or not
		pos = 0;
		for (; str[ind + 1] != '\0'; pos++, ind++){
			continue;
		}
		return str[pos];
	}
	return '\0';				//if greater than the length
}