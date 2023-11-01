<h1 align="center">📚 Get_Next_Line Project</h1>

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
    int file_descriptor;
    char *line = NULL;

    // Open the file
    file_descriptor = open("test.txt", O_RDONLY);
    if (file_descriptor < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Use fetch_next_line to read lines from the file
    while (fetch_next_line(file_descriptor, &line) > 0)
    {
        // Print each line to the console
        printf("%s\n", line);
        // Free the memory allocated for each line
        free(line);
        line = NULL;
    }

    // Check if there was an error reading the last line
    if (line != NULL)
    {
        free(line);
    }

    // Close the file
    close(file_descriptor);

	//   It is also possible to run cc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c -o get_next_line and modify BUFFER_SIZE 

    return (0);
}
This example reads a file named test.txt and prints each line to the console.
