
#include "ft_printf.h"

void	apostrophe(t_info *info, int *p)
{
	if (!(*p % 3) && *p)
	{
		info->buf[info->lenght++] = '.';
	}
	else if (*p == 0)
		*p = 0;
	*p -= 1;
}

void	ntoa(t_info *info, unsigned long long value)
{
	int			digit;
	static	int	index = 0;

	index_max_buf(info);
	if (value >= info->base)
	{
		index++;
		ntoa(info, value / info->base);
	}
	digit = value % info->base;
	if (digit < 10)
		info->buf[info->lenght++] = digit + '0';
	else if (info->flags & FLAGS_UPPERCASE)
	{
		info->buf[info->lenght++] = digit + 'A' - 10;
	}
	else
	{
		info->buf[info->lenght++] = digit + 'a' - 10;
	}
	if ((info->flags & FLAGS_APOSTROPHE))
		apostrophe(info, &index);
}
