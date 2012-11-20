import socket
from datetime import datetime

#"DDHHMMSS.JPGPP"

ENDERECO = ''   #Endereco do servidor
PORTA = 2000    #Porta do servidor
ADDR = (ENDERECO, PORTA)    #Tupla endereco-porta
EOF = "\n\r##"  #Terminador do arquivo
CAMINHO = "/home/felipe/socketPython/"  #Caminho onde as fotos serao armazenadas
#EXTENSAO = ".jpg"   #Extensao do arquivo

socketServidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socketServidor.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
socketServidor.bind(ADDR)

try:
    socketServidor.listen(5)
    print("Servidor rodando na porta %d" %PORTA)

    while 1:
        socketCliente, endereco = socketServidor.accept()
        
        inicioTransmissao = datetime.now()
        
        print(">> Conexao recebida (%s:%d)" %(endereco[0],endereco[1]))

        dado = ""

        while(dado[-4:] != EOF):
            dado += socketCliente.recv(1024)

        temp = dado[-18:]
        dado = dado.replace(temp, "")

        temp = temp.replace(EOF, "")
        
        ponto = temp[-2:]
        extensao = temp[-6:-2]
        tnome = temp[:-6]
        print (str(temp))

        print (ponto)
        print (extensao)
        print (tnome)

        nome = tnome + ponto + extensao
        print (nome)
        nomeArquivo = CAMINHO + str(nome)

        arquivo = open(nomeArquivo, "wb")
        arquivo.write(dado)
        arquivo.close()
        socketCliente.close()
        fimTransmissao = datetime.now()

        print(">> Recepcao terminada em %ss" % str(fimTransmissao - inicioTransmissao))
        socketServidor.shutdown(socket.SHUT_RDWR)
        
except KeyboardInterrupt:
    print(">> Fechando Conexao")
    socketServidor.shutdown(socket.SHUT_RDWR)
    socketServidor.close()
    print(">> Servidor encerrado")
