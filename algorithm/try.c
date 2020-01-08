#include <stdio.h>

int main( void )
{
	char str[5] = {'M', 'A', 'R', 'I', 'O'};
	char str2[6] = {'W', 'A', 'R', 'I', 'O','\0'};
	printf( "%s %s\n", str2, str );
	return 0;
}