#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    FILE *f; //читать текстовый файл
    int fd; //записать в бинарный файл
    int num; 
    
    if (argc < 3)
    {
        printf("Use: ./int2bin text_file bin_file\n");
        return 1;
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Couldn't open file %s\n", argv[1]);
        return 1;
    }
    fd = creat(argv[2], 0644);
    if (fd == -1)
    {
        fprintf(stderr, "Couldn't open file %s\n", argv[2]);
        fclose(f);
        return 1;
    }
    while(fscanf(f, "%d", &num) == 1) //читаем пока есть числа в файле
    {
        write(fd, &num, sizeof(int)); //запись числа в бинарном виде в файл
    }
    fclose(f);
    close(fd);

    return 0;
}
