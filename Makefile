CC = gcc
CFLAGS = -Wall -Wextra -pedantic -shared -fPIC
PYTHON = python3

all: core_lib python_plugin

core_lib:
	$(CC) $(CFLAGS) -o core/librpc.so core/rpc.c

python_plugin:
	$(PYTHON) -m py_compile plugins/rpc_client.py

clean:
	rm -f core/*.so plugins/*.pyc

.PHONY: all core_lib python_plugin clean