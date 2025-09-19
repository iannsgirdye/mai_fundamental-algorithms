#include "utilities.h"
#include "functions.h"

int main(int argc, char* argv[]) {
  if (validate_arguments_count(argc, argv)) {
    return 0;
  };

  int x;
  if (validate_x(argv[1], &x)) {
    return 0;
  }

  char flag;
  if (validate_flag(argv[2], &flag)) {
    return 0;
  }

  switch (flag) {
    case 'h':
      flag_h(x);
      break;
    case 'p':
      flag_p(x);
      break;
    case 's':
      flag_s(x);
      break;
    case 'e':
      flag_e(x);
      break;
    case 'a':
      flag_a(x);
      break;
    case 'f':
      flag_f(x);
      break;
  }

  return 0;
}
