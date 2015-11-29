/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
int strlength(char* str)
{
	if (str == NULL)
		return 0;
	int i;
	for (i = 0; str[i] != '\0'; i++){}
	return i;
}
char removeSpaces(char *str) {
	int len = strlength(str);
	if (len==0)
		return '\0';
	int i = 0;
	while (str[i] != '\0'){
		while (str[i] != ' ' && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			int j = i + 1;
			while (str[j] == ' ' && str[j] != '\0')
				j++;
			if (str[j] == '\0')
				str[i] = '\0';
			else
			{
				int temp = i;
				while (j <= len)
				{
					str[i] = str[j];
					i++, j++;
				}
				i = temp;
			}
		}
	}
	return 'a';
}