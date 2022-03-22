
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
			if (data[y][i] != '0' && data[y][i] != '9'
					&& data[y][i] != '8' && data[y][i] != '7'
					&& data[y][i] != '6' && data[y][i] != '5'
					&& data[y][i] != '4' && data[y][i] != '3'
					&& data[y][i] != '2' && data[y][i] != '1'
					&& data[y][i] != '-' && data[y][i] != '+')
				return (-1);
			if ((data[y][i] == '-' && data[y][i + 1] == '-')
					|| (data[y][i] == '+' && data[y][i + 1] == '+'))
				return(-1);
			i++;
		}
		y++;
	}
	return (1);
}

int	ft_lenstr(char **data)
{
	int	index;

	index = 0;
	while(data[index])
		index++;
	return (index);
}

/*int	checkdouble(char **data)
{
	int len;
	int len2;
	int	*dint;

	len = ft_lenstr(data);
	dint = malloc(sizeof(int) * len);
	len = 0;
	while (data[len])
	{
		dint[len] = ft_atoi(data[len]);
		len++;
	}
	len = 0
	while (dint[len])
	{
		len2 = 0;
		while(dint[len2])
		{
			if(dint[len2] == dint[len])
				return (-1);
			len2++;
		}
		len++;
	}
	return (1);
}*/

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
