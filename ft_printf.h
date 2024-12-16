/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:45:22 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/16 14:21:32 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_printf(const char *format, ...);
void	print_int(int n);
void	print_str(char *str, int fd);
void	print_char(char c);

#endif
