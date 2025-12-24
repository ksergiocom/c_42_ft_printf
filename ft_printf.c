#include <stdio.h>
#include "libft.h"
#include <stdarg.h>

void ft_puthex(unsigned long n, int caps)
{
    char *hex_digits = "0123456789abcdef";
    char selected;
    
    if (n >= 16)
        ft_puthex(n / 16, caps);
    selected = hex_digits[n % 16];
    if(caps)
        selected = ft_toupper(selected);
    ft_putchar_fd(selected,1);
}

int ft_printf(char *str, ...)
{
    va_list list_args;
    va_start(list_args, str);    

    while(*str){
        if(*str != '%')
            ft_putchar_fd(*str,1);
        if(*str == '%'){
            str++;
            if(*str == '%')
                ft_putchar_fd('%',1);
            if(*str == 'c')
                ft_putchar_fd(va_arg(list_args,int),1);
            else if(*str == 's')
                ft_putstr_fd(va_arg(list_args, char*),1);
            else if(*str == 'i' || *str == 'd')
                ft_putnbr_fd(va_arg(list_args, int),1);
            else if(*str == 'u')
                ft_putnbr_fd(va_arg(list_args,unsigned int),1);
            else if(*str == 'x'){
                ft_putchar_fd('x',1);
                ft_puthex(va_arg(list_args,int),0);
            }else if(*str == 'X'){
                ft_putchar_fd('X',1);
                ft_puthex(va_arg(list_args,int),1);
            }else if(*str == 'p'){
                ft_putstr_fd("0x", 1);
                ft_puthex((unsigned long) va_arg(list_args,void *),0);
            }
        }
        str++;
    }

    va_end(list_args);

    return 0;
}

int main(void)
{
    char *str = "Hola";

    ft_printf("%s -> %p\n",str, str);
    printf("%s -> %p\n",str, str);

    return 0;
}