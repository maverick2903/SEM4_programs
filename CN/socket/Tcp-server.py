import socket

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

tcp_host = socket.gethostname()
tcp_port = 12345

sock.bind((tcp_host,tcp_port))
sock.listen(1)

print("Server is listening on ",tcp_host,tcp_port)

while True:
    print("Waiting for client...")
    client_sock, client_address = sock.accept()
    print("Client connected from", client_address)

    while True:
        data = client_sock.recv(1024)
        if not data:
            break

        received_message = data.decode()
        print("Received Message:", received_message)

        if received_message == "close":
            client_sock.close()
            break

        response_message = "Hello from the server"
        client_sock.sendall(response_message.encode())

    if received_message == "close":
        print("Closing server...")
        break

sock.close()