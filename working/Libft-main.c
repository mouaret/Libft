#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "libft.h"

/********** my ft_functions  *************************************************/
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ft_putchar(str[i++]);
}

/********** colors **********************************************************/

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

/*
int main () 
{
  red();
  printf("Hello ");
  yellow();
  printf("world\n");
  reset();
  return 0;
}
*/

/********************************************************************/
void TEST_STRNSTR(char *haystack, char *needle, size_t len, char *expected_result)
{
	char *result = ft_strnstr(haystack, needle, len);
	if (result == (char *)expected_result) 
	{
    	green();
		printf("Test:PASS: '%s' in '%s' [result='%s']\n", needle, haystack, result);
		reset();
  	} else 
	{
    	red();
		printf("Test:FAIL: '%s' in '%s' (expected '%s')", needle, haystack, expected_result ? expected_result : "(null)"); \
		printf( "%p, %p \n", result, expected_result);
		reset();
  	}
}


/***************************************************************************/
void test_ft_strchr(const char *haystack, char needle, char *expected_output)
{
	char *result = ft_strchr(haystack, needle);
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


/****************************************************************************/
void test_ft_strrchr(const char *haystack, char needle, char *expected_output)
{
	char *result = ft_strrchr(haystack, needle);
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

/*********************************************/
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

/*********************************************/
void test_strlcpy(void)
{
  char buffer[100];

	char tab[1000]; char *src;
	src = "This is a test string"; ft_strlcpy(tab, src, 10); printf("'%s' [10 chars copied]\n", tab);
	src = ""; ft_strlcpy(tab, src, 10); printf("'%s' [ null string copied] \n", tab);

	// Empty source string
  	ft_strlcpy(buffer, "", sizeof(buffer));
  	printf("Empty source: '%s'\n", buffer);

  	// Source string fits entirely
  	strcpy(buffer, "Hello, world!");
  	ft_strlcpy(buffer, "is shorter", sizeof(buffer));
  	printf("Fits entirely: '%s'\n", buffer);

	// Source string truncated (buffer full)
  	strcpy(buffer, "This is a long string");
  	ft_strlcpy(buffer, " that overflows", sizeof(buffer));
  	printf("Truncated: '%s'\n", buffer); // Only "This is a" should be copied

  	// Destination buffer too small (no null termination)
  	strcpy(buffer, "Hello");
  	ft_strlcpy(buffer, "World", 4);
  	printf("Small destination: '%.*s'\n", 4, buffer); // Print only first 4 characters

  	// Size argument is 0 (empty destination)
  	buffer[0] = 'a';
  	ft_strlcpy(buffer, " appended", 0);
  	printf("'a' : Size is 0: '%s'\n", buffer);  // Only original character remains

  	// Non-null terminated source string (undefined behavior)
  	char bad_src[] = "Not null terminated";
  	buffer[0] = '\0';
  	ft_strlcpy(buffer, bad_src, sizeof(buffer));
  	printf("Non-null terminated source (undefined): '%s'\n", buffer); // This might not print as expected
} 

/*********************************************/
void test_ft_memcpy(void) {
  char src[100], dst[100];

  // Empty source string
  memset(dst, 0, sizeof(dst));
  ft_memcpy(dst, "", sizeof(dst));
  printf("Empty source: '%s'\n", dst);
  fflush(stdout);

  // Source string fits entirely
  strcpy(src, "Hello, world!");
  ft_memcpy(dst, src, sizeof(src));
  printf("Fits entirely: '%s'\n", dst);
  fflush(stdout);

  // Overlapping buffers (undefined behavior, test for functionality only)
  strcpy(src, "This overlaps");
  ft_memcpy(src + 5, src, 10);
  printf("Overlapping buffers: '%s'\n", src); // This might not print as expected
  fflush(stdout);

  // Destination buffer smaller (truncation)
  strcpy(src, "This is a longer string");
  memset(dst, 'b', sizeof(dst));
  ft_memcpy(dst, src, sizeof(dst));
  printf("100 chars to copy, truncated destination: [%ld] '%s'\n", sizeof(dst), dst);
  fflush(stdout);

  // Size argument is 0 (no copy)
  memset(dst, 0, sizeof(dst));
  ft_memcpy(dst, src, 0);
  printf("Size of src is 0: '%s'\n", dst);
  fflush(stdout);
}


/*********************************************/
void test_memcmp(int k, const void *a, const void *b, size_t size, int expected) {
  int result = ft_memcmp(a, b, size);
//  printf("'%s' -vs- '%s'", (char*)a, (char*)b);
  if (result == expected) {
    printf("%2d:PASS: '%s' <> '%s' (expected %d, got %d)\n", k, (char *)a, (char *)b, expected, result);
  } else {
    printf("%2d:FAIL: '%s' <> '%s' (expected %d, got %d)\n", k, (char *)a, (char *)b, expected, result);
  }
}

/*********************************************/
void test_ft_memcmp(void) {
  char str1[100], str2[100];

  int k = 1;
  
  // Empty buffers (size 0)
  memset(str1, 0, sizeof(str1));
  memset(str2, 0, sizeof(str2));
  test_memcmp(k++, str1, str2, 0, 0);

  memset(str1, 'a', 10);
  memset(str2, 'b', 2);
  test_memcmp(k++, str1, str2, 5, -1);

  // Equal strings
  strcpy(str1, "Hello, world!");
  strcpy(str2, "Hello, world!");
  test_memcmp(k++, str1, str2, sizeof(str1), 0);

  // Strings differ in the middle (various sizes)
//  for (size_t i = 0; i < 8; i++) {
	size_t i = 3;
    strcpy(str1, "This is different");
    strcpy(str2, "This is something else");
    str1[i] = 'X';  // Introduce difference at different positions
    test_memcmp(k++, str1, str2, i-1, 0);  // Up to the difference, should be equal
    test_memcmp(k++, str1, str2, i, 0);  // Up to the difference, should be equal
    test_memcmp(k++, str1, str2, sizeof(str1), -27); //(str1[i] > str2[i]) ? -1 : 1);
//  }

  // Strings differ at the end (shorter string)
  strcpy(str1, "Equal beginning");
  strcpy(str2, "Equal beginning, shorter");
  test_memcmp(k++, str1, str2, sizeof(str1), -44);

  // Strings differ at the end (longer string)
  strcpy(str1, "Equal beginning");
  strcpy(str2, "Equal beginning, longer string with X");
  test_memcmp(k++, str1, str2, sizeof(str1), -44);  // Limited by size

  // Non-null terminated strings (undefined behavior)
  char bad_str1[] = "Not null terminated";
  char bad_str2[] = "Another not null terminated";
  test_memcmp(k++, bad_str1, bad_str2, sizeof(bad_str1), 13); // This might not be reliable

  char bad_str3[] = "";
  char bad_str4[] = "ABCD (null terminated) -vs- not null terminated";
  test_memcmp(k++, bad_str3, bad_str4, sizeof(bad_str3), -65); // This might not be reliable
}


/*********************************************/
void test_ft_memmove(void) 
{
  char src[100], dst[100];

	// Test 1: Empty copy
	dst[0] = 'X';
	ft_memmove(dst, src, 0);
	if (dst[0] != 'X')
		printf("FAIL:");
	else 
		printf("PASS:");
	printf("Empty copy\n");
	fflush(stdout);

	// Test 2: Non-overlapping copy
	src[0] = 'a'; src[1] = 'b'; src[2] = 'c';
	dst[0] = 'x'; dst[1] = 'y'; dst[2] = 'z';
  	ft_memmove(dst, src, 3);
	if (dst[0] != 'a' || dst[1] != 'b' || dst[2] != 'c') // Failure
		printf("FAIL:");
	else 
		printf("PASS:");
	printf("Non-overlapping copy\n");
	fflush(stdout);

  // Test 3: Overlapping copy (beginning)
  ft_memcpy(dst, "this is an example", sizeof(dst));
  ft_memmove(dst, dst + 1, 3);
  if (ft_memcmp(dst, "hiss is", 3) != 0)
		printf("FAIL:");
	else 
		printf("PASS:");
	printf("Overlapping copy (beginning): '%s'\n", dst);
	fflush(stdout);
/*  ft_memcpy(dst, "this is an example", sizeof(dst));
  memmove(dst, dst + 1, 3);
	printf("Overlapping copy (beginning): '%s'\n\n", dst);
*/

  // Test 4: Overlapping copy (end)
  src[0] = 'a'; src[1] = 'b'; src[2] = 'c';
  dst[0] = 'x'; dst[1] = 'y'; dst[2] = 'a'; dst[3] = 'b';
  ft_memmove(dst + 2, src, 2);
  if (dst[0] != 'x' || dst[1] != 'y' || dst[2] != 'a' || dst[3] != 'b') // Failure
		printf("FAIL:");
	else 
		printf("PASS:");
	printf("Overlapping copy (end)\n");
	fflush(stdout);

  // Test 5: Overlapping copy (complete overlap)
  src[0] = 'X'; src[1] = 'Y'; src[2] = 'Z';
  dst[0] = 'x'; dst[1] = 'y'; dst[2] = 'z';
  ft_memmove(dst, src, 3);
  if (dst[0] != 'X' || dst[1] != 'Y' || dst[2] != 'Z') // Failure
		printf("FAIL:");
  else 
		printf("PASS:");
	printf("Overlapping copy (complete overlap)\n");
	fflush(stdout);
}

/******************************************************************/
void test_calloc_sys(size_t n, size_t size, int expected_result) 
{
	void *ptr = calloc(n, size);

	if (ptr == NULL && expected_result == 0) 
	{
    	printf("Test passed -[sys] (expected [null] for n=%zu, size=%zu)\n", n, size);
	} 
	else if (ptr != NULL && expected_result == 0) 
	{
    	printf("Test passed -[sys] (allocation successful for n=%zu, size=%zu) [%p]\n", n, size, ptr);
    	free(ptr);  // Free memory if allocated
  	} 
	else 
	{
    	printf("Test failed -[sys] (unexpected result [%d] for n=%zu, size=%zu)\n", expected_result, n, size);
    if (ptr != NULL)
      free(ptr);  // Free memory if allocated unexpectedly
	}
}
void test_calloc(size_t n, size_t size, int expected_result) 
{
	void *ptr = ft_calloc(n, size);

	if (ptr == NULL && expected_result == 0) 
	{
    	printf("Test passed (expected [null] for n=%zu, size=%zu) [%p]\n", n, size, ptr);
	} 
	else if (ptr != NULL && expected_result == 0) 
	{
    	printf("Test passed (allocation successful for n=%zu, size=%zu)\n", n, size);
    	free(ptr);  // Free memory if allocated
  	} 
	else 
	{
    	printf("Test failed (unexpected result for n=%zu, size=%zu)\n", n, size);
    if (ptr != NULL)
      free(ptr);  // Free memory if allocated unexpectedly
	}
}

void	test_ft_calloc(void) {
  test_calloc(0, 10, 0);    // n = 0 (should fail)
  test_calloc_sys(0, 10, 0);    // n = 0 (should fail)
  test_calloc(1, 0, 1);     // size = 0 (should fail)
  test_calloc_sys(1, 0, 1);     // size = 0 (should fail)
  test_calloc(5, sizeof(int), 0);  // Allocate 5 integers (should succeed)
  test_calloc(1024, 1, 0);   // Allocate 1024 bytes (should succeed)
  test_calloc(10, 1024 * 1024, 1); // Large allocation (might fail)

  // Test case with overflow (n * size overflows size_t)
  size_t max_size_t = (size_t) -1;
  test_calloc(max_size_t, 2, 1);

  // Test case with unexpected success (implementation might differ)
  test_calloc((size_t) -1, 1, 1);  // Negative n (implementation dependent)
}


/******************************************************************/
void test_ft_strdup(void)
{
    char *a = "Hello world !";
    char *b;

    b = ft_strdup(a);
    if (b) { ft_putstr(b); ft_putchar('\n'); } if (b) free(b); 

    b = ft_strdup(""); 
    if (b) { ft_putstr(b); ft_putchar('\n'); } if (b) free(b); 

    b = ft_strdup(NULL );
    if (b) { ft_putstr(b); ft_putchar('\n'); } if (b) free(b); 
}


void ft_split_print(char **str_v)
{
	int i = 0;

	if (str_v)
	{
		while (str_v[i] != 0)
		{
			printf("'%s' / ", str_v[i]);
			free(str_v[i]);
			i++;
		}
	printf("\n");
	fflush(stdout);
	}
}


/******************* main ***********************************************/
int main(int argc, char **argv)
/******************* main ***********************************************/
{
	int		c;
	char    *s;
    int     res;
	int		n;
	char 	**str_v;

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
	c = 'a'; printf("%c [%d] is %s\n", c, c, ft_isascii(c) ? "ascii" : "not ascii");
	c = 127; printf("%c [%d] is %s\n", c, c, ft_isascii(c) ? "ascii" : "not ascii");
	c = 128; printf("%c [%d] is %s\n", c, c, ft_isascii(c) ? "ascii" : "not ascii");

	printf("\n--- isdigit ---\n");
	c = 'a'; printf("%c [%d] is %s\n", c, c, ft_isdigit(c) ? "digit" : "not digit");
	c = '0'; printf("%c [%d] is %s\n", c, c, ft_isdigit(c) ? "digit" : "not digit");
	c = '9'; printf("%c [%d] is %s\n", c, c, ft_isdigit(c) ? "digit" : "not digit");

	printf("\n--- isprint ---\n");
	c = 9;   printf("%c [%d] is %s / %d\n", c, c, ft_isprint(c) ? "print" : "not print", isprint(c));
	c = 'W'; printf("%c [%d] is %s / %d\n", c, c, ft_isprint(c) ? "print" : "not print", isprint(c));
	c = 128; printf("%c [%d] is %s / %d\n", c, c, ft_isprint(c) ? "print" : "not print", isprint(c));

	printf("\n--- tolower ---\n");
	c = 'W'; printf("%c [%d] is %c\n", c, c, ft_tolower(c));
	c = '+'; printf("%c [%d] is %c\n", c, c, ft_tolower(c));
	c = 'a'; printf("%c [%d] is %c\n", c, c, ft_tolower(c));

	printf("\n--- strlen ---\n");
	char s2[100];
	strcpy(s2, "Hello");  printf("[%s] is %zu\n", s2, ft_strlen(s2));
	strcpy(s2, "Hello "); printf("[%s] is %zu\n", s2, ft_strlen(s2));
	strcpy(s2, "");       printf("[%s] is %zu\n", s2, ft_strlen(s2));

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
	str="This is a test"; 		TEST_STRNSTR(str, "This", 20, str);
  	str="This is another test  "; TEST_STRNSTR(str, "test", 20, &str[16]);
  	str="This is another test  "; TEST_STRNSTR(str, "test", 5, NULL);
  	str="No match here"; 		TEST_STRNSTR(str, "substring", 30,  NULL);
  	str="Some string"; 			TEST_STRNSTR(str, "", 30, str); // Empty needle
  	str="Short haystack"; 		TEST_STRNSTR(str, "too long", 30, NULL); // Needle longer than haystack
  	str="Find \0null"; 			TEST_STRNSTR(str, "\0null", 20, str); // Substring with null character
	str=""; 			TEST_STRNSTR(str, "find", 30, NULL); // Substring with null character
	str="This is a -1 test"; 		TEST_STRNSTR(str, "is a", -1, str);

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

	printf("\n--- ft_split ---\n");
	str = "This is a test string";
	str_v = ft_split(str, ' '); ft_split_print(str_v); if (str_v) free(str_v);
/*
	str_v = ft_split(str, '%'); if (str_v) free(str_v);
	str_v = ft_split("", ' '); if (str_v) free(str_v);
*/

	printf("\n--- ft_strlcat ---\n");
	test_strlcat();

	printf("\n--- ft_strrchr ---\n");
	//char *str;
	haystack1 = "This is a test string"; test_ft_strrchr(haystack1, 'z', NULL);
	str= "Hello, world!";  test_ft_strrchr(str, 'H', (char *)&str[0]);
	str= "Hello, world!";  test_ft_strrchr(str, 'o', (char *)&str[8]);
	str="This is a story"; test_ft_strrchr(str, 's', &str[10]);
  	str="Hello, world!";   test_ft_strrchr(str, 'l', &str[10]);
	str="Find the last character"; test_ft_strrchr(str, '\0', &str[ft_strlen(str)]);

	printf("\n--- ft_strlcpy ---\n");	
	test_strlcpy();

	printf("\n--- ft_memcpy ---\n");	
	test_ft_memcpy();

	printf("\n--- ft_memcmp ---\n");	
	test_ft_memcmp();

	printf("\n--- ft_memmove ---\n");
	test_ft_memmove();

	printf("\n--- ft_calloc ---\n");
	test_ft_calloc();

	printf("\n--- ft_strdup ---\n");
	test_ft_strdup();

	printf("\n--- ft_sttrim ---\n");
	

	printf("\n--- ft_itoa ---\n");
	n = 1234; printf("'%d' = '%s'\n", n, ft_itoa(n));
	n = -56789; printf("'%d' = '%s'\n", n, ft_itoa(n));
	n = INT_MAX; printf("'%d' = '%s'\n", n, ft_itoa(n));
	n = INT_MIN; printf("'%d' = '%s'\n", n, ft_itoa(n));
	n = 0; printf("'%d' = '%s'\n", n, ft_itoa(n));
	n = -1; printf("'%d' = '%s'\n", n, ft_itoa(n));
	return 0;
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
