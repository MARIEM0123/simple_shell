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
 * @path:the parameter numero one to be defined in here
 * @argc:the parameter numero one to be defined in here
 * @line_count:the parameter numero one to be defined in here
 * @err_num:the parameter numero one to be defined in here
 * @linecount_flag: the parameter numero one to be defined in here
 * @fname: the parameter numero one to be defined in here
 * @env: the parameter numero one to be defined in here
 * @environ: the parameter numero one to be defined in here
 * @history: the parameter numero one to be defined in here
 * @alias: the parameter numero one to be defined in here
 * @env_changed: the parameter numero one to be defined in here
 * @status: the parameter numero one to be defined in here
 * @cmd_buf: the parameter numero one to be defined in here
 * @cmd_buf_type:the parameter numero one to be defined in here
 * @readfd: the parameter numero one to be defined in here
 * @histcount: the parameter numero one to be defined in here
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
	char *type;
	int (*func)(info_t *);
} tab_bnt;


int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);


int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);


int loophsh(char **);


void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);


int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);


char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);


char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


char **strtow(char *, char *);
char **strtow2(char *, char);


char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int bfree(void **);


int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);


int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);


int _myhistory(info_t *);
int _myalias(info_t *);


ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);


void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);


char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);


data_l *add_node(data_l **, const char *, int);
data_l *add_node_end(data_l **, const char *, int);
size_t print_list_str(const data_l *);
int delete_node_at_index(data_l **, unsigned int);
void free_list(data_l **);

size_t list_len(const data_l *);
char **list_to_strings(data_l *);
size_t print_list(const data_l *);
data_l *node_starts_with(data_l *, char *, char);
ssize_t get_node_index(data_l *, data_l *);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif

