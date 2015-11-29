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
int strLength(char* str){
	if (str == NULL)
		return 0;
	int i;
	for (i = 0; str[i] != '\0'; i++){}
	return i;
}
char ** commonWords(char *str1, char *str2) {
	int len1 = strLength(str1);
	char** result;
	int start[20], end[20];
	int len2 = strLength(str2);
	int count = 0;
	if (len1==0||len2==0)
		return NULL;
	int i=0, j=0;
	while (str1[i] != '\0')
	{
		while (str1[i] == ' '&&str1[i] != '\0')
			i++;
		int itemp = i;
		j = 0;
		while (str2[j] != '\0')
		{
			int flag = 0;
			i = itemp;
			while (str2[j] == ' ' && str2[j] != '\0')
				j++;
			if (str2[j] == '\0')
				break;
			while (str1[i] == str2[j] || (str1[i] == ' '&&str2[j] == '\0') || (str1[i] == '\0'&&str2[j] == ' '))
			{
				if ((str1[i] == ' '&&str2[j] == '\0') || (str1[i] == '\0'&&str2[j] == ' ') || (str1[i] == ' '&&str2[j] == ' ')){
					start[count] = itemp;
					end[count] = i;
					count++;
					flag = 1;
					break;
				}
				else
				{
					i++, j++;
				}
			}
			if (flag)
				break;
			else
			{
				while (str2[j] != ' '&&str2[j] != '\0')
					j++;
			}
		}
		i = itemp;
		while (str1[i] != ' '&&str1[i] != '\0')
			i++;
	}
	if (!count)
		return NULL;
	else
	{
		result = (char**)malloc(count*sizeof(char));
		for (i = 0; i < count; i++)
		{
			char* str = (char*)malloc(31 * sizeof(char));
			j = start[i];
			int k = 0;
			while (j < end[i])
			{
				str[k] = str1[j];
				j++;
				k++;
			}
			str[k] = '\0';
			result[i] = str;
		}
	}	
	return result;
}