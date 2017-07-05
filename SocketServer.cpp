#include <winsock2.h>
#include <iostream>
#include <memory.h>
#include <stdio.h>

using namespace std;
int main()
{
    struct hostent *hp;
    struct in_addr addr;
    struct sockaddr_in serverAddr;
    WSADATA wsaData;
    int ret = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(ret != 0)
    {
        cout << "Error" << endl;
        WSACleanup();
    }
    SOCKET clientfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientfd == INVALID_SOCKET)
    {
        MessageBox(0,"´´½¨Ì×½Ó×ÖÊ§°Ü!","Warning", MB_ICONEXCLAMATION);
        closesocket(clientfd);
        WSACleanup();
    }
    addr.s_addr = inet_addr("192.168.168.135");
    hp = gethostbyaddr((const char *)&addr,sizeof(addr),AF_INET);
    memset(&serverAddr,'\0',sizeof(struct sockaddr_in));
    memcpy((char*)&serverAddr.sin_addr,(char *)hp->h_addr_list[0],hp->h_length);    //OK
        serverAddr.sin_family = hp->h_addrtype;
    serverAddr.sin_port = htons(6000);
    if(connect(clientfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr))<0)
        cout<<"error"<<endl;
    int length;
    char buffer[5];
    for(int i=0;i<5;i++)
        buffer[i]='a';
    if ((length = send(clientfd, buffer, 5, 0)) == SOCKET_ERROR)
        MessageBox(0,"·¢ËÍÊ§°Ü!","Warning", MB_ICONEXCLAMATION);
    return 0;
}
