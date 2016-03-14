/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int int_to_str(int, char *,int);
int pow(int, int);
void reverse_str(char *,int);

void number_to_str(float number, char *str,int afterdecimal){
	int int_part, ind=0;
	float decimal_part;
	if (number<0){
		str[0] = '-';
		ind = 1;
		number = -number;
	}
	int_part = (int)number;
	decimal_part = number - int_part;
	ind += int_to_str(int_part, str+ind,0);
	if (afterdecimal > 0){
		str[ind] = '.';
		str[ind + 1];
		int_part = decimal_part*pow(10, afterdecimal);
		ind = int_to_str(int_part, str + ind+1, afterdecimal);
		
	}
}
int int_to_str(int num, char *str, int no_digit){
	int i,mod;
	for (i = 0; num != 0; i++){
		mod = num % 10;
		str[i] = mod + '0';
		num = num / 10;
	}
	if (i < no_digit){
		for (; i < no_digit; i++){
			str[i] = '0';
		}
	}
	str[i] = '\0';
	reverse_str(str,i-1);
	return i;
}
void reverse_str(char *str,int len){
	int i;
	char ch;
	for (i = 0; i < len; i++, len--){
		ch = str[i];
		str[i] = str[len];
		str[len] = ch;
	}
}
int pow(int base, int power){
	int res = 1, i;
	for (i = 0; i < power; i++){
		res *= base;
	}
	return res;
}