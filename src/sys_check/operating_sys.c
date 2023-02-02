#include <main_header.h>

// cpu info goes in that order user, nice, system, idle, iowait, irq, softirq, steal;

int linux_cpu_perf() 
{
    int index = 1;
    long long total = 0;
    long long value = 0;
    long long idle = 0;
    double cpu_usage = 0;
    int len = 0;
    int fd = open("/proc/stat", O_RDONLY);
    char* str = my_readline(fd);
    close(fd);
    tmp_buff_reset();
    char** tokens = dirty_split(str, 0, ' ');

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

    free(str);
    free(tokens);
     printf("CPU usage: %.2f%%\n", cpu_usage);
    return cpu_usage; 
}
    // printf("the total is : %lli\n", total);
    // printf("idle value is : %lli\n", idle);

int linux_mem_perf()
{
    int fd = open("/proc/meminfo", O_RDONLY);
    char* str = NULL ;
    int index = 0;
    char** tokens = NULL;
    int count = 0;
    long arr[3] = {0};
    int len = 0;
    double mem_usage = 0;
    while ((str = my_readline(fd)))
    {
        count = count_cmd(str) - 1;
        tokens = dirty_split(str, 0, ' ');
        len = my_strlen(tokens[count]);
        arr[index] = my_ctoi(tokens[count], len);
        index += 1;
        free(str);
        free(tokens);
        if (index == 3)
        {
            tmp_buff_reset();
            break;
        }
    }
    mem_usage = (double)(arr[0] - arr[2]) / arr[0] * 100.0;
    close(fd);
    printf("mem usage is: %.2f%%\n",mem_usage);
    return mem_usage;
}

int operating_sys()
{
#ifdef _WIN32
    write(STDERR_FILENO,ERR_MESSAGE_WIN, ERR_MESSAGE_WIN_SIZE)
    return EXIT_SUCCESS
#elif _WIN64
    write(STDERR_FILENO,ERR_MESSAGE_WIN, ERR_MESSAGE_WIN_SIZE)
    return EXIT_SUCCESS
#elif __linux__
    // printf("Running on Linux\n");
    if (linux_cpu_perf() > PERF_LIMIT || linux_mem_perf() > PERF_LIMIT)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
#elif __APPLE__
    write(STDERR_FILENO, ERR_MESSAGE_MACOS, ERR_MESSAGE_MACOS_SIZE)
    return EXIT_SUCCESS
#endif
}