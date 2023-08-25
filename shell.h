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

#define DATA_0 \
{NULL, NULL, 0, NULL, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0, NULL, 0, \
                0, NULL, NULL}

#define ZERO_NUM        0
#define MIINUSONE -1
#define NUM_TWO 2
#define NUM_TREE 3
#define CONVERT_UNSIGNED        2
#define NUM_UN  1
#define MESS_STORY      "the history"
#define CONVERT_LOWERCASE       1
#define MAXIMUM_BYTE_NUM 1024
#define MAX_ARRAY_NUM 1024
#define HIST_MAX        4096

extern char **par_envv;
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
/**
 * struct ssch - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct ssch
{
	char *yht;
	int (*gct)(DATA_t *);

} sch_table;
int _putchar(char c);
void _puts(char *str);
int _isb(int s);
char *_getenv(const char *name, char **environ);
void print_env(char **env);
int stline(char *h);
int pp_stry(DATA_t *DATA);
int h_his(DATA_t *DATA, char *array, int linekk);
void handle_var(__attribute__((unused))int c);
int amoi(char *c);
void VERIFIC(DATA_t *DATA, char *array, size_t*p, size_t i, size_t ll);
int VRFC(DATA_t *, char *, size_t*);
char *abd(const char *search, const char *find);
void _entry(char *c);
char *_memset(char *c, char a, unsigned int m);
char *_strd(const char *c);
int p_dtt(int input, int ffile);
int _pprtchar(char sh);
int rm_env(DATA_t *DATA);
void error_output(DATA_t *DATA, char *c);
ssize_t input_array(DATA_t *DATA, char **array, size_t*l);
ssize_t d_array(DATA_t *DATA, char *array, size_t *i);
void *_realloc(void *x, unsigned int par1, unsigned int par2);
char *_strchr(char *str, char x);
char *_strncpy(char *par1, char *par2, int count);
char *_strncat(char *par1, char *par2, int count);
STRRUCT_L *add_nds_z(STRRUCT_L **head, const char *str, int num);
int _line_parm(DATA_t *DATA, char **pp, size_t *l);
void rm_ct(char *array);
STRRUCT_L *add_nds_end(STRRUCT_L **h, const char *ch, int num);
char *ret_story_fd(DATA_t *DATA);
int del_ndss(STRRUCT_L **h, unsigned int k);
char *_memset(char *c, char a, unsigned int m);
int don_p_story(DATA_t *DATA);
char *ev_value(DATA_t *DATA, const char *pnn);
char *_strcpy(char *par1, char *par2);
char *_strcat(char *par1, char *par2);
int listing_env(DATA_t *DATA);
int hloop(DATA_t *DATA, char **av);
void data_net(DATA_t *DATA);
int mode_intr(DATA_t *DATA);
ssize_t p_input_line(DATA_t *DATA);
char **word_str(char *c, char *d);
char *_strdup(const char *c);
STRRUCT_L *str_nds(STRRUCT_L *nds, char *l, char c);
int alias_subt(DATA_t *DATA);
int varias_subt(DATA_t *DATA);
int the_delimiter(char s, char *l);
char *convert_number(long int L, int sprt, int parmt);
int str_chg(char **par1, char *par2);
int _strcompare (char *c1, char *c2);
int rw_p_story(DATA_t *DATA);
void DATA_star(DATA_t *DATA, char **b);
void lib_DATA(DATA_t *DATA, int fld);
void str_free(char **str);
void lib_data(STRRUCT_L **x);
int lib_pointer(void **x);
int srch_tab(DATA_t *DATA);
int EXIT_FUNCT(DATA_t *DATA);
size_t p_strings(const STRRUCT_L *h);
int NW_ennv(DATA_t *DATA);
int ch_dir(DATA_t *DATA);
int _myp_story(DATA_t *DATA);
int _init_env(DATA_t *DATA, char *a, char *b);
int _len_string(char *c);
int env_sitting(DATA_t *DATA);
void _pputs(char *c);
int _pputchar(char c);
char *env_name(DATA_t *DATA, const char *l);
int rm_env(DATA_t *DATA);
int init_new_env(DATA_t *DATA, char *b, char *a);
int ch_cur_dir(DATA_t *DATA);
void err_output(DATA_t *DATA, char *x);
int alias_input(STRRUCT_L *nds);
int alias_init (DATA_t *DATA, char *c);
ssize_t nds_count(STRRUCT_L *par1, STRRUCT_L *nds);
int alias_c (DATA_t *DATA, char *ch);
int  _alias_(DATA_t *DATA);
char **get_par_envv(DATA_t *DATA);
char **STRRUCT_Lo_strings(STRRUCT_L *x);
size_t linked_lgnt(const STRRUCT_L *x);
void ex_comm(DATA_t *DATA);
int _putffile(char a, int file);
int _putffile(char a, int file);
int rm_env(DATA_t *DATA);
int rmp_env(DATA_t *DATA, char *x);
int _putsffile(char *c, int file);

#endif

