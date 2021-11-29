/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_shared.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:56:18 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/29 08:55:23 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_SHARED_H
# define FT_PIPEX_SHARED_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "ft_pipex_struct.h"

/**
 * @brief Sets n bytes of s to 0.
 *
 * @param s Pointer to the start of the memory location
 * @param n Buffer size
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief function shall allocate unused space for an array of 'nmemb'
 * elements each of whose size in bytes is 'size'. The space shall
 * be initialized to all bits 0.
 *
 * @param nmemb Number of elements.
 * @param size Number of bytes by type.
 * @return void* Return a pointer to the allocated memory, which
 * is suitably aligned for any built-in type. On error, this
 * functions return NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Function copies n bytes from memory area src to memory
 * area dest. The memory areas must not overlap.
 * Use memmove if the memory areas do overlap.
 *
 * @param dest Pointer to the memory location where the contents
 * are copied to.
 * @param src Pointer to the memory location where the contents
 * are copied from.
 * @param n Number of bytes to copy from src to dest.
 * @return void* Returns a pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t num);

/**
 * @brief Used to copy a block of memory from a location to another.
 *
 * @param dest Pointer to the memory location where the contents
 * are copied to.
 * @param src Pointer to the memory location where the contents
 * are copied from.
 * @param n Number of bytes to copy from src to dest.
 * @return void* Returns a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Is uset to fill a block of memory with a particular value.
 *
 * @param s Pointer of memory area.
 * @param c Constant bytes to fill memory area.
 * @param n Number of bytes fill.
 * @return void* Returns a pointer to the memory are s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings
 * obtained by splitting 's' using the character 'c' as a delimiter.
 * The array must be ended by a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character
 * @return char** The array fo new strings resulting from the split.
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Shall return a pointer to a new string, which is a
 * a duplicate fo the string pointed to by s.
 *
 * @param s Pointer to the start fo the string do be copied.
 * @return char* On success, returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, wich
 * is the result of the concatenation os 's1' and 's2'.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return char* The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Append the NULL-terminated string src to the end fo dst.
 * It will append at most size - ft_strlen(dst) - 1 byte, NULL-terminating
 * the result.
 *
 * @param dst Pointer to the destination area of memory
 * @param src Pointer to the source area of memory
 * @param dstsize Buffer size in bytes
 * @return size_t Return the total length of the string, that is the
 * initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Copies up to size - 1 character from the NULL-terminenated
 * string src to dst, NULL terminating the result.
 *
 * @param dst Pointer to the destination area of memory
 * @param src Pointer to the source area of memory
 * @param dstsize Buffer size in bytes
 * @return size_t Return the length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Function calculates the length of a given string.
 * It doesn't count null character.
 *
 * @param s Represents the string variable whose length we have
 * to find.
 * @return size_t This funcition return the length of string passed.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Locates the first occurrence of the null-terminated string
 * little in the string big, where not more than len character
 * are searched. Characters that appear after a '\0' character are
 * not searched.
 * @param big String to be searched by 'little'
 * @param little String to search in 'big'
 * @param len Number of bytes to search
 * @return char* If little is an empty string, big is returned; if
 * little occurs nowhere in big, NULL is the returned; otherwise a
 * pointer to the first character of the first occurrence of little
 * is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Function that prints the error message and deallocates memory.
 *
 * @param chest Data struct
 * @param t_bool This variable informs what type of message should be printed
 * on the screen and if it is necessary to give free in the path variable.
 * @param k
 * @return int Exit status/code 2.
 */
int		ft_message_clean(t_pipex *chest, int t_bool, int k);

/**
 * @brief Function that initializes the struct values, and handling the
 * commands that are in argv.
 *
 * @param chest Data struct
 * @param argc Argument count
 * @param argv Argument value
 * @param envp Enverioment pointer, where there is the variable $PATH that
 * contains the path of the binary files of the commands that will be executed.
 * @return int Return 0 on success or exit status/code on error 2.
 */
int		ft_parse_cmd(t_pipex *chest, int argc, char *argv[], char *envp[]);

#endif
