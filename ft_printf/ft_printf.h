/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:46:44 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/16 19:53:27 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# define UPPER_HEXADECIMAL 	"0123456789ABCDEF"
# define LOWER_HEXADECIMAL 	"0123456789abcdef"
# define DECIMAL 			"0123456789"

size_t	ft_printf(const char *fixed_arg, ...);
size_t	printchar(char c);
size_t	printstr(char *s);
size_t	print_base_nbr(long int n, char *format);
size_t	print_base_u_nbr(unsigned long int n, char *format);
size_t	printptr(uintptr_t ptr, char *hexadecimal);
#endif