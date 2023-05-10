/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:46:44 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/10 23:50:06 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

# define UPPER_HEXADECIMAL	"0123456789ABCDEF"
# define LOWER_HEXADECIMAL	"0123456789abcdef"

int			ft_printf(const char *fixed_arg, ...);
int			printchar(char c);
int			printstr(char *s);
int			printnbr(long n);
int			printhexa(int decimal, char *hexadecimal);
int			printptr(uintptr_t ptr, char *hexadecimal);
#endif