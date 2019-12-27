#Notes to Programmer.
    
Adding support for multiple signifiers to mean and reference the same thing.
- const char** signifiers in the create_argument functions as overrides?
- argument class to use a 3rd vector ;(
- the reason this would be useful is for use cases like -o, --output, or -output
    
Building in help support into creation of argument parser args.
    
Error handling for expected supplemental arguments.
    
Ability to declare if an argument is mandatory.
- Reflection of this in the help support.
    
Adding support for space delimited supplemental arguments, equals delimited supplemental
arguments, or custom character delimited supplemental arguments.
- i.e., `-output x.txt` vs. `-output=x.txt` vs. `-output~x.txt`
- would this be a global thing,per argument, or global with a per argument override?
