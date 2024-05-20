#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"


void test_ft_strchr(const char *haystack, char needle, char *expected_output)
{
	char *result = strchr(haystack, needle);
  	if (result == expected_output) 
	{
    	printf("Test passed: searching '%c' in [%s], results is [%s]\n", needle, haystack, result);
  	} 
	else 
	{
    	if (expected_output == NULL) {
    		printf("Test passed: Expected not to find '%c' in [%s], and the result is [%s] <%p>,<%p>\n",
             needle, haystack, result, result, expected_output);
    } 
	else 
	{
      printf("Test failed: Expected to find '%c' in [%s] and the resut was [%s] but expected [%s]\n",
             needle, haystack, result, expected_output);
    }
  }
}
		/*
void test_strchr(const char *haystack, char needle, char *expected_output) {
  char *result = strchr(haystack, needle);

  if (result == expected_output) {
    printf("Test passed: Found '%c' in '%s' as expected.\n", needle, haystack);
  } else {
    if (expected_output == NULL) {
      printf("Test failed: Expected not to find '%c' in '%s' but found '%s'\n",
             needle, haystack, result);
    } else {
      printf("Test failed: Expected to find '%c' at %p in '%s' but found '%s'\n",
             needle, expected_output, haystack, result);
    }
  }
}
*/

int main(int argc, char **argv)
{
	int		c;
	char    *s;
    int     res;
	int		n;

    (void) argc;
    (void) argv;

	printf("\n--- atoi ---\n");
    s = " -1 ";    res = ft_atoi(s); printf("%s=%d\n", s, res);
    s = " +1234 "; res = ft_atoi(s); printf("%s=%d\n", s, res);

	printf("\n--- isalpha ---\n");
	c = 'a'; printf("%c is %s\n", c, ft_isalpha(c) ? "alpha" : "not alpha");
	c = '+'; printf("%c is %s\n", c, ft_isalpha(c) ? "alpha" : "not alpha");
	c = '9'; printf("%c is %s\n", c, ft_isalpha(c) ? "alpha" : "not alpha");

	printf("\n--- isalnum ---\n");
	c = 'a'; printf("%c is %s\n", c, ft_isalnum(c) ? "alnum" : "not alnum");
	c = '+'; printf("%c is %s\n", c, ft_isalnum(c) ? "alnum" : "not alnum");
	c = '9'; printf("%c is %s\n", c, ft_isalnum(c) ? "alnum" : "not alnum");

	printf("\n--- isascii ---\n");
	c = 'a'; printf("%c [%d]is %s\n", c, c, ft_isascii(c) ? "ascii" : "not ascii");
	c = 127; printf("%c [%d]is %s\n", c, c, ft_isascii(c) ? "ascii" : "not ascii");
	c = 128; printf("%c [%d]is %s\n", c, c, ft_isascii(c) ? "ascii" : "not ascii");

	printf("\n--- isdigit ---\n");
	c = 'a'; printf("%c [%d]is %s\n", c, c, ft_isdigit(c) ? "digit" : "not digit");
	c = '0'; printf("%c [%d]is %s\n", c, c, ft_isdigit(c) ? "digit" : "not digit");
	c = '9'; printf("%c [%d]is %s\n", c, c, ft_isdigit(c) ? "digit" : "not digit");

	printf("\n--- isprint ---\n");
	c = 9;   printf("%c [%d]is %s / %d\n", c, c, ft_isprint(c) ? "print" : "not print", isprint(c));
	c = 'W'; printf("%c [%d]is %s / %d\n", c, c, ft_isprint(c) ? "print" : "not print", isprint(c));
	c = 128; printf("%c [%d]is %s / %d\n", c, c, ft_isprint(c) ? "print" : "not print", isprint(c));

	printf("\n--- tolower ---\n");
	c = 'W'; printf("%c [%d]is %c\n", c, c, ft_tolower(c));
	c = '+'; printf("%c [%d]is %c\n", c, c, ft_tolower(c));
	c = 'a'; printf("%c [%d]is %c\n", c, c, ft_tolower(c));

	printf("\n--- strlen ---\n");
	s = "Hello";  printf("[%s] is %d\n", s, ft_strlen(s));
	s = "Hello "; printf("[%s] is %d\n", s, ft_strlen(s));
	s = "";       printf("[%s] is %d\n", s, ft_strlen(s));

	printf("\n--- strncmp ---\n");
	char *t1, *t2;
	t1 = "Hell Hello";    t2 = "Hello "; n = 4;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	t1 = "Word !!!"; t2 = "World !!!"; n = 3;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	t1 = "World !!!"; t2 = "World"; n = 6;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	t1 = "World !!!"; t2 = "World"; n = 0;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	t1 = ""; t2 = "Hello The"; n = 7;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	t1 = "Hello The"; t2 = ""; n = 7;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	t1 = "\127"; t2 = "A"; n = 1;
	printf("%s:%s:[%d] ==> %d/%d\n", t1, t2, n, ft_strncmp(t1, t2, n), strncmp(t1,t2,n));

	printf("\n--- strncmp ---\n");
	const char haystack1[] = "This is a test string"; c = 'z';
	test_ft_strchr(haystack1, c, NULL);
	//printf("[%s]:%c:[%s]\n", haystack1, c, ft_strchr(haystack1, c));

	char *str;
	str= "Hello, world!";  test_ft_strchr(str, 'H', (char *)&str[0]);
	str="This is a story"; test_ft_strchr(str, 's', &str[3]);
  	str="Hello, world!";   test_ft_strchr(str, 'd', &str[11]);
	str="Find the last character"; test_ft_strchr(str, '\0', &str[ft_strlen(str)]);
	//str="Find last"; test_ft_strchr(str, 't', &(str[ft_strlen(str)-1]));

	return 0;
}
