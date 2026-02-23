/////////////////////////////////////////////////////////////
//
// Final Code 
//
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//
// Using Every Command Of Linux
//
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//
// Header For Function call
//
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/utsname.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>

/////////////////////////////////////////////////////////////
//
// INBUILD MACRO
//
/////////////////////////////////////////////////////////////

#define MAX_BUFFER_SIZE 1024

/////////////////////////////////////////////////////////////
//
// USER DEFINED MACRO
//
/////////////////////////////////////////////////////////////

#define MAX_ARGS 20

/////////////////////////////////////////////////////////////
//
// Function     : cdx
// Description  : Directory Path Set
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*
    Algorithm

    Accept new Directory path
    call chdir with that path
    Call getcwd to Check the Changed path

*/

int cdx(int argc, char *argv[])
{
    char Buffer[256] = {'\0'};

    if(argc != 2)
    {
        printf("Error : Insufficient argument\n");
        printf("Use Command as ./cdx DirectoryPath\n");
        return -1;
    }

    if(chdir(argv[1]) == -1)
    {
        printf("Error : Unable to change current Directory\n");

        return -1;
    }

    getcwd(Buffer,sizeof(Buffer)-1);

    printf("Current Directory Change to %s\n",Buffer);

    return 0;
}

/*

    Input   : ./cdx   DirectoryPath 
    Output  : argv[0] argv[1]     

    argc = 2

*/

/////////////////////////////////////////////////////////////
//
// Function     : cpx
// Description  : Copy Files and Directory
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm 

    Open Source File for Reading
    Create Destination File
    Read the Data from Source
    write it into Destination
    close both Files

*/

int cpx(int argc, char *argv[])
{
    int fdSrc = 0,fdDest = 0, iRet = 0;
    char Buffer[MAX_BUFFER_SIZE];

    if(argc != 3)
    {
        printf("cp : Missing file operand\n");
        printf("Use Command as ./cpx SourceFile DestinationFile\n");
        return -1;
    }

    memset(Buffer, '\0', sizeof(Buffer));

    fdSrc = open(argv[1], O_RDONLY);
    if(fdSrc < 0)
    {
        printf("Error : Cannot stat %s\n : No Such file or Directory" ,argv[1]);
        return -1;
    }

    fdDest = creat(argv[2], 0644);
    if(fdDest < 0)
    {
        printf("Error : Missing Destination file operand afte %s\n",argv[2]);
        close(fdSrc);
        return -1;
    }

    while((iRet = read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        if(write(fdDest, Buffer, iRet) != iRet)
        {
            printf("Error : write failed\n");
            close(fdSrc);
            close(fdDest);
            return -1;
        }
    }

    if(iRet < 0)
    {
        printf("Error : Read failed\n");
    }
    else
    {
        printf("Success : Copy completed successfully\n");
    }

    close(fdSrc);
    close(fdDest);

    return 0;
}

/*

    Input   : ./cpx   Source.txt  Des.txt
    Output  : argv[0] argv[1]     argv[2]

    argc = 3

*/

/////////////////////////////////////////////////////////////
//
// Function     : catx
// Description  : Concatenate files and print on the console
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Accept file name from Command line
    Check weather file is existing or not
    if its existing then print on console
    if its not existing
    Display No such file or Directory

*/

int catx(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[MAX_BUFFER_SIZE] = {'\0'};
    int iRet = 0;

    if(argc != 2)
    {
        printf("Error : Insufficient argument\n");
        printf("Use Command as ./catx FileName\n");
        return -1;
    }

    if(access(argv[1], F_OK) != 0)
    {
        printf("cat : %s: No such file or Directory\n",argv[1]);
        return -1;
    }
    else
    {
        fd = open(argv[1], O_RDONLY);

        if(fd < 0)
        {
            printf("Error : Unable to open File\n");
            return -1;
        }

        while((iRet = read(fd,Buffer,sizeof(Buffer))) > 0)
        {
            write(1,Buffer,iRet);
        }
        printf("\n");

        close(fd);
    }

    return 0;
}

/*

    Input   : ./catx    Source.txt  
    Output  : argv[0]   argv[1]     

    argc = 2

*/

/////////////////////////////////////////////////////////////
//
// Function     : lsx
// Description  : List directory contains
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

	Open the Current Directory(".")
	read all aentries from that directory
	print the name of file
	close the directory  
  
*/

int lsx(int argc, char *argv[])
{
    char *path = ".";
    DIR *dp = NULL;
    struct dirent *dobj;
    int Option = 0;
    // 1 : ls -a
    // 2 : ls -i

    if(argc == 1)
    {
        Option = 0;  
    }
    else if(strcmp(argv[1], "-a") == 0)
    {
        Option = 1;
    }
    else if(strcmp(argv[1], "-i") == 0)
    {
        Option = 2;
    }
    else if(strcmp(argv[1], "-d") == 0)
    {
        printf("%s\n", path);
        return 0;
    }
    else
    {
        printf("lsx: invalid option -- '%s'\n", argv[1]);
        return -1;
    }

    dp = opendir(path);
    if(dp == NULL)
    {
        printf("Error : Unable to open Directory\n");
        return -1;
    }

    while((dobj = readdir(dp)) != NULL)
    {
        if(Option == 0)
        {
            if(dobj->d_name[0] != '.')   
                printf("%s\t", dobj->d_name);
        }
        else if(Option == 1)
        {
            printf("%s\t", dobj->d_name);
        }
        else if(Option == 2)
        {
            printf("%ld %s\n", dobj->d_ino, dobj->d_name);
        }
    }

    printf("\n");
    closedir(dp);

    return 0;
}

/*

    Input   : ./lsxx    -i      
    Output  : argv[0]   argv[1]     

    argc = 2

*/

/////////////////////////////////////////////////////////////
//
// Function     : mvx
// Description  : Move (rename) files
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Open Source File for Reading
    Create Destination File
    Read The Data from Source
    Write it into Destination
    Close both Files
  
*/

int mvx(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("mv : missing file operand\n");
        printf("Use command as mvx SourcePath DestinationPath\n");
        return -1;
    }

    if(rename(argv[1],argv[2]) == -1)
    {
        printf("mv: cannot stat %s: No such file or directory\n",argv[1]);
        return -1;
    }
    printf("Success : %s file or direactory gets created\n",argv[2]);
    
    return 0;
}

