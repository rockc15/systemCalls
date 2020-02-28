#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h> 

#define	BUFFSIZE    4096



void main(int argc, char *argv[]){
    struct stat buf1;
    struct stat buf2;
    char override = ' ';
    int file1Desc;
    int file2Desc;
    char file1Buf[BUFFSIZE];
    

    if(argc != 3){
        perror("You must have two files too run mycopy.c");
        exit(1);
    }

    //gets the stats on file1
    if(stat(argv[1], &buf1) < 0){
        perror("File 1 does not exsit");
        exit(1);
    }


    //opens file1 and read it into file1buf
    file1Desc = open(argv[1], O_RDWR);
    read(file1Desc, file1Buf,  buf1.st_size);

    //handles file2
    if(stat(argv[2], &buf2) >= 0){
        printf("Do you want to overide %s? (y/n) > ", argv[2]);
        scanf("%c", &override);
        file2Desc = open(argv[2],  O_RDWR);
    }else{
        file2Desc = open(argv[2],  O_RDWR | O_CREAT);
        write(file2Desc, file1Buf, buf1.st_size);
        chmod(argv[2], buf1.st_mode);
    }

    if(override == 'y'){
        write(file2Desc, file1Buf, buf1.st_size);
        chmod(argv[2], buf1.st_mode);
    } 

    close(file1Desc);
    close(file2Desc);
}