# RPC Prove Project Manual

This manual explains how to set up and use the RPC Prove project, which demonstrates local RPC calls between a C library and a Python client.

## Project Structure

- `core/`: Contains the C implementation of the RPC library
  - `rpc.c`: C source file for the RPC library
- `plugins/`: Contains the Python RPC client
  - `rpc_client.py`: Python script that makes RPC calls to the C library
- `Makefile`: Manages the build process
- `manual.md`: This file, explaining how to use the project

## Step-by-Step Guide

1. **Compile the C library**
   ```
   make core_lib
   ```
   This compiles the C source file into a shared library (`librpc.so`).

2. **Prepare the Python client**
   ```
   make python_plugin
   ```
   This command byte-compiles the Python script for slightly faster execution.

3. **Run the Python client**
   ```
   python3 plugins/rpc_client.py
   ```
   This executes the Python script, which loads the C library and makes an RPC call.

4. **Clean up (optional)**
   ```
   make clean
   ```
   This removes compiled files if you want to start fresh.

## Explanation

- The C library (`rpc.c`) defines two functions:
  - `rpc_call`: Simulates an RPC call by appending a prefix to the input message.
  - `get_response`: Returns the result of the last RPC call.

- The Python client (`rpc_client.py`) uses `ctypes` to load and interact with the C library:
  - It loads the shared library (`librpc.so`).
  - It defines the function signatures for the C functions.
  - It provides a `make_rpc_call` function that wraps the C function calls.

- When you run the Python script, it makes an RPC call with the message "Hello, RPC!" and prints the response.

This project demonstrates how to create a simple RPC system where Python code can make calls to C functions, simulating a local RPC mechanism.