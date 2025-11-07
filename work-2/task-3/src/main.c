#include "../include/overFunctions.h"
#include <stdio.h>
#include <limits.h>


#define BUFFER_SIZE 128


void printTestName(const char *name) {
  printf("\n==> %s <==\n", name);
}


void test1() {
  char result[BUFFER_SIZE];
  const char *str1 = "HELLO!";
  const char *str2 = "123abc";
  
  printTestName("test1-1");
  oversprintf(result, "oversprintf | %s %s\n", str1, str2);
  printf("%s", result);

  printTestName("test1-2");
  oversprintf(result, "oversprintf | %s %s\n", str1, str2);
  printf("%s", result);

  printTestName("test1-3");
  oversprintf(result, "oversprintf | %s %s\n", str1, str2);
  printf("%s", result);
  
  printTestName("test1-4");
  overfprintf(stdout, "overfprintf | %s %s\n", str1, str2);
}


void test2() {
  char result[BUFFER_SIZE];
  const long long int number = 12345678;

  printTestName("test2-1");
  overfprintf(stdout, "overfprintf | %lld\n", number);

  printTestName("test2-2");
  oversprintf(result, "oversprintf | %lld\n", number);
  printf("%s", result);
}


void test3() {
  char result[BUFFER_SIZE];
  const int number = 999;
  
  printTestName("test3-1");
  oversprintf(result, "oversprintf | %d: %Ro, %Zr\n", number, number, number);
  printf("%s", result);

  printTestName("test3-2");
  oversprintf(result, "oversprintf | %d: %Ro, %Zr\n", number, number, number);
  printf("%s", result);

  printTestName("test3-3");
  overfprintf(stdout, "overfprintf | %d: %Ro, %Zr\n", number, number, number);
}


void test4() {
  char result[BUFFER_SIZE];
  const char *ospf = "oversprintf";
  const char *ofpf = "overfprintf";
  const int number = 1234;

  printTestName("test4-1");
  oversprintf(result, "%s | %d: %Ro, %Zr\n", ospf, number, number, number);
  printf("%s", result);

  printTestName("test4-2");
  overfprintf(stdout, "%s | %d: %Ro, %Zr\n", ofpf, number, number, number);
}


void test5() {
  char result[BUFFER_SIZE];
  const char *ospf = "oversprintf";
  const char *ofpf = "overfprintf";
  const int number = 1234;

  printTestName("test5-1");
  printf("count of printed symbols: %d\n", oversprintf(result, "%s | %d: %Ro, %Zr\n", ospf, number, number, number));
  printf("%s", result);

  printTestName("test5-2");
  printf("count of printed symbols: %d\n", overfprintf(stdout, "%s | %d: %Ro, %Zr\n", ofpf, number, number, number));
}


int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  
  return 0;
}
