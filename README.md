### systemCalls


`open(filename, int flags, int mode)`

open returns a int filedescriptor

**open flags int constants**
    1. O_RDONLY: read only 
    2. O_WRONLY: write only
    3. O_RDWR: read and write 
    4. O_CREAT: create file if it doesn’t exist
    5. O_EXCL: prevent creation if it already exists




`write(fd, * buf, size_t count)`

write() writes up to count bytes from the buffer starting at buf to
       the file referred to by the file descriptor fd.