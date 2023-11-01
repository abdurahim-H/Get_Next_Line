# 📚 Get_Next_Line Project

## 📖 Overview
`get_next_line` is a function that reads a file line by line. The main goal of this project is to create a function 
that returns a line ending with a newline, read from a file descriptor.

## 🛠 Usage
```c
int get_next_line(int fd, char **line);

fd is a file descriptor from which to read.
line is the address of a pointer to a character that will be used to save the line read from the file descriptor fd.
The function returns 1 if a line has been read, 0 if the end of the file has been reached, or -1 if an error occurred.

📝 Example
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
This example reads a file named test.txt and prints each line to the console.
