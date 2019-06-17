#include <cassert>
#include <string>
#include <vector>
#include <iostream>

// Write a program that succeeds if there is just one argument, and fails otherwise

int doMain(const std::vector<std::string>& args)
{
    const size_t argc = args.size();
    if (argc == 2u) {
        return 0;
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
}

int main(int argc, char * argv[])
{

    const std::vector<std::string> args(argv, argv + argc);

    const std::string programName(args[0]);

    assert(doMain( { programName } ) == 1);
    assert(doMain( { programName, "arg1" } ) == 0);
    assert(doMain( { programName, "arg1", "arg2" } ) == 1);

    return doMain(args);

}