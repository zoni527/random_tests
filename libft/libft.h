/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:42:55 by jvarila           #+#    #+#             */
/*   Updated: 2025/04/01 10:59:14 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ================================ HEADERS ================================= */

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ---------------------------------------------------------------- ft_printf */

# include <stdarg.h>
# include <stdint.h>

/* -------------------------------------------------------------------- extra */

# include <stdbool.h>

/* =========================== ORIGINAL LIBFT =============================== */

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

size_t			ft_strlen(const char *s);

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

char			*ft_strnstr(const char *big, const char *little, size_t len);

int				ft_atoi(const char *nptr);

void			*ft_calloc(size_t nmemb, size_t size);

char			*ft_strdup(const char *s);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(const char *s, int fd);
int				ft_putendl_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);

/* -------------------------------------------------------------------- bonus */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/* ============================ GET_NEXT_LINE =============================== */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FILE_LIMIT
#  define FILE_LIMIT 10
# endif

typedef struct s_buffer
{
	int			fd;
	int			eof;
	size_t		flushed_bytes;
	size_t		unflushed_bytes;
	char		memory[BUFFER_SIZE];
}	t_buffer;

char			*get_next_line(int fd);
size_t			ft_strlen(const char *str);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*strjoin_and_free(char *s1, char *s2);

/* ============================== FT_PRINTF ================================= */

# ifndef CONVERSION_SET
#  define CONVERSION_SET "cspdiuxX%"
# endif

# ifndef HEX_BASE_LOWER_CASE
#  define HEX_BASE_LOWER_CASE "0123456789abcdef"
# endif

# ifndef HEX_BASE_UPPER_CASE
#  define HEX_BASE_UPPER_CASE "0123456789ABCDEF"
# endif

int				ft_printf(const char *format_str, ...);
int				handle_c(const char **format_str_ptr, va_list *ap);
int				handle_s(const char **format_str_ptr, va_list *ap);
int				handle_p(const char **format_str_ptr, va_list *ap);
int				handle_d(const char **format_str_ptr, va_list *ap);
int				handle_i(const char **format_str_ptr, va_list *ap);
int				handle_u(const char **format_str_ptr, va_list *ap);
int				handle_hex_lowercase(const char **format_str_ptr, va_list *ap);
int				handle_hex_uppercase(const char **format_str_ptr, va_list *ap);

/* ============================== ADDITIONS ================================= */

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

/* ------------------------------- Strings ---------------------------------- */
/* ------------------------------------------------------------ string output */

int				ft_putstr(const char *s);
int				ft_putchar(char c);
int				ft_putendl(const char *s);

/* -------------------------------------------------------- string validation */

bool			ft_isnumstr(const char *str);
bool			ft_contains_duplicate_char(const char *str);
bool			ft_valid_multinumberstring(const char *str);
bool			ft_valid_hex_string(const char *str);

bool			ft_is_empty_string(const char *str);
bool			ft_is_whitespace_string(const char *str);

/* ---------------------------------------------------------- string analysis */

int				ft_word_count(const char *str);
int				ft_char_index(const char *str, int c);
int				ft_count_char(const char *str, int c);

/* --------------------------------------------------------- string modifying */

void			ft_replace_char(char *str, int c1, int c2);

/* --------------------------------------------------------- string traversal */

char			*ft_skip_whitespace(const char *str);
char			*ft_skip_char(const char *str, char c);

/* --------------------------------------------------------- string to number */

long int		ft_atol(const char *nptr);
unsigned int	ft_atou_base(const char *str, const char *base);
unsigned int	ft_atohex(const char *str);

/* -------------------------------------------------------- string comparison */

int				ft_strcmp(const char *s1, const char *s2);

/* ------------------------------- Numbers ---------------------------------- */
/* ------------------------------------------------------------ number output */

int				ft_putnbr(int n);
int				ft_putnbr_base(unsigned int n, const char *base);

/* ----------------------------------------------------------- digit counters */

int				ft_int_digits(int n);
int				ft_long_digits(long int n);
int				ft_uint_digits(unsigned int n);
int				ft_ulong_digits(unsigned long n);
int				ft_ulong_hex_digits(unsigned long n);

/* ----------------------------------------------------------- return helpers */

int				ft_free_ptr_return_int(void **ptr_to_ptr, int i);
int				ft_write_error_return_int(char *error_message,
					int return_value);
void			*ft_write_error_return_null(char *error_message);

/* --------------------------------------------------------- number selection */

int				ft_larger_int(int a, int b);
int				ft_smaller_int(int a, int b);

/* -------------------------------------------------------- number comparison */

int				ft_first_int_larger(int a, int b);
int				ft_first_int_smaller(int a, int b);

/* --------------------------------------------------------- number to string */

char			*ft_longtoa(long int n);
char			*ft_hextoa(unsigned long n, unsigned char mode);
char			*ft_utoa(unsigned int n);
char			*ft_ulongtoa(unsigned long n);

/* --------------------------------- Arrays --------------------------------- */

void			ft_free_split(char ***words_ptr);

/* ---------------------------------- Math ---------------------------------- */

int				ft_iabs(int num);

/* --------------------------------- Chars ---------------------------------- */

int				ft_islower(int c);
int				ft_isupper(int c);

/* --------------------------------- Bools ---------------------------------- */

void			ft_toggle_bool(bool *value);

/* --------------------------------- Memory --------------------------------- */

void			*ft_realloc(void *src, size_t size_old, size_t size_new);

/* ================================ MEMARENA ================================ */

// Default size is 10 MiB (1024^2)
# ifndef MEM_ARENA_SIZE
#  define MEM_ARENA_SIZE	1048576
# endif

# define MSG_ERROR_ALLOC	"ERROR: couldn't alloc"
# define MSG_ERROR_CAPACITY	"ERROR: requested memory chunk is too large"

# ifndef ERROR_ALLOC
#  define ERROR_ALLOC		2
# endif

# ifndef ERROR_CAPACITY
#  define ERROR_CAPACITY	3
# endif

typedef struct s_memarena	t_memarena;

typedef struct s_memarena
{
	size_t		capacity;
	size_t		bytes_used;
	void		*heap_memory;
	t_memarena	*next;
}	t_memarena;

void			*ft_new_memarena(void);
void			*ft_ma_malloc(t_memarena *arena, size_t bytes_required);
void			*ft_ma_calloc(t_memarena *arena, size_t nmemb, size_t size);
void			ft_free_memarena_exit(t_memarena *arena, const char *msg);
void			*ft_free_memarena(t_memarena *arena);
void			ft_reset_memarena(t_memarena *arena);
void			*ft_ma_malloc(t_memarena *arena, size_t bytes_required);

char			*ft_ma_strjoin(t_memarena *arena, char const *s1,
					char const *s2);
char			*ft_ma_strdup(t_memarena *arena, const char *s);
char			*ft_ma_substr(t_memarena *arena, char const *s,
					unsigned int start, size_t len);
char			**ft_ma_split(t_memarena *arena, char const *s, char c);

/* -------------------------------------------------------------------------- */

#endif
