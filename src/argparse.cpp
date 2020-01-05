// Example program
#include <iostream>
#include <string>
#include <cassert>
#include <array>
#include <string_view>

namespace argparse {
    
    class parser { 
    public:
        template <unsigned int size>
		struct argument {
            const char* signifier;
            std::array<std::string_view, size> results;

			argument(const char* signifier_)
			: signifier(signifier_)
			{
			}

			void set_defaults(std::initializer_list<const char*> defaults)
			{
				switch(defaults.size())
				{
					case size:
						// Copy 1 to 1
						break;
					case 1:
						// Copy element sup_c times into results.
						break;
					default:
						[[unlikely]] throw std::invalid_argument("defaults of illegal length provided");
					case 0:
						break;
				}
			}
        };
        
    private:
        argument registered_arguments_;
    
    public:
        parser() = default;
    
        /* Configuration. */
        // default values must be provided for each supplemental argument.
        void create_argument(std::initializer_list<const char*> signifiers, const unsigned int sup_c, std::initializer_list<const char*> defaults)
		{
//			registered_arguments_.emplace_back(signifiers[0], sup_c);

	//		if (defaults != nullptr)
	//			(registered_arguments_.back()).set_defaults(defaults);
		}

        /* Actual work. */

        bool operator()(char ** args);
    	
		void print_arguments()
		{
	//		for(auto& arg: registered_arguments_)
	//			std::cout << arg.signifier << "," << arg.sup_c << std::endl;
		}
	};
}

constexpr int test_cexpr(std::initializer_list<const char*> x)
{
	return (int) (*x.begin())[0];
}

int main()
{
    argparse::parser parser;
    parser.create_argument({"-c", "-v"}, 0, {});
  
	constexpr int x = test_cexpr({"FUCK"});	


  //  parser.print_arguments();
}

