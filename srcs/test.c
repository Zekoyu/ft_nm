# 0 "./ft_nm.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "./ft_nm.c"
# 1 "././ft_nm.h" 1



# 1 "/usr/include/fortify/stdlib.h" 1 3 4
# 20 "/usr/include/fortify/stdlib.h" 3 4

# 20 "/usr/include/fortify/stdlib.h" 3 4
__extension__

# 1 "/usr/include/stdlib.h" 1 3 4







# 1 "/usr/include/features.h" 1 3 4
# 9 "/usr/include/stdlib.h" 2 3 4
# 21 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 10 "/usr/include/bits/alltypes.h" 3 4
typedef int wchar_t;
# 50 "/usr/include/bits/alltypes.h" 3 4
typedef unsigned long size_t;
# 22 "/usr/include/stdlib.h" 2 3 4

int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);

long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);
void *aligned_alloc(size_t, size_t);

_Noreturn void abort (void);
int atexit (void (*) (void));
_Noreturn void exit (int);
_Noreturn void _Exit (int);
int at_quick_exit (void (*) (void));
_Noreturn void quick_exit (int);

char *getenv (const char *);

int system (const char *);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

int mblen (const char *, size_t);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);
int wctomb (char *, wchar_t);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);




size_t __ctype_get_mb_cur_max(void);
# 101 "/usr/include/stdlib.h" 3 4
int posix_memalign (void **, size_t, size_t);
int setenv (const char *, const char *, int);
int unsetenv (const char *);
int mkstemp (char *);
int mkostemp (char *, int);
char *mkdtemp (char *);
int getsubopt (char **, char *const *, char **);
int rand_r (unsigned *);






char *realpath (const char *restrict, char *restrict);
long int random (void);
void srandom (unsigned int);
char *initstate (unsigned int, char *, size_t);
char *setstate (char *);
int putenv (char *);
int posix_openpt (int);
int grantpt (int);
int unlockpt (int);
char *ptsname (int);
char *l64a (long);
long a64l (const char *);
void setkey (const char *);
double drand48 (void);
double erand48 (unsigned short [3]);
long int lrand48 (void);
long int nrand48 (unsigned short [3]);
long mrand48 (void);
long jrand48 (unsigned short [3]);
void srand48 (long);
unsigned short *seed48 (unsigned short [3]);
void lcong48 (unsigned short [7]);



# 1 "/usr/include/alloca.h" 1 3 4
# 9 "/usr/include/alloca.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 10 "/usr/include/alloca.h" 2 3 4

void *alloca(size_t);
# 141 "/usr/include/stdlib.h" 2 3 4
char *mktemp (char *);
int mkstemps (char *, int);
int mkostemps (char *, int, int);
void *valloc (size_t);
void *memalign(size_t, size_t);
int getloadavg(double *, int);
int clearenv(void);


void *reallocarray (void *, size_t, size_t);
void qsort_r (void *, size_t, size_t, int (*)(const void *, const void *, void *), void *);
# 23 "/usr/include/fortify/stdlib.h" 2 3 4
# 5 "././ft_nm.h" 2
# 1 "/usr/include/sys/stat.h" 1 3 4
# 21 "/usr/include/sys/stat.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 85 "/usr/include/bits/alltypes.h" 3 4
typedef long time_t;
# 152 "/usr/include/bits/alltypes.h" 3 4
typedef unsigned mode_t;




typedef unsigned long nlink_t;




typedef long off_t;




typedef unsigned long ino_t;




typedef unsigned long dev_t;




typedef long blksize_t;




typedef long blkcnt_t;
# 229 "/usr/include/bits/alltypes.h" 3 4
struct timespec { time_t tv_sec; int :8*(sizeof(time_t)-sizeof(long))*(1234==4321); long tv_nsec; int :8*(sizeof(time_t)-sizeof(long))*(1234!=4321); };
# 245 "/usr/include/bits/alltypes.h" 3 4
typedef unsigned uid_t;




