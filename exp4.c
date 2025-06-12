#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;
    
    struct stat fileStat;
    
    if (stat(argv[1], &fileStat) < 0)
        return 1;
    
    printf("Information for %s\n", argv[1]);
    printf("*****************************\n");
    printf("File Size: \t\t %ld bytes \n", fileStat.st_size);
    printf("File Access Time: \t\t %ld \n", fileStat.st_atime);
    printf("File Permission: 't");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    return 0;
}
