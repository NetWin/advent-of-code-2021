#include <iostream>
#include "./input.h"
#include "../utils/utils.h"

int main()
{

  uint64_t startTime = getMillis();

  const int SlidingWindowWidth = 3;
  const int numberOfValues = sizeof(depths) / sizeof(int);
  const int numberOfValuesToIterate = numberOfValues - (SlidingWindowWidth - 1);

  int lastDepth = 0;
  int increasedValues = 0;

  for (int i = 0; i < numberOfValuesToIterate; i++)
  {

    // Get Value of sliding window
    int tmp = 0;
    for (int j = 0; j < SlidingWindowWidth; j++)
    {
      tmp += depths[i + j];
    }

    // Compare window depth with last depth (if there is one)
    if (lastDepth != 0 && tmp > lastDepth)
    {
      increasedValues++;
    }

    lastDepth = tmp;
  }

  uint64_t endTime = getMillis();

  std::cout << "Number of increased Values: " << increasedValues << std::endl;
  std::cout << "Took " << (endTime - startTime) << "ms" << std::endl;

  return 0;
}