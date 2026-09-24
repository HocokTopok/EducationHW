////////////////////////////////////////////////////////////////

#include <iostream>
#include <print>

////////////////////////////////////////////////////////////////

int main()
{
  double epsilon = 0.0; std::cin >> epsilon;

//  ------------------------------------------------------------

  double pi = 0.0; double exponent = 0.0;

//  ------------------------------------------------------------

  double current = 1.0; bool sign = false;

  while (1.0 / current >= epsilon)
  {
    pi += (sign ? -1.0 : 1.0) / current;

    current += 2.0;

    sign = !sign;
  }

  pi *= 4;

//  ------------------------------------------------------------
  
  current = 1.0; double divider = 1.0; 

  while (current >= epsilon)
  {
    exponent += current;

    current /= divider;
    
    ++divider;
  }

//  ------------------------------------------------------------

  std::print("pi = {}, exponent = {}", pi, exponent);
}

////////////////////////////////////////////////////////////////