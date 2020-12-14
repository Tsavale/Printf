
#include "ft_printf.h"

void	conv_type_percentage(t_info *info, va_list va)
{
	size_t	i;

	i = 0;
	info->lenght = 0;
	if (info->flags & FLAGS_ZERO && info->flags & FLAGS_LEFT)
		info->flags &= ~FLAGS_ZERO;
	if (!(info->flags & FLAGS_LEFT))
	{
		put_width_in_buf(info, 1);
		info->buf[info->lenght++] = '%';
	}
	if ((info->flags & FLAGS_LEFT))
	{
		info->buf[info->lenght++] = '%';
		put_width_in_buf(info, 1);
	}
	info->ret += write(1, info->buf, info->lenght);
	(void)va;
	(void)i;
}
