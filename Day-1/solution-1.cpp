#include <iostream>
#include "./input.h"
#include "../utils/utils.h"

int main()
{

  uint64_t startTime = getMillis();

  int lastDepth = 0;
  int increasedValues = 0;

  for (int &num : depths)
  {
    if (lastDepth != 0 && num > lastDepth)
    {
      increasedValues++;
    }
    lastDepth = num;
  }

  uint64_t endTime = getMillis();

  std::cout << "Number of increased Values: " << increasedValues << std::endl;
  std::cout << "Took " << (endTime - startTime) << "ms" << std::endl;

  return 0;
}