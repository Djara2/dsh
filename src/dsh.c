#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// allocates memory, so make sure to free after you're done.
int* get_escape_indices(char *string);

int main(int argc, char **argv) {
	size_t input_buffer_length = 0;
	size_t input_buffer_capacity = 4096;
	char input_buffer[input_buffer_capacity];
	char current_char = 0;
	char previous_char = 0;
	
	size_t tokens_length = 0;
	size_t tokens_capacity = 256;
	char *tokens[tokens_capacity];
	size_t current_token_length = 0;

	unsigned short program_name_iterator = 0;
	unsigned short program_name_length = 0;
	unsigned short program_name_capacity = 64;
	char *program_name = (char*) malloc(program_name_capacity);
	if(program_name == NULL) {
		fprintf(stderr, "Failed to allocate memory to store program name.\n");
		exit(EXIT_FAILURE);
	}

	// Get input from the user
	while(current_char != "\n" && previous_char != '\\') {
		if(input_buffer_length >= input_buffer_capacity) {
			printf(stderr, "Maximum command size reached.\n");
			break;
		}

		previous_char = current_char;
		current_char = fgetc(stdin);
		input_buffer[input_buffer_length] = current_char;
		input_buffer_length++;
	}

	if(input_buffer_length == 0) break;

	// Interpret input as a command
	// (1) First part is always a binary.
	current_char = input_buffer[0];

	// (1.1) Program name contains spaces and the user is resolving the spaces by enclosing the whole thing with double quotes.
	if(current_char == '\"') {
		if(input_buffer_length < 3) { 
			fprintf(stderr, "Syntax Error. Program name starts with a double quote, but input buffer is less than 3 characters long.\n");
			break;
		}
		
		// Read characters until the next double quote. NO EXPANSIONS OR SPECIAL SYMBOLS - all characters will be read literally
		program_name_iterator = 1;
		current_char = input_buffer[program_name_iterator];	
		while(current_char != '\"') {
			// ensure sufficient space in program name buffer.
			if(program_name_length >= program_name_capacity) {
				program_name_capacity *= 2;
				program_name = (char *) realloc(program_name, program_name_capacity);
				if(program_name == NULL) {
					fprintf(stderr, "Memory error. Failed to reallocate program name buffer so that it may hold %hu bytes.\n", program_name_capacity);
					exit(EXIT_FAILURE);
				}
			}

			program_name[program_name_length] = current_char;
			current_char = input_buffer[program_name_iterator];
			program_name_length++;
			program_name_iterator++;
		}
	}
	// (1.2) Program name contains spaces and the user is resolving the spaces by enclosing the whole thing with single quotes.
	else if(current_char == '\'') {

	} 
	// (1.3) program name does not contain spaces or the user is using escapes to resolve the spaces.
	else { 

	}
	
	// Case 1: built-in command
	// Case 2: fork the current process
		// 

}

int* get_escape_indices(char *string, size_t string_length, int *indices_length, int *indices_capacity) {
	if(string == NULL) {
		fprintf(stderr, "[get_escape_indices] Provided char* argument was NULL. Returning NULL.\n");
		return NULL;
	}
	if(string_length == 0) {
		fprintf(stderr, "[get_escape_indices] Provided int string_length argument is 0. Expected a string that is at least 1 character long.\n");
		return NULL;
	} 
	if(indices_length == NULL) {
		fprintf(stderr, "[get_escape_indices] Provided int* indices_length argument points to NULL. This argument is required to manage the buffer being returned.\n");
		return NULL;
	}
	if(indices_capacity == NULL) {
		fprintf(stderr, "[get_escape_indices] Provided int* indices_capacity argument points to NULL. This argument is required to manage the buffer being returned.\n");
		return NULL;
	}
	char previous = string[0];
	for(size_t i = 1; i < string_length; i++) 
}
