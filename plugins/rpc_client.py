import socket

def make_rpc_call(method, params, host='localhost', port=12345):
    message = f"{method}:{params}"
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.sendall(message.encode('utf-8'))
        response = s.recv(1024)
    return response.decode('utf-8').strip()

if __name__ == "__main__":
    while True:
        method = input("Enter RPC method (or 'quit' to exit): ")
        if method.lower() == 'quit':
            break
        params = input("Enter parameters: ")
        result = make_rpc_call(method, params)
        print("Server response:", result)