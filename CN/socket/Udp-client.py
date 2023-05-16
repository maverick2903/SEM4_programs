# Udp-client.py
import socket

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)      # For UDP

udp_host = socket.gethostname()		# Host IP
udp_port = 12345			        # specified port to connect

print ("UDP target IP:", udp_host)
print ("UDP target Port:", udp_port)

while True:   
    msg = input("Enter a message: ")
    sock.sendto(bytes(msg,'utf-8'),(udp_host,udp_port))		# Sending message to UDP server
    if msg == "close":
        sock.close
        break    