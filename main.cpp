/**
 * \file
 * \brief Contains only two function
*/
#include <string.h>
#include "quad_solver.hpp"


/**
 * \brief Reads command line arguments 
 * \param [in] argc Amount of arguments
 * \param [in] argv Array of strings
 * \param [out] in_stream Input file pointer
 * \param [out] out_stream Output file pointer
 * \return Exit code (see #EXIT_CODE)
*/
static EXIT_CODE read_args(int argc, char *argv[], FILE **in_stream, FILE **out_stream);


/** 
 * \brief The main function of the program
 * 
 * \note Possible commnad line arguments:
 * \note -i "filename" Changes input stream to the given file
 * \note -o "filename" Changes output stream to the given file
 * \note -t Runs some predefined tests before start
 * \note -ts "filename" Runs some predefined tests before start and tests from the given file 
 * 
 * \warning In case of wrong arguments, program will close
*/
int main(int argc, char *argv[]) {
    FILE *in_stream = stdin, *out_stream = stdout;

    int exit_code = read_args(argc, argv, &in_stream, &out_stream);
    if (exit_code != OK) {
        fprintf(out_stream, "Argument reader failed with exit code %d\n", exit_code);
        return 1;
    }

    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    exit_code  = input(in_stream, &a, &b, &c);
    if (exit_code != OK) {
        fprintf(out_stream, "Input failed with exit code %d\n", exit_code);
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


static EXIT_CODE read_args(int argc, char *argv[], FILE **in_stream, FILE **out_stream) {
    while(argc--) {
        // input stream
        if (strcmp(*argv, "-i") == 0) {
            argc--, argv++;
            *in_stream = fopen(*argv, "r");

            if (!*in_stream)
                return NO_FILE;
        }

        // output stream
        if (strcmp(*argv, "-o") == 0) {
            argc--, argv++;
            *out_stream = fopen(*argv, "w");
        }

        // test before start enable
        if (strcmp(*argv, "-t") == 0) {
            start_testing(NULL);
        }

        // test before start enable from your file
        if (strcmp(*argv, "-ts") == 0) {
            argc--, argv++;
            FILE *test_stream = fopen(*argv, "r");
            start_testing(test_stream);
        }

        argv++;        
    }

    return OK;
}
