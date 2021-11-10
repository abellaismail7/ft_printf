

#include <unistd.h>
void filler(char c, int times)
{
	while(times--)
		write(1, &c, 1);

}
