/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>
#define SIZE 31
int words_generator(char *,char **);
int is_same(char *, char *);
void add_word(char **, char *,int *);
int isnew_Word(char **, char *,int);

char ** commonWords(char *str1, char *str2) {
	if (str1==NULL||str2==NULL)
		return NULL;
	int str1_w_count, str2_w_count,ind_1,ind_2,ind,count=0;

	char **str1_words, **str2_words, **res_words;
	str1_words = (char **)malloc(10 * sizeof(char *));
	str2_words = (char **)malloc(10 * sizeof(char *));
	res_words = (char **)malloc(10 * sizeof(char *));
	for (ind_1 = 0; ind_1 < 10; ind_1++){
		str1_words[ind_1] = (char *)malloc(31 * sizeof(char));
		str2_words[ind_1] = (char *)malloc(31 * sizeof(char));
		res_words[ind_1] = (char *)malloc(31 * sizeof(char));
	}
	
	str1_w_count = words_generator(str1,str1_words);
	str2_w_count = words_generator(str2,str2_words);
	
	if (str1_w_count > 0 && str2_w_count > 0){
		for (ind_1 = 0; ind_1 < str1_w_count; ind_1++){
			for (ind_2 = 0; ind_2 < str2_w_count; ind_2++){
				if (is_same(str1_words[ind_1], str2_words[ind_2])){
					add_word(res_words, str1_words[ind_1],&count);
				}
			}
		}
		if (count>0)
			return res_words;
		else
			return NULL;
	}
	else{
		return NULL;
	}
}
int words_generator(char *str, char **res){
	int i, j,wd_c=0;
	char word[31];
	for (i = 0, j = 0; str[i] != '\0'; i++){
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' || str[i] == '.'){
			word[j] = '\0';
			if (isnew_Word(res, word,wd_c)){
				add_word(res, word,&wd_c);
			}
			j = 0;
		}
		else{
			word[j++] = str[i];
		}
	}
		word[j] = '\0';
		if (isnew_Word(res, word, wd_c)){
			add_word(res, word, &wd_c);
		}
	return wd_c;
}
int isnew_Word(char **res, char *word, int n){
	for (int i = 0; i < n; i++){
		if (is_same(res[i], word)){
			return 0;
		}
	}
	return 1;
}
int is_same(char *str1, char *str2){
	int i, f = 1;
	for (i = 0; str1[i] != '\0'&&str2[i] != '\0'; i++){
		if (str1[i] != str2[i]){
			return 0;
		}
	}
	if (str1[i] == '\0'&&str2[i] == '\0'){
		return 1;
	}
	else{
		return 0;
	}
}
void add_word(char **res, char *wrd, int *n){
	int f = 0,i;
	res[*n] = (char *)malloc(31 * sizeof(char));
	for (i = 0; wrd[i] != '\0'; i++){
		res[*n][i] = wrd[i];
		f = 1;
	}
	if (f == 1){
		res[*n][i] = '\0';
		(*n)++;
	}
}