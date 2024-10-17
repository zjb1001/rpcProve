import socket

def make_rpc_call(message, host='localhost', port=12345):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        s.sendall(message.encode('utf-8'))
        response = s.recv(1024)
    return response.decode('utf-8')

if __name__ == "__main__":
    result = make_rpc_call("Hello, RPC!")
    print(result)