#include <cassert>
#include <string>
#include <vector>
#include <iostream>

// Write a program that returns heads for a true, tails for a false and fails if there are no,
// too many arguments, or if the arguments are neither true or false

/// Do the main function
int doMain(const std::vector<std::string>& args)
{
    const size_t argc = args.size();
    if (argc == 2u) {
        if (args[1] == "true") {
            std::cout << "heads\n";
        }
        else if (args[1] == "false") {
            std::cout << "tails\n";
        }
        else {
            std::cout << "The argument was neither true or false.\n";
            return 1;
        }
    }
    else {

        if (argc < 2u) {
            std::cout << "No argument was provided.\n";
        }
        else if (argc > 2u) {
            std::cout << "More than one argument were provided.\n";
        }

        return 1;
    }
    return 0;
}

/// Main function
int main(int argc, char * argv[])
{

    const std::vector<std::string> args(argv, argv + argc);

    const std::string programName(args[0]);

    assert(doMain( { programName } ) == 1);
    assert(doMain( { programName, "true" } ) == 0);
    assert(doMain( { programName, "false" } ) == 0);
    assert(doMain( { programName, "true", "true" } ) == 1);
    assert(doMain( { programName, "nonsense" } ) == 1);

    return doMain(args);

}