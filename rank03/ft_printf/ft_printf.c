#include <stdarg.h>
#include <unistd.h>

static int	ft_put_base(int nb, char *range, int base, int *len)
{
	if (nb < 0 && ++(*len))
		return (write(1, "-", 1), ft_put_base(-nb, "0123456789", 10, len));
	if (nb >= base)
		ft_put_base(nb / base, range, base, len);
	return (write(1, &range[nb % base], 1), ++(*len));
}

static int ft_put_digit(int nb, int len)
{
	return ft_put_base(nb, "0123456789", 10, &len);
}

static int ft_put_hex(unsigned int nb, int len)
{
	return ft_put_base(nb, "0123456789abcdef", 16, &len);
}

static int	ft_put_str(char *str, int len)
{
	while (str && str[len] && ++len);
	return (str ? write(1, str, len) : write(1, "(null)", 6));
}

int	ft_printf(const char *fmt, ...)
{
	int len = 0;
	va_list ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) == 's' && fmt++)
			len += ft_put_str(va_arg(ap, char *), 0);
		else if (*fmt == '%' && *(fmt + 1) == 'd' && fmt++)
			len += ft_put_digit(va_arg(ap, int), 0);
		else if (*fmt == '%' && *(fmt + 1) == 'x' && fmt++)
			len += ft_put_hex(va_arg(ap, unsigned int), 0);
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (len);
}