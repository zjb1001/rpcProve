#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpc.c"

#define MAX_MESSAGE_LENGTH 100

void handle_rpc_call(const char* message) {
    rpc_call(message);
    const char* response = get_response();
    printf("%s\n", response);
}

int main() {
    char buffer[MAX_MESSAGE_LENGTH];
    
    printf("RPC server is running. Enter 'quit' to exit.\n");
    
    while(1) {
        printf("Enter RPC message: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
        
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;
        
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        
        handle_rpc_call(buffer);
    }
    
    printf("RPC server shutting down.\n");
    return 0;
}