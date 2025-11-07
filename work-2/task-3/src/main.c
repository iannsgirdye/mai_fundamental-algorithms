#include "../include/overFunctions.h"
#include <stdio.h>
#include <limits.h>


#define BUFFER_SIZE 128


void printTestHeading(const char *name) {
  printf("\n===> %s <===\n", name);
}


void test1() {
  printTestHeading("test1");

  char result[BUFFER_SIZE];
  const char *str1 = "HELLO!";
  const char *str2 = "123abc";
  
  printf("\ntest1-1: \n");
  oversprintf(result, "oversprintf | %s %s\n", str1, str2);
  printf("%s", result);

  printf("\ntest1-2: \n");
  oversprintf(result, "oversprintf | %s %s\n", str1, str2);
  printf("%s", result);

  printf("\ntest1-3: \n");
  oversprintf(result, "oversprintf | %s %s\n", str1, str2);
  printf("%s", result);
  
  printf("\ntest1-4: \n");
  overfprintf(stdout, "overfprintf | %s %s\n", str1, str2);
}


void test2() {
  printTestHeading("test2");

  char result[BUFFER_SIZE];
  const long long int number = 12345678;

  printf("\ntest2-1: \n");
  overfprintf(stdout, "overfprintf | %lld\n", number);

  printf("\ntest2-2: \n");
  oversprintf(result, "oversprintf | %lld\n", number);
  printf("%s", result);
}


void test3() {
  printTestHeading("test3");

  char result[BUFFER_SIZE];
  const int number = 999;
  
  printf("\ntest3-1: \n");
  oversprintf(result, "oversprintf | %d: %Ro, %Zr\n", number, number, number);
  printf("%s", result);

  printf("\ntest3-2: \n");
  oversprintf(result, "oversprintf | %d: %Ro, %Zr\n", number, number, number);
  printf("%s", result);

  printf("\ntest3-3: \n");
  overfprintf(stdout, "overfprintf | %d: %Ro, %Zr\n", number, number, number);
}


void test4() {
  printTestHeading("test4");

  char result[BUFFER_SIZE];
  const char *ospf = "oversprintf";
  const char *ofpf = "overfprintf";
  const int number = 1234;

  printf("\ntest4-1: \n");
  oversprintf(result, "%s | %d: %Ro, %Zr\n", ospf, number, number, number);
  printf("%s", result);

  printf("\ntest4-2: \n");
  overfprintf(stdout, "%s | %d: %Ro, %Zr\n", ofpf, number, number, number);
}


int main() {
  test1();
  test2();
  test3();
  test4();
  
  return 0;
}
