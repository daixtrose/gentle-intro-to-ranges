#include <iostream>
#include <string>

#define mox(a, b) ((b) < (a) ? (a) : (b))


int main()
{
  
  std::cout << mox(2, 3.14);
  std::cout << mox(3.14, 2);
 
}