#include <main_header.h>
#define BUFSIZE 1024
#define ERR_MESSAGE_WIN "1: Ressource analysis unavailable on windows"
#define CPU_SIZE_ARR 11
#define CPU_LEN_STR 12

// cpu info goes in that order user, nice, system, idle, iowait, irq, softirq, steal;

int linux_cpu_perf() 
{

    int fd = open("/proc/stat", O_RDONLY);
    init_my_readline();
    char* str = my_readline(fd);
    close(fd);
    my_readline(-1);
    char** tokens = dirty_split(str, 0, ' ');
    int index = 1;
    long long total = 0;
    long long value = 0;
    long long idle = 0;
    double cpu_usage = 0;
    int len = 0;
    while (index < CPU_SIZE_ARR)
    {
        len = my_strlen(tokens[index]);
        value = my_ctoi(tokens[index],len);
        total += value; 
        if (index == 5)
        {
            idle = value; 
        }
        index += 1;
    }
    cpu_usage = (double)(total - idle) / total * 100.0;
    printf("the total is : %lli\n", total);
    printf("idle value is : %lli\n", idle);
    printf("CPU usage: %.2f%%\n", cpu_usage);
    free(str);
    free(tokens);
    return 0; 
}

int linux_mem_perf()
{
    int fd = open("/proc/meminfo", O_RDONLY);
    init_my_readline();
    char* str = NULL ;
    int index = 0;
    char** tokens = NULL;
    int count = 0;
    long arr[3] = {0};
    int len = 0;
    double mem_usage = 0;
    while ((str = my_readline(fd)))
    {
        count = count_cmd(str) -1;
        tokens = dirty_split(str, 0, ' ');
        len = my_strlen(tokens[count]);
        arr[index] = my_ctoi(tokens[count], len);
        index += 1;
        free(str);
        free(tokens);
        if (index == 3)
        {
            fd = -1;
        }
    }
    // free(str);
    mem_usage = (double)(arr[0] - arr[2]) / arr[0] * 100.0;
    printf("mem usage is: %.2f%%\n",mem_usage);
    close(fd);
}

// int linux_perf_analysis_counter_check() 
// {
//     char buffer[BUFSIZE]; 
//     FILE *fp; // Open the /proc/stat file for reading 
//     fp = fopen("/proc/stat", "r");
//     if (fp == NULL)
//     {
//         perror("Error opening /proc/stat");
//         exit(EXIT_FAILURE);
//     }
//     // Read the first line of the file, which contains the CPU information 
//     if (fgets(buffer, BUFSIZE, fp) == NULL) 
//     {
//         perror("Error reading /proc/stat");
//         exit(EXIT_FAILURE);
//     }
//         // Extract the CPU information from the line
//     long long user, nice, system, idle, iowait, irq, softirq, steal;
//     if (sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal) != 8)
//     { 
//         perror("Error parsing /proc/stat");
//         exit(EXIT_FAILURE);
//     } 
//     // Calculate the total CPU usage
//     long long total = user + nice + system + idle + iowait + irq + softirq + steal;
//     // Calculate the percentage of CPU usage
//     double usage = (double)(total - idle) / total * 100.0; 
//     // Print the results
//     printf("the total is : %lli\n", total);
//     printf("idle value is : %lli\n", idle);
//     printf("CPU usage: %.2f%%\n", usage); 
//     // Close the /proc/stat file 
//     fclose(fp); 
//     return 0; 
// }


void operating_sys()
{

#ifdef _WIN32   
    printf("1: Ressource analysis unavailable on windows\n");

#elif _WIN64
    printf("1: Ressource analysis unavailable on windows\n");

#elif __linux__ 
    printf("Running on Linux\n");
    linux_cpu_perf();
    linux_mem_perf();
    // printf("counter check");
    // linux_perf_analysis_counter_check();

#elif __APPLE__
    printf("1: Ressource analysis unavailable on mac os\n");

#endif 
}