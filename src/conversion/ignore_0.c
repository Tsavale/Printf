
#include "ft_printf.h"

void	ignore_0_when_left(t_info *info)
{
	if ((info->flags & FLAGS_LEFT))
	{
		info->flags &= ~(FLAGS_ZERO);
	}
}

void	ignore_0_when_precision(t_info *info)
{
	if ((info->flags & FLAGS_PRECISION) && (info->flags & FLAGS_ZERO))
		info->flags &= ~FLAGS_ZERO;
}
