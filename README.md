### systemCalls


`open(filename, int flags, int mode)`

open returns a int filedescriptor

**open flags int constants**
    O_RDONLY: read only 
    O_WRONLY: write only
    O_RDWR: read and write 
    O_CREAT: create file if it doesn’t exist
    O_EXCL: prevent creation if it already exists





write() writes up to count bytes from the buffer starting at buf to
       the file referred to by the file descriptor fd.
`write(fd, * buf, size_t count)`


read() reads a file into a buff
`ssize_t read(int fd, void *buf, size_t count)`


chmod() sets the privileges of file 2 to match file 1
`int chmod(const char *pathname, mode_t mode);`

stat() gets the metadata of a file
`int stat(const char *pathname, struct stat *statbuf);`

close() close a file
`close(int fileDescriptor)`