/*

    Input   : ./mvx     SourcePath  DestPath      
    Output  : argv[0]   argv[1]     argv[2]

    argc = 3

*/

/////////////////////////////////////////////////////////////
//
// Function     : pwdx
// Description  : Print name of Current/working Directory
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm
    
    Call the system call getcwd
    Print the Result of getcwd

*/

int pwdx(int argc, char *argv[])
{
    char Buffer[1024] = {'\0'};

    getcwd(Buffer, sizeof(Buffer));

    printf("%s",Buffer);

    printf("\n");

    return 0;
}

/*

    Input   : ./pwdx          
    Output  : argv[0]   

    argc = 1

*/

/////////////////////////////////////////////////////////////
//
// Function     : rmx
// Description  : Remove files or directory
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Call the system call uname
    print the information from ursname structure

*/
int rmx(int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("rmx : Missing operand\n");
        printf("Use as : ./rmx Path\n");
        return -1;
    }

    if(access(argv[1], F_OK) == 0)
    {
        if(unlink(argv[1]) == -1)
        {
            printf("rmx : Cannot remove %s : No such file or directory\n",argv[1]);
            return -1;
        }
        else
        {
            printf("Success : %s file get Deleted\n",argv[1]);
        }
    }
    else
    {
        printf("Error : Unable to Delete as File\n");
        return -1;
    }

    return 0;
}

/*

    Input   : ./rmx     FileName
    Output  : argv[0]   argv[1]

    argc = 2

*/

/////////////////////////////////////////////////////////////
//
// Function     : statx
// Description  : Display file or file system status
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Accept file Name from command line
    Call access to check existance of file
    Call stat system call to get files metadata
    Display the Metadata

*/

