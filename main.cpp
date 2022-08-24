/**
 * \file
 * \brief This stream contains only the main() function
*/
#include <string.h>
#include "quad_solver.hpp"


/**
 * \brief Reads command line arguments
 * \param [in] argc Amount of arguments
 * \param [in] argv Array of strings
 * \param [out] in_stream Input file pointer
 * \param [out] out_stream Output file pointer
*/
static int read_args(int argc, char *argv[], FILE **in_stream, FILE **out_stream);


/// The main function of the program
int main(int argc, char *argv[]) {
    FILE *in_stream = stdin, *out_stream = stdout;

    read_args(argc, argv, &in_stream, &out_stream);

    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    INPUT_EXIT_CODE input_code = input(in_stream, &a, &b, &c);
    if (input_code != OK) {
        fprintf(out_stream, "Input failed with exit code %d\n", input_code);
        return 1;
    }

    // calculate result
    Solution result = solve_quadratic(a, b, c);

    // print result
    output(out_stream, result);

    // file close
    fclose(in_stream);
    fclose(out_stream);

    return 0;
}


static int read_args(int argc, char *argv[], FILE **in_stream, FILE **out_stream) {
    while(argc--) {
        // input argument
        if (strcmp(*argv, "-i") == 0) {
            if (!(argv++)) {
                printf("Wrong arguments");
                return 1;
            }

            *in_stream = fopen(*argv, "r");

            if (!*in_stream) {
                printf("Can't open file %s\n", *argv);
                return 1;
            }

            argc--;
        }

        // output argument
        if (strcmp(*argv, "-o") == 0) {
            if (!(argv++)) {
                printf("Wrong arguments");
                return 1;
            }

            *out_stream = fopen(*argv, "w");

            argc--;
        }

        argv++;        
    }

    return 0;
}