typedef unsigned gid_t;
# 22 "/usr/include/sys/stat.h" 2 3 4

# 1 "/usr/include/bits/stat.h" 1 3 4



struct stat {
 dev_t st_dev;
 ino_t st_ino;
 nlink_t st_nlink;

 mode_t st_mode;
 uid_t st_uid;
 gid_t st_gid;
 unsigned int __pad0;
 dev_t st_rdev;
 off_t st_size;
 blksize_t st_blksize;
 blkcnt_t st_blocks;

 struct timespec st_atim;
 struct timespec st_mtim;
 struct timespec st_ctim;
 long __unused[3];
};
# 24 "/usr/include/sys/stat.h" 2 3 4
# 73 "/usr/include/sys/stat.h" 3 4
int stat(const char *restrict, struct stat *restrict);
int fstat(int, struct stat *);
int lstat(const char *restrict, struct stat *restrict);
int fstatat(int, const char *restrict, struct stat *restrict, int);
int chmod(const char *, mode_t);
int fchmod(int, mode_t);
int fchmodat(int, const char *, mode_t, int);
mode_t umask(mode_t);
int mkdir(const char *, mode_t);
int mkfifo(const char *, mode_t);
int mkdirat(int, const char *, mode_t);
int mkfifoat(int, const char *, mode_t);


int mknod(const char *, mode_t, dev_t);
int mknodat(int, const char *, mode_t, dev_t);


int futimens(int, const struct timespec [2]);
int utimensat(int, const char *, const struct timespec [2], int);


int lchmod(const char *, mode_t);
# 6 "././ft_nm.h" 2
# 1 "/usr/include/fortify/unistd.h" 1 3 4
# 20 "/usr/include/fortify/unistd.h" 3 4
__extension__

# 1 "/usr/include/unistd.h" 1 3 4
# 37 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 65 "/usr/include/bits/alltypes.h" 3 4
typedef long ssize_t;




typedef long intptr_t;
# 235 "/usr/include/bits/alltypes.h" 3 4
typedef int pid_t;
# 260 "/usr/include/bits/alltypes.h" 3 4
typedef unsigned useconds_t;
# 38 "/usr/include/unistd.h" 2 3 4

int pipe(int [2]);
int pipe2(int [2], int);
int close(int);
int posix_close(int, int);
int dup(int);
int dup2(int, int);
int dup3(int, int, int);
off_t lseek(int, off_t, int);
int fsync(int);
int fdatasync(int);

ssize_t read(int, void *, size_t);
ssize_t write(int, const void *, size_t);
ssize_t pread(int, void *, size_t, off_t);
ssize_t pwrite(int, const void *, size_t, off_t);

int chown(const char *, uid_t, gid_t);
int fchown(int, uid_t, gid_t);
int lchown(const char *, uid_t, gid_t);
int fchownat(int, const char *, uid_t, gid_t, int);

int link(const char *, const char *);
int linkat(int, const char *, int, const char *, int);
int symlink(const char *, const char *);
int symlinkat(const char *, int, const char *);
ssize_t readlink(const char *restrict, char *restrict, size_t);
ssize_t readlinkat(int, const char *restrict, char *restrict, size_t);
int unlink(const char *);
int unlinkat(int, const char *, int);
int rmdir(const char *);
int truncate(const char *, off_t);
int ftruncate(int, off_t);






int access(const char *, int);
int faccessat(int, const char *, int, int);

int chdir(const char *);
int fchdir(int);
char *getcwd(char *, size_t);

unsigned alarm(unsigned);
unsigned sleep(unsigned);
int pause(void);

pid_t fork(void);
pid_t _Fork(void);
int execve(const char *, char *const [], char *const []);
int execv(const char *, char *const []);
int execle(const char *, const char *, ...);
int execl(const char *, const char *, ...);
int execvp(const char *, char *const []);
int execlp(const char *, const char *, ...);
int fexecve(int, char *const [], char *const []);
_Noreturn void _exit(int);

