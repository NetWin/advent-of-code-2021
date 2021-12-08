#include <stdio.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../utils/utils.h"

#include "./input.h"

std::vector<std::string> string_split(const std::string &strToSplit, char delimeter)
{
  std::stringstream ss(strToSplit);
  std::string item;
  std::vector<std::string> splittedStrings;
  while (std::getline(ss, item, delimeter))
  {
    splittedStrings.push_back(item);
  }
  return splittedStrings;
}

int main()
{

  uint64_t startTime = getMillis();

  int yPos = 0;
  int xPos = 0;

  for (std::string str : directions)
  {
    auto splits = string_split(str, ' ');
    std::string direction = splits.at(0);
    int distance = std::stoi(splits.at(1));

    if (strcmp(direction.c_str(), "down") == 0)
      yPos += distance;
    if (strcmp(direction.c_str(), "up") == 0)
      yPos -= distance;
    if (strcmp(direction.c_str(), "forward") == 0)
      xPos += distance;
  }

  uint64_t endTime = getMillis();

  std::cout << "New Position: [" << xPos << ", " << yPos << "]" << std::endl;
  std::cout << "Multiplied: " << xPos * yPos << std::endl;
  std::cout << "Took " << (endTime - startTime) << "ms" << std::endl;

  return 0;
}