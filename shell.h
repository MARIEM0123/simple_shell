#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define ZERO_NUM        0
#define NUM_ONE		1
#define NUM_TWO		2
#define NUM_TREE	3


#define CASE_CONV	1
#define CASE_US_CONV	2


#define CASE_GLN 0
#define CASE_STRING 0

#define MESS_DEF	"its my project"
#define NUM_MAXIMUM	4096

extern char **environ;

/**
 * struct str0 - the structure is defined here
 * @runem: the paramerter is defined here
 * @rst: the string is defined here
 * @next: points to the next node
 */
typedef struct str0
{
	int runem;
	char *rst;
	struct str0 *next;
} data_l;

/**
 * struct Data_tab - the structure to be defined in here
 * @arg:the parameter numero one to be defined in here
 * @argv:the parameter numero one to be defined in here
 * @link:the parameter numero one to be defined in here
 * @argc:the parameter numero one to be defined in here
 * @lnumber:the parameter numero one to be defined in here
 * @n_er:the parameter numero one to be defined in here
 * @numbers: the parameter numero one to be defined in here
 * nfd: the parameter numero one to be defined in here
 * @dt: the parameter numero one to be defined in here
 * @sth: the parameter numero one to be defined in here
 * @alias: the parameter numero one to be defined in here
 * @prb: the parameter numero one to be defined in here
 * @mod: the parameter numero one to be defined in here
 * @etat: the parameter numero one to be defined in here
 * @arr_cmd: the parameter numero one to be defined in here
 * @file_rd: the parameter numero one to be defined in here
 * @stc: the parameter numero one to be defined in here
 */
typedef struct Data_tab
{
	char *arg;
	char **argv;
	char *link;
	int argc;
	unsigned int lnumber;
	int n_er;
	int numbers;
	char *nfd;
	data_l *dt;
	data_l *sth;
	data_l *alias;
	char **prb;
	int mod;
	int etat;
	char **arr_cmd;
	int arr_cmdt;
	int file_rd;
	int num_stc;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct bnt - the straucture to be defined in our case
 * @type: the parameter of the structure
 * @func: the function is defined here
 */
typedef struct bnt
{
	char *es;
	int (*gc)(info_t *);
} tab_bnt;


int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int hsh(info_t *, char **);
void _eputs(char *);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);
int turn_hsh(char **);
char *string_duplic(char *, int, int);
int _eputchar(char);
int _fileput(char c, int fd);
int _fileputs(char *str, int fd);
char *_strdup(const char *);

int _strlen(char *);
int _strcmp(char *, char *);
char *init_func(const char *, const char *);
char *_strcat(char *, char *);
char *_strrcpy(char *, char *, int);
char *_memset(char *, char, unsigned int);
char *_strcpy(char *, char *);
void _puts(char *);
int _putchar(char);
char **t_str(char *, char *);
void *_realloc(void *, unsigned int, unsigned int);
char *_strrcat(char *, char *, int);
char *hr_str(char *, char);
char **t2_str(char *, char);
int _atoi(char *);

void lib_f(char **);
int lib_g(void **);
int _atoi2(char *);
int interactive(info_t *);
int delimiter(char, char *);
int _isalpha(int);
int exit_func(info_t *);
void err_output(info_t *, char *);
int d_output(int, int);
char *n_conv(long int, int, int);
void c_rm(char *);
int _cd(info_t *);
int func_hp(info_t *);
void data_lib(info_t *, int);
int _hstr(info_t *);
int _myalias(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
int _unsetenv(info_t *, char *);
void clear_info(info_t *);
void set_info(info_t *, char **);
char **get_environ(info_t *);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int list_env_p(info_t *);
int write_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
size_t print_list_str(const data_l *);
int _setenv(info_t *, char *, char *);
void free_list(data_l **);
int read_history(info_t *info);
char *get_history_file(info_t *info);
int renumber_history(info_t *info);
data_l *node_starts_with(data_l *, char *, char);
data_l *add_node(data_l **, const char *, int);
data_l *add_node_end(data_l **, const char *, int);
int nds_dl(data_l **, unsigned int);
void ver_ch(info_t *, char *, size_t *, size_t, size_t);
int string_md(char **, char *);
size_t list_len(const data_l *);
char **strings_list(data_l *);
size_t print_list(const data_l *);
ssize_t get_node_index(data_l *, data_l *);
int vars_md(info_t *);
int is_lchx(info_t *, char *, size_t *);
int alias_md(info_t *);

#endif

