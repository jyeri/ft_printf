#include "new.h"

int int_len(int i)
{
	int holder;
	int len = 0;

	holder = i;
	while (holder > 0)
	{
		holder = holder / 10;
		len++;
	}
	return (len);
}

void ft_putnbr_us(unsigned int n, int base)
{
	if (n / base < 1)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_us(n / base, base);
		ft_putnbr_us(n % base, base);
	}
}

void print_sign(t_flags *flags, char sign)
{
	if (sign)
	{
		ft_putchar(sign);
		flags->printlen++;
	}
}

void print_prec(t_flags *flags, int prec)
{
	while (prec > 0)
	{
		ft_putchar('0');
		flags->printlen++;
		prec--;
	}
}

void print_width(t_flags *flags, int len, char sign, int n)
{
	int is_sign;
	int total;
	char pad;

	is_sign = 0;
	if (sign)
		is_sign = 1;
	if (flags->zero && flags->precision < 0 && !flags->minus)
		pad = '0';
	else
		pad = ' ';
	if ((flags->precision + is_sign) > (len + is_sign))
		total = flags->precision + is_sign;
	else if (flags->precision || n)
		total = len + is_sign;
	else
		total = 0;
	while (flags->width > total)
	{
		ft_putchar(pad);
		flags->printlen++;
		flags->width--;
	}
}

void print_int(t_flags *flags, int len, int sign, int n)
{
	if(flags->minus)
	{
		print_sign(flags, sign);
		print_prec(flags, (flags->precision - len));
		if (n || flags->precision != 0)
			ft_putnbr_us(n, 10);
		print_width(flags, len, sign, n);
	}
	else
	{
		if (flags->zero && flags->precision != 0)
		{
			print_sign(flags, sign);
			print_width(flags, len, sign, n);
		}
		else
		{
			print_width(flags, len, sign, n);
			print_sign(flags, sign);
		}
		print_prec(flags, (flags->precision - len));
		if (n || flags->precision != 0)
			ft_putnbr_us(n, 10);
	}
}

int print_diu(t_flags *flags)
{
	int len;
	long int n;
	char sign;

	sign = '\0';
	if (flags->plus)
		sign = '+';
	if (flags->type == 'd' || flags->type == 'i')
	{
		n = va_arg(flags->args, int);
		if (n < 0)
		{
			sign = '-';
			n = n * -1;
		}
	}
	else
		n = va_arg(flags->args, unsigned int);
	len = int_len(n);
	print_int(flags, len, sign, n);
	return (1);
}



//#include "new.h"
//
//int int_len(int i)
//{
//	int holder;
//	int len = 0;
//
//	holder = i;
//	while (holder > 0)
//	{
//		holder = holder / 10;
//		len++;
//	}
//	return (len);
//}
//
//int print_di(t_flags *flags)
//{
//	int i;
//	int len;
//
//	i = va_arg(flags->args, int);
//	len = i;
//
//	if (flags->width || flags->precision)
//	{
//		if (flags->dot)
//			flags->precision = flags->precision - int_len(len);
//		flags->width = flags->width - int_len(len) - flags->precision;
//		if (flags->minus)
//		{
//			if (flags->plus)
//			{
//				ft_putchar('+');
//				flags->width--;
//			}
//			while (flags->precision-- > 0)
//				ft_putchar('0');
//			ft_putnbr(i);
//			while (flags->width-- > 0)
//				ft_putchar(' ');	
//		}
//		else
//		{
//			while (flags->width-- > 0)
//			{
//				ft_putchar(' ');
//				if (flags->plus && flags->width-- == 1)
//					ft_putchar('+');
//			}
//			if (flags->dot)
//			{
//				while (flags->precision-- > 0)
//					ft_putchar('0');
//			}
//		}
//	}
//	if (!flags->minus)
//		ft_putnbr(i);
//	return (1);
//}
//