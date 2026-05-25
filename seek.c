#include<stdio.h>
int main(){
    int queue[100], vis[100];
    int n, head;
    int seekCount = 0;

    printf("Enter no. of requests");
    scanf("%d", &n);

    printf("Enter req sequence: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &queue[i]);
        vis[i] = 0;  // marked initally all unvisited
    }

    printf("Enter the head position : ");
    scanf("%d", &head);

    for(int i = 0; i<n; i++){   // movememt of pages
        int mini = 9999;
        int pos = -1;

        // find nearest number in value 
        for(int j = 0; j<n; j++){
            if(vis[j] == 0){    // univisted
                int diff = abs(queue[i] - queue[j]);

                if(diff < mini){
                    mini  = diff;
                    pos = j;
                }
            }
        }

        // movement
        printf("Disk moves from %d to %d with seek %d\n", head, queue[pos], mini);
        seekCount++;
        head = queue[pos];
        vis[pos] = 1;
    }

    printf("\nTotal seek movement: %d\n", seekCount);

    return 0;
}



// input queue , head , no of process, 
// maintain a vis array and a seekCount variable 