pid_t getpid(void);
pid_t getppid(void);
pid_t getpgrp(void);
pid_t getpgid(pid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
pid_t getsid(pid_t);
char *ttyname(int);
int ttyname_r(int, char *, size_t);
int isatty(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);

uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
int getgroups(int, gid_t []);
int setuid(uid_t);
int seteuid(uid_t);
int setgid(gid_t);
int setegid(gid_t);

char *getlogin(void);
int getlogin_r(char *, size_t);
int gethostname(char *, size_t);
char *ctermid(char *);

int getopt(int, char * const [], const char *);
extern char *optarg;
extern int optind, opterr, optopt;

long pathconf(const char *, int);
long fpathconf(int, int);
long sysconf(int);
size_t confstr(int, char *, size_t);






int setreuid(uid_t, uid_t);
int setregid(gid_t, gid_t);
int lockf(int, int, off_t);
long gethostid(void);
int nice(int);
void sync(void);
pid_t setpgrp(void);
char *crypt(const char *, const char *);
void encrypt(char *, int);
void swab(const void *restrict, void *restrict, ssize_t);




int usleep(unsigned);
unsigned ualarm(unsigned, unsigned);






int brk(void *);
void *sbrk(intptr_t);
pid_t vfork(void);
int vhangup(void);
int chroot(const char *);
int getpagesize(void);
int getdtablesize(void);
int sethostname(const char *, size_t);
int getdomainname(char *, size_t);
int setdomainname(const char *, size_t);
int setgroups(size_t, const gid_t *);
char *getpass(const char *);
int daemon(int, int);
void setusershell(void);
void endusershell(void);
char *getusershell(void);
int acct(const char *);
long syscall(long, ...);
int execvpe(const char *, char *const [], char *const []);
int issetugid(void);
int getentropy(void *, size_t);
extern int optreset;
# 260 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix.h" 1 3 4
# 261 "/usr/include/unistd.h" 2 3 4
# 23 "/usr/include/fortify/unistd.h" 2 3 4
# 7 "././ft_nm.h" 2
# 1 "/usr/include/fcntl.h" 1 3 4
# 20 "/usr/include/fcntl.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 21 "/usr/include/fcntl.h" 2 3 4

# 1 "/usr/include/bits/fcntl.h" 1 3 4
# 23 "/usr/include/fcntl.h" 2 3 4

struct flock {
 short l_type;
 short l_whence;
 off_t l_start;
 off_t l_len;
 pid_t l_pid;
};

int creat(const char *, mode_t);
int fcntl(int, int, ...);
int open(const char *, int, ...);
int openat(int, const char *, int, ...);
int posix_fadvise(int, off_t, off_t, int);
int posix_fallocate(int, off_t, off_t);
# 159 "/usr/include/fcntl.h" 3 4
int lockf(int, int, off_t);
# 8 "././ft_nm.h" 2
# 1 "/usr/include/fortify/stdio.h" 1 3 4
# 20 "/usr/include/fortify/stdio.h" 3 4
__extension__

# 1 "/usr/include/stdio.h" 1 3 4
# 26 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 320 "/usr/include/bits/alltypes.h" 3 4
typedef struct _IO_FILE FILE;





typedef __builtin_va_list va_list;




typedef __builtin_va_list __isoc_va_list;
# 27 "/usr/include/stdio.h" 2 3 4
# 56 "/usr/include/stdio.h" 3 4
typedef union _G_fpos64_t {
 char __opaque[16];
 long long __lldata;
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);




int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);




