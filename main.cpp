#include <cstdlib>
#include <cstring>
#include "lab.h"
#include <iostream>
#include "sayfetdinovsf.h"
#include "zhalninrv.h"
#include "borisovayu.h"

void print_usage(char* name);


int main(int argc, char** argv)
{
  if (argc < 3) {
    print_usage(argv[0]);
    return 0;
  }

  lab *l = NULL;
  if (strcmp(argv[1], "zhalninrv") == 0) {
    l = new zhalninrv();
  }
  else if (strcmp(argv[1], "sayfetdinovsf") == 0) {
    l = new sayfetdinovsf();
  }
  else if (strcmp(argv[1], "borisovayu") == 0) {
    l = new borisovayu();
  }
  else  {
    print_usage(argv[0]);
    return 0;
  }

  l->read_file();
  l->run(atoi(argv[2]));
  l->write_result();
  l->check_result();

  //delete l; // TODO:
  return 0;
}


void print_usage(char* name)
{
  std::cout << "Usage:\n\n  " << name << " <fio> <lab_number>\n";
}
