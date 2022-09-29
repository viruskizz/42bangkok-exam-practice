#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd) 
{
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0) { return (NULL); }
    char *line = malloc(100000), *buf = line;
    while (read(fd, buf, 1) > 0 && *buf++ != '\n');
    return (buf > line) ? (*buf = 0, line) : (free(line), NULL);
}

// #include <unistd.h>
// #include <stdlib.h>

// char *get_next_line(int fd)
// {
//     int 	i = 0;
//     int 	rd = 0;
//     char	character;
//     char 	*buffer = malloc(10000);

//     while ((rd = read(fd, &character, 1)) > 0)
//     {
//         buffer[i++] = character;
//         if (character == '\n')
//             break;
//     }
//     if ((!buffer[i - 1] && !rd) || rd == -1)
//     {
//         free(buffer);
//         return (NULL);
//     }
//     buffer[i] =  '\0';
//     return(buffer);
// }

// char *get_next_line(int fd)
// {
//     int 	i = 0;
//     int 	rd = 0;
// 	char	buf[1000000];
//     char 	*line = malloc(10000);
// 	static char	temp;

// 	if (!temp)
// 		temp = malloc(10000);
// 	while ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
// 	{
// 		buf[rd] = '\0';
// 		while (buf[i])
// 		{
// 			line[i++] = buf[i++];
// 			if (line[i - 1] == '\n')
// 			{
// 				line[i] = '\0';
// 				return (line);
// 			}
// 		}
// 	}
//     if ((!line[i - 1] && !rd) || rd == -1)
//     {
//         free(line);
//         return (NULL);
//     }
//     line[i] =  '\0';
//     return(line);
// }