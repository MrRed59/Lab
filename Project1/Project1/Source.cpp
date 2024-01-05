#include<unistd.h>
#include<stdio.h>

int main()
{
	int x, y;

	char s[64];

	x = 8;
	y = 17;

	sprintf(s, "x=%d y=%d\n", x, y);

	_write(1, s, sizeof(s));

	return 0;
}


