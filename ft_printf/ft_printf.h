/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:46:44 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/11 16:33:52 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define UPPER_HEXADECIMAL "0123456789ABCDEF"
# define LOWER_HEXADECIMAL "0123456789abcdef"
# define DECIMAL "0123456789"

int	ft_printf(const char *fixed_arg, ...);
int	printchar(char c);
int	printstr(char *s);
int	print_base_nbr(long long int n, long long int base, char *format);
int	print_base_u_nbr(unsigned long long int n, unsigned long long int base, \
															char *format);
int	printptr(uintptr_t ptr, char *hexadecimal);
#endif