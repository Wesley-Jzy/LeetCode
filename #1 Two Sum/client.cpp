//
//  client.cpp
//  net
//
//  Created by 姜子悦 on 16/7/5.
//  Copyright (c) 2016年 姜子悦. All rights reserved.
//

#include "client.h"

void Client::create_sockaddr_in()
{
    server_addr_in.sin_len = sizeof(struct sockaddr_in);
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(server_port);
    server_addr_in.sin_addr.s_addr = inet_addr(server_ip);
    bzero(&(server_addr_in.sin_zero), 8);
}

void Client::create_socket()
{
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        std::cout << "Socket Error" << std::endl;
    }
}

void Client::connect_to_Server()
{
    //发起交易请求，此处为一问一答
    char recv_msg[1024];
    char reply_msg[1024];
    
    if (connect(server_socket, (struct sockaddr *)&server_addr_in, sizeof(struct sockaddr_in))==0)
    {
        /* connect成功之后，绑定到一个系统分配的端口上，全相关，包含服务器端的信息，可以用来和服务器端进行通信。*/
        while (1)
        {
            bzero(recv_msg, 1024);
            bzero(reply_msg, 1024);
            long byte_num = recv(server_socket,recv_msg,1024,0);
            recv_msg[byte_num] = '\0';
            printf("Your father said:%s\n",recv_msg);
            
            printf("reply:");
            scanf("%s",reply_msg);
            if (send(server_socket, reply_msg, 1024, 0) == -1)
            {
                perror("send error");
            }
        }
        
    }
}

Client::Client()
{
    create_sockaddr_in();
    create_socket();
}