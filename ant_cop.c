/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_cop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:10:25 by wdonnell          #+#    #+#             */
/*   Updated: 2022/06/06 13:36:47 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_strsplit(char const *s, char c);
void	free_str_arr(char **arr);

void add_to_arr(char *line, char **arr, int *ants_arr, int num_ants)
{
	char **ln;
	char **info;
	int i = 0;
	int j;

	ln = ft_strsplit(line, ' ');
	while (ln[i])
	{
		j = 0;
		while (j < num_ants)
		{
			ants_arr[j] = 0;
			j++;
		}
		info = ft_strsplit(ln[i], '-');
		if (ants_arr[atoi(&info[0][1]) - 1])
		{
			//same ant on same line
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
			if (info[1][0] == arr[j][0] && strcmp(info[1], ))
			{
				if (!strcmp(info[1], arr[j]))
				{
					//same room on same line
					printf("same room on same line\n");
					exit(0);
				}
			}
			j++;
		}
		arr[atoi(&info[0][1]) - 1] = strdup(info[1]);

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

int ants_in_same_room(char *line, char **arr)
{

	return (1);
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

	getline(&line, &n, stdin);
	num_ants = atoi(line);
	ants_arr = malloc(sizeof(int) * num_ants);
	arr = malloc(sizeof(char *) * num_ants);
	while (i < num_ants)
		arr[i++] = strdup("start");

	//free(line);
	printf("num_ants = %d\n", num_ants);
	while (getline(&line, &n, stdin) > 0)
	{
		if((p = strchr(line, '\n')))
			*p = '\0';
		//get start and end
		if ()
		{

		}
		else if (line[0] == 'L')
		{
			add_to_arr(line, arr, ants_arr, num_ants);
			//if (!ants_in_same_room(line, arr))
			//{
			//	free(line);
			//	printf("ERROR: multiple ants in the same room\n");
			//	exit (0);
			//}
			line_count++;
		}
		/*
		i = 0;
		while(i < num_ants)
		{
			printf("%d %s\n", i + 1, arr[i]);
			i++;
		}
		*/

	}
	free_str_arr(arr);
	free(ants_arr);
	return (0);
}

//clang -Wall -Wextra -Werror ant_cop.c functions.c -o ant_cop

//out put num of lines printed