int statx(int argc, char *argv[])
{
    struct stat sobj;
    int iRet = 0;
    char Arr[11] = "----------";

    if(argc != 2)
    {
        printf("stat : Missing operand\n");
        printf("Use command as ./statx Filename\n");
        return -1;
    }

    if(access(argv[1], F_OK) == 0)
    {
        iRet = stat(argv[1], &sobj);

        if(iRet == -1)
        {
            printf("stat : cannot stat %s : No much file or Directory\n",argv[1]);

            return -1;
        }
        printf("File : %s\n", argv[1]);
        printf("Size : %ld bytes\t", (long)sobj.st_size);
        printf("Blocks : %ld\t", (long)sobj.st_blocks);
        printf("IO Block : %ld\t", (long)sobj.st_blksize);
        printf("Inode : %ld\t", (long)sobj.st_ino);
    }
    else
    {
        printf("Error : File Not Found\n");
        return -1;
    }

    // Permission + File Type Section

    if(S_ISDIR(sobj.st_mode)) Arr[0] = 'd';
    if(S_ISLNK(sobj.st_mode)) Arr[0] = 'l';

    // Regular File permision

    if(sobj.st_mode & S_IRUSR) Arr[1] = 'r';
    if(sobj.st_mode & S_IWUSR) Arr[2] = 'w';
    if(sobj.st_mode & S_IXUSR) Arr[3] = 'x';
        
    if(sobj.st_mode & S_IRGRP) Arr[4] = 'r';
    if(sobj.st_mode & S_IWGRP) Arr[5] = 'w';
    if(sobj.st_mode & S_IXGRP) Arr[6] = 'x';
    
    if(sobj.st_mode & S_IROTH) Arr[7] = 'r';
    if(sobj.st_mode & S_IWOTH) Arr[8] = 'w';
    if(sobj.st_mode & S_IXOTH) Arr[9] = 'x';

    printf("File primision : %s\n",Arr);

    return 0;
}

/*

    Input   : ./statx   FileName
    Output  : argv[0]   argv[1]

    argc = 2

*/

/////////////////////////////////////////////////////////////
//
// Function     : touchx
// Description  : Change file timestamps
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Accept file Name from Command Line
    Check weather file is existing or not
    if its existing return
    if its not existing
    create that file

*/

int touchx(int argc, char * argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("touch : missing file operand\n");
        printf("Use command as touch & FileName\n");
        return -1;
    }

    if(access(argv[1], F_OK) == 0)
    {
        return 0;
    }
    else
    {
        fd = creat(argv[1],0777);
        if(fd != -1)
        {
            close(fd);
        }
        printf("Success : %s file gets Created\n",argv[1]);
    }

    return 0;
}

/*

    Input   : ./touchx  FileName
    Output  : argv[0]   argv[1]

    argc = 2

*/

/////////////////////////////////////////////////////////////
//
// Function     : unamex
// Description  : Print System information
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Call the system call uname
    print the information from utsname Structure

*/

int unamex(int argc, char * argv[])
{
    struct utsname obj;
    int iRet = 0;

    iRet = uname(&obj);

    if(iRet == -1)
    {
        printf("Error : unable to fetch System Information\n");
        return -1;
    }

    printf("Operating system Name : %s\n",obj.sysname);
    printf("Node name : %s\n",obj.nodename);
    printf("OS Version : %s\n",obj.release);
    printf("Machine Name : %s\n",obj.machine);
    printf("Version No.%s\n",obj.version);

    return 0;
}

/*

    Input   : ./unamex  
    Output  : argv[0]

    argc = 1

*/

/////////////////////////////////////////////////////////////
//
// Function     : mkdirx_p
// Description  : Make Directories
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 17-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Create Directory
    If its not exist

*/

int mkdir_p(const char *path)
{
    char temp[256];
    char *p = NULL;
    size_t len;

    snprintf(temp, sizeof(temp), "%s", path);
    len = strlen(temp);

    if(temp[len - 1] == '/')
    {
        temp[len - 1] = 0;
    }

    for(p = temp + 1; *p; p++)
    {
        if(*p == '/')
        {
            *p = 0;
            mkdir(temp, 0777);
            *p = '/';
        }
    }

    if(mkdir(temp, 0777) == -1)
    {
        if(errno != EEXIST)
        {
            perror("mkdir -p");
            return -1;
        }
    }

    return 0;
}

