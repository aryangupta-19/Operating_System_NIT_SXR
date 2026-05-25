#include <stdio.h>
#include<stdlib.h>
int main()
{
    int queue[100];
    int n, head;
    int seekCount = 0;
    float avg;
    int diskSize = 199;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // 1) sort-> bubble sort
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            if (queue[j] > queue[j + 1]){
                int temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    int pos= -1;
    // find split position
    for (int i = 0; i < n; i++){
        if (queue[i] >= head){
            pos = i;
            break;
        }
    }

    if(pos == -1) pos = n;

    printf("\nMovement sequence:\n");

    // move right first
    for (int i = pos; i < n; i++){
        int diff = abs(head - queue[i]);
        seekCount += diff;
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[i], diff);
        head = queue[i];  // important!
    }

    // move left
    for (int i = pos - 1; i >= 0; i--){
        int diff = abs(head - queue[i]);
        seekCount += diff;
        printf("Disk head moves from %d to %d with seek %d\n", head, queue[i], diff);
        head = queue[i];
    }

     printf("\nTotal seek count = %d\n", seekCount);

    return 0;
}