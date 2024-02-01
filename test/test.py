import socket

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
try:
    s.connect(('192.168.1.13',8001))
except Exception as e:
    print('server not found or not open')
while True:
    c= input('input thie content you want to send:')
    s.sendall(c.encode())
    data=s.recv(1024).decode()
    print('Recv',data)
    if c.lower()=='bye':
        break
s.close()
