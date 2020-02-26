#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h> 


void main(int argc, char *argv[]){

    struct stat buf;
    char override = ' ';
    int file1Desc;
    int file2Desc;
    FILE *newfile;
    size_t nbyts;


    char file1Buf[20];



    if(argc != 3){
        perror("You must have two files too run mycopy.c");
        exit(1);
    }

    if(stat(argv[1], &buf) < 0){
        perror("File 1 does not exsit");
        exit(1);
    }

    if(stat(argv[2], &buf) >= 0){
        printf("Do you want to overide %s? (y/n) > ", argv[2]);
        scanf("%c", &override);
        file2Desc = open(argv[2], O_RDWR);
    }
    
    

    file1Desc = open(argv[1], O_RDWR);



    read(file1Desc, file1Buf, 20);


    if(override == 'y'){
        write(file2Desc, file1Buf, 20);

    }
        

    







}