import socket

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

tcp_host = socket.gethostname()
tcp_port = 12345

sock.connect((tcp_host,tcp_port))
print("Connected to server at ",tcp_host,tcp_port)

while True:
    msg = input("Enter your message: ")
    sock.send(msg.encode())
    res = sock.recv(1024)
    print("Response recieved from server: ",res.decode())
    if msg == "close":
        print("Closing client...")
        sock.close()
        break