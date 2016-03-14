/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>

void reverse(char *, int, int);

void str_words_in_rev(char *input, int len){
	if (input != NULL || len > 0){		//validity
		reverse(input, 0, len - 1);
		int i,strt_ind=0,end_ind=1,flag=1;
		for (i = 0; input[i] != '\0'; i++){
			if ((input[i] == ' ' || input[i] == '\t' || input[i] == '\n')&&strt_ind!=end_ind){
				end_ind = i - 1;
				reverse(input, strt_ind, end_ind);
				strt_ind = i + 1;
				flag = 0;
			}
		}
		reverse(input, strt_ind, i - 1);		//reversing the last word
	}
}
void reverse(char *str, int first, int last){
	for (char temp_ch; first < last; first++, last--){
		temp_ch = str[first];
		str[first] = str[last];
		str[last] = temp_ch;
	}
}