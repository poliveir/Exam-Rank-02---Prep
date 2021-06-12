#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define TRUE 1
#define FALSE 0

enum	e_flags
{
	point = 0
};

typedef struct s_details
{
	const char	*fmt;
	va_list		args;
	int		wid;
	int		pre;
	int		flags[1];
	int		n_chr_total;
}	t_details;

/*
** UTILITIES:
*/

void	ft_putchar(char c)i
{
	write(1, &c, 1);
}

/*
** STRING MANIPULATION:
*/

int	ft_strlen(const char *s)
{
	int size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)&(*s));
		s++;
	}
	if (*s == (char)c)
		return ((char *)&(*s));
	return (0);
}

/*
** MATHS:
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	int nbr;

	if (ft_isdigit(*s))
	{
		nbr = 0;
		while (ft_isdigit(*s))
		{
			nbr = (nbr * 10) + (*s - '0');
			s++;
		}
		return (nbr);
	}
	return (0);
}

int	ft_count_digits(long long nbr, char x_or_i)
{
	int	n_digits;

	n_digits = 1;
	if (x_or_i == 'i')
	{
		if (nbr < 0)
		{
			n_digits++;
			nbr *= -1;
		}
		while (nbr > 9)
		{
			n_digits++;
			nbr /= 10;
		}
	}
	else if (x_or_i == 'x')
	{
		while (nbr > 15)
		{
			n_digits++;
			nbr /= 16;
		}
	}
	return (n_digits);
}

void	ft_putnbr(int nbr)
{
	char c;

	if (nbr == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_puthex(unsigned int nbr)
{
	if (nbr > 15)
		ft_puthex(nbr / 16);
	ft_putchar("0123456789abcdef"[nbr % 16]);
}

/*
** MAIN FUNCTIONS:
*/

void	ft_hex_conv(t_details *details)
{
	unsigned int	hex;
	int		n_chr;

	hex = va_arg(details->args, unsigned int);
	n_chr = ft_count_digits(hex, 'x');
	if (hex == 0 && !details->pre && details->flags[point])
		n_chr--;
	details->n_chr_total += n_chr;
	if (n_chr < details->pre)
	{
		while (details->wid > details->pre)
		{
			write(1, " ", 1);
			details->n_chr_total++;
			details->wid--;
		}
	}
	else
	{
		while (details->wid > n_chr)
		{
			write(1, " ", 1);
			details->n_chr_total++;
			details->wid--;
		}
	}
	if (hex == 0 && !details->pre && details->flags[point])
	{
		details->fmt++;
		return ;
	}
	while (details->pre > n_chr)
	{
		write(1, "0", 1);
		details->n_chr_total++;
		details->pre--;
	}
	ft_puthex(hex);
	details->fmt++;
}

void	ft_int_conv(t_details *details)
{
	int i;
	int n_chr;
	int minus;

	i = va_arg(details->args, int);
	minus = FALSE;
	if (i < 0)
		minus = TRUE;
	n_chr = ft_count_digits(i, 'i');
	if (i == 0 && !details->pre && details->flags[point])
			n_chr--;
	details->n_chr_total += n_chr;
	if (n_chr < details->pre)
	{
		while (details->wid > details->pre + minus)
		{
			write(1, " ", 1);
			details->n_chr_total++;
			details->wid--;
		}
	}
	else
	{
		while (details->wid > n_chr)
		{
			write(1, " ", 1);
			details->n_chr_total++;
			details->wid--;
		}
	}
	if (i == 0 && !details->pre && details->flags[point])
	{
		details->fmt++;
		return ;
	}
	if (i < 0)
		write(1, "-", 1);
	while (details->pre > n_chr - minus)
	{
		write(1, "0", 1);
		details->n_chr_total++;
		details->pre--;
	}
	ft_putnbr(i);
	details->fmt++;
}

void	ft_str_conv(t_details *details)
{
	char	*s;
	int	n_chr;

	s = va_arg(details->args, char*);
	if (!s)
		s = "(null)";
	n_chr = ft_strlen(s);
	if (details->flags[point] && details->pre < n_chr)
		n_chr = details->pre;
	while (details->wid > n_chr)
	{
		write(1, " ", 1);
		details->n_chr_total++;
		details->wid--;
	}
	write(1, s, n_chr);
	details->n_chr_total += n_chr;
	details->fmt++;
}


void	ft_conversions(t_details *details)
{
	if (*details->fmt == 's')
		ft_str_conv(details);
	else if (*details->fmt == 'd')
		ft_int_conv(details);
	else if (*details->fmt == 'x')
		ft_hex_conv(details);
}

void	ft_check_wid(t_details *details)
{
	if (ft_isdigit(*details->fmt))
		details->wid = ft_atoi(details->fmt);
	while (ft_isdigit(*details->fmt))
		details->fmt++;
}

void	ft_check_pre(t_details *details)
{
	details->flags[point] = TRUE;
	details->fmt++;
	if (ft_isdigit(*details->fmt))
		details->pre = ft_atoi(details->fmt);
	while (ft_isdigit(*details->fmt))
		details->fmt++;
}

void	ft_check_flags(t_details *details)
{
	details->wid = 0;
	details->pre = 0;
	details->flags[point] = FALSE;
	while (!(ft_strchr("sdx", *details->fmt)) && *details->fmt)
	{
		ft_check_wid(details);
		if(*details->fmt == '.')
			ft_check_pre(details);
	}
	if (ft_strchr("sdx", *details->fmt))
		ft_conversions(details);
}

int	ft_printf(const char *format, ...)
{
	int	n_chr;
	t_details	*details;
	t_details	details_list;

	details = &details_list;
	details->fmt = format;
	details->n_chr_total = 0;
	va_start(details->args, format);
	while (*details->fmt)
	{
		if (*details->fmt == '%')
		{
			details->fmt++;
			ft_check_flags(details);
		}
		else
		{
			write (1, &(*details->fmt), 1);
			details->fmt++;
			details->n_chr_total++;
		}
	}
	va_end(details->args);
	n_chr = details->n_chr_total;
	return (n_chr);
}
