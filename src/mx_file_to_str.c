#include "libmx.h"

static size_t get_len_file(const char *file) {
	int fd = open(file, O_RDONLY);
	char buffer;
	int size = 0;

	while (read(fd, &buffer, 1) > 0)
		++size;

	close(fd);
	return size;
}

static char *file_to_str(const char *file, char *filestr) {
	int fd = open(file, O_RDONLY);
	char buffer;

	if (!fd)
		return NULL;

	for (size_t i = 0; read(fd, &buffer, 1) > 0; i++)
		filestr[i] = buffer;

	close(fd);
	return filestr;
}

char *mx_file_to_str(const char *file) {
	size_t len;
	char *filestr = NULL;
	
	if (!file)
		return NULL;
	
	if (!(len = get_len_file(file)))
		return NULL;

	if (file && (len >= 0)) {
		filestr = mx_strnew(len);
		if (file_to_str(file, filestr))
			return filestr;
		else
			return NULL;
	}
	return NULL;
}
