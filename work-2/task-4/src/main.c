#include "../include/overFunctions.h"
#include "../include/returnStatus.h"
#include <stdio.h>


void printTestName(const char *name) {
  printf("\n===> %s <===\n", name);
}


void test1() {
  printTestName("test1");
  
  int number;
  char c1, c2;
  char str[BUFSIZ];
  int convertedRoman;
  unsigned int convertedZeckendorf;
  const char *src = "  12345XXXIII0001110011cc hello";

  oversscanf(src, "%d%Ro%Zr%c%c%s", &number, &convertedRoman, &convertedZeckendorf, &c1, &c2, str);
  printf("\"%d\" \"%d\" \"%u\" \"%c\" \"%c\" \"%s\"\n", number, convertedRoman, convertedZeckendorf, c1, c2, str);
}


void test2() {
  printTestName("test2");
  
  int number;
  char c1, c2;
  char str[BUFSIZ];
  int convertedRoman;
  unsigned int convertedZeckendorf;
  const char *src = "  12345XXXIII0001110011cc hello";

  oversscanf(src, "%d%Ro%Zr%c%c%s", &number, &convertedRoman, &convertedZeckendorf, &c1, &c2, str);
  printf("\"%d\" \"%d\" \"%u\" \"%c\" \"%c\" \"%s\"\n", number, convertedRoman, convertedZeckendorf, c1, c2, str);
}


void test3() {
  printTestName("test3");
  
  int number;
  char c1, c2;
  char str[BUFSIZ];
  int convertedRoman;
  unsigned int convertedZeckendorf;

  overfscanf(stdin, "%d%Ro%Zr%c%c%s", &number, &convertedRoman, &convertedZeckendorf, &c1, &c2, str);
  printf("\"%d\" \"%d\" \"%u\" \"%c\" \"%c\" \"%s\"\n", number, convertedRoman, convertedZeckendorf, c1, c2, str);
}


int main() {
  test1();
  test2();
  test3();

  return 0;
}
