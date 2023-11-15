<h1 align="center">📚 Get_Next_Line Project 📚</h1>

<p align="center">
	<img src="https://img.shields.io/badge/Made%20with-C-blue?style=for-the-badge&logo=c">
	<img src="https://img.shields.io/badge/Platform-Linux-lightgrey?style=for-the-badge">
</p>

## 🌈 Overview 🌈
`get_next_line` is a function that reads a file line by line. The main goal of this project is to create a function 
that returns a line ending with a newline, read from a file descriptor.

## 🛠 Usage 🛠
```c
int get_next_line(int fd, char **line);

fd is a file descriptor from which to read.
line is the address of a pointer to a character that will be used to save the line read from the file descriptor fd.
The function returns 1 if a line has been read, 0 if the end of the file has been reached, or -1 if an error occurred.

📝 Example 📝

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	// Open the file
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open and read the file.\n");
		return (1);
	}

	// Use get_next_line to read and print each line
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	// Close the file
	close(fd);

	return (0);
}
This example reads a file named test.txt and prints each line to the console.

📦 Installation 📦

	1. Clone the repository
	2. Run make to compile the library
	3. Include get_next_line.h in your C files and use it as shown in the example above