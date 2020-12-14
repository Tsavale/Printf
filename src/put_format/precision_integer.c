
#include "ft_printf.h"

void	put_precision_in_buf(t_info *info, unsigned int size)
{
	if (info->flags & FLAGS_PRECISION)
	{
		info->flags &= ~FLAGS_ZERO;
		if (info->precision > size)
		{
			size = info->precision - size;
			fill_buf(info, size, '0');
		}
	}
}
