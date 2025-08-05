//
//  args.c
//  sort-random-length-list
//
//  Created by Nathan on 7/28/25.
//

#include "../include/args.h"

void print_usage(const char* program_name) {
    printf("Usage: %s -f <filename> | --file <filename>\n", program_name);
    printf("Options:\n");
    printf("  -f, --file <filename>    Specify the input file containing names\n");
    printf("  -h, --help              Show this help message\n");
}

Args_t* parse_args(int argc, const char* argv[]) {
    Args_t* args = (Args_t*)malloc(sizeof(Args_t));
    if (!args) {
        perror("Failed to allocate memory for arguments");
        exit(EXIT_FAILURE);
    }
    
    args->filename = NULL;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: %s requires a filename argument\n", argv[i]);
                print_usage(argv[0]);
                free_args(args);
                exit(EXIT_FAILURE);
            }
            // Allocate memory and copy the filename
            args->filename = (char*)malloc(strlen(argv[i + 1]) + 1);
            if (!args->filename) {
                perror("Failed to allocate memory for filename");
                free_args(args);
                exit(EXIT_FAILURE);
            }
            strcpy(args->filename, argv[i + 1]);
            i++; // Skip the next argument since we've processed it
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            free_args(args);
            exit(EXIT_SUCCESS);
        }
        else {
            fprintf(stderr, "Error: Unknown option '%s'\n", argv[i]);
            print_usage(argv[0]);
            free_args(args);
            exit(EXIT_FAILURE);
        }
    }
    
    // Check if filename was provided
    if (!args->filename) {
        fprintf(stderr, "Error: No input file specified\n");
        print_usage(argv[0]);
        free_args(args);
        exit(EXIT_FAILURE);
    }
    
    return args;
}

void free_args(Args_t* args) {
    if (args) {
        if (args->filename) {
            free(args->filename);
        }
        free(args);
    }
}
