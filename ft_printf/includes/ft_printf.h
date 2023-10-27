/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 03:24:54 by adedieu           #+#    #+#             */
/*   Updated: 2022/12/01 05:11:57 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*				From libft				*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

/*				From printf				*/
int		ft_printf(const char *s, ...);
int		process_pointer(void *p);
int		process_lower_hexa(unsigned long n);
int		process_upper_hexa(unsigned int n);
int		process_number(int number);
int		process_unsigned(unsigned int number);
int		process_string(const char *string);

#endif
