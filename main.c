#include "monty.h"
overrall_t vrall;
/**
 * start_vrall - starts the universal variables
 * @fd: file descrp
 * Return: void
 */
void start_vrall(FILE *fd)
{
	vrall.lifo = 1;
	vrall.cline = 1;
	vrall.args = NULL;
	vrall.h = NULL;
	vrall.fd = fd;
	vrall.buf = NULL;
}

/**
 * input_scanner - scans if file exists
 * @ac: argument count
 * @av: argument vector
 * Return: structure
 */
FILE *input_scanner(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

fd = fopen(av[1], "r");

if (fd == NULL)
{
    fprintf(stderr, "Error: Can't open file %s\n", av[1]);
    exit(EXIT_FAILURE);
}

return (fd);
}

/**
 * free_vrall - frees the universal variables
 * Return: void
 */
void free_vrall(void)
{
	op_freelist(vrall.h);
	free(vrall.buf);
	fclose(vrall.fd);
}

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0
 */
int main(int ac, char *av[])
{
    void (*f)(stack_t **stack, unsigned int line_number);
    FILE *fd;
    size_t x = 256;
    char *line = NULL;
    char *y = NULL;
    char *z[2] = {NULL, NULL};

    fd = input_scanner(ac, av);
    start_vrall(fd);
    line = (char*)malloc(sizeof(char) * x);
    if (!line)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    while ((y = fgets(line, x, fd)) != NULL)
    {
        z[0] = my_strtok(line, " \t\n");
        if (z[0] && z[0][0] != '#')
        {
            f = retrive_ops(z[0]);
            if (!f)
            {
                fprintf(stderr, "L%u: ", vrall.cline);
                fprintf(stderr, "unknown instruction %s\n", z[0]);
                free(line);
                free_vrall();
                exit(EXIT_FAILURE);
            }
            vrall.args = my_strtok(NULL, " \t\n");
            f(&vrall.h, vrall.cline);
        }
        vrall.cline++;
    }

    free(line);
    free_vrall();

    return 0;
}
