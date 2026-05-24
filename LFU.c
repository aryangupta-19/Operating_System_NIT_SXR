#include<stdio.h>

int main(){

    int pages[50], frames[10], freq[10];
    int n, f;
    int faults = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");

    for(int i = 0; i < n; i++){
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // initialize
    for(int i = 0; i < f; i++){
        frames[i] = -1;
        freq[i] = 0;
    }

    for(int i = 0; i < n; i++){
        int found = 0;
        // check hit
        for(int j = 0; j < f; j++){
            if(frames[j] == pages[i]){
                freq[j]++;
                found = 1;
                break;
            }
        }

        // fault
        if(found == 0){
            int pos = -1;
            // empty frame
            for(int j = 0; j < f; j++){
                if(frames[j] == -1){
                    pos = j;
                    break;
                }
            }

            // replacement
            if(pos == -1){
                int max = freq[0];
                pos = 0;
                for(int j = 1; j < f; j++){
                    if(freq[j] > max){
                        max = freq[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            freq[pos] = 1;
            faults++;
        }
        printf("Frames: ");
        for(int j = 0; j < f; j++){
            if(frames[j] != -1) printf("%d ", frames[j]);
            else    printf("- ");
        }

        printf("\n");
    }

    printf("\nPage Faults = %d\n", faults);
    return 0;
}