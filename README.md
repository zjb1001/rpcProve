# RPC Prove Project Manual

This manual explains how to set up and use the RPC Prove project, which demonstrates network-based RPC calls between a C server and a Python client.

## Project Structure

- `core/`: Contains the C implementation of the RPC server
  - `rpc_server.c`: C source file for the RPC server
- `plugins/`: Contains the Python RPC client
  - `rpc_client.py`: Python script that makes RPC calls to the C server
- `Makefile`: Manages the build process
- `manual.md`: This file, explaining how to use the project

## Step-by-Step Guide

1. **Compile the C server**
   ```
   make rpc_server
   ```
   This compiles the C source files into an executable RPC server.

2. **Prepare the Python client**
   ```
   make python_client
   ```
   This command byte-compiles the Python script for slightly faster execution.

3. **Run the RPC server**
   ```
   ./core/rpc_server
   ```
   This starts the RPC server, which will listen for incoming connections on port 12345.

4. **Run the Python client**
   ```
   python3 plugins/rpc_client.py
   ```
   This executes the Python script, which connects to the RPC server and allows you to make RPC calls.

5. **Making RPC calls**
   When the Python client is running, you'll be prompted to enter:
   - The RPC method name (e.g., "echo" or "add")
   - The parameters for the method (e.g., "Hello, World!" for echo, or "5 3" for add)

   Example session:
   ```
   Enter RPC method (or 'quit' to exit): echo
   Enter parameters: Hello, RPC!
   Server response: Echo: Hello, RPC!

   Enter RPC method (or 'quit' to exit): add
   Enter parameters: 5 3
   Server response: Result: 8

   Enter RPC method (or 'quit' to exit): quit
   ```

6. **Clean up (optional)**
   ```
   make clean
   ```
   This removes compiled files if you want to start fresh.

## Explanation

- The C server (`rpc_server.c` and `rpc.c`):
  - Listens for incoming connections on port 12345.
  - Registers RPC methods like "echo" and "add".
  - Handles RPC calls by parsing the method name and parameters, executing the appropriate function, and sending back the result.

- The Python client (`rpc_client.py`):
  - Uses sockets to connect to the RPC server.
  - Provides a `make_rpc_call` function that sends a message to the server and receives the response.
  - Offers an interactive prompt for the user to make multiple RPC calls.

This project demonstrates how to create a simple RPC system where a Python client can make calls to a C server over a network connection. The server supports multiple RPC methods, and the client allows for interactive use of these methods.