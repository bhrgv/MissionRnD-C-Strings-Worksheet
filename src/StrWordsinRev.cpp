/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void str_words_in_rev(char *input, int len){
	int i = 0, j = len - 1;
	while (i < j)
	{
		char c = input[i];
		input[i] = input[j];
		input[j] = c;
		i++, j--;
	}
	i = 0;
	j = 0;
	while (input[j] != '\0')
	{
		j = i+1;
		while (input[j] != '\0' && input[j] != ' ')
			j++;
		int jtemp = j-1;
		while (i < jtemp)
		{
			char c = input[i];
			input[i] = input[jtemp];
			input[jtemp] = c;
			i++, jtemp--;
		}
		while (input[j] == ' ')
			j++;
		i = j;
	}
}
