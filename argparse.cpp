// Example program
#include <iostream>
#include <string>

#include <vector>

namespace argparse {
    
    class parser { 
    public:
        struct argument {
            char * signifier;
            unsigned int supplementals;
            std::vector<char *> defaults;
            std::vector<char *> results;
        };
        
    private:
    
         
        std::vector<argument> registered_arguments_;
    
    public:
        parser() = default;
    
        /* Configuration. */
        void create_argument(const char * signifier);
        // sup_count = 0 is equivalent to above.
        void create_argument(const char * signifier, const unsigned int sup_count);
        // default value is the same for each supplemental argument.
        void create_argument(const char * signifier, const unsigned int sup_count, const char * default_value);
        // default values must be provided for each supplemental argument.
        void create_argument(const char * signifier, const unsigned int sup_count, const char ** default_values);
        
        void register_argument(const argument& new_argument);
        
        /* Actual work. */
        bool operator()(char ** args);
    };
}

int main()
{
    argparse::parser parser;
    parser.create_argument("-c")
    
    parser.print_arguments()
}

