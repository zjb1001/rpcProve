#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

char response[MAX_MESSAGE_LENGTH];

void rpc_call(const char* message) {
    snprintf(response, MAX_MESSAGE_LENGTH, "RPC Response: %s", message);
}

const char* get_response() {
    return response;
}