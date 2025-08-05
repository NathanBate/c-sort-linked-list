//
//  args.h
//  sort-random-length-list
//
//  Created by Nathan on 7/28/25.
//

#ifndef ARGS_H
#define ARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* filename;
} Args_t;

// Function declarations
void print_usage(const char* program_name);
Args_t* parse_args(int argc, const char* argv[]);
void free_args(Args_t* args);

#endif // ARGS_H
