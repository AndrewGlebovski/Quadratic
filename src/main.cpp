/**
 * \file
 * \brief Contains only two function
*/
#include <string.h>
#include "quad_solver.hpp"


FILE *in_stream = stdin;
FILE* out_stream =stdout;


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
    parse(argc, argv);

    // init params
    double a = NAN, b = NAN, c = NAN;

    // read params
    int exit_code  = input(in_stream, &a, &b, &c);
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
