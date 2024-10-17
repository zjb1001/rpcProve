import ctypes

# Load the shared library
lib = ctypes.CDLL('./core/librpc.so')

# Define function signatures
lib.rpc_call.argtypes = [ctypes.c_char_p]
lib.get_response.restype = ctypes.c_char_p

def make_rpc_call(message):
    # Convert Python string to bytes
    message_bytes = message.encode('utf-8')
    
    # Make the RPC call
    lib.rpc_call(message_bytes)
    
    # Get the response
    response = lib.get_response()
    
    # Convert bytes to Python string
    return response.decode('utf-8')

if __name__ == "__main__":
    result = make_rpc_call("Hello, RPC!")
    print(result)