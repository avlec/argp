#include "../include/argparse.hpp"

// Simple example for how inplace conversions are supposed to be used.
struct custom_type {
  const char* s;
};
void s_to_custom_type(const char* value, void* storage_location) {
  static_cast<custom_type*>(storage_location)->s = value;
}

// Some cooler things this enables is building in more complicated things like
// in this example converting the argument into a file handle for read/write ops.
void arg_to_file_ptr(const char* value, void* location) {
  *static_cast<FILE**>(location) = fopen(value, "rw");
}

void arg_to_set_bool(const char* value, void* location) {
  if (value != argparse::no_value)
    *static_cast<bool*>(location) = true;
}

int main(int argc, char** argv) {
/*  argparse::parser parser =
  {
  { "-c", argparse::argument_type::no_param, "specifies the target is to be compiled but not linked." },
  { "-o", argparse::argument_type::single, "specifies the output file",  }
  };
  parser.parse(argc, argv);
*/
  FILE* yehaw = nullptr;
  bool c = false;
  std::cout << yehaw;
  // Note, no_param arguments must not be given a default value.
  argparse::argument a1 { "-c", argparse::argument::no_param, arg_to_set_bool, &c };
  argparse::argument a { "-o", argparse::argument::single_param, "test.txt", arg_to_file_ptr, &yehaw };
  a.set_value("test.txt");
  a.attempt_conversion();
  std::cout << " ... " << static_cast<char>(fgetc(yehaw)) << std::endl;
}
