#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_fl			*fl;
	unsigned int	size;

	if (!format)
		return (0);
	if (!(fl = (t_fl*)(malloc(sizeof(t_fl)))))
		return (0);
	va_start(ap, format);
	size = ft_format(format, &ap, fl);
	va_end(ap);
	free(fl);
	return (size);
}

int			ft_format(const char *format, va_list *ap, t_fl *fl)
{
	int		size;

	size = 0;
	while (*format)
	{
		ft_start_fl(fl);
		if (*format == '%')
		{
			format += ft_process(ap, (char *)format + 1, fl);
			size += (fl->cv == 'c') ? ft_write(ap, fl) : ft_strlen(fl->str);
			if (fl->str)
				ft_putstr_fd(fl->str, 1);
		}
		if (!fl->str && (fl->cv != 'c' || fl->cv == 0))
		{
			write(1, format, 1);
			size++;
		}
		else if (!fl->str && fl->cv != 0 && fl->cv != 'c')
			break ;
		free(fl->str);
		format++;
	}
	return (size);
}

int			ft_process(va_list *ap, char *str, t_fl *fl)
{
	int i;

	i = 0;
	i += ft_flag_inf(&str[i], fl);
	i += ft_fw_inf(ap, &str[i], fl);
	if (str[i] == '.')
	{
		fl->p = 0;
		i++;
		i += ft_precision_inf(ap, &str[i], fl);
	}
	if (ft_isaconversion(str[i]))
		ft_conversion(ap, str[i], fl);
	return ((ft_isaconversion(str[i])) ? i + 1 : 0);
}

int			ft_write(va_list *ap, t_fl *fl)
{
	int i;

	i = 1;
	while (fl->fw > 1)
	{
		write(1, " ", 1);
		fl->fw--;
		i++;
	}
	ft_putchar_fd(va_arg(*ap, int), 1);
	while (fl->fw < -1)
	{
		write(1, " ", 1);
		fl->fw++;
		i++;
	}
	return (i);
}
