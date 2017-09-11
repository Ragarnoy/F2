static int	tryfit(t_pos *pos, char str[][13], t_tlist *elem)
{
//	int ret;
	if (!elem)
	{
		debug(str, pos->s);
		exit(0);
	}
	while (pos->x <= pos->s && elem)
	{
		while (pos->y <= pos->s && elem)
		{
	printf("\nCoordinates are %d and %d and size is %d\nCurrent tetri is\n%s\n",pos->x, pos->y, pos->s, elem->tetri);
	debug(str, pos->s);
			if (pos->x >= pos->s)
				return (1);
			if (pos->x == pos->s && pos->y == pos->s && elem)
				{
					printf("AWDAWDWA\n");
					pos->s++;
				}
			if (!ft_putpiece(str, pos, *elem, 1))
				pos->y++;
			else if (ft_putpiece(str, pos, *elem, 0))
				tryfit(pos, str, elem->next);
			tryfit(pos, str, elem);
			pos->y++;
			//if (ret)
			//	return (1);
			//remove_t(str, elem->letter);
		}
		pos->y = 0;
		pos->x++;
	}
	if (pos->x >= 9)
		return (0);
	return (1);
}