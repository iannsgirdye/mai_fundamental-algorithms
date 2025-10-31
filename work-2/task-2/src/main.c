#include "../include/functions.h"
#include "../include/colors.h"
#include <stdio.h>
#include <stdlib.h>


void testMemchr() {
  const char *str = "abcdefg";
  const char c = 'c';
  const size_t n = 4;

  printf(
    COLOR_YELLOW "memchr"
    COLOR_MAGENTA "("
    COLOR_CYAN "\"%s\""
    COLOR_WHITE ", "
    COLOR_CYAN "'%c'"
    COLOR_WHITE ", "
    COLOR_CYAN "%zu"
    COLOR_MAGENTA ")"
    COLOR_WHITE ": %p, %p\n",
    str, c, n,
    str, memchr(str, c, n)
  );
}


void testMemcmp() {
  const char *str1 = "abcdefg";
  const char *str2 = "abcdeee";
  const size_t n = 5;

  printf(
    "memcmp(\"%s\", \"%s\", %zu): %d\n", 
    str1, str2, n,
    memcmp(str1, str2, n)
  );
}


void testMemcpy() {
  const char *src = "abcdef";
  char dest[7];
  const size_t n = 1;
  
  memcpy(dest, src, n);
  dest[n] = '\0';
  printf(
    "memcpy(dest, \"%s\", %zu): \"%s\"\n", 
    src, n, dest
  );
}


void testMemset() {
  char str[10];
  const char c = 'g';
  const size_t n = 8;

  memset(str, c, n);
  str[n] = '\0';
  printf(
    "memset(str, '%c', %zu): \"%s\"\n",
    c, n, str
  );
}


void testStrncat() {
  char dest[10] = {'1', '2', '3', '4', '5'};
  const char *destCopy = "12345";
  const char *src = "6789";
  const size_t n = 4;

  printf(
    "strncat(\"%s\", \"%s\", %zu): \"%s\"\n",
    destCopy, src, n, strncat(dest, src, n)
  );
}


void testStrchr() {
  const char *str = "328658";
  const char c = '8';

  printf(
    "strchr(\"%s\", %c): %p, %p\n",
    str, c, str, strchr(str, c)
  );
}


void testStrncmp() {
  const char *str1 = "876543";
  const char *str2 = "87600000";
  const size_t n = 3;

  printf(
    "strncmp(\"%s\", \"%s\", %zu): %d\n",
    str1, str2, n, strncmp(str1, str2, n)
  );
}


void testStrncpy() {
  char dest[10];
  const char *src = "123456789";
  const size_t n = strlen(src);

  printf("strncpy(dest, \"%s\"): \"%s\"\n", src, strncpy(dest, src, n));
}


void testStrcspn() {
  const char *str1 = "1234567";
  const char *str2 = "7654";
  
  printf(
    "strcspn(\"%s\", \"%s\"): %zu\n",
    str1, str2, strcspn(str1, str2)
  );
}


void testStrerror() {
  const int errnum = 10;
  printf("strerror(%d): %s\n", errnum, strerror(errnum));
}


void testStrLen() {
  const char *str = "12345678";
  printf("strlen(\"%s\"): %zu\n", str, strlen(str));
}


void testStrpbrk() {
  const char *str1 = "12345";
  const char *str2 = "98765";

  printf(
    "strpbrk(\"%s\", \"%s\"): str1=%p, &c=%p\n",
    str1, str2, str1, strpbrk(str1, str2)
  );
}


void testStrrchr() {
  const char *str = "123123123";
  const char c = '2';

  printf(
    "strrchr(\"%s\", '%c'): str=%p, &c=%p\n",
    str, c, str, strrchr(str, c)
  );
}


void testStrstr() {
  const char *haystack = "12345671234567";
  const char *needle = "45678";

  printf(
    "strstr(\"%s\", \"%s\"): haystack=%p, needle=%p\n",
    haystack, needle, haystack, strstr(haystack, needle)
  );
}


void testStrtok() {
  char str[] = "1234_567,890!";
  const char *delim = ",!_?";

  printf("strtok(\"%s\", \"%s\"): \"%s\"\n", str, delim, strtok(str, delim));
  printf("strtok(%p, \"%s\"): \"%s\"\n", NULL, delim, strtok(NULL, delim));
  printf("strtok(%p, \"%s\"): \"%s\"\n", NULL, delim, strtok(NULL, delim));
  printf("strtok(%p, \"%s\"): \"%s\"\n", NULL, delim, strtok(NULL, delim));
}


int main() {
  testMemchr();
  testMemcmp();
  testMemcpy();
  testMemset();
  testStrncat();
  testStrchr();
  testStrncmp();
  testStrncpy();
  testStrcspn();
  testStrerror();
  testStrLen();
  testStrpbrk();
  testStrrchr();
  testStrstr();
  testStrtok();

  return 0;
}
