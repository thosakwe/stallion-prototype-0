/* note these headers are all provided by newlib - you don't need to provide
 * them */
#include <stallion/stallion.h>
#include <stdio.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>

char **environ; /* pointer to array of char * strings that define the current
                   environment variables */

void _exit() {
  // TODO: How to get exit code from newlib?
  stallion_syscall_exit(0);
}

int close(int file);
int execve(char *name, char **argv, char **env);
int fork();
int fstat(int file, struct stat *st);

int getpid() {
  return stallion_syscall_get_pid();
}

int isatty(int file);
int kill(int pid, int sig);
int link(char *old, char *new);
int lseek(int file, int ptr, int dir);
int open(const char *name, int flags, ...);
int read(int file, char *ptr, int len);
caddr_t sbrk(int incr);
int stat(const char *file, struct stat *st);
clock_t times(struct tms *buf);
int unlink(char *name);
int wait(int *status);
int write(int file, char *ptr, int len);
// int gettimeofday(struct timeval *__restrict p, struct timezone *__restrict
// z);