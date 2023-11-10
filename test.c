
#define COLOR_DEF "\033[0;39m"
#define COLOR_RED "\033[0;91m"
#define COLOR_BLUE "\033[0;94m"
#define COLOR_GREEN "\033[0;92m"
#define COLOR_YELLOW "\033[0;93m"
#define COLOR_MAGENTA "\033[0;95m"
#define COLOR_CYAN "\033[0;96m"
#define COLOR_WHITE "\033[0;97m"

#include <stdio.h>
#include <fcntl.h>
int	main()
{
	char *word;
	printf("%s", COLOR_RED);
	printf("this is red");
	printf("%s", COLOR_DEF);
	printf("this is standard");
	printf("this is%s blue. %sAnd this is %sgreen.Works?\n\n", COLOR_BLUE, COLOR_DEF, COLOR_GREEN);
	printf(COLOR_DEF);
	printf("Guess:\n");

	read(0, word, 6);

	//printf("\rbears");
	return (0);
}
