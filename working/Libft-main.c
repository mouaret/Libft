#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "libft.h"

void TEST_STRNSTR(char *haystack, char *needle, char *expected_result)
{
	char *result = ft_strnstr(haystack, needle, ft_strlen(needle));
	if (result == (char *)expected_result) 
	{
    	printf("Test: PASS:'%s' in '%s' [result='%s']\n", needle, haystack, result);
  	} else 
	{
    	printf("Test: FAIL:'%s' in '%s' (expected '%s')\n", needle, haystack, expected_result ? expected_result : "(null)"); \
		printf("%p, %p \n", result, expected_result);
  	}
}

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
void test_strlcat(void)
{
	  char dst[100];

  // Empty destination
  ft_memset(dst, 0, sizeof(dst));
  if (ft_strlcat(dst, "hello", sizeof(dst)) != 5) 
  	printf("Test 1 : failed\n");
  else	
	printf("Test 1 : PASS\n");


  // Destination with some content
  ft_memset(dst, 0, sizeof(dst));
  strcpy(dst, "world");
  if (ft_strlcat(dst, "!", sizeof(dst)) != 6)
    printf("Test 2 failed\n");
  else
  	printf("Test 2 : PASS\n");
  

  // Truncation case (source string doesn't fit entirely)
  ft_memset(dst, 0, sizeof(dst));
  strcpy(dst, "small");
  if (ft_strlcat(dst, "buffer", sizeof(dst)) != 11)
    printf("Test 3 failed\n");
  else
  	printf("Test 3 : PASS\n");

  // Null destination
  memset(dst, 0, sizeof(dst));
  if (ft_strlcat(NULL, "hello", sizeof(dst)) != 0)
    printf("Test 4 failed\n");
  else
  	printf("Test 4 : PASS\n");

  // Null source
  memset(dst, 0, sizeof(dst));
  if (ft_strlcat(dst, NULL, sizeof(dst)) != 0)
    printf("Test 5 failed\n");
  else
  	printf("Test 5 : PASS\n");


  // Zero destination size
  memset(dst, 0, sizeof(dst));
  if (ft_strlcat(dst, "hello", 0) != 0) 
    printf("Test 6 failed\n");
  else
  	printf("Test 6 : PASS\n");

}

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
	s = "Hello";  printf("[%s] is %zu\n", s, ft_strlen(s));
	s = "Hello "; printf("[%s] is %zu\n", s, ft_strlen(s));
	s = "";       printf("[%s] is %zu\n", s, ft_strlen(s));

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

	printf("\n--- ft_strchr ---\n");
	char *str;
	const char *haystack1 = "This is a test string"; test_ft_strchr(haystack1, 'z', NULL);
	str= "Hello, world!";  test_ft_strchr(str, 'H', (char *)&str[0]);
	str="This is a story"; test_ft_strchr(str, 's', &str[3]);
  	str="Hello, world!";   test_ft_strchr(str, 'd', &str[11]);
	str="Find the last character"; test_ft_strchr(str, '\0', &str[ft_strlen(str)]);
	//str="Find last"; test_ft_strchr(str, 't', &(str[ft_strlen(str)-1]));

	printf("\n--- ft_strnstr ---\n");
	str="This is a test"; 		TEST_STRNSTR(str, "This", str);
  	str="This is another test  "; TEST_STRNSTR(str, "test", &str[16]);
  	str="No match here"; 		TEST_STRNSTR(str, "substring", NULL);
  	str="Some string"; 			TEST_STRNSTR(str, "", str); // Empty needle
  	str="Short haystack"; 		TEST_STRNSTR(str, "too long", NULL); // Needle longer than haystack
  	str="Find \0null"; 			TEST_STRNSTR(str, "\0null", str); // Substring with null character
	str=""; 			TEST_STRNSTR(str, "find", NULL); // Substring with null character

	printf("\n--- ft_memset ---\n");
	unsigned char tab2[100];
	ft_memset((void *)tab2, 128, 10);
	for (int i=0; i<5; i++)
		printf("%d - ", tab2[i]);
	printf("\n");

	printf("\n--- ft_bzero ---\n");
	ft_bzero((void *)tab2, 3);
	for (int i=0; i<5; i++)
		printf("%d - ", tab2[i]);
	printf("\n");

	printf("\n--- ft_memchr ---\n");
	ft_memset((void *)tab2, 'A', 10);
	tab2[7]= 'B';
	printf("%s : should be 'BAA'\n", (char *) ft_memchr((void *)tab2, 'B', 10));

	printf("\n--- ft_strlcat ---\n");
	test_strlcat();

	printf("\n--- ft_strlcpy ---\n");	// will be tested later
	char tab[1000]; char *src;
	src = "This is a test string"; ft_strlcpy(tab, src, 10); printf("'%s'\n", tab);
	src = ""; ft_strlcpy(tab, src, 10); printf("'%s'\n", tab);

	return 0;
}