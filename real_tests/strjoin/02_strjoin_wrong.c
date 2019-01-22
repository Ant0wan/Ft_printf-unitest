/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic2_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 10:29:34 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 16:14:11 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	strjoin_basic2(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *res;

	s1 = "Hello my file is really long so please do not read this otherwise you will probably lose 10 minutes of your precious time on earth. Indeed our time on earth is ticking, and we must get the most out of every second. This is why you shouldn't read the following text: Pong (Thiti Mahayotaruk) is a high-school outcast who loves to draw. He turns his daily activities into comic book stories, making his real-life crush, Ming (Narikun Ketprapakorn) the female protagonist and himself as the hero. One day, he accidentally submits his comic book to the teacher. May Nhai (Sutatta Udomsilp), another high-school outcast who has the ";
	s2 = "ability to discharge electricity when her heart rate rises, discovers Pong's book. When she reveals his book to the entire class, including Ming, Pong tries to get back to her but he is repelled by her hidden ability. He promises to keep it a secret and they become friends. Later on, Pong starts to encourage May Nhai to confess her feelings for Fame (Thanapob Leeratanakajorn), the most famous person in school, but she is scared she might electrocute him. Little does she know, Fame secretly likes her as well. He invites her to join track-and-field, in which she agrees to after Pong persuades her. During this time, Pong slowly feels love towards May Nhai, and she starts to become his female protagonist in his stories. Seeing that Fame and May Nhai are getting closer, he is about to give his love up and just continue to support them. However, he decides to change his destiny; so he fights for her. In the end, May Nhai chooses Pong over Fame because he stands by her despite her power.";
	s3 = "Hello my file is really long so please do not read this otherwise you will probably lose 10 minutes of your precious time on earth. Indeed our time on earth is ticking, and we must get the most out of every second. This is why you shouldn't read the following text: Pong (Thiti Mahayotaruk) is a high-school outcast who loves to draw. He turns his daily activities into comic book stories, making his real-life crush, Ming (Narikun Ketprapakorn) the female protagonist and himself as the hero. One day, he accidentally submits his comic book to the teacher. May Nhai (Sutatta Udomsilp), another high-school outcast who has the ability to discharge electricity when her heart rate rises, discovers Pong's book. When she reveals his book to the entire class, including Ming, Pong tries to get back to her but he is repelled by her hidden ability. He promises to keep it a secret and they become friends. Later on, Pong starts to encourage May Nhai to confess her feelings for Fame (Thanapob Leeratanakajorn), the most famous person in school, but she is scared she might electrocute him. Little does she know, Fame secretly likes her as well. He invites her to join track-and-field, in which she agrees to after Pong persuades her. During this time, Pong slowly feels love towards May Nhai, and she starts to become his female protagonist in his stories. Seeing that Fame and May Nhai are getting closer, he is about to give his love up and just continue to support them. However, he decides to change his destiny; so he fights for her. In the end, May Nhai chooses Pong over Fame because he stands by her despite her power.";
	res = ft_strjoin(s1, s2);
	if (strcmp(s3, res) == 0)
	{
		if (res)
			free(res);
		return (0);
	}
	else
	{
		if (res)
			free(res);
		return (-1);
	}
}
