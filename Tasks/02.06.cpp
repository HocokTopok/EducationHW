////////////////////////////////////////////////////////////////

#include <iostream>
#include <print>
#include <cmath>

////////////////////////////////////////////////////////////////

int main()
{
  double arr[100]{};

//  ------------------------------------------------------------

  size_t count = 0; std::cin >> count;

//  ------------------------------------------------------------

  for (size_t i = 0; i < count; ++i)
  {
    std::cin >> arr[i];
  }

//  ------------------------------------------------------------

  for (size_t i = 0; i < count; ++i)
  {
    for (size_t j = 0; j < count - 1 - i; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }

//  ------------------------------------------------------------

  double min = arr[0]; double max = arr[count - 1];

//  ------------------------------------------------------------

  double median = 0.0;

  if (count % 2 != 0)
  {
    median = arr[(count - 1) / 2];
  } else
  {
    median = (arr[count / 2] + arr[(count / 2) - 1]) / 2;
  }
    
//  ------------------------------------------------------------

  double average = 0.0;
  
  for (size_t i = 0; i < count; ++i)
  {
    average += arr[i];
  }

  average /= count;

//  ------------------------------------------------------------

  double sd = 0.0;

  for (size_t i = 0; i < count; ++i)
  {
    sd += std::pow(arr[i] - average, 2);
  }

  sd /= count;

  sd = std::sqrt(sd);

//  ------------------------------------------------------------

  std::print("min = {}, max = {}, median = {}, average = {}, standart deviation = {}", min, max, median, average, sd);
}

////////////////////////////////////////////////////////////////