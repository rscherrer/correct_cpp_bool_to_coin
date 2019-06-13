#include <iostream>
#include <string>


/// Main function
int main(int argc, char * argv[]) {

    try {

        // Initialize the coin side
        std::string coin = "heads";

        // Check for number of arguments
        if (argc == 1) {
            throw std::runtime_error("No argument was provided. Please provide an argument.");
        }

        if (argc > 2) {
            throw std::runtime_error("More than one argument were provided. Please provide exactly one argument.");
        }

        // Convert to string
        std::string argument(argv[1]);

        // Change coin side if needed and check for validity of the input string
        if (argument == "false") {

            coin = "tails";

        }

        if (argument != "true") {

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