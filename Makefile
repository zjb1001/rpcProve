CC = gcc
CFLAGS = -Wall -Wextra -pedantic
# PYTHON = python
PYTHON = python3

all: rpc_server python_client

rpc_server:
	$(CC) $(CFLAGS) -o core/rpc_server core/rpc_server.c

python_client:
	$(PYTHON) -m py_compile plugins/rpc_client.py

clean:
	rm -f core/rpc_server plugins/*.pyc

.PHONY: all rpc_server python_client clean
