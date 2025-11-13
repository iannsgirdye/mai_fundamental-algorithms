#include <stdio.h>
#include "../include/checkBrackets.h"

int main() {
  char str[BUFSIZ];
  scanf("%s", str);
  printf("%s\n", chech_brackets(str) ? "true" : "false");
  return 0;
}
