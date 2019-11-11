#include "libmx.h"

static int	mx_check_line(int const fd, char *mass, char *stak[fd], int buf_size, char delim) {
	int	ret;
	char *sup;
	char *pos;

	while ((pos = mx_strchr(mass, delim)) == NULL \
			&& (ret = read(fd, mass, buf_size)) > 0) {
		mass[ret] = '\0';
		sup = stak[fd];
		stak[fd] = mx_strjoin(sup, mass);
		mx_strdel(&sup);
	}

	mx_strdel(&mass);

	if (ret == -1)
		return (-2);

	return (1);
}

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
	static char	 *stak[1024];
	char *mass;
	int	ret;
	char *sup;
	char *pos;

	if (fd < 0 || buf_size < 1 || !(mass = mx_strnew(buf_size)))
		return (-2);

	if (stak[fd] == NULL)
		stak[fd] = mx_strnew(1);
	if ((ret = mx_check_line(fd, mass, stak, buf_size, delim)) == -1)
		return (-2);
	if ((pos = mx_strchr(stak[fd], delim)) != NULL)
	{
		*lineptr = mx_strsub(stak[fd], 0, pos - stak[fd]);
		sup = stak[fd];
		stak[fd] = mx_strdup(pos + 1);
		mx_strdel(&sup);
		return mx_strlen(*lineptr);
	}
	*lineptr = mx_strdup(stak[fd]);
	mx_strdel(&stak[fd]);
	return -1;
}
