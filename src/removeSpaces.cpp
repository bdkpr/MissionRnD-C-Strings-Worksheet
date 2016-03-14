/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>

char removeSpaces(char *str) {
	if (str==NULL)			//validate
		return '\0';
	int i, j;
	for (i = 0, j = 0; str[i] != '\0'; i++){
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
			continue;
		}
		else{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}