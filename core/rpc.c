#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_RPC_METHODS 1000

typedef void (*rpc_method)(const char*, char*);

char response[MAX_MESSAGE_LENGTH];

struct {
    char* name;
    rpc_method method;
} rpc_methods[MAX_RPC_METHODS];

int rpc_method_count = 0;

void register_rpc_method(const char* name, rpc_method method) {
    if (rpc_method_count < MAX_RPC_METHODS) {
        rpc_methods[rpc_method_count].name = strdup(name);
        rpc_methods[rpc_method_count].method = method;
        rpc_method_count++;
    }
}

void rpc_call(const char* method_name, const char* params) {
    for (int i = 0; i < rpc_method_count; i++) {
        if (strcmp(rpc_methods[i].name, method_name) == 0) {
            rpc_methods[i].method(params, response);
            return;
        }
    }
    snprintf(response, MAX_MESSAGE_LENGTH, "Error: Unknown RPC method '%s'", method_name);
}

const char* get_response() {
    return response;
}

// Example RPC methods
void echo(const char* params, char* response) {
    snprintf(response, MAX_MESSAGE_LENGTH, "Echo: %s", params);
}

void add(const char* params, char* response) {
    int a, b;
    if (sscanf(params, "%d %d", &a, &b) == 2) {
        snprintf(response, MAX_MESSAGE_LENGTH, "Result: %d", a + b);
    } else {
        snprintf(response, MAX_MESSAGE_LENGTH, "Error: Invalid parameters for add. Please provide two integers separated by a space.");
    }
}

// Initialize RPC methods
void init_rpc_methods() {
    register_rpc_method("echo", echo);
    register_rpc_method("add", add);
    // Add more methods here as needed
}