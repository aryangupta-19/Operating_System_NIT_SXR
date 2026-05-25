#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[100], n, head;
    int seekCount = 0;
    float avg;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the sequence of requests:\n");
    // requests start from index 1
    for(int i = 1; i <= n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // store initial head at index 0
    queue[0] = head;

    printf("\nMovement sequence:\n");

    for(int j = 0; j < n; j++) {
        int diff = abs(queue[j] - queue[j + 1]);
        seekCount += diff;
        printf(
            "Disk head moves from %d to %d with seek %d\n",
            queue[j],
            queue[j + 1],
            diff
        );
    }

    avg = (float) seekCount / n;

    printf("\nTotal seek movement: %d\n", seekCount);
    printf("Average seek time: %.2f\n", avg);

    return 0;
}