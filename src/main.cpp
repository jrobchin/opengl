#include <string.h>
#include <iostream>
#include <getopt.h>

#include <utils.hpp>
#include <triangle.hpp>

int main(int argc, char *const argv[])
{
  for (;;)
  {
    switch (getopt(argc, argv, "p:")) // note the colon (:) to indicate that 'b' has a parameter and is not a switch
    {
    case 'p':
      if (strcmp(optarg, "triangle") == 0)
      {
        std::cout << "Running triangle" << std::endl;
        runTriangle();
      }
      break;
    case -1:
      break;
    }

    break;
  }

  return 0;
}