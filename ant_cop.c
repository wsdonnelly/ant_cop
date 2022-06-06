/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_cop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:10:25 by wdonnell          #+#    #+#             */
/*   Updated: 2022/06/05 16:18:23 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_strsplit(char const *s, char c);
void	free_str_arr(char **arr);

void add_to_arr(char *line, char **arr)
{
	char **ln;
	char **info;
	int i = 0;

	ln = ft_strsplit(line, ' ');
	while (ln[i])
	{
		info = ft_strsplit(ln[i], '-');
		//if (!valid_path(arr[atoi(&info[0][1]) - 1], info[1]))
		//{
		//		//free
		//		printf("ERROR: invalid path\n");
		//		exit (0);
		//}
		arr[atoi(&info[0][1]) - 1] = strdup(info[1]);
		free_str_arr(info);
		i++;
		int j =0;
		while(j < 5)
		{
			printf("%d %s\n", j + 1, arr[j]);
			j++;
		}
	}
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
	int i = 0;

	getline(&line, &n, stdin);
	num_ants = atoi(line);
	arr = malloc(sizeof(char *) * num_ants);
	while (i < num_ants)
		arr[i++] = strdup("start");

	//free(line);
	printf("num_ants = %d\n", num_ants);
	while (getline(&line, &n, stdin) > 0)
	{
		//printf("line: %s", line);
		if (line[0] == 'L')
		{
			add_to_arr(line, arr);
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

	return (0);
}

//gcc -Wall -Wextra -Werror ant_cop.c -o ant_cop