/*

    Input   : ./mkdir   -p      DirectoryName
    Output  : argv[0]   argv[1] argv[2]

    argc = 3

*/

/////////////////////////////////////////////////////////////
//
// Function     : mkdirx
// Description  : Make Directories
// Auther       : Ravne Sanyam Bhupendrkumar
// Date         : 17-Feb-2026
//
/////////////////////////////////////////////////////////////

/*

    Algorithm

    Create Directories 
    If its not exist

*/

int mkdirx(int argc, char * argv[])
{
    int fd = 0;

    if(argc < 2)
    {
        printf("%s: Missing Operand\n",argv[0]);
        return -1;
    }

    // mkdir -p
    if(strcmp(argv[1], "-p") == 0)
    {
        if(argc != 3)
        {
            printf("%s -p : Missing Operand\n",argv[1]);
        }

        if(mkdir_p(argv[2]) == 0)
        {
            printf("Success %s: Directory gets Created\n",argv[2]);
        }
        return 0;
    }

    // Normal mkdir
    if(access(argv[1], F_OK) == 0)
    {
        printf("%s: cannot create directory %s: File exists\n",argv[0],argv[1]);
        return 0;
    }
    
    if(mkdir(argv[1], 0777) == -1)
    {
        perror("mkdirx");
        return -1;
    }
    printf("Success : Directory %s created succesfully \n",argv[1]);

    return 0;
}

/*

    Input   : ./mkdirx  DirectoryName  
    Output  : argv[0]   argv[1]

    argc = 1

*/

/*---------------------------------------------------------*/

/////////////////////////////////////////////////////////////
//
// Function     : Main
// Description  : To call the functions Contains logic
// Auther       : Ravne Sanyam Bhupendrakumar
// Date         : 16-Feb-2026
//
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//
// Infinite Loop behave Like shell
//
/////////////////////////////////////////////////////////////

int main()
{
    char command[MAX_BUFFER_SIZE];
    char *argv[MAX_ARGS];
    char cwd[MAX_BUFFER_SIZE];
    int argc;

    while(1)
    {
        getcwd(cwd,sizeof(cwd));

        printf("\033[1;91m%s\033[0m $ ",cwd);     // Colour to shell direcotry 
        fgets(command, sizeof(command), stdin);

        // Remove newline
        command[strcspn(command, "\n")] = 0;

        // Exit condition
        if(strcmp(command, "exit") == 0)
        {
            printf("Exiting shell...\n");
            printf("THANKS FOR USING Sanyam LINUX Shell...\n");
            printf("BYE...\n");

            break;
        }

        // Tokenization
        argc = 0;
        char *token = strtok(command, " ");
        while(token != NULL)
        {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        // For Continue the Loop 
        if(argc == 0)
        {
            continue;
        }

        // Command Handling
        if(strcmp(argv[0], "cpx") == 0)
        {
            cpx(argc, argv);
        }
        else if(strcmp(argv[0], "catx") == 0)
        {
            catx(argc, argv);
        }
        else if(strcmp(argv[0], "cdx") == 0)
        {
            cdx(argc, argv);
        }
        else if(strcmp(argv[0], "lsx") == 0)
        {
            lsx(argc,argv);
        }
        else if(strcmp(argv[0], "mvx") == 0)
        {
            mvx(argc,argv);
        }
        else if(strcmp(argv[0], "pwdx") == 0)
        {
            pwdx(argc,argv);
        }
        else if(strcmp(argv[0], "rmx") == 0)
        {
            rmx(argc,argv);
        }
        else if(strcmp(argv[0], "statx") == 0)
        {
            statx(argc,argv);
        }
        else if(strcmp(argv[0], "touchx") == 0)
        {
            touchx(argc,argv);
        }
        else if(strcmp(argv[0], "unamex") == 0)
        {
            unamex(argc,argv);
        }
        else if(strcmp(argv[0], "mkdirx") == 0)
        {
            mkdirx(argc,argv);
        }
        else if(strcmp(argv[0], "clear") == 0)
        {
            printf("\033[H\033[J");
        }
        else
        {
            printf("%s Command not found\n",argv[0]);
            printf("Use : %sx\n",argv[0]);
        }   
    }

    return 0;
}
