#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::string code;
    while (true) {
      int *anker = (int *)calloc(30000, sizeof(int));
      int *ptr = anker;
      ptr += 15000;
      std::cout << "> " << std::flush;
      std::getline(std::cin, code);
      int code_size = code.size();
      std::map<int, int> loop_map;
      std::vector<int> loop_stack;

      for (int i = 0; i < code_size; i++) {
        if (code[i] == '[') {
          loop_stack.push_back(i);
        } else if (code[i] == ']') {
          if (loop_stack.empty()) {
            std::cerr << "Unmatched ']' at position " << i << std::endl;
            exit(1);
          }
          int open = loop_stack.back();
          loop_stack.pop_back();
          loop_map[open] = i;
          loop_map[i] = open;
        }
      }

      if (!loop_stack.empty()) {
        std::cerr << "Unmatched '[' at position " << loop_stack.back()
                  << std::endl;
        exit(1);
      }

      for (int i = 0; i < code_size; i++) {
        char c = code[i];
        switch (c) {
        case '>':
          ptr++;
          break;
        case '<':
          ptr--;
          break;
        case '+':
          if (*ptr == 256) {
            *ptr = 0;
          } else {
            (*ptr)++;
          }
          break;
        case '-':
          if (*ptr > 0) {
            (*ptr)--;
          } else {
            *ptr = 256;
          }
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
          if (*ptr == 0) {
            i = loop_map[i];
          }
          break;
        case ']':
          if (*ptr != 0) {
            i = loop_map[i];
          }
          break;
        default:
          break;
        }
      }
      free(anker);
    }
  }

  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Cannot open file: " << argv[1] << std::endl;
    return 1;
  }
  std::string code, line;
  while (std::getline(file, line)) {
    code += line;
  }
  int *anker = (int *)calloc(30000, sizeof(int));
  int *ptr = anker;
  ptr += 15000;
  int code_size = code.size();

  std::map<int, int> loop_map;
  std::vector<int> loop_stack;

  for (int i = 0; i < code_size; i++) {
    if (code[i] == '[') {
      loop_stack.push_back(i);
    } else if (code[i] == ']') {
      if (loop_stack.empty()) {
        std::cerr << "Unmatched ']' at position " << i << std::endl;
        exit(1);
      }
      int open = loop_stack.back();
      loop_stack.pop_back();
      loop_map[open] = i;
      loop_map[i] = open;
    }
  }

  if (!loop_stack.empty()) {
    std::cerr << "Unmatched '[' at position " << loop_stack.back() << std::endl;
    exit(1);
  }

  for (int i = 0; i < code_size; i++) {
    char c = code[i];
    switch (c) {
    case '>':
      ptr++;
      break;
    case '<':
      ptr--;
      break;
    case '+':
      if (*ptr == 256) {
        *ptr = 0;
      } else {
        (*ptr)++;
      }
      break;
    case '-':
      if (*ptr > 0) {
        (*ptr)--;
      } else {
        *ptr = 256;
      }
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
      if (*ptr == 0) {
        i = loop_map[i];
      }
      break;
    case ']':
      if (*ptr != 0) {
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
