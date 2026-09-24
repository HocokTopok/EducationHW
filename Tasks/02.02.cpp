////////////////////////////////////////////////////////////////

#include <print>
#include <iostream>
#include <cmath>

////////////////////////////////////////////////////////////////

int main()
{
  const double epsilon = 1e-9;

//  ------------------------------------------------------------

	double a = 0.0, b = 0.0, c = 0.0;

  std::cin >> a >> b >> c;

//  ------------------------------------------------------------
  
  if (std::abs(a) < epsilon)
  {
    if (std::abs(b) < epsilon)
    {
      if (std::abs(c) < epsilon)
      {
        std::print("Infinite roots");
      }
      else
      {
        std::print("No real roots");
      }
    }
    else
    {
      double result = - c / b;

      std::print("{}", result);
    }
  }
  else
  {
    double discriminant = (b * b) - 4 * a * c;

    if (std::abs(discriminant) < epsilon)
    {
      double result = - b / (2 * a);

      std::print("{}", result);
    }
    else if (discriminant < 0.0)
    {
      std::print("No real roots");
    }
    else
    {
      double result_1 = (- b - std::sqrt(discriminant)) / (2 * a);

      double result_2 = (- b + std::sqrt(discriminant)) / (2 * a);

      std::print("{} {}", result_1, result_2);
    }
  }	
}

////////////////////////////////////////////////////////////////