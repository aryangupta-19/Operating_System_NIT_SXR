#include <stdio.h>
#include <stdlib.h>

int main()
{
    int queue[100];
    int n, head;
    int seekCount = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort the request queue (bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (queue[j] > queue[j + 1]) {
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    // Find split position
    int pos = 0;
    while (pos < n && queue[pos] < head)
        pos++;

    printf("\nMovement sequence:\n");

    // Move RIGHT (serving all greater requests)
    for (int i = pos; i < n; i++) {
        int diff = abs(head - queue[i]);
        seekCount += diff;
        printf("Move from %d to %d (seek %d)\n", head, queue[i], diff);
        head = queue[i];
    }

    // C-LOOK jump: go to first request (smallest)
    if (pos > 0) {
        int diff = abs(head - queue[0]);
        seekCount += diff;
        printf("Jump from %d to %d (seek %d)\n", head, queue[0], diff);
        head = queue[0];
    }

    // Continue moving RIGHT again
    for (int i = 0; i < pos; i++) {
        int diff = abs(head - queue[i]);
        seekCount += diff;
        printf("Move from %d to %d (seek %d)\n", head, queue[i], diff);
        head = queue[i];
    }

    printf("\nTotal seek count = %d\n", seekCount);

    return 0;
}