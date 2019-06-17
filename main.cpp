#include <iostream>
#include <string>
#include <vector>
#include <cassert>

/// Do the main
int doMain(const std::vector<std::string>& args) noexcept
{
    try {

        const size_t argc = args.size();

        // Initialize the coin side
        std::string coin = "heads";

        // Check for number of arguments
        if (argc == 1) {
            throw std::runtime_error("No argument was provided. Please provide an argument.");
        }

        if (argc > 2) {
            throw std::runtime_error("More than one argument were provided. Please provide exactly one argument.");
        }

        // Change coin side if needed and check for validity of the input string
        if (args[1] == "false") {

            coin = "tails";

        }
        else if (args[1] != "true") {

            throw std::runtime_error("The argument was neither true or false. Please provide either true or false.");

        }

        // Print the result
        std::cout << coin << '\n';

    }
    catch(const std::exception &err) {

        std::cerr << "Exception: " << err.what() << '\n';

        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

/// Main function
int main(int argc, char * argv[])
{

    // Tests
    assert(doMain( { "bool_to_coin" } ) == 1);
    assert(doMain( { "bool_to_coin", "true" } ) == 0);
    assert(doMain( { "bool_to_coin", "false" } ) == 0);
    assert(doMain( { "bool_to_coin", "true", "true" } ) == 1);
    assert(doMain( { "bool_to_coin", "nonsense" } ) == 0);

    const std::vector<std::string> args(argv, argv + argc);
    const int out = doMain(args);

    return out;

}