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

int power(int x, int y)
{
	if (y == 0)
		return 1;
	else
		return x*power(x, y - 1);
}
void number_to_str(float number, char *str,int afterdecimal){
	int intpart;
	int decpart;
	int input_pointer = 0,flag=0;
	if (number < 0)
	{
		number *= -1;
		flag = 1;
	}
	intpart = (int)number;
	decpart = (number - intpart) * power(10,afterdecimal);
	if (afterdecimal)
	{
		while (decpart)
		{
			int d = decpart % 10;
			decpart /= 10;
			str[input_pointer++] = (char)(d + 48);
		}
		str[input_pointer++] = '.';
	}
	while (intpart)
	{
		int d = intpart % 10;
		intpart /= 10;
		str[input_pointer++] = (char)(d + 48);
	}
	if (flag)
		str[input_pointer++] = '-';
	int i = 0,j=input_pointer-1;
	while (i < j)
	{
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++, j--;
	}
	str[input_pointer] = '\0';
}
