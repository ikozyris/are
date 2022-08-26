#include <stdio.h>
#include <string.h>

    FILE* fp;
    char option[20];
    size_t lines = 1;
    int ch, indx, m;
    char fname[20];
    


int e()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    while ((ch = getc(fp)) != EOF)
    {
        if(ch=='\n')
            printf("$");
        putc(ch, stdout);

    }
    printf("$\n");
    fclose(fp);
    return 0;
}

int rl()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    printf ("%03zu |", lines++);
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
        if (ch == '\n')
        {
            printf ("%03zu |", lines++);
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}

int r()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    printf("\n");
    fclose(fp);
    return 0;
}

int hlp()
{  
    printf( "Usage: are [FILE]... [OPTION]...                                              \n"
            "   -r   --read              Read file                                         \n"
            "   -rl  --read-lines        Read with the line number before each line        \n"
            "   -e,  --show-ends         Display $ at end of each line                     \n"
            "   -sn  --single-number     Print total line number at the start              \n"
            "   -h   --help              Display this help and exit                        \n"
            "   -v   --version           Output version information and exit               \n\n"
            "Examples:                                                                     \n"
            "    are ~/text.txt -sn              Read text.txt without printing the lines  \n"
            "    are /etc/apt/sources.list -r    Read normally                             \n"
            "                                                                              \n"
	       "Documentation can be found on github.com/ikozyris/are/wiki                   \n");
    return 0;
}

int sn()
{
    fp = fopen(fname,"r");
    if(fp  == NULL)
    {
        perror("fopen(): ");
        return -1;
    }
    else
    {
    while((ch=fgetc(fp))!=EOF)//getting number of lines
    {
        if(ch=='\n')
            lines++;
    }
    fclose(fp);
    fp = fopen(fname,"r"); //open file in read mode
    printf("lines:%ld\n-------\n", lines);
    while ((ch = getc(fp)) != EOF)
        putc(ch, stdout);
    fclose(fp);
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        if (strcmp("-v", argv[1]) == 0 || strcmp("--version", argv[1]) == 0) {
            printf("ARE - Advanced REader Version 0.1 Created by ikozyris and gkozyris\nLicensed under Gnu General Public License v3\nSource code available at: http://github.com/ikozyris/are/ \n");
            return 0;
        }

	    if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
            hlp();
	        return 0;
	    }

        else printf("Invalid argument %s", argv[1]);
    }

    if (argc == 3)
    {
        strcpy(fname, argv[1]);
        strcpy(option, argv[2]);

        if (strcmp("-sn", option) == 0 || strcmp("--single-number", option) == 0) {
            sn();
            return 0;
        }

        if (strcmp("-e", option) == 0 || strcmp("--show-ends", option) == 0) {
            e();
            return 0;
        }

        if (strcmp("-rl", option) == 0 || strcmp("--read-lines", option) == 0) {
            rl();
            return 0;
        }

        if (strcmp("-r", option) == 0 || strcmp("--read", option) == 0) {
            r();
            return 0;
        }

        else hlp();
    }
}
