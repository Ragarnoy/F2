#include "fillit.h"

int		ft_putpiece(char grid[][13], t_pos *pos, t_tlist elem)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = pos->y;
	x = pos->x;
	while (elem.tetri[i])
	{
		if (elem.tetri[i] == '\n')
		{
			x++;
			y = pos->y;
		}
		else
		{
			if (x >= pos->s || y >= pos->s)
				return (0);
			if (elem.tetri[i] != '.')
				grid[x][y] = elem.letter;
			y++;
		}
		i++;
	}
	return (1);
}

int		ft_check_place(char grid[][13], t_pos *pos, t_tlist elem)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = pos->y;
	x = pos->x;
	while (elem.tetri[i])
	{
		if (elem.tetri[i] == '\n')
		{
			x++;
			y = pos->y;
		}
		else
		{
			if (x >= pos->s || y >= pos->s)
				return (0);
			if (grid[x][y] != '.' && elem.tetri[i] != '.')
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int		ft_check_n_put(char grid[][13], t_pos *pos, t_tlist elem)
{
	if (ft_check_place(grid, pos, elem))
	{
		ft_putpiece(grid, pos, elem);
		return (1);
	}
	return (0);
}