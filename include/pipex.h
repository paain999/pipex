/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:51 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/01 12:07:03 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		fd[2];
	int		here_doc;
	int		invalid_infile;
	char	**paths;
	char	**cmd_args;
}		t_pipex;


char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	**ft_split(char const *s, char c);

#endif