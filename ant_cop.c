/*
**ANT_COP 1.0
*/
        _.---._
     .-' ((O)) '-.
      \ _.\_/._ /
       /..___..\
       ;-.___.-;
      (| e ) e |)     .;.
       \  /_   /      ||||
       _\__-__/_    (\|'-|
     /` / \V/ \ `\   \ )/
    /   \  Y  /   \  /=/
   /  |  \ | / {}  \/ /
  /  /|   `|'   |\   /
  \  \|    |.   | \_/
   \ /\    |.   |
    \_/\   |.   |
    /)_/   |    |
   // ',__.'.__,'
  //   |   |   |
 //    |   |   |
(/     |   |   |
       |   |   |
       | _ | _ |
       |   |   |
       |   |   |
       |   |   |
       |___|___|
       /  J L  \
      (__/   \__)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_strsplit(char const *s, char c);
void	free_str_arr(char **arr);

void add_to_arr(char *line, char **arr, int *ants_arr, int num_ants, char *start, char *end)
{
	char **ln;
	char **info;
	int i = 0;
	int j;
	char *temp;

	j = 0;
	while (j < num_ants)
	{
		ants_arr[j] = 0;
		j++;
	}
	ln = ft_strsplit(line, ' ');
	while (ln[i])
	{
		info = ft_strsplit(ln[i], '-');
		if (ants_arr[atoi(&info[0][1]) - 1])
		{
			printf("same ant on same line\n");
			exit(0);
		}
		ants_arr[atoi(&info[0][1]) - 1] = 1;
		//if (!valid_path(arr[atoi(&info[0][1]) - 1], info[1]))
		//{
		//		//free
		//		printf("ERROR: invalid path\n");
		//		exit (0);
		//}
		j = 0;
		while (j < num_ants)
		{
			if (strcmp(info[1], start) && strcmp(info[1], end))
			{
				if (info[1][0] == arr[j][0])
				{
					if (!strcmp(info[1], arr[j]))
					{
						printf("same room on same line\n");
						exit(0);
					}
				}
			}
			j++;
		}
		temp = arr[atoi(&info[0][1]) - 1];
		arr[atoi(&info[0][1]) - 1] = strdup(info[1]);
		free(temp);
		free_str_arr(info);
		i++;
		
	}
	j =0;
	while(j < num_ants)
	{
		printf("%d %s\n", j + 1, arr[j]);
		j++;
	}
	printf("\n");
	free_str_arr(ln);
}
/*
int valid_path(char *rm1, char *rm2)
{

}
*/
int	main()
{
	char *line = NULL;
	size_t n = 0;
	int num_ants;
	int line_count = 0;
	char **arr;
	int *ants_arr;
	int i = 0;
	char *p;
	char *start;
	char *end;
	char **start_end;

	getline(&line, &n, stdin);
	num_ants = atoi(line);
	ants_arr = malloc(sizeof(int) * num_ants);
	arr = malloc(sizeof(char *) * num_ants);
	while (i < num_ants)
		arr[i++] = strdup("start");

	printf("num_ants = %d\n", num_ants);
	while (getline(&line, &n, stdin) > 0)
	{
		if((p = strchr(line, '\n')))
			*p = '\0';
		if (line[0] == '#')
		{
			if (!strcmp(line, "##start"))
			{
				getline(&line, &n, stdin);
				if((p = strchr(line, '\n')))
					*p = '\0';
				start_end = ft_strsplit(line, ' ');
				start = strdup(start_end[0]);
				free_str_arr(start_end);
				continue ;
			}
			else if (!strcmp(line, "##end"))
			{
				getline(&line, &n, stdin);
				if((p = strchr(line, '\n')))
					*p = '\0';
				start_end = ft_strsplit(line, ' ');
				end = strdup(start_end[0]);
				free_str_arr(start_end);
				continue ;
			}
		}
		else if (line[0] == 'L')
		{
			add_to_arr(line, arr, ants_arr, num_ants, start, end);
			line_count++;
		}

	}
	free(line);
	printf("line count: %d\n", line_count);
	free(start);
	free(end);
	free_str_arr(arr);
	free(ants_arr);
	return (0);
}

//clang -Wall -Wextra -Werror ant_cop.c functions.c -o ant_cop

//out put num of lines printed

//./lem-in < maps/basic_maps/subject2-1.map | leaks -atExit -- ../ant_cop/./ant_cop