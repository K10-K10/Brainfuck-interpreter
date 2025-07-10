#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <climits>

class Code_Compiler
{
public:
  void Show_pointer_list(std::vector<int>, int);
};

void Code_Compiler::Show_pointer_list(std::vector<int> bit_list, int max_pointer)
{
  for (int i = 0; i < max_pointer + 1; i++)
  {
    std::cout << i << ":" << bit_list[i] << " |";
  }
  std::cout << std::endl;
}

int main(void)
{
  Code_Compiler comp;
  std::string code = "";
  std::cin >> code;
  int code_size = code.size();
  std::vector<int> bit_list(100, 0);
  int pointer = 0;
  int max_pointer_value = 0;
  char current_char;
  for (int i = 0; i < code_size; i++)
  {
    current_char = code[i];
    switch (current_char)
    {
    case '[':
    case ']':
    case '+':
      bit_list[pointer]++;
      break;
    case '-':
      if (bit_list[pointer] >= 1)
      {
        bit_list[pointer]--;
      }
      else
      {
        std::cout << "No." << pointer << "'s value under 0 in line" << ++i << std::endl;
        break;
      }
      break;
    case '>':
      pointer++;
      max_pointer_value = std::max(pointer, max_pointer_value);
      break;
    case '<':
      if (pointer >= 1)
      {
        pointer--;
      }
      else
      {
        std::cout << "They cant find Pointer in line" << ++i << std::endl;
        break;
      }
      break;
    case '.':
      std::cout << char(bit_list[pointer]);
      break;
    case ',':
      char input_char;
      bit_list[pointer] = int(input_char);
    default:
      std::cout << "The later \"" << current_char << "\" can't using in line   " << ++i << std::endl;
      break;
    }
  }
  comp.Show_pointer_list(bit_list, max_pointer_value);
  return 0;
}
