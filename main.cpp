#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>

int main()
{
  int *anker = (int *)calloc(30000, sizeof(int));
  int *ptr = anker;

  std::string code;
  std::cin >> code;
  int code_size = code.size();

  std::map<int, int> loop_map;
  std::vector<int> loop_stack;

  for (int i = 0; i < code_size; i++)
  {
    if (code[i] == '[')
    {
      loop_stack.push_back(i);
    }
    else if (code[i] == ']')
    {
      if (loop_stack.empty())
      {
        std::cerr << "Unmatched ']' at position " << i << std::endl;
        exit(1);
      }
      int open = loop_stack.back();
      loop_stack.pop_back();
      loop_map[open] = i;
      loop_map[i] = open;
    }
  }

  if (!loop_stack.empty())
  {
    std::cerr << "Unmatched '[' at position " << loop_stack.back() << std::endl;
    exit(1);
  }

  for (int i = 0; i < code_size; i++)
  {
    char c = code[i];
    switch (c)
    {
    case '>':
      ptr++;
      break;
    case '<':
      ptr--;
      break;
    case '+':
      (*ptr)++;
      break;
    case '-':
      if (*ptr > 0)
        (*ptr)--;
      break;
    case '.':
      std::cout << char(*ptr);
      break;
    case ',':
      char in;
      std::cin >> in;
      *ptr = int(in);
      break;
    case '[':
      if (*ptr == 0)
      {
        i = loop_map[i];
      }
      break;
    case ']':
      if (*ptr != 0)
      {
        i = loop_map[i];
      }
      break;
    default:
      break;
    }
  }

  free(anker);
  return 0;
}
