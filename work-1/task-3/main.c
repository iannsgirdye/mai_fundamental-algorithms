#include "utilities.h"
#include "functions.h"


int main(int argc, char* argv[]) {
  if (validate_arguments_count(argc, argv) != OK) {
    return 0;
  }

  switch (argv[1][1]) {
    case 'q':
      flag_q(argc, argv);
      break;
    case 'm':
      flag_m(argc, argv);
      break;
    case 't':
      flag_t(argc, argv);
      break;
  }

  return 0;
}
