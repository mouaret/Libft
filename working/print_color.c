#include <stdio.h>

void print_8_colours()
{
    for (int i = 0; i < 108; i++)
    {
        if (i % 9 == 0 && i != 0)
            printf("\n");	// cout << endl;
        printf("\033[%dm %3d\033[m", i, i);
    }
}

int main(int argc, char **argv)
{
	print_8_colours();
	return (0);
}