char *cuserid(char *);
void setlinebuf(FILE *);
void setbuffer(FILE *, char *, size_t);
int fgetc_unlocked(FILE *);
int fputc_unlocked(int, FILE *);
int fflush_unlocked(FILE *);
size_t fread_unlocked(void *, size_t, size_t, FILE *);
size_t fwrite_unlocked(const void *, size_t, size_t, FILE *);
void clearerr_unlocked(FILE *);
int feof_unlocked(FILE *);
int ferror_unlocked(FILE *);
int fileno_unlocked(FILE *);
int getw(FILE *);
int putw(int, FILE *);
char *fgetln(FILE *, size_t *);
int asprintf(char **, const char *, ...);
int vasprintf(char **, const char *, __isoc_va_list);
# 23 "/usr/include/fortify/stdio.h" 2 3 4
# 9 "././ft_nm.h" 2
# 1 "/usr/include/sys/mman.h" 1 3 4
# 17 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 18 "/usr/include/sys/mman.h" 2 3 4
# 114 "/usr/include/sys/mman.h" 3 4
# 1 "/usr/include/bits/mman.h" 1 3 4
# 115 "/usr/include/sys/mman.h" 2 3 4

void *mmap (void *, size_t, int, int, int, off_t);
int munmap (void *, size_t);

int mprotect (void *, size_t, int);
int msync (void *, size_t, int);

int posix_madvise (void *, size_t, int);

int mlock (const void *, size_t);
int munlock (const void *, size_t);
int mlockall (int);
int munlockall (void);
# 137 "/usr/include/sys/mman.h" 3 4
int madvise (void *, size_t, int);
int mincore (void *, size_t, unsigned char *);


int shm_open (const char *, int, mode_t);
int shm_unlink (const char *);
# 10 "././ft_nm.h" 2
# 1 "/usr/include/stdint.h" 1 3 4
# 20 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 55 "/usr/include/bits/alltypes.h" 3 4
typedef unsigned long uintptr_t;
# 96 "/usr/include/bits/alltypes.h" 3 4
typedef signed char int8_t;




typedef signed short int16_t;




typedef signed int int32_t;




typedef signed long int64_t;




typedef signed long intmax_t;




typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned int uint32_t;




typedef unsigned long uint64_t;
# 146 "/usr/include/bits/alltypes.h" 3 4
typedef unsigned long uintmax_t;
# 21 "/usr/include/stdint.h" 2 3 4

typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
# 95 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/stdint.h" 1 3 4
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 96 "/usr/include/stdint.h" 2 3 4
# 11 "././ft_nm.h" 2



# 1 "/usr/include/elf.h" 1 3 4
# 10 "/usr/include/elf.h" 3 4
typedef uint16_t Elf32_Half;
typedef uint16_t Elf64_Half;

typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf64_Word;
typedef int32_t Elf64_Sword;

typedef uint64_t Elf32_Xword;
typedef int64_t Elf32_Sxword;
typedef uint64_t Elf64_Xword;
typedef int64_t Elf64_Sxword;

typedef uint32_t Elf32_Addr;
typedef uint64_t Elf64_Addr;

typedef uint32_t Elf32_Off;
typedef uint64_t Elf64_Off;

typedef uint16_t Elf32_Section;
typedef uint16_t Elf64_Section;

typedef Elf32_Half Elf32_Versym;
typedef Elf64_Half Elf64_Versym;



typedef struct {
  unsigned char e_ident[(16)];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct {
  unsigned char e_ident[(16)];
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;
  Elf64_Off e_phoff;
  Elf64_Off e_shoff;
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;
# 326 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word sh_name;
  Elf32_Word sh_type;
  Elf32_Word sh_flags;
  Elf32_Addr sh_addr;
  Elf32_Off sh_offset;
  Elf32_Word sh_size;
  Elf32_Word sh_link;
  Elf32_Word sh_info;
  Elf32_Word sh_addralign;
  Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct {
  Elf64_Word sh_name;
  Elf64_Word sh_type;
  Elf64_Xword sh_flags;
  Elf64_Addr sh_addr;
  Elf64_Off sh_offset;
  Elf64_Xword sh_size;
  Elf64_Word sh_link;
  Elf64_Word sh_info;
  Elf64_Xword sh_addralign;
  Elf64_Xword sh_entsize;
} Elf64_Shdr;
# 426 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word ch_type;
  Elf32_Word ch_size;
  Elf32_Word ch_addralign;
} Elf32_Chdr;

typedef struct {
  Elf64_Word ch_type;
  Elf64_Word ch_reserved;
  Elf64_Xword ch_size;
  Elf64_Xword ch_addralign;
} Elf64_Chdr;
# 448 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Section st_shndx;
} Elf32_Sym;

