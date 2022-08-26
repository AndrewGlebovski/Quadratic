/**
 * \file
 * \brief Contains command line arguments parser
*/
#include <string.h>
#include "quad_solver.hpp"


typedef struct {
	const char* short_name; ///< Command short name
	const char* long_name; ///< Command long name
	int mode; ///< Mode
	void (*func)(char *[]); ///< Command parser function
	void *data; ///< Additional data
} Command;


void set_input_stream(char *argv[]);
void set_output_stream(char *argv[]);
void run_predefined_tests(char *argv[]);
void run_tests_from_file(char *argv[]);


int parse(int argc, char* argv[]) {
	Command command_list[] = {
		{"-i", "--input", 0, &set_input_stream, NULL},
		{"-o", "--output", 0, &set_output_stream, NULL},
		{"-t", "--test", 0, &run_predefined_tests, NULL},
		{"-ts", "--test-stream", 0, &run_tests_from_file, NULL},
	};

	for(int j = 0; j < argc; j++) {
		int n = sizeof(command_list) / sizeof(Command);
		for(int i = 0; i < n; i++) {
			if (strcmp(command_list[i].short_name, argv[j]) == 0 || strcmp(command_list[i].long_name, argv[j]) == 0)
				(*(command_list[i].func))(&argv[j]);
		}
	}

	return 0;
}



void set_input_stream(char *argv[]) {
	if (*(argv + 1))
		FILE* stream = fopen(*(argv + 1), "r");
	else
		printf("No filename after %s, argument ignored\n", *argv);
}


void set_output_stream(char *argv[]) {
	if (*(argv + 1))
		FILE* stream = fopen(*(argv + 1), "w");
	else
		printf("No filename after %s, argument ignored\n", *argv);
}


void run_predefined_tests(char *argv[]) {
	start_testing(NULL);
	printf("%s\n", *argv);
}


void run_tests_from_file(char *argv[]) {
	if (*(argv + 1))
		start_testing(fopen(*(argv + 1), "r"));
	else
		printf("No filename after %s, argument ignored\n", *argv);
}

