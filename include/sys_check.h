#ifndef __HEADERFILE_G_
#define __HEADERFILE_G_

#define ERR_MESSAGE_WIN "1: Ressource analysis unavailable on windows\n"
#define ERR_MESSAGE_WIN_SIZE 45
#define ERR_MESSAGE_MACOS "1: Ressource analysis unavailable on mac os\n"
#define ERR_MESSAGE_MACOS_SIZE 44
#define CPU_SIZE_ARR 11
#define CPU_LEN_STR 12

int     operating_sys();
int     linux_perf_analysis();
int     linux_mem_perf();

#endif