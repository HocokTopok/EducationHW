////////////////////////////////////////////////////////////////

#include <iostream>
#include <print>
#include <cmath>

////////////////////////////////////////////////////////////////

int main()
{
  size_t size = 0; size_t capacity = 1;

//  ------------------------------------------------------------

  double* arr = new double[capacity]{};

//  ------------------------------------------------------------

  double new_element = 0.0;

  while (std::cin >> new_element)
  {
    if (size >= capacity)
    {
      double* old_arr = arr;

      capacity *= 2;

      arr = new double[capacity]{};

      for (size_t i = 0; i < size; ++i)
      {
        arr[i] = old_arr[i];
      }

      delete[] old_arr;
    }

    arr[size] = new_element;

    ++size;
  }

//  ------------------------------------------------------------

  for (size_t i = 0; i < size; ++i)
  {
    for (size_t j = 0; j < size - 1 - i; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }

//  ------------------------------------------------------------

  double min = arr[0]; double max = arr[size - 1];

//  ------------------------------------------------------------

  double median = 0.0;

  if (size % 2 != 0)
  {
    median = arr[(size - 1) / 2];
  } else
  {
    median = (arr[size / 2] + arr[(size / 2) - 1]) / 2;
  }
    
//  ------------------------------------------------------------

  double average = 0.0;
  
  for (size_t i = 0; i < size; ++i)
  {
    average += arr[i];
  }

  average /= size;

//  ------------------------------------------------------------

  double sd = 0.0;

  for (size_t i = 0; i < size; ++i)
  {
    sd += std::pow(arr[i] - average, 2);
  }

  sd /= size;

  sd = std::sqrt(sd);

//  ------------------------------------------------------------

  delete[] arr;

//  ------------------------------------------------------------

  std::print("min = {}, max = {}, median = {}, average = {}, standart deviation = {}", min, max, median, average, sd);
}

////////////////////////////////////////////////////////////////