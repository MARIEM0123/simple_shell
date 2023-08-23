#ifndef _SHELL
#define _SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
int _putchar(char c);
void _puts(char *str);
int _isb(int s);
char *_getenv(const char *name, char **environ);
void print_env(char **env);
int stline(char *h);

/**
 * struct liststr – the list to be defined
 * @num: the parameter 1
 * @str: THE parameter 2
 * @too: THE PARAMETER 3
 */
typedef struct liststr
{
        int num;
        char *str;
        struct liststr *too;
}STRRUCT_L;
/**
 * struct DATA_list – the structure name
 * @arg: parameter 1
 * @argv: parameter
 * @argc: parameter
 * @path: parameter
 * @linekk_flag: parameter
 * @num_lines: parameter
 * @increm: parameter
 * @fpnn: parameter
 * @evn: parameter
* @alias: parameter
* @env_mod: parameter
* @etat: parameter
* @histkk: parameter
* @L_array: parameter
* @L_array_type: parameter
* @rddfile: parameter
 * @par_envv: parameter
 * @p_story: parameter
 */
typedef struct DATA_listing
{
	char *arg;
	char **argv;
	int argc;
char *path;
int linekk_flag;
	unsigned int num_lines;
	int increm;
	char *fpnn;
	STRRUCT_L *evn;
	STRRUCT_L *alias;
	int env_mod;
	int etat;
int histkk;
	char **L_array;
	int L_array_type;
	int rddfile;
	char **par_envv;
STRRUCT_L *p_story;
} DATA_t;

int h_his(DATA_t *DATA, char *array, int linekk);
void handle_var(__attribute__((unused))int c);
int amoi(char *c);
void VERIFIC(DATA_t *DATA, char *array, size_t*p, size_t i, size_t ll);
int VRFC(DATA_t *, char *, size_t*);
char *abd(const char *search, const char *find);
void _entry(char *c);
int p_dtt(int input, int ffile);
int _pprtchar(char sh);
void error_output(DATA_t *DATA, char *c);
ssize_t input_array(DATA_t *DATA, char **array, size_t*l);
ssize_t d_array(DATA_t *DATA, char *array, size_t *i);
void *_realloc(void *x, unsigned int par1, unsigned int par2);
char *_strchr(char *str, char x);
char *_strncpy(char *par1, char *par2, int count);
char *_strncat(char *par1, char *par2, int count);
STRRUCT_L *add_nds_end(STRRUCT_L **head, const char *str, int num);
int _line_parm(DATA_t *DATA, char **pp, size_t *l);
void rm_ct(char *array);
#define MAX_ARRAY_NUM 1024
#define ZERO_NUM	0
#define MIINUSONE -1
#define CONVERT_UNSIGNED	2
#define CONVERT_LOWERCASE	1
#define MAXIMUM_BYTE_NUM 1024

#endif


