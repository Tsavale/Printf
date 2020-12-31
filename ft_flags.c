#include "ft_printf.h"

void		ft_flag_applier(t_fl *fl)
{
	char *tmp;

	ft_special_cases(fl);
	if (fl->str && fl->p >= 0 && fl->cv == 's')
		ft_point_flag_str(fl);
	if (fl->str && fl->p >= 0 && ft_isin(fl->cv, "diuxX%"))
		ft_point_flag_nbr(fl);
	if (fl->str && fl->cv == 'p')
	{
		tmp = ft_strjoin("0x", fl->str);
		free(fl->str);
		fl->str = tmp;
	}
	if (fl->str && fl->fw != 0)
		ft_space_flags(fl);
}

void		ft_special_cases(t_fl *fl)
{
	char	*tmp;

	if (fl->str && ft_isin(fl->cv, "pdiuxX%"))
	{
		if (fl->p == 0 && fl->str[0] == '0')
		{
			tmp = ft_strdup("");
			free(fl->str);
			fl->str = tmp;
		}
		if (fl->p <= -1 || (fl->cv == '%'))
			fl->p = (fl->str[0] == '-') ? fl->zeros - 1 : fl->zeros;
		else if (fl->p < fl->zeros + (fl->str[0] == '-') && (fl->fw >= 0)
																&& fl->p != 0)
			fl->fw = fl->zeros;
	}
	if (fl->str == NULL && fl->cv == 's')
		fl->str = ft_strdup("(null)");
}

void		ft_point_flag_str(t_fl *fl)
{
	char	*tmp;
	int		i;

	if (fl->cv == 's' && fl->p >= 0 && fl->str)
	{
		i = 0;
		tmp = ft_substr(fl->str, 0, fl->p);
		free(fl->str);
		fl->str = tmp;
	}
}

void		ft_point_flag_nbr(t_fl *fl)
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	if (fl->p > ((int)ft_strlen(fl->str) - (fl->str[0] == '-')))
	{
		if (!(s = malloc(sizeof(char*) * (fl->p + (fl->str[0] == '-') + 1))))
			return ;
		if (fl->str[0] == '-')
			s[i++] = '-';
		while (fl->p-- > ((int)ft_strlen(fl->str)) - (fl->str[0] == '-'))
			s[i++] = '0';
		s[i] = '\0';
		tmp = ft_strjoin(s, &(fl->str[(fl->str[0] == '-')]));
		free(s);
		free(fl->str);
		fl->str = tmp;
	}
}

void		ft_space_flags(t_fl *fl)
{
	char	*s;
	char	*tmp;
	int		i;
	int		abs;

	i = 0;
	abs = ((fl->fw > 0) ? fl->fw : -fl->fw);
	if (fl->zeros > abs)
		abs = fl->zeros;
	if (!(s = malloc(sizeof(char) * (abs + 1))))
		return ;
	while (abs-- > (int)ft_strlen(fl->str))
		s[i++] = ' ';
	s[i] = '\0';
	if (fl->fw > 0)
		tmp = ft_strjoin(s, fl->str);
	else
		tmp = ft_strjoin(fl->str, s);
	free(s);
	free(fl->str);
	fl->str = tmp;
}
