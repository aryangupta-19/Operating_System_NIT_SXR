#include <stdio.h>
#include <stdlib.h>

int main() {

    int queue[100], q_size, head;
    int seek = 0, diff;
    float avg;

    printf("Enter the number of requests: ");
    scanf("%d", &q_size);

    printf("Enter the sequence of requests:\n");

    // requests start from index 1
    for(int i = 1; i <= q_size; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // store initial head at index 0
    queue[0] = head;

    printf("\nMovement sequence:\n");

    for(int j = 0; j < q_size; j++) {

        diff = abs(queue[j] - queue[j + 1]);
        seek += diff;

        printf(
            "Disk head moves from %d to %d with seek %d\n",
            queue[j],
            queue[j + 1],
            diff
        );
    }

    avg = (float) seek / q_size;

    printf("\nTotal seek movement: %d\n", seek);
    printf("Average seek time: %.2f\n", avg);

    return 0;
}