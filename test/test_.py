import socket
# Gethostname()获取本地主机名
# Gethostbyname() 根据主机名获取Ip地址
# Getservbyport() 根据端口号获取主机名
# Getservbyname() 根据服务名获取对应的端口号

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 8001))
s.listen(2)
print('listen at port:  8001')
conn, addr = s.accept()
print('connected by ', addr)
while True:
    data = conn.recv(1024)
    data = data.decode()
    print('recv:', data)
    c = input('input your word')
    conn.sendall(c.encode())
    if c.lower()=='bye':
        break
conn.close()
s.close()
