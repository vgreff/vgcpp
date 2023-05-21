
#include <iostream>
#include <vbg/hft/Hexdump.hpp>

int main(int argc, char const *argv[])
{
  std::cout << "This is main" << std::endl;
  unsigned char data[150];
  unsigned char c = 0;
  for (auto &val : data)
  {
    val = c++;
  }

  std::cout << vbg::hft::Hexdump(data, sizeof(data)) << std::endl;
  std::cout << 15 << std::endl;

  return 0;
}
