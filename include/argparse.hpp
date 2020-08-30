#ifndef ARGPARSE_HPP
#define ARGPARSE_HPP

#include <utility>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

#include <optional>

namespace argparse {

  constexpr const char* no_value = nullptr;
  constexpr const char* flag_set = "";

  struct argument {
    const char* signifier;
    std::size_t num;
    const char* value;

    static constexpr std::size_t no_param = 0;
    static constexpr std::size_t single_param = 1;

    // Responsible for in-place conversion of value to user defined storage.
    void (*conversion_func)(const char*, void*);
    void* storage_location;

    private:
      void check_num() {
        if (num == 0 && value != no_value)
          throw std::invalid_argument("argparse: default value given to no_param argument (illformed)");
      }
    public:

    argument(const char* s, std::size_t t, const char* default_value = nullptr)
      : signifier{s}, num{t}, value{default_value}, conversion_func{nullptr}, storage_location{nullptr}
    { check_num(); }

    argument(const char* s, std::size_t t, const char* default_value = nullptr, void (*c_f)(const char*, void*) = nullptr, void* s_l = nullptr)
      : signifier{s}, num{t}, value{default_value}, conversion_func{c_f}, storage_location{s_l} {}

    argument(const char* s, std::size_t t, void (*c_f)(const char*, void*), void* s_l)
      : signifier{s}, num{t}, value{no_value}, conversion_func{c_f}, storage_location{s_l} {}


    void attempt_conversion() {
      this->conversion_func(this->value, storage_location);
    }

    void set_value(const char* new_value = flag_set) {
      this->value = new_value;
      this->attempt_conversion();
    }

  };

  class parser {

    std::vector<argument> args;

    std::optional<std::size_t> is_arg_signifier(const char* s) {
      // TODO Discover cleaner way to impliment this.
      // possible solution could be to sort args by signifier
      // and do a binary search for the signifier.
      for(std::size_t i = 0; i < this->args.size(); ++i)
        if(strcmp(this->args[i].signifier, s) == 0)
          return std::optional<std::size_t>(i);

      return std::optional<std::size_t>();
    }

    public:
      parser() = default;


      /*
       * Parses command line arguments. If conversion function and storage
       * location are provided the conversion function will be used to
       * convert the string into the object type expected for that argument.
       */
      void parse(std::size_t argc, const char** argv) {

        std::optional<std::size_t> curr_arg;

        for(std::size_t i = 0; i < argc; ++i, ++argv) {
          curr_arg = is_arg_signifier(*argv);
          if(curr_arg.has_value()) {
            argument& arg = args[curr_arg.value()];

            // If argument takes no parameter set value true.
            if(arg.num == 0) {
              arg.set_value();
              continue;
            }

            // Take next argument to use.
            if(++argv == nullptr || ++i < argc) {
              // Error: argument value for signifier expected, none provided
              throw -1;
            }

            arg.set_value(*argv);

          }
        }
      }
  };
}

#endif
