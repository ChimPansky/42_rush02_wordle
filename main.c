#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MAX_DB_SIZE
# define MAX_DB_SIZE 10000
#endif

#define ERR_INVALID_WORD 2
#define ERR_MALLOC 2

typedef struct s_database
{
	char	*word[MAX_DB_SIZE];
	size_t	size;
}			t_database;

void	err_hndling(int errno)
{
	char	*err_msg;

	if (errno == ERR_INVALID_WORD)
		err_msg = "Invalid word read. Exiting.";
	else if (errno == ERR_MALLOC)
		err_msg = "Allocation Error (Malloc failed). Exiting.";
	else
		err_msg = "Unknown Error. Exiting.";

	dprintf(STDERR_FILENO, err_msg);
}

int	check_word(char *word)
{
	if (words->word[words->size][5 != '\n' || bytes_read < 5])
		return (ERR_INVALID_WORD);
	return (0);
	// if word not alpha...
}
void	clear_database(t_database *words)
{
	while (words->word)
	{
		free(words->word);
	}


}

int	read_database(char *path, t_database *words)
{
	int	fd;
	int	bytes_read;

	words->size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		 return (fd);
	bytes_read = 1;
	while (bytes_read)
	{
		words->word[words->size] = malloc(sizeof(char) * 5);
		if (!words->word[words->size])
		{
			clear_database(words);
			return (1);
		}
		bytes_read = read(fd, words->word[words->size], 6);
		if (check_word(words->word[words->size]))
		{
			clear_database(words);
			return (1);
		}
		words->size++;
	}
	close(fd);
	return (0);
}

int main()
{
	int	err;
	t_database	words;

	err = read_database("words.txt");
	if (err)
	{
		err_hndling(err);
		return(err);
	}
	return (0);
}