typedef struct {
  Elf64_Word st_name;
  unsigned char st_info;
  unsigned char st_other;
  Elf64_Section st_shndx;
  Elf64_Addr st_value;
  Elf64_Xword st_size;
} Elf64_Sym;

typedef struct {
  Elf32_Half si_boundto;
  Elf32_Half si_flags;
} Elf32_Syminfo;

typedef struct {
  Elf64_Half si_boundto;
  Elf64_Half si_flags;
} Elf64_Syminfo;
# 534 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;

typedef struct {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
} Elf64_Rel;



typedef struct {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
  Elf32_Sword r_addend;
} Elf32_Rela;

typedef struct {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
  Elf64_Sxword r_addend;
} Elf64_Rela;
# 570 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;

typedef struct {
  Elf64_Word p_type;
  Elf64_Word p_flags;
  Elf64_Off p_offset;
  Elf64_Addr p_vaddr;
  Elf64_Addr p_paddr;
  Elf64_Xword p_filesz;
  Elf64_Xword p_memsz;
  Elf64_Xword p_align;
} Elf64_Phdr;
# 705 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Sword d_tag;
  union {
      Elf32_Word d_val;
      Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;

typedef struct {
  Elf64_Sxword d_tag;
  union {
      Elf64_Xword d_val;
      Elf64_Addr d_ptr;
  } d_un;
} Elf64_Dyn;
# 874 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Half vd_version;
  Elf32_Half vd_flags;
  Elf32_Half vd_ndx;
  Elf32_Half vd_cnt;
  Elf32_Word vd_hash;
  Elf32_Word vd_aux;
  Elf32_Word vd_next;
} Elf32_Verdef;

typedef struct {
  Elf64_Half vd_version;
  Elf64_Half vd_flags;
  Elf64_Half vd_ndx;
  Elf64_Half vd_cnt;
  Elf64_Word vd_hash;
  Elf64_Word vd_aux;
  Elf64_Word vd_next;
} Elf64_Verdef;
# 912 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word vda_name;
  Elf32_Word vda_next;
} Elf32_Verdaux;

typedef struct {
  Elf64_Word vda_name;
  Elf64_Word vda_next;
} Elf64_Verdaux;




typedef struct {
  Elf32_Half vn_version;
  Elf32_Half vn_cnt;
  Elf32_Word vn_file;
  Elf32_Word vn_aux;
  Elf32_Word vn_next;
} Elf32_Verneed;

typedef struct {
  Elf64_Half vn_version;
  Elf64_Half vn_cnt;
  Elf64_Word vn_file;
  Elf64_Word vn_aux;
  Elf64_Word vn_next;
} Elf64_Verneed;
# 949 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word vna_hash;
  Elf32_Half vna_flags;
  Elf32_Half vna_other;
  Elf32_Word vna_name;
  Elf32_Word vna_next;
} Elf32_Vernaux;

typedef struct {
  Elf64_Word vna_hash;
  Elf64_Half vna_flags;
  Elf64_Half vna_other;
  Elf64_Word vna_name;
  Elf64_Word vna_next;
} Elf64_Vernaux;







typedef struct {
  uint32_t a_type;
  union {
      uint32_t a_val;
  } a_un;
} Elf32_auxv_t;

typedef struct {
  uint64_t a_type;
  union {
      uint64_t a_val;
  } a_un;
} Elf64_auxv_t;
# 1056 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word n_namesz;
  Elf32_Word n_descsz;
  Elf32_Word n_type;
} Elf32_Nhdr;

typedef struct {
  Elf64_Word n_namesz;
  Elf64_Word n_descsz;
  Elf64_Word n_type;
} Elf64_Nhdr;
# 1099 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Xword m_value;
  Elf32_Word m_info;
  Elf32_Word m_poffset;
  Elf32_Half m_repeat;
  Elf32_Half m_stride;
} Elf32_Move;

