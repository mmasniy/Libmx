#include "libmx.h"

static int	check_line(t_rl *read_l, char *stak[read_l->fd]) {
	int	ret;

	while ((read_l->pos = mx_strchr(read_l->mass, read_l->delim)) == NULL \
			&& (ret = read(read_l->fd, read_l->mass, read_l->buf_size)) > 0) {
		read_l->mass[ret] = '\0';
		read_l->sup = stak[read_l->fd];
		stak[read_l->fd] = mx_strjoin(read_l->sup, read_l->mass);
		mx_strdel(&(read_l->sup));
	}
	mx_strdel(&(read_l->mass));
	if (ret == -1) {
		free(read_l);
		return (-2);
	}
	return (1);
}

static void read_line_len(char **lineptr, t_rl *read_l, char *stak[read_l->fd]) {
		*lineptr = mx_strsub(stak[read_l->fd], 0, read_l->pos - stak[read_l->fd]);
		read_l->sup = stak[read_l->fd];
		stak[read_l->fd] = mx_strdup(read_l->pos + 1);
		mx_strdel(&(read_l->sup));
		free(read_l);
}

static void init_read(t_rl *read_l, int buf_size, char delim, const int fd) {
	read_l->buf_size = buf_size;
	read_l->delim = delim;
	read_l->fd = fd;
}

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
	static char	 *stak[256];
	t_rl *read_l;

	if (fd < 0 || buf_size < 1 || !(read_l = (t_rl *)malloc(sizeof(t_rl)))
		|| !(read_l->mass = mx_strnew(buf_size)))
		return (-2);
	init_read(read_l, buf_size, delim, fd);
	if (stak[fd] == NULL)
		stak[fd] = mx_strnew(1);
	if (check_line(read_l, stak) == -2)
		return (-2);
	if ((read_l->pos = mx_strchr(stak[fd], read_l->delim)) != NULL) {
		read_line_len(lineptr, read_l, stak);
		return mx_strlen(*lineptr);
	}
	*lineptr = mx_strdup(stak[read_l->fd]);
	mx_strdel(&stak[read_l->fd]);
	free(read_l);
	return -1;
}
