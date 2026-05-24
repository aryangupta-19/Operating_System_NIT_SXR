#include<stdio.h>
int main(){
    int pages[50], frames[10], time[10];
    int n, f;
    int faults = 0;
    int counter = 0;    // increments on each fault or hit then used to store in time 

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // initialize frames
    for(int i = 0; i < f; i++){
        frames[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int found = 0;
        // check hit        --> if hit then simple increment counter and 
        for(int j = 0; j < f; j++){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }
        // page fault
        if(found == 0){
            int pos = -1;

            for(int j = 0; j < f; j++){     // checking if there is any frame empty or we have to replace 
                if(frames[j] == -1){
                    pos = j;
                    break;
                }
            }

            if(pos == -1){      // if pos = -1 then it means frame is full we have to find lrc process to replace 
                int mini = time[0];
                pos = 0;
                for(int j = 1; j < f; j++){
                    if(time[j] < mini){     // finding process which is saved at farthest counter that will be lesser than recent counters 
                        mini = time[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        printf("Frames: ");
        for(int j = 0; j < f; j++){
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nPage Faults = %d\n", faults);
    printf("Page Hits = %d\n", n - faults);

    return 0;
}
