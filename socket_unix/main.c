#include "client.h"
#include <unistd.h>

int main(void) {
    ClientSocket client;
    initClientSocket(&client);
    printf("connect %d\n",connectToServer(&client));
    while (1) {
        printf("write %d\n",writeData(&client,"123456",7));
        sleep(2);
    }
    disconnect(&client);
    return 0;
}