typedef struct {
  Elf64_Xword m_value;
  Elf64_Xword m_info;
  Elf64_Xword m_poffset;
  Elf64_Half m_repeat;
  Elf64_Half m_stride;
} Elf64_Move;
# 1446 "/usr/include/elf.h" 3 4
typedef union {
  struct {
      Elf32_Word gt_current_g_value;
      Elf32_Word gt_unused;
  } gt_header;
  struct {
      Elf32_Word gt_g_value;
      Elf32_Word gt_bytes;
  } gt_entry;
} Elf32_gptab;



typedef struct {
  Elf32_Word ri_gprmask;
  Elf32_Word ri_cprmask[4];
  Elf32_Sword ri_gp_value;
} Elf32_RegInfo;



typedef struct {
  unsigned char kind;

  unsigned char size;
  Elf32_Section section;

  Elf32_Word info;
} Elf_Options;
# 1517 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word hwp_flags1;
  Elf32_Word hwp_flags2;
} Elf_Options_Hw;
# 1677 "/usr/include/elf.h" 3 4
typedef struct {
  Elf32_Word l_name;
  Elf32_Word l_time_stamp;
  Elf32_Word l_checksum;
  Elf32_Word l_version;
  Elf32_Word l_flags;
} Elf32_Lib;

typedef struct {
  Elf64_Word l_name;
  Elf64_Word l_time_stamp;
  Elf64_Word l_checksum;
  Elf64_Word l_version;
  Elf64_Word l_flags;
} Elf64_Lib;
# 1706 "/usr/include/elf.h" 3 4
typedef Elf32_Addr Elf32_Conflict;

typedef struct {
  Elf32_Half version;
  unsigned char isa_level;
  unsigned char isa_rev;
  unsigned char gpr_size;
  unsigned char cpr1_size;
  unsigned char cpr2_size;
  unsigned char fp_abi;
  Elf32_Word isa_ext;
  Elf32_Word ases;
  Elf32_Word flags1;
  Elf32_Word flags2;
} Elf_MIPS_ABIFlags_v0;
# 1763 "/usr/include/elf.h" 3 4
enum
{
  Val_GNU_MIPS_ABI_FP_ANY = 0,
  Val_GNU_MIPS_ABI_FP_DOUBLE = 1,
  Val_GNU_MIPS_ABI_FP_SINGLE = 2,
  Val_GNU_MIPS_ABI_FP_SOFT = 3,
  Val_GNU_MIPS_ABI_FP_OLD_64 = 4,
  Val_GNU_MIPS_ABI_FP_XX = 5,
  Val_GNU_MIPS_ABI_FP_64 = 6,
  Val_GNU_MIPS_ABI_FP_64A = 7,
  Val_GNU_MIPS_ABI_FP_MAX = 7
};
# 15 "././ft_nm.h" 2




# 1 "./././libft/libft.h" 1
# 16 "./././libft/libft.h"
# 1 "/usr/include/fortify/string.h" 1 3 4
# 20 "/usr/include/fortify/string.h" 3 4
__extension__

# 1 "/usr/include/string.h" 1 3 4
# 25 "/usr/include/string.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 343 "/usr/include/bits/alltypes.h" 3 4
typedef struct __locale_struct * locale_t;
# 26 "/usr/include/string.h" 2 3 4

void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);


# 1 "/usr/include/fortify/strings.h" 1 3 4
# 19 "/usr/include/fortify/strings.h" 3 4
# 1 "/usr/include/strings.h" 1 3 4
# 11 "/usr/include/strings.h" 3 4
# 1 "/usr/include/bits/alltypes.h" 1 3 4
# 12 "/usr/include/strings.h" 2 3 4




int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
char *index (const char *, int);
char *rindex (const char *, int);



int ffs (int);
int ffsl (long);
int ffsll (long long);


int strcasecmp (const char *, const char *);
int strncasecmp (const char *, const char *, size_t);

