#include <main_header.h>
#define BUFSIZE 1024 

int linux_perf_analysis() 
{ 
    char buffer[BUFSIZE]; 
    FILE *fp; // Open the /proc/stat file for reading 
    fp = fopen("/proc/stat", "r");
    if (fp == NULL)
    { 
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    } 
    // Read the first line of the file, which contains the CPU information 
    if (fgets(buffer, BUFSIZE, fp) == NULL) 
    { 
        perror("Error reading /proc/stat");
        exit(EXIT_FAILURE);
    }
        // Extract the CPU information from the line
    long long user, nice, system, idle, iowait, irq, softirq, steal;
    if (sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal) != 8)
    { 
        perror("Error parsing /proc/stat");
        exit(EXIT_FAILURE);
    } 
    // Calculate the total CPU usage
    long long total = user + nice + system + idle + iowait + irq + softirq + steal;
    // Calculate the percentage of CPU usage 
    double usage = (double)(total - idle) / total * 100.0; 
    // Print the results 
    printf("CPU usage: %.2f%%\n", usage); 
    // Close the /proc/stat file 
    fclose(fp); 
    return 0; 
}

void operating_sys()
{

#ifdef _WIN32   
    printf("1: Ressource analysis unavailable on windows\n");

#elif __linux__ 
    printf("Running on Linux\n");
    linux_perf_analysis();

#elif __APPLE__
    printf("1: Ressource analysis unavailable on mac os\n");

#endif 
}