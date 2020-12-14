
#include "ft_printf.h"

void	fill_buf(t_info *info, size_t n, char c)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		info->buf[info->lenght++] = c;
		index++;
		if (!(info->lenght ^ BUF_SIZE))
		{
			info->ret += write(1, info->buf, info->lenght);
			info->lenght = 0;
		}
	}
}