int strcasecmp_l (const char *, const char *, locale_t);
int strncasecmp_l (const char *, const char *, size_t, locale_t);
# 20 "/usr/include/fortify/strings.h" 2 3 4
# 60 "/usr/include/string.h" 2 3 4





char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);



char *strsep(char **, const char *);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
void explicit_bzero (void *, size_t);
# 23 "/usr/include/fortify/string.h" 2 3 4
# 17 "./././libft/libft.h" 2
# 1 "./././libft/ft_gnl/ft_gnl.h" 1
# 16 "./././libft/ft_gnl/ft_gnl.h"

# 16 "./././libft/ft_gnl/ft_gnl.h"
char *get_next_line(int fd);
void flush_gnl_buffer(void);
# 18 "./././libft/libft.h" 2
# 1 "./././libft/ft_malloc/ft_malloc.h" 1
# 16 "./././libft/ft_malloc/ft_malloc.h"
void ft_free(void *ptr);
void ft_free_all(void);
void *ft_malloc(size_t size);
# 19 "./././libft/libft.h" 2
# 1 "./././libft/ft_printf/ft_printf.h" 1
# 16 "./././libft/ft_printf/ft_printf.h"
int ft_printf(const char *str, ...);
int ft_printf_fd(int fd, const char *str, ...);
# 20 "./././libft/libft.h" 2


void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
void *ft_realloc(void *mem, size_t size, size_t new_size);


int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_isspace(int c);
int ft_tolower(int c);
int ft_toupper(int c);


void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char const *s, int fd);
void ft_putendl_fd(char const *s, int fd);
void ft_putnbr_fd(int n, int fd);


typedef struct s_list
{
 void *content;
 struct s_list *next;
} t_list;
t_list *ft_lstnew(void const *content);
void ft_lstadd_front(t_list **alst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **alst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


char **ft_split(char const *s, char *charset);
void ft_free_str_array(char **str_array);
char **ft_split_single(char const *s, char c);
void ft_sort_string_array(char **array, int (*sort_func)(char *, char *));
char *ft_concat_str_array(char **array);


size_t ft_strlen(const char *s);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *big, const char *little, size_t len);
void ft_striteri(char *s, void (*f)(unsigned int, char *));
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s, char const *set);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strcmp(const char *s1, const char *s2);
char *ft_rm_substr(char *src, size_t index, size_t size);
char *ft_rm_char(char *src, size_t index);
char *ft_insert_str(char *src, char *str, size_t index);


int ft_is_valid_nbr(char *nbr_str);
int ft_is_str_number(char *number_str);
void print_error_if_needed(char *error, int *printed_error);
int print_error(char *error);
int print_error_plus_arg(char *arg);


long ft_atol(const char *nptr);
int ft_atoi(const char *nptr);
char *ft_itoa(int n);
# 20 "././ft_nm.h" 2



typedef struct s_symbol
{
 char *name;
 size_t offset;
 char type;
} t_symbol;

extern unsigned int g_flags;
# 2 "./ft_nm.c" 2



# 1 "././ft_nm_template.h" 1
# 15 "././ft_nm_template.h"
# 1 "./././ft_nm.h" 1
# 16 "././ft_nm_template.h" 2

void ft_nm_64bits() {
    Elf64_Ehdr pouet;
 return;
}
# 6 "./ft_nm.c" 2

unsigned int g_flags = 0;

