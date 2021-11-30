// C server side code
#include <memory.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
int main()
{
    int udpSocket, nBytes;
    char buffer[3000], xor[3000];
    char const key[1024] = "HIDDENKEY";
    struct sockaddr_in serverAddr, clientAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size, client_addr_size;
    int i;
    udpSocket = socket(PF_INET, SOCK_DGRAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5004);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    bind(udpSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    addr_size = sizeof serverStorage;
    puts("Waiting for client :");
    int count = 0;
    while (1)
    {
        nBytes = recvfrom(udpSocket, buffer, 3000, 0, (struct sockaddr *)&serverStorage,
                          &addr_size);
        printf("Message no : %d\n", ++count);
        for (i = 0; i < nBytes - 1; i++)
        {
            if (buffer[i] != '\n')
                xor[i] = (char)(buffer[i] ^ key[i]);
            else
                xor[i] = buffer[i];
        }
        printf("Encrypted message stored in file : (First 15 characters)\n");
        // printing some of the character to have a feel of encryption
        for (i = 0; i < 15; ++i)
            printf("%02X ", xor[i]);
        printf("\n");
        FILE *fp;
        fp = fopen("temp.txt", "w+");
        for (i = 0; i < nBytes - 1; i++)
        {
            if (xor[i] != '\n')
                fprintf(fp, "%X", xor[i]);
            else
                fprintf(fp, "%c", xor[i]);
        }
        fclose(fp);
        sendto(udpSocket, xor, nBytes, 0, (struct sockaddr *)&serverStorage,
               addr_size);
    }
    return 0;
}
#include <stdio.h>
int main()
{
    char mat[5][5];
    printf("Enter key table\n");
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            printf("\nEnter value %d %d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    printf("\nEnter input: ");
    char msg[100];
    gets(msg);
    //..........Server Side...........
    int cry[200];
    int ptr = 0;
    for (int i = 0; i < sizeof(msg); i++)
    {
        // for(int j=0;j>)
        // cry[ptr]
    }
    return 0;
}