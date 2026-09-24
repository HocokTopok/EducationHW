////////////////////////////////////////////////////////////////

#include <print>
#include <vector>

////////////////////////////////////////////////////////////////

int main()
{
  const unsigned long long upper_limit = 100;

  size_t max_length = 0; unsigned long long max_start = 0;

//  ------------------------------------------------------------

  std::vector<size_t> cache(upper_limit + 1, 0);

//  ------------------------------------------------------------

  size_t len = 0;

  for (unsigned long long start = 1; start <= upper_limit; ++start)
  {
    len = 0;

    unsigned long long current = start;

    std::vector<unsigned long long> path = {current};

    while (current != 1)
    {
      if (current % 2 == 0)
      {
        current /= 2;
      }
      else
      {
        current *= 3;

        ++current;
      }

      if (current <= upper_limit && cache[current] != 0)
      {
        len = cache[current];
      
        break;
      }

      path.push_back(current);
    }

    while (!path.empty())
    {
      ++len;

      unsigned long long step = path.back();

      path.pop_back();

      if (step <= upper_limit)
      {
        cache[step] = len;
      }
    }

    if (max_length < len)
    {
      max_length = len;

      max_start = start;
    }
  }

//  ------------------------------------------------------------

  std::print("max start = {}, max len = {}", max_start, max_length);
}

////////////////////////////////////////////////////////////////