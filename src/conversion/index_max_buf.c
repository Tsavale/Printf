
#include "ft_printf.h"

void	index_max_buf(t_info *info)
{
	if (!(info->lenght ^ BUF_SIZE))
	{
		info->ret += write(1, info->buf, info->lenght);
		info->lenght = 0;
	}
}