void ft_nm(char *filename)
{
 int fd;
 struct stat file_infos;
 char *file_content;

 if ((fd = open(filename, 
# 15 "./ft_nm.c" 3 4
                         00
# 15 "./ft_nm.c"
                                 )) < 0)
 {
  ft_printf("Cannot open file %s\n", filename);
  return;
 }

 if (fstat(fd, &file_infos) < 0)
 {
  ft_printf("Cannot stat file %s\n", filename);
  close(fd);
  return;
 }

 if (file_infos.st_size < 
# 28 "./ft_nm.c" 3 4
                         (16)
# 28 "./ft_nm.c"
                                  )
 {
  ft_printf("File '%s' has been truncated\n", filename);
  close(fd);
  return;
 }


 if ((file_content = mmap(
# 36 "./ft_nm.c" 3 4
                         ((void*)0)
# 36 "./ft_nm.c"
                             , file_infos.st_size, 
# 36 "./ft_nm.c" 3 4
                                                   1
# 36 "./ft_nm.c"
                                                            , 
# 36 "./ft_nm.c" 3 4
                                                              0x02
# 36 "./ft_nm.c"
                                                                         , fd, 0)) == 
# 36 "./ft_nm.c" 3 4
                                                                                      ((void *) -1)
# 36 "./ft_nm.c"
                                                                                                )
 {
  ft_printf("Cannot map file %s\n", filename);
  close(fd);
  return;
 }


 close(fd);






 unsigned char *elf_identification = (unsigned char*)file_content;

 if (elf_identification[
# 53 "./ft_nm.c" 3 4
                       0
# 53 "./ft_nm.c"
                              ] == 
# 53 "./ft_nm.c" 3 4
                                   0x7f 
# 53 "./ft_nm.c"
                                           && elf_identification[
# 53 "./ft_nm.c" 3 4
                                                                 1
# 53 "./ft_nm.c"
                                                                        ] == 
# 53 "./ft_nm.c" 3 4
                                                                             'E' 
# 53 "./ft_nm.c"
                                                                                     && elf_identification[
# 53 "./ft_nm.c" 3 4
                                                                                                           2
# 53 "./ft_nm.c"
                                                                                                                  ] == 
# 53 "./ft_nm.c" 3 4
                                                                                                                       'L' 
# 53 "./ft_nm.c"
                                                                                                                               && elf_identification[
# 53 "./ft_nm.c" 3 4
                                                                                                                                                     3
# 53 "./ft_nm.c"
                                                                                                                                                            ] == 
# 53 "./ft_nm.c" 3 4
                                                                                                                                                                 'F'
# 53 "./ft_nm.c"
                                                                                                                                                                        )
 {
  if (elf_identification[
# 55 "./ft_nm.c" 3 4
                        6
# 55 "./ft_nm.c"
                                  ] != 
# 55 "./ft_nm.c" 3 4
                                       1
# 55 "./ft_nm.c"
                                                 )
  {
   ft_printf("File '%s' ELF version is invalid\n", filename);
   munmap(file_content, file_infos.st_size);
   return;
  }

  unsigned char class = elf_identification[
# 62 "./ft_nm.c" 3 4
                                          4
# 62 "./ft_nm.c"
                                                  ];

  if (class == 
# 64 "./ft_nm.c" 3 4
              1
# 64 "./ft_nm.c"
                        )
  {

  }
  else if (class == 
# 68 "./ft_nm.c" 3 4
                   2
# 68 "./ft_nm.c"
                             )
  {
   ft_nm_64bits(filename, file_content, file_infos.st_size);
  }
  else
  {
   ft_printf("File '%s' header is invalid (wrong header class)\n", filename);
   munmap(file_content, file_infos.st_size);
   return;
  }

  munmap(file_content, file_infos.st_size);
 }
 else
 {
  ft_printf("File '%s' is not an ELF file\n", filename);
  return;
 }
}


int main(int argc, char **argv)
{
 char *filenames[argc];
 int filecount;

 for (int i = 1; i < argc; i++)
 {
  if (!ft_strcmp("-r", argv[i]))
  {
   g_flags |= 1 << 1;
  }
  else
  {
   filenames[filecount++] = argv[i];
  }
 }


 if (filecount == 0)
 {
  filecount = 1;
  filenames[0] = "a.out";
 }

 for (int i = 0; i < filecount; i++)
 {
  char *file = filenames[i];

  if (filecount != 1)
   ft_putstr_fd("test", 
# 118 "./ft_nm.c" 3 4
                       1
# 118 "./ft_nm.c"
                                    );


  ft_nm(file);
 }
}
