#include <string.h>
#include <memory>
#include <map>
#include <iostream>
#include <getopt.h>

#include <utils.hpp>
#include <exercises/all.hpp>

int main(int argc, char *const argv[])
{
  std::map<std::string, Exercise *> m{
      {"triangle", new Triangle()},
      {"square", new Square()}};

  Exercise *exercise;

  for (;;)
  {
    switch (getopt(argc, argv, "p:")) // note the colon (:) to indicate that 'b' has a parameter and is not a switch
    {
    case 'p':
      exercise = m[optarg];
      exercise->initialize().run();
      break;
    case -1:
      break;
    }

    break;
  }

  return 0;
}