#include <stdio.h>
#include "./queue_template.h"


DEF_QUEUE(byte, uint8_t, uint16_t, void *)
END_DEF_QUEUE(byte)

int main()
{
    uint8_t buffer[8];

    QUEUE_NAME(byte) Q;

    QUEUE_INIT(byte, &Q, buffer, 8);

    uint8_t val = 1;

    QUEUE_IN(byte, &Q, &val);
    val++;
    QUEUE_IN(byte, &Q, &val);
    val++;
    QUEUE_IN(byte, &Q, &val);
    val++;
    QUEUE_IN(byte, &Q, &val);
    val++;
    QUEUE_IN(byte, &Q, &val);
    val++;

    uint8_t out;

    printf("peek all\n");
    for (uint8_t i = 0; i < 8; i++) {
        if (QUEUE_PEEK(byte, &Q, &out)) {
            printf("%u\n", out);
        }
    }

    if (QUEUE_IS_EMPTY(byte, &Q)) {
        printf("queue is empty\n");
    } else {
        printf("queue is not empty, size is %d\n", QUEUE_SIZE(byte, &Q));
    }

    QUEUE_RESET_PEEK(byte, &Q);

    printf("peek all\n");
    for (uint8_t i = 0; i < 8; i++) {
        if (QUEUE_PEEK(byte, &Q, &out)) {
            printf("%u\n", out);
        }
    }

//    printf("QUEUE_GET_ALL_PEEKED\n");
//    QUEUE_GET_ALL_PEEKED(byte, &Q);

    printf("out all\n");
    for (uint8_t i = 0; i < 8; i++) {
        if (QUEUE_OUT(byte, &Q, &out)) {
            printf("%u\n", out);
        }
    }

    return 0;
}