//
//  main.c
//  sort-random-length-list
//
//  Created by Nathan on 7/28/25.
//

#include "include/linked_list.h"
#include "include/args.h"

int main(int argc, const char * argv[]) {

    // Parse command line arguments
    Args_t* args = parse_args(argc, argv);
    
    FILE* file = fopen(args->filename, "r");
        if (!file) {
            perror("Could not open file");
            return 1;
        }

        Node_t* head = NULL;
        char buffer[MAX_NAME_LEN];

        while (fgets(buffer, sizeof(buffer), file)) {

            // Remove newline character if present
            // strcspn works kind of like the indexOf method in JavaScript
            buffer[strcspn(buffer, "\n")] = '\0';  
            
            append_node(&head, buffer);
        }

        fclose(file);

        printf("Unsorted list:\n");
        print_list(head);

        sort_list(head);

        printf("\nSorted list:\n");
        print_list(head);

        free_list(head);
        free_args(args);
        return 0;
}
