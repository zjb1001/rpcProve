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
   This compiles the C source file into an executable RPC server.

2. **Prepare the Python client**
   ```
   make python_client
   ```
   This command byte-compiles the Python script for slightly faster execution.

3. **Run the RPC server**
   ```
   ./core/rpc_server
   ```
   This starts the RPC server, which will listen for incoming connections.

4. **Run the Python client**
   ```
   python3 plugins/rpc_client.py
   ```
   This executes the Python script, which connects to the RPC server and makes an RPC call.

5. **Clean up (optional)**
   ```
   make clean
   ```
   This removes compiled files if you want to start fresh.

## Explanation

- The C server (`rpc_server.c`):
  - Listens for incoming connections on port 12345.
  - Handles RPC calls by appending a prefix to the received message and sending it back.

- The Python client (`rpc_client.py`):
  - Uses sockets to connect to the RPC server.
  - Provides a `make_rpc_call` function that sends a message to the server and receives the response.

- When you run the Python script, it makes an RPC call with the message "Hello, RPC!" and prints the response received from the server.

This project demonstrates how to create a simple RPC system where a Python client can make calls to a C server over a network connection.