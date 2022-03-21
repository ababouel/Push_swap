
#include "src/include/push_swap.h"

void	ft_freememx(void **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}

int	checknum(char **data)
{
	int	i;
	int	y;

	y = 0;
	while (data[y])
	{
		i = 0;
		while (data[y][i])
		{
			if (data[y][i] > '0' && data[y][i] < '9')
				return (-1);
			i++;
		}
		y++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**data;
	char	*alldata;
	int		index;
	int		indey;

	index = 1;
	indey = 0;
	if (ac > 1)
	{
		while (av[index])
		{
			alldata = ft_strjoin(alldata, av[index]);
			alldata = ft_strjoin(alldata, " ");
			index++;	
		}
		data = ft_split(alldata, ' ');
		printf("check result => %d\n",checknum(data));
		if (checknum(data) != -1)
		{
			index = 0;
			while(data[index])
			{
				printf("=>%s\n", data[index]);
				index++;
			}
			ft_freememx((void **)data);
		}
		else
		{
			free(alldata);
			write(1, "ERROR\n",6);
		}
	}
}
