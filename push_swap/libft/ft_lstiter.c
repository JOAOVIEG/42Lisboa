/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:36:21 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/12 11:34:35 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, int (*f)(int *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		(f)(&lst->content);
		lst = lst->next;
	